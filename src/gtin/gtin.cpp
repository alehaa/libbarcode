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



/** \brief Constructs a \ref barcode_gtin object.
 */
barcode_gtin::barcode_gtin () : barcode_numeric()
{
}


/** \brief Constructs a \ref barcode_gtin object, initializing the value of
 *  \ref data with \p source.
 *
 * \details Constructs a \ref barcode_gtin object, initializing the value of
 *  \ref data with \p source.
 *  \p source will be checked, if it only contains integers, as \ref charset
 *  only contains integers.
 *
 *
 * \param source std::string to be copied.
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
barcode_gtin::barcode_gtin (const std::string& source) : barcode_numeric(source)
{
}


/** \brief Constructs a \ref barcode_gtin object, initializing the value of
 *  \ref data with the first \p sublen characters of \p source starting at
 *  position \p subpos.
 *
 * \details Constructs a \ref barcode_gtin object, initializing the value of
 *  \ref data with the first \p sublen characters of \p source starting at
 *  position \p subpos.
 *  \p source will be checked, if it only contains integers, as \ref charset
 *  only contains integers.
 *
 *
 * \param source std::string to be copied.
 * \param subpos Position of the first character in \p source that is copied to
 *  \ref barcode::data as a substring.
 * \param sublen Length of the substring to be copied (if \p source is shorter,
 *  as many characters as possible are copied).
 *  A value of string::npos indicates all characters until the end of str.
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
barcode_gtin::barcode_gtin (const std::string& source, size_t subpos, size_t sublen) : barcode_numeric(source, subpos, sublen)
{
}
