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


#ifndef LIBBARCODE_GTIN_H
#define LIBBARCODE_GTIN_H

/*
 * include header files
 */
#include <numeric.hpp>


class barcode_gtin : public barcode_numeric {
	public:
		barcode_gtin ();
		barcode_gtin (const std::string& source);
		barcode_gtin (const std::string& source, size_t subpos, size_t sublen);

//		size_t set_addon_code (const std::string &source);
//		size_t set_addon_code (const std::string &source, size_t subpos, size_t sublen);
//		size_t get_addon_code ();

//		bool is_valid ();

	protected:
		std::string data_addon_code;

	private:
//		char checksum (size_t offset);
};

#endif
