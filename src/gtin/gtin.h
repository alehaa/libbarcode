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

#ifndef LIBBARCODE_GTIN_H
#define LIBBARCODE_GTIN_H


/* include headers
 */
#include <stdbool.h>


/* function declarations
 */
bool barcode_gtin_validate_charset (const char* src);
bool barcode_gtin_validate (const char* src);

int barcode_gtin_encode (const char* src, const char* dest);
int barcode_gtin_decode (const char* src, const char* dest);


#endif // LIBBARCODE_GTIN_H
