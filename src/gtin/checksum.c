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
#include "checksum.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>


/** \brief Calculates the checksum for \p src
 *
 * \details This function calculates the checksum for \p src. The last \p trim
 *  characters will not be evaluated for the checksum.
 *
 *
 * \note This function is not used to be public and will be used internal only.
 *  It assumes, that there was a charset check before and that \p src has a
 *  valid length.
 *
 *
 * \param src Source data
 * \param trim Number of characters for which the checksum should be calculated
 *
 * \return Returns checksum on success. On error, -1 is returned.
 */
int
barcode_gtin_checksum (const char *src, size_t trim)
{
	// Check if argument pointers are NULL. src must not be NULL!
	assert(src);


	// calculate length of src
	size_t l = strlen(src);

	// if length is zero, return an error
	if (l == 0)
		return -1;


	/* calculate checksum: The checksum is calculated from the sum back (without
	 * checksum) to front alternately multiplied by 3 and 1 and at the end
	 * devided by modulo 10.
	 */
	bool multiply = true;
	char checksum = 0;
	for (const char *p = src + l - trim; p >= src; p--) {
		if (multiply) checksum += *p * 3;
		else checksum += *p;

		multiply = !multiply;
	}


	return ((-checksum % 10) % 10);
}
