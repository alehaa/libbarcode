/* This file is part of libbarcode.
 *
 * libbarcode is free software: you can redistribute it and/or modify it under the
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

#ifndef GTIN_H
#define GTIN_H

#include <cstddef>

class barcode_gtin {
	public:
		barcode_gtin ();
		~barcode_gtin ();

		void enable_addon_codes ();
		void disable_addon_codes ();

		bool set_data (const char *p_data, bool p_contains_checksum = true, const char *p_addon_code = NULL);
		const char * get_data ();
		const char * get_addon_code ();
		void clear();

		const short get_gtin_gs1_prefix ();
		const int get_gtin_company_number ();
		const short get_gtin_item_reference ();

	protected:
		bool checksum ();

	private:
		bool conf_handle_addon_codes;

		unsigned char *data_gtin, data_gtin_length;
		unsigned char *data_addon_code, data_addon_code_length;

		unsigned char * cstr2carray (const char *p_data, unsigned char p_data_length);
		const char * carray2cstr (unsigned char *p_data, unsigned char p_data_length);
		unsigned int carray2int (unsigned char *p_data, unsigned char p_data_length);
};

#endif
