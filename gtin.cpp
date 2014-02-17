/* This file is part of libgtin.
 *
 * libgtin is free software: you can redistribute it and/or modify it under the
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

/* include header file */
#include "gtin.h"


/* destructor
 * clean up all internal memory
 */
gtin::~gtin () {
	this->reset();
}


/* reset ();
 * clean up all data in internal memory.
 */
void gtin::reset () {
	if (this->data_gtin != nullptr) {
		delete[] this->data_gtin;
		this->data_gtin = nullptr;
		this->data_gtin_length = 0;
	}

	if (this->data_addon_code != nullptr) {
		delete[] this->data_addon_code;
		this->data_addon_code = nullptr;
		this->data_addon_code_length = 0;
	}
}



/* set_handle_addon_codes (bool p_handle)
 * Schaltet die Verarbeitung von Addon-Codes ein oder aus
 */
void gtin::set_handle_addon_codes (bool p_handle) {
	this->handle_addon_code = p_handle;
}
