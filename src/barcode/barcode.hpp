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

/*
 * include header files
 */
//#include <cstddef>
#include <stdexcept>


#ifndef LIBBARCODE_H
#define LIBBARCODE_H

class barcode {
	public:
		int set_data (const char *source) throw(std::invalid_argument);
		int get_data (char *destination);

	protected:
		//int atoia (char *destination, const char *source, size_t num);
		//int iatoa (char *destination, const char *source, size_t num);
		//int iatoi (int *destination, const char *source, size_t num);

		std::string data;
		/**< Internal storage for data */
		//std::regex data_allowed_regex;
		/**< String containing regex that \p source must match to assign value
		 * to barcode:: data */

	private:
};

#endif
