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

#include <barcode.hpp>



int main ()
{
	barcode t;

	// use try-catch to catch errors while setting data
	try {
		std::string source = "0123abcdABCD+-*/";

		// try to set data
		size_t num = t.set_data(source);

		// did everything worked fine?
		if (num == source.length()) return 0;
		else std::cerr << "Error in set_data(): returned length didn't match length of source!" << std::endl;

	} catch (std::invalid_argument &ex) {
		// an error occured in set_data()
		std::cerr << "Invalid argument: " << ex.what() << std::endl;
	}

	// an error occured
	return 1;
}
