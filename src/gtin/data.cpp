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

#include "gtin.hpp"



/** \brief Copies the first \p sublen characters of \p source starting at
 *  position \p subpos into internal memory.
 *
 * \details Copies the first \p sublen characters of \p source starting at
 *  position \p subpos referenced by \p source into \ref barcode::data.
 *
 *
 * \param source std::string to be copied.
 * \param subpos Position of the first character in \p source that is copied to
 *  \ref barcode::data as a substring.
 * \param sublen Length of the substring to be copied (if \p source is shorter,
 *  as many characters as possible are copied).
 *  A value of string::npos indicates all characters until the end of str.
 *
 * \return The number of copied characters.
 *
 * \throw std::invalid_argument If \p source contains unallowed characters an
 *  invalid_argument exception is thrown.
 * \throw std::out_of_range If \p subpos is greater than \p source's length,
 *  an out_of_range exception is thrown.
 * \throw std::length_error If the resulting string length would exceed the
 *  max_size, a length_error exception is thrown.
 * \throw std::bad_alloc A bad_alloc exception is thrown if the function needs
 *  to allocate storage and fails.
 */
size_t barcode_gtin::set_data (const std::string &source, size_t subpos, size_t sublen)
{
	// is length of source ok?
	size_t len = source.length();
	if ((len < 7 || len > 8) && (len < 11 || len > 15) && len != 18)
		throw std::invalid_argument("source has wrong length");

	// cxall inherited set_data
	return barcode_numeric::set_data(source, subpos, sublen);
}


/** \brief Copies string \p source into internal memory.
 *
 * \details Copies the string referenced by \p source into \ref barcode::data.
 *
 *
 * \param source std::string to be copied.
 *
 * \return The number of copied characters.
 *
 * \throw std::invalid_argument If \p source contains unallowed characters an
 *  invalid_argument exception is thrown.
 * \throw std::out_of_range If \p subpos is greater than \p source's length,
 *  an out_of_range exception is thrown.
 * \throw std::length_error If the resulting string length would exceed the
 *  max_size, a length_error exception is thrown.
 * \throw std::bad_alloc A bad_alloc exception is thrown if the function needs
 *  to allocate storage and fails.
 */
size_t barcode_gtin::set_data (const std::string &source)
{
	return this->set_data(source, 0, std::string::npos);
}
