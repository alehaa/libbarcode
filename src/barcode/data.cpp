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

#include <cstring>
#include <cstdlib>

#include "barcode.hpp"



/** \brief Copies the first \p num characters of \p source into internal memory.
 *
 * \details Copies the first \p num characters of string referenced by \p source
 *  into \ref barcode::data.
 *
 *
 * \param source \ref std::string to be copied.
 * \param num Maximum number of characters to be copied from \p source.
 *
 * \return The number of copied characters.
 *
 * \include barcode/data/set_data_substring.cpp
 */
size_t barcode::set_data (const std::string &source, size_t subpos, size_t sublen)
{
	// copy source into temp string
	std::string temp;
	temp.assign(source, subpos, sublen);

	// check, if source contains characters, that are not allowed
	if (!this->data_allowed_characters.empty()) {
		if (temp.find_first_not_of(this->data_allowed_characters, 0) != std::string::npos)
			throw std::invalid_argument("source contains unallowed character");
	}

	// copy source into data
	this->data = temp;

	// return failure
	return temp.length();
}


/** \brief Copies string \p source into internal memory.
 *
 * \details Copies the string referenced by \p source into \ref barcode::data.
 *
 *
 * \param source \ref std::string to be copied.
 *
 * \return The number of copied characters.
 *
 * \include barcode/data/set_data_string.cpp
 */
size_t barcode::set_data (const std::string &source)
{
	return this->set_data(source, 0, source.length());
}


/**
 * \brief Returns \ref barcode::data.
 *
 *
 * \return Returns \ref barcode::data.
 *
 *
 * \include barcode/data/get_data.cpp
 */
std::string barcode::get_data ()
{
	return this->data;
}
