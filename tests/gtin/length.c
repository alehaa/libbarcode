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
#include <gtin.h>

#include <stdlib.h>


int
main (int argc, char **argv)
{
	// characters to be checked
	const char *str;
	#ifdef LIBBARCODE_GTIN_LENGTH_8
		str = "01234567";
	#elif LIBBARCODE_GTIN_LENGTH_11
		str = "01234567890";
	#elif LIBBARCODE_GTIN_LENGTH_12
		str = "012345678901";
	#elif LIBBARCODE_GTIN_LENGTH_13
		str = "0123456789012";
	#elif LIBBARCODE_GTIN_LENGTH_14
		str = "01234567890123";
	#elif LIBBARCODE_GTIN_LENGTH_15
		str = "012345678901234";
	#elif LIBBARCODE_GTIN_LENGTH_16
		str = "0123456789012345";
	#elif LIBBARCODE_GTIN_LENGTH_18
		str = "012345678901234567";
	#endif


	#if defined(LIBBARCODE_GTIN_LENGTH_8) || defined(LIBBARCODE_GTIN_LENGTH_12) \
		|| defined(LIBBARCODE_GTIN_LENGTH_13) || defined(LIBBARCODE_GTIN_LENGTH_14) \
		|| defined(LIBBARCODE_GTIN_LENGTH_15) || defined(LIBBARCODE_GTIN_LENGTH_18)
		if (barcode_gtin_validate_length(str))
			return EXIT_SUCCESS;
	#else
		if (!barcode_gtin_validate_length(str))
			return EXIT_SUCCESS;
	#endif

	// test was not passed
	return EXIT_FAILURE;
}
