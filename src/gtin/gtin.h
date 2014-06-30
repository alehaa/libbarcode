/* This file is part of libbarcode.
 *
 * libbarcode is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Copyright (C)
 *  2013-2014 Alexander Haase <alexander.haase@rwth-aachen.de>
 */

#ifndef LIBBARCODE_GTIN_H
#define LIBBARCODE_GTIN_H


/*
 * include header files
 */
#include <cstddef>
#include <stdexcept>
#include <string>


class barcode_gtin {
	public:
		barcode_gtin ();
		~barcode_gtin ();

		void clear ();

		int set_data (const char *source) throw(std::invalid_argument);
		//int set_data (const char *source, size_t num) throw(std::invalid_argument);
		//int set_data (std::string &source) throw(std::invalid_argument);
		//int set_data (std::string &source, size_t num) throw(std::invalid_argument);

		int get_data (char *destination);
		//int get_data (std::string &destination);

		int set_addon_code (const char *source) throw(std::invalid_argument);
		//int set_addon_code (const char *source, size_t num) throw(std::invalid_argument);
		//int set_addon_code (std::string &source) throw(std::invalid_argument);
		//int set_addon_code (std::string &source, size_t num) throw(std::invalid_argument);

		int get_addon_code (char *destination);
		//int get_addon_code (std::string &destination);

		bool is_valid ();
		void appdend_checksum ();

		const uint16_t get_gs1_country_prefix ();
		const uint32_t get_gs1_company_reference ();
		const uint16_t get_gs1_item_reference ();

	protected:

	private:
		std::string data;
		/**< Internal storage for data */

		std::string addon_code;
		/**< Internal storage for addon_code */

		//unsigned char * cstr2carray (const char *p_data, unsigned char p_data_length);
		//const char * carray2cstr (unsigned char *p_data, unsigned char p_data_length);
		//unsigned int carray2int (unsigned char *p_data, unsigned char p_data_length);
};

#endif
