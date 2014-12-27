/* This file is part of libbarcode.
 *
 * libbarcode is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License and GNU
 *  Lesser General Public License along with this program. If not, see
 *
 * http://www.gnu.org/licenses/
 *
 *
 * Copyright (C)
 *  2013-2014 Alexander Haase <alexander.haase@rwth-aachen.de>
 */


/* include headers
 */
#include "gtin.h"

#include <assert.h>
#include <string.h>


/** \brief Checks if \p src has a valid length for GTIN barcodes.
 *
 * \details This function checks, if \p src has a valid length for GTIN
 *  barcodes. A valid GTIN is 8, 12, 13 or 14 digits long. GTIN with length 13
 *  may have an addon-code with length 2 or 5.
 *
 *
 * \p src C-string to be checked.
 *
 * \return Returns true on success and false, if \p src contains any invalid
 *  character.
 */
bool
barcode_gtin_validate_length (const char* src)
{
	// Check if argument pointers are NULL. src must not be NULL!
	assert(src);


	// check length
	size_t length = strlen(src);
	if (length == 8 || (length >= 12 && length <= 15) || length == 18)
		return true;

	// no valid length
	return false;
}
