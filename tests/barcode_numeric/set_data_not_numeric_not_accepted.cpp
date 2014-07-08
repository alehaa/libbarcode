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

#include <numeric.hpp>



int main ()
{
	barcode_numeric t;

	// use try-catch to catch errors while setting data
	try {
		std::string source = "0123abcdABCD+-*/";

		// try to set data
		size_t num = t.set_data(source);

		// source should not be accepted!
		if (num == source.length()) {
			std::cout << "source was accepted: Test failed!" << std::endl;
			return 1;
		} else {
			std::cout << "source was not accepted: Test passed!" << std::endl;
			return 0;
		}

	} catch (std::invalid_argument &ex) {
		// an error occured in set_data()
		std::cout << "source was not accepted: Test passed!" << std::endl;
		return 0;
	}

	// an error occured
	return 1;
}
