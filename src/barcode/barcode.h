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
#include <cstddef>


#ifndef LIBBARCODE_H
#define LIBBARCODE_H

class barcode {
	public:
		barcode ();
		~barcode ();

	protected:
		int atoia (char *destination, const char *source, size_t num);
		int iatoa (char *destination, const char *source, size_t num);
		int iatoi (int *destination, const char *source, size_t num);

		int set_data (const char *source);
		char *data; /**< internal storage for data */
		size_t data_length; /**< length of \ref data */
		bool data_convert_to_ia;
		/**< flag, if \p source should be converted with \ref atoia to an
		 * array of integers */

	private:
};

#endif
