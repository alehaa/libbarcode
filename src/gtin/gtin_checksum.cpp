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



/* checksum
 * @return:
 *	returns true if checksum could be calculated (and validated if was set) or
 *	false on errors
 *
 * Checksum calculates the checksum for this->gtin. If checksum was not already
 * set, it will be appended as last digit in GTIN. Otherwise the last digit will
 * be checked against calculated checksum and result will be returned.
 */
bool gtin::checksum () {
	// is data in this->data_gtin?
	if (!this->data_gtin) return false;

	// go from right to left through the array and multiply alternately with 3 and 1
	bool multiply = true;
	char c = 0;
	for (unsigned char *p = this->data_gtin + this->data_gtin_length - 2, *p_end = this->data_gtin; p >= p_end; p--) {
		if (multiply) c += *p * 3;
		else c += *p;

		multiply = !multiply;
	}

	// calc checksum
	c = (-c) % 10;
	if (c < 0) c += 10;

	// validate checksum, if is part of this->data_gtin. Otherwise append checksum
	if (this->data_gtin[this->data_gtin_length - 1] == 255) {
		this->data_gtin[this->data_gtin_length - 1] = c;
		return true;
	}else return (this->data_gtin[this->data_gtin_length - 1] == c);
}
