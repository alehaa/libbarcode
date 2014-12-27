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

#include "checksum.h"


/** \brief Checks if \p src only contains valid characters for GTIN barcodes and
 *  if the checksum is valid.
 *
 * \details This function checks, if \p src only contains valid characters for
 *  GTIN barcodes. Only digits (0-9) are valid characters. In addition the
 *  checksum at the end of \p src will be checked.
 *
 *
 * \p src C-string to be checked.
 *
 * \return Returns true on success and false, if \p src contains any invalid
 *  character, or if the checksum is invalid.
 */
bool
barcode_gtin_validate (const char* src)
{
	// Check if argument pointers are NULL. src must not be NULL!
	assert(src);


	// check charset
	if (!barcode_gtin_validate_charset(src))
		return false;

	/* check length.
	 * A normal GTIN is 8, 12, 13 or 14 digits long. GTIN with length 13 may
	 * have an addon-code with length 2 or 5.
	 */
	size_t length = strlen(src);
	if (length != 8 && (length < 12 || length > 15) && length != 18)
		return false;

	// calculate trim for checksum
	size_t trim = 1;
	if (length == 15 || length == 18)
		trim += (length - 13);

	// calculate checksum
	int checksum = barcode_gtin_checksum(src, trim);
	if (checksum < 0)
		return false;

	// validate checksum
	if (src[length - 1] != checksum)
		return false;

	// no error occured
	return true;
}
