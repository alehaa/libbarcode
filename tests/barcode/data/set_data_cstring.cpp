#include <exception>
#include <iostream>
#include <cstring>

#include <barcode.hpp>


int main ()
{
	barcode t;

	try {
		const char data[] = "0123abcdABCD+-*/";

		if (t.set_data(&data[0]) == strlen(data)) return 0;

	} catch (std::invalid_argument &ex) {
		std::cerr << "Invalid argument: " << ex.what() << std::endl;
	}

	// an error occured
	return 1;
}
