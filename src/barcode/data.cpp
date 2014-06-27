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
#include <cstring>
#include <cstdlib>

#include "barcode.h"


/**
 * \brief Copy C string \p source into internal memory.
 *
 * \details Copies the C string pointed by \p source into \ref data, including
 *  the terminating null character (and stopping at that point).
 *
 *  If \ref data_convert_to_ia is true, \p source will be converted with \ref
 *  atoia to an array of integer which will be stored in \ref data.
 *
 *
 * \param source C string to be copied.
 *
 * \return If \p source is successfully copied, 0 is returned. Otherwise -1 is
 *  returned.
 *
 *
 * \b Example:
 * \code
 * #include <iostream>
 *
 * void barcode::test ()
 * {
 *   const char source[11] = "1234567890";
 *
 *   if (this->set_data(&destination[0]) < 0)
 *     std::cerr << "Error while copying source" << std::endl;
 * }
 * \endcode
 */
int barcode::set_data (const char *source)
{
	// if source is NULL, we can't copy it
	if (source == NULL) return -1;

	// get length of source
	size_t source_length = strlen(source);

	// resize this->data to new length, if needed
	if (source_length != this->data_length) {
		size_t new_size = source_length;
		if (!this->data_convert_to_ia) new_size++;

		// realloc memory
		void *temp = realloc(this->data, new_size);
		if (temp == NULL) return -1;
		else this->data = (char *)temp;

		// set this->data_length
		this->data_length = source_length;
	}

	// should data be converted?
	if (this->data_convert_to_ia) {
		// copy converted data into this->data
		if (this->atoia(this->data, source, source_length) < 0) return -1;
	} else {
		// data should only be copied as C string
		if (strncpy(this->data, source, source_length) != this->data)
			return -1;
	}

	// return success
	return 0;
}
