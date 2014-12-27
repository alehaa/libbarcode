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
#include <ctype.h>


/** \brief Checks if \p src only contains valid characters for GTIN barcodes.
 *
 * \details This function checks, if \p src only contains valid characters for
 *  GTIN barcodes. Only digits (0-9) are valid characters.
 *
 *
 * \p src C-string to be checked.
 *
 * \return Returns true on success and false, if \p src contains any invalid
 *  character.
 */
bool
barcode_gtin_validate_charset (const char* src)
{
	// Check if argument pointers are NULL. src must not be NULL!
	assert(src);


	// check any character in src
	for (const char *p = src; *p; p++) {
		// if *p is not a digit, return false
		if (!isdigit(*p))
			return false;
	}

	// no invalid character found
	return true;
}
