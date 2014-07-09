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

#include <string>
#include <exception>
#include <iostream>

#include <barcode.hpp>



int main ()
{
	try {
		// string to test assign
		std::string source = "0123abcdABCD+-*/";

		// try to construct empty object
		barcode t(source, 5, 4);

		std::cout << "success: barcode object could be constructed with substring assignment." << std::endl;
		return 0;
	} catch (std::exception &ex) {
		// an error occured in set_data()
		std::cerr << "failure: exception: " << ex.what() << std::endl;
	}

	// an error occured
	return 1;
}
