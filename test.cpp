#include "gtin.h"
#include <iostream>

int main () {
	gtin t;

	if (t.set_data("3607345266190", true, "12345")) {
		std::cout << t.get_data() << "\n";
		std::cout << t.get_gtin_gs1_prefix();
		std::cout << t.get_gtin_company_number();
		std::cout << t.get_gtin_item_reference() << "\n";
	}
}
