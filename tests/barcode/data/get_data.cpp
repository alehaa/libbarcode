/** This \file is part of libbarcode.
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

#include <exception>
#include <iostream>
#include <string>

#include <barcode.hpp>


int main ()
{
	barcode t;

	try {
		std::string source = "0123abcdABCD+-*/";

		if (t.set_data(source) == source.length()) {
			if (t.get_data() == source) return 0;
		}

	} catch (std::invalid_argument &ex) {
		std::cerr << "Invalid argument: " << ex.what() << std::endl;
	}

	// an error occured
	return 1;
}
