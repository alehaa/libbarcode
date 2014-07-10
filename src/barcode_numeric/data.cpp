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

#include "numeric.hpp"


/** \brief Checks, if data copied to \ref data is valid.
 *
 * \details This function checks, if \p source only contains digits.
 *
 *
 * \param source std::string thaat should be checked.
 *
 * \return Returns true, if \p source only contains digits.
 */
#include <iostream>
bool barcode_numeric::check_data (const std::string &source) const
{
	std::cout << "numeric: " << source << std::endl;

	return false;
}
