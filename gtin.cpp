/* include header file */
#include "gtin.h"


/* destructor
 * clean up all internal memory
 */
gtin::~gtin () {
	this->reset();
}


/* reset ();
 * clean up all data in internal memory.
 */
void gtin::reset () {
	if (this->data_gtin != nullptr) {
		delete[] this->data_gtin;
		this->data_gtin = nullptr;
		this->data_gtin_length = 0;
	}

	if (this->data_addon_code != nullptr) {
		delete[] this->data_addon_code;
		this->data_addon_code = nullptr;
		this->data_addon_code_length = 0;
	}
}



/* set_handle_addon_codes (bool p_handle)
 * Schaltet die Verarbeitung von Addon-Codes ein oder aus
 */
void gtin::set_handle_addon_codes (bool p_handle) {
	this->handle_addon_code = p_handle;
}
