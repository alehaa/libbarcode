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

#include <stdexcept>
#include <string>

#include "barcode.hpp"



/** \brief Copies the string referenced by \p source into \ref data.
 *
 *  If \ref charset is not empty, \p source will be checked, if it only contains
 *  characters listed in \ref charset.
 *
 *
 * \param source std::string to be copied.
 *
 * \return *this
 *
 * \throw std::invalid_argument If \p source contains unallowed characters an
 *  invalid_argument exception is thrown.
 * \throw std::out_of_range If \p subpos is greater than \p source's length,
 *  an out_of_range exception is thrown.
 * \throw std::length_error If the resulting string length would exceed the
 *  max_size of \ref data, a length_error exception is thrown.
 * \throw std::bad_alloc A bad_alloc exception is thrown if the function needs
 *  to allocate storage and fails.
 */
barcode& barcode::assign_data (const std::string &source)
{
	// pass through
	return this->assign_data(source, 0, std::string::npos);
}


/** \brief Copies the first \p sublen characters of \p source starting at
 *  position \p subpos into \ref data.
 *
 * \details Copies the first \p sublen characters of \p source starting at
 *  position \p subpos referenced by \p source into \ref data.
 *
 *  If \ref charset is not empty, \p source will be checked, if it only contains
 *  characters listed in \ref charset.
 *
 *
 * \param source std::string to be copied.
 * \param subpos Position of the first character in \p source that is copied to
 *  \ref data as a substring.
 * \param sublen Length of the substring to be copied (if \p source is shorter,
 *  as many characters as possible are copied).
 *  A value of string::npos indicates all characters until the end of str.
 *
 * \return *this
 *
 * \throw std::invalid_argument If \p source contains unallowed characters an
 *  invalid_argument exception is thrown.
 * \throw std::out_of_range If \p subpos is greater than \p source's length,
 *  an out_of_range exception is thrown.
 * \throw std::length_error If the resulting string length would exceed the
 *  max_size of \ref data, a length_error exception is thrown.
 * \throw std::bad_alloc A bad_alloc exception is thrown if the function needs
 *  to allocate storage and fails.
 */
barcode& barcode::assign_data (const std::string& source, size_t subpos, size_t sublen)
{
	/* copy source into internal memory
	 *
	 * this assign could throw exceptions. See documentation of std::string
	 */
	this->data.assign(source, subpos, sublen);

	/* if data_allowed_characters contains any restrictions for characters, that
	 * are the only allowed characters to be in source, check if only allowed
	 * characters are in source (now stored in data!)
	 */
	if (!this->charset.empty()) {
		if (this->data.find_first_not_of(this->charset) != std::string::npos) {
			throw std::invalid_argument("source contains unallowed character");
		}
	}

	// return reference to this object
	return *this;
}


/** \brief Returns \ref barcode::data.
 *
 *
 * \return Returns \ref barcode::data.
 */
std::string barcode::get_data () const
{
	return this->data;
}
