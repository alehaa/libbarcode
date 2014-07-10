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

#ifndef LIBBARCODE_NUMERIC_H
#define LIBBARCODE_NUMERIC_H

#include <string>
#include <cstddef>

#include <barcode.hpp>


class barcode_numeric : public barcode {
	public:
		barcode_numeric ();
		barcode_numeric (const std::string& source);
		barcode_numeric (const std::string& source, size_t subpos, size_t sublen);

	protected:
		bool check_data (const std::string& source) const;
};

#endif
