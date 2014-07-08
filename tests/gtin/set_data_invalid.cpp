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

#include <cstddef>
#include <exception>
#include <iostream>
#include <string>
#include <cstdlib>

#include <gtin.hpp>



int main (int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Test confiduartion failed: not enough arguments!" << std::endl;
		return 1;
	}

	// how long should string be?
	size_t num = atoi(argv[1]);

	std::string source;
	for (size_t i = 0; i < num; i++)
		source.push_back('2');

	std::cout << "Testing with string: '" << source << "'" << std::endl;


	barcode_gtin t;
	try {
		if (t.set_data(source) == num) {
			// source was accepted
			std::cerr << "source was accepted. Test failed!" << std::endl;
			return 1;
		} else {
			std::cout << "Error in set_data(): returned length didn't match sublen!" << std::endl;
			return 0;
		}

	} catch (std::exception &ex) {
		// an error occured in set_data()
		std::cout << "exception was thrown: " << ex.what() << std::endl;
		return 0;
	}

	// an error occured
	return 1;
}
