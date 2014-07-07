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
//#include <regex>

#include "barcode.hpp"


/**
 * \brief Copy C string \p source into internal memory.
 *
 * \details Copies the C string pointed by \p source into \ref barcode::data.
 *
 *  \p source will only be copied, if it matches \ref
 *  barcode::data_allowed_regex.
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
 *   if (this->set_data(&source[0]) < 0)
 *     std::cerr << "Error while copying source" << std::endl;
 * }
 * \endcode
 */
size_t barcode::set_data (const char *source)
{
	// if source is NULL, we can't copy it
	if (source == NULL) throw std::invalid_argument("source is NULL");

	// get length of source
	size_t len = strlen(source);

	// check, if source contains characters, that are not allowed
	if (!this->data_allowed_characters.empty()) {
		if (strspn(source, this->data_allowed_characters.c_str()) != len)
			throw std::invalid_argument("source contains unallowed character");
	}


	// copy source into data
	this->data = source;

	// return failure
	return len;
}


/**
 * \brief Copy \ref barcode::data into C string \p destination.
 *
 *
 * \param destination Pointer to the destination array.
 *
 * \return If \ref barcode::data is successfully copied, 0 is returned.
 *  Otherwise -1 is returned.
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
 *   if (this->set_data(&source[0]) < 0)
 *     std::cerr << "Error while copying source" << std::endl;
 *
 *   char dest[11];
 *   if (this->get_data(&dest[0]) < 0)
 *     std::cerr << "Error while copying into destination" << std::endl
 * }
 * \endcode
 */
int barcode::get_data (char *destination)
{
	// if this->data is empty, we can't copy it
	if (!this->data.empty()) {
		if (std::strcpy(destination, this->data.c_str()) == destination) {
			return 0;
		}
	}

	// return failure
	return -1;
}
