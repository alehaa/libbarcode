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

#ifndef GTIN_H
#define GTIN_H

class gtin {
	public:
		~gtin ();

		void set_handle_addon_codes (bool p_handle);

		bool set_data (const char* p_data, bool p_contains_checksum = true);
		const char * get_data ();

		bool set_addon_code (const char* p_data);
		const char * get_addon_code ();


		enum class gtin_type {
			ERR = -1,
			NONE = 0,
			STOREINTERNAL = 1,
			PRESSCODE_GERMANY = 2,
			ISSN = 3,
			ISBN = 4,
			ISMN = 5,
			REFUND_RECEIPT = 6,
			COUPON = 7,
			COMMON_CURRENCY_COUPON = 8,
		};

		const gtin::gtin_type get_gtin_type ();
		const short get_gtin_gs1_prefix ();
		const int get_gtin_section_articlenumber ();
		const short get_gtin_section_amount ();

		void reset ();


	protected:
		unsigned char * cstr_to_chararray (const char *p_data, unsigned char p_data_length);
		const char * chararray_to_cstr (unsigned char *p_data, unsigned char p_data_length);
		int chararray_to_int (unsigned char *p_data, unsigned char p_data_length = 1);

		unsigned char* data_gtin = nullptr, data_gtin_length;
		unsigned char* data_addon_code = nullptr, data_addon_code_length;

		bool checksum ();

		bool handle_addon_code = true;
};

#endif
