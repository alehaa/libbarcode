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
	// GTIN8 to be checked
	const char *str = "65833254";
	#ifdef LIBBARCODE_GTIN_CHECKSUM_8_ERR
		str = "65833255";
	#elif LIBBARCODE_GTIN_CHECKSUM_8_SWAP
		str = "65833524";

	#elif LIBBARCODE_GTIN_CHECKSUM_13
		str = "5901234123457";
	#elif LIBBARCODE_GTIN_CHECKSUM_13_ERR
		str = "5901234123456";
	#elif LIBBARCODE_GTIN_CHECKSUM_13_SWAP
		str = "5901234124357";
	#endif


	#if defined(LIBBARCODE_GTIN_CHECKSUM_8_ERR) \
		|| defined(LIBBARCODE_GTIN_CHECKSUM_8_SWAP) \
		|| defined(LIBBARCODE_GTIN_CHECKSUM_13_ERR) \
		|| defined(LIBBARCODE_GTIN_CHECKSUM_13_SWAP)
		if (!barcode_gtin_validate(str))
			return EXIT_SUCCESS;
	#else
		if (barcode_gtin_validate(str))
			return EXIT_SUCCESS;
	#endif

	// test was not passed
	return EXIT_FAILURE;
}
