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

#include "barcode.hpp"



/** \brief Copies the string referenced by \p source into \ref data.
 *
 *  If \ref charset is not empty, \p source will be checked, if it only contains
 *  characters listed in \ref charset.
 *
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
barcode& barcode::operator= (const std::string& source)
{
	return this->assign_data(source);
}
