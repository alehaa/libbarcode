/* This file is part of libgtin.
 *
 * libgtin is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Copyright 2013-2014 Alexander Haase <alexander.haase@rwth-aachen.de>
 */

#include "gtin.h"

#include <string>



/* clear
 *
 * This function resets all non-static data to its default values and deletes
 * allocated memory blocks
 */
void gtin::clear () {
	if (this->data_gtin) delete[] this->data_gtin;
	this->data_gtin = nullptr;
	this->data_gtin_length = 0;

	if (this->data_addon_code) delete[] this->data_addon_code;
	this->data_addon_code = nullptr;
	this->data_addon_code_length = 0;
}


/* set_data
 * @param:
 *	const char *p_data: array of char, containing the digits of the GTIN-code
 *	bool p_contains_checksum: indicates, if p_data contains a checksum
 *
 * @return:
 *	returns true, if data, checksum (if included in p_data) and addon-code (if
 *	included in p_data) could be validated. Otherwise false will be returned.
 *
 *
 * This function trys to validate p_data, checks the checksum if it is included
 * in p_data and the addon-code (if it is included in p_data and should be
 * handled)
 */
bool gtin::set_data (const char* p_data, bool p_contains_checksum, const char *p_addon_code) {
	// return false, if p_data is nullptr
	if (!p_data) return false;

	// If data is set, cleanup existing data
	if (this->data_gtin) this->clear();

	// check, if length of p_data is okay
	size_t p_data_length = std::char_traits<char>::length(p_data);
	bool match = false;
	if (p_contains_checksum) {
		if (p_data_length == 8 || (p_data_length >= 8 && p_data_length <= 14)) match = true;
		if (!match && !p_addon_code && (p_data_length == 15 || p_data_length == 18)) match = true;
	} else
		if (p_data_length == 7 || (p_data_length >= 11 && p_data_length <= 13)) match = true;

	if (!match) return false;

	/* Check with the help of p_data_length whether an addon Code was passed and how
	 * long are addon_code and data area. */
	if (p_contains_checksum && (p_data_length == 15 || p_data_length == 18)) {
		/* Addon codes exist only for GTIN-13 codes so that the addon code must have a
		 * length of p_data_length minus 13 */
		this->data_addon_code_length = p_data_length - 13;
		this->data_gtin_length = 13;
	} else {
		if (!p_contains_checksum) p_data_length++;
		this->data_gtin_length = p_data_length;
	}

	// translate p_data to array of chars (int)
	if (!(this->data_gtin = this->cstr2carray(p_data, this->data_gtin_length))) return false;

	// checksum was passed. Check, if it's valid
	if (!p_contains_checksum || (p_contains_checksum && !this->checksum())) {
		/* if addon-code should not be handled, or no addon-code is in p_data, all tests
		 * are passed now */
		if (!this->conf_handle_addon_codes || (this->data_addon_code_length == 0 && !p_addon_code)) return true;

		// translate addon-code to array of chars (int)
		if (this->data_addon_code_length == 0) {
			this->data_addon_code_length = std::char_traits<char>::length(p_addon_code);
			if ((this->data_addon_code = this->cstr2carray(p_addon_code, this->data_addon_code_length))) return true;
		} else
			if ((this->data_addon_code = this->cstr2carray(&p_data[this->data_gtin_length], this->data_addon_code_length))) return true;
	}

	// an error occured
	this->clear();
	return false;
}


/* get_data();
 * @return:
 *	returns a pointer to cstring
 *
 * returns data in this->data_gtin as cstring or nullptr on error
 */
const char * gtin::get_data () {
	return this->carray2cstr(this->data_gtin, this->data_gtin_length);
}


/* get_addon_code();
 * @return:
 *	returns a pointer to cstring
 *
 * returns data in this->data_addon_code as cstring or nullptr on error
 */
const char * gtin::get_addon_code () {
	return this->carray2cstr(this->data_addon_code, this->data_addon_code_length);
}
