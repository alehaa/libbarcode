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

/*
 * include header files
 */
#include "gtin.h"


/**
 * \brief Constructs an \ref barcode_gtin object.
 */
barcode_gtin::barcode_gtin ()
{
}


/**
 * \brief Destructs the \ref barcode_gtin object.
 */
barcode_gtin::~barcode_gtin ()
{
}


/**
 * \brief Erases the contents of the \ref barcode_gtin object.
 */
void barcode_gtin::clear ()
{
	this->data.clear();
	this->addon_code.clear();
}
