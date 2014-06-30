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
#include <stdexcept>

#include "gtin.h"


/**
 * \brief Copies \p source to \ref barcode_gtin::data.
 *
 * \p source will be checked for length and only containing integers. If every
 *  check passed, \p source will be copied to \ref barcode_gtin::data.
 *
 *
 * \param source C string to be copied.
 *
 * \return Returns the number of identified characters.
 *
 * \throw std::invalid_argument Will be thrown, if \p source contains any
 *  other char then integers
 */
int barcode_gtin::set_data (const char *source) throw (std::invalid_argument)
{
	// throw exception, if source is nullptr
	if (source == nullptr) throw std::invalid_argument("source is NULL");

	// return failure
	return -1;
}


/*
 * \brief Copies the first \p num characters of \p source to \ref
 *  barcode_gtin::data.
 *
 * \p source will be checked for length and only containing integers. If every
 *  check passed, the first \p num characters of \p source will be copied to
 *  \ref barcode_gtin::data.
 *
 *
 * \param source C string to be copied.
 * \param num Number of characters to be copied.
 *
 * \return Returns the number of identified characters.
 *
 * \throw std::invalid_argument Will be thrown, if \p source contains any
 *  other char then integers
 *
 * int barcode_gtin::set_data (const char *source, size_t num) throw(std::invalid_argument)
 * {
 * }
 */
