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
	const char *str = "0123456789";
	#ifdef LIBBARCODE_GTIN_CHARSET_1
		str = "01234a56789";
	#elif LIBBARCODE_GTIN_CHARSET_2
		str = "01234-56789";
	#endif


	#if defined(LIBBARCODE_GTIN_CHARSET_1) || defined(LIBBARCODE_GTIN_CHARSET_2)
		if (!barcode_gtin_validate_charset(str))
			return EXIT_SUCCESS;
	#else
		if (barcode_gtin_validate_charset(str))
			return EXIT_SUCCESS;
	#endif

	// test was not passed
	return EXIT_FAILURE;
}
