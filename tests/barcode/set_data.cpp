#include <barcode.hpp>

int main ()
{
	barcode t;

	if (t.set_data("0123456") < 0) return 1;
	else return 0;
}
