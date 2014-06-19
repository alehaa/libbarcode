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

#include "barcode.h"


/**
 * \brief Convert C String to array of char (integer).
 *
 * \details Converts the first \p num characters of \p source and stores them
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
 * \param destination Pointer to the destination array where the converted
 *  content is to be stored.
 * \param source C string to be converted.
 * \param num Maximum number of characters to be converted from source.
 *
 * \return If \p source is successfully converted, the number of converted
 *  characters is returned. Otherwise -1 is returned.
 *
 *
 * \b Example:
 * \code
 * #include <iostream>
 *
 * void barcode::test ()
 * {
 *   const char source[11] = "1234567890";
 *   char destination[10];
 *
 *   if (this->atoia(&destination[0], &source[0], 10) < 0)
 *     std::cerr << "Error while converting source" << std::endl;
 *
 *   std::cout << "Converted: ";
 *
 *   for (int i = 0; i < 10; i++)
 *     std::cout << (int) destination[i];
 *
 *   std::cout << std::endl;
 * }
 * \endcode
 */
int barcode::atoia (char *destination, const char *source, size_t num)
{
	// if source or destination is NULL, we can't convert / copy into it
	if (source == NULL || destination == NULL) return -1;

	int c = 0;
	for (int i = 0; i < (int) num; i++, destination++) {
		// if we are at the end of source, pad destination with zeros
		if (*source == '\0') {
			*destination = 0;
			continue;
		}

		// return error, if char in source is no integer
		if ((*source < 48) || (*source > 57)) return -1;

		// copy and convert content
		*destination = *source - 48;
		source++;
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
 * @note Beware that size of \p destination has to be the size of \p source +
 *  1, because of the terminating null-character that is added at the end of
 *  \p destination.
 *
 *
 * @param destination Pointer to the destination array where the converted
 *  content is to be stored.
 * @param source array of cahr to be converted.
 * @param num Maximum number of chars to be converted from source.
 *
 * @return If \p source is successfully converted, the number of converted
 *  chars is returned. Otherwise -1 is returned.
 *
 *
 * \b Example:
 * \code
 * #include <iostream>
 *
 * void barcode::test ()
 * {
 *   const char source[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
 *   char destination[11];
 *
 *   if (this->iatoa(&destination[0], &source[0], 10) < 0)
 *     std::cerr << "Error while converting source" << std::endl;
 *
 *   std::cout << "Converted: " << destination << std::endl;
 * }
 * \endcode
 */
int barcode::iatoa (char *destination, const char *source, size_t num)
{
	// if source or destination is NULL, we can't convert / copy into it
	if (source == NULL || destination == NULL) return -1;

	// copy and convert content
	for (int i = 0; i < (int) num; i++, source++, destination++)
		*destination = *source + 48;

	// add terminating null-character
	*destination = '\0';

	// return number of converted chars
	return (int) num; 
}


/**
 * @brief Convert array of char (integer) to integer.
 *
 * @details Converts the first \p num chars (integers) of \p source and stores
 *  them in \p destination.
 *
 *  \p destination and \p source shall not overlap.
 *
 *
 * @param destination Pointer to the destination integer where the converted
 *  content is to be stored.
 * @param source array of cahr to be converted.
 * @param num Maximum number of chars to be converted from source.
 *
 * @return If \p source is successfully converted, the number of converted
 *  chars is returned. Otherwise -1 is returned.
 *
 *
 * \b Example:
 * \code
 * #include <iostream>
 *
 * void barcode::test ()
 * {
 *   const char source[4] = {1, 2, 3, 4};
 *   int destination;
 *
 *   if (this->iatoi(&destination, &source[0], 4) < 0)
 *     std::cerr << "Error while converting source" << std::endl;
 *
 *   std::cout << "Converted: " << destination << std::endl;
 * }
 * \endcode
 */
#include <iostream>
int barcode::iatoi (int *destination, const char *source, size_t num)
{
	// if source or destination is NULL, we can't convert / copy into it
	if (source == NULL || destination == NULL) return -1;

	// jump to last char that should be converted
	source += num - 1;

	// clean up destination
	*destination = 0;

	// copy and convert content
	int p = 1;
	for (int i = 0; i < (int) num; i++, source--, p *= 10)
		*destination += *source * p;

	// return number of converted chars
	return (int) num;
}
