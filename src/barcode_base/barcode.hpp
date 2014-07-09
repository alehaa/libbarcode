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

#include <string>
#include <cstddef>



#ifndef LIBBARCODE_H
#define LIBBARCODE_H

class barcode {
	public:
		barcode ();
		barcode (const std::string& source);
		barcode (const std::string& source, size_t subpos, size_t sublen);

		barcode& operator= (const std::string& source);

		barcode& assign_data (const std::string& source);
		barcode& assign_data (const std::string& source, size_t subpos, size_t sublen);

		std::string get_data () const;

	protected:
		std::string data;
		/**< Internal storage for data */
		std::string charset;
		/**< String containing all characters that are allowed to be used in
		 * \ref data or any other storage for data entrys that could be encoded
		 * as barcode */
};

#endif
