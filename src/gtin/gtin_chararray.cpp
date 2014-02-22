/* This file is part of libbarcode.
 *
 * libbarcode is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Copyright 2013-2014 Alexander Haase <alexander.haase@rwth-aachen.de>
 */

/* include header files */
#include "gtin.h"

#include <cmath>
#include <iostream>



/* cstr2carray
 * @param:
 *	const char *p_data: array of char, containing a cstring with digits
 *	unsigned char p_data_length: number of chars that should be converted. If
 *		set to 0, all chars up to the end of cstring will be converted.
 *
 * @return:
 *	returns a pointer to an array of unsigned char, or the nullptr, if an
 *	error occured.
 *
 *
 * This function trys to convert a cstring to an array of unsigned chars. If
 * p_data_length is set to 0, all chars in p_data will be converted. If
 * p_data_length is greater than number of chars in p_data, all other elements
 * of array will be filles with '255'.
 */
unsigned char * gtin::cstr2carray (const char *p_data, unsigned char p_data_length) {
	// test, if p_data is not the nullptr and p_data_length > 0
	if (!p_data || p_data_length == 0) return NULL;

	// create new buffer
	unsigned char *buffer = new unsigned char[p_data_length];

	// go through cstring
	unsigned char *b = buffer, *b_end = buffer + p_data_length;
	for (const char *p = p_data; *p && (b < b_end); p++ && b++) {
		// check, if *p is a number
		if ((*p < 48) || (*p > 57)) {
			// *p is no number. Delete buffer and return nullptr.
			delete[] buffer;
			return NULL;
		}

		*b = *p - 48;
	}

	// fill free elements at end of array with '255'
	for (; b < b_end; b++)
		*b = 255;

	return buffer;
}


/* carray2cstr
 * @param:
 *	unsigned char *p_data: array of unsigned char
 *	unsigned char p_data_length: number of digits that should be converted. If
 *		set to 0, all digits up to the end of array will be converted.
 *
 * @return:
 *	returns a pointer to an array of char, or the nullptr, if an
 *	error occured.
 *
 *
 * This function trys to convert an array of unsigned chars to a cstring.
 */
const char * gtin::carray2cstr (unsigned char *p_data, unsigned char p_data_length) {
	// test, if p_data is not the nullptr and p_data_length > 0
	if (!p_data || p_data_length == 0) return NULL;

	// create new buffer
	char *buffer = new char[p_data_length + 1];

	// go through carray
	char *b = buffer, *b_end = buffer + p_data_length;
	for (unsigned char *p = p_data, *p_end = p_data + p_data_length; (p < p_end) && (b < b_end); p++ && b++) {
		if (*p == 255) {
			delete[] buffer;
			return NULL;
		}

		*b = *p + 48;
	}

	// fill free elements at end of array with '\0'
	for (; b <= b_end; b++)
		*b = '\0';

	return buffer;
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
unsigned int gtin::carray2int (unsigned char *p_data, unsigned char p_data_length) {
	// test, if p_data is not the nullptr and p_data_length > 0
	if (!p_data || p_data_length == 0) return -1;

	// go through carray
	int c = 0;
	char e = 0;
	for (unsigned char *p = p_data + p_data_length - 1, *p_end = p_data; p >= p_end; p--, e++)
		c += (int) (*p * pow(10, e));

	return c;
}
