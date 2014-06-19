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
#include "barcode.h"

#include <cstddef>
//#include <cmath>
//#include <iostream>


/**
 * @brief Convert C String to array of char (integer).
 *
 * @details Converts the first \p num characters of \p source and stores them
 *  in \p destination.
 *
 *  If the end of the source C string (which is signaled by a
 *  null-character) is found before \p num characters have been copied,
 *  \p destination is padded with zeros until a total of \p num characters
 *  have been written to it, but only the number of converted characters will
 *  be returned.
 *
 *  \p destination and \p source shall not overlap.
 *
 *
 * @param destination Pointer to the destination array where the converted
 *  content is to be stored.
 * @param source C string to be converted.
 * @param num Maximum number of characters to be converted from source.
 *
 * @return If \p source is successfully converted, the number of converted
 *  characters is returned. Otherwise -1 is returned.
 */
int barcode::atoia (char *destination, const char *source, size_t num)
{
	// if destination is NULL, we can't copy to it
	if (destination == NULL) return -1;

	const char *s = source;
	char *d = destination;
	int c = 0;

	for (int i = 0; i < (int) num; i++, d++) {
		// if we are at the end of source, pad destination with zeros
		if (*s == '\0') {
			*d = 0;
			continue;
		}

		// return error, if char in source is no integer
		if ((*s < 48) || (*s > 57)) return -1;

		// copy and convert content
		*d = *s - 48;
		s++;
		c++;
	}

	// return number of converted chars
	return c; 
}


/**
 * @brief Convert array of char (integer) to C String.
 *
 * @details Converts the first \p num chars (integers) of \p source and stores
 *  them in \p destination.
 *
 *  \p destination and \p source shall not overlap.
 *
 * @note Beware that size of \p destination has to be \p + 1, because of the
 *  terminating null-character that is added at the end of \p destination.
 *
 *
 * @param destination Pointer to the destination array where the converted
 *  content is to be stored.
 * @param source array of cahr to be converted.
 * @param num Maximum number of characters to be converted from source.
 *
 * @return If \p source is successfully converted, the number of converted
 *  characters is returned. Otherwise -1 is returned.
 */
int barcode::iatoa (char *destination, const char *source, size_t num)
{
	// if destination is NULL, we can't copy to it
	if (destination == NULL) return -1;

	const char *s = source;
	char *d = destination;

	// copy and convert content
	for (int i = 0; i < (int) num; i++, s++, d++)
		*d = *s + 48;

	// return number of converted chars
	return (int) num; 
}







/* carray2int
 * @param:
 *	unsigned char *p_data: array of unsigned char
 *	unsigned char p_data_length: number of digits that should be converted. If
 *		set to 0, all digits up to the end of array will be converted.
 *
 * @return:
 *	returns an integer of converted digits or -1 if an error occured
 *
 *
 * This function trys to convert an array of unsigned chars to an integer.
 */
/*unsigned int barcode_gtin::carray2int (unsigned char *p_data, unsigned char p_data_length) {
	// test, if p_data is not the nullptr and p_data_length > 0
	if (!p_data || p_data_length == 0) return -1;

	// go through carray
	int c = 0;
	char e = 0;
	for (unsigned char *p = p_data + p_data_length - 1, *p_end = p_data; p >= p_end; p--, e++)
		c += (int) (*p * pow(10, e));

	return c;
}*/
