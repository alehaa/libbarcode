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
	if (this->verbose) this->log_message("cleaning up internal memory ...");

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

	this->gtin_buff_gs1_prefix = 0;
	this->gtin_buff_section_articlenumber = 0;
	this->gtin_buff_section_amount = 0;
}


/* enable_addon_code ();
 * Addon-Codes will be handled and saved.
 */
void gtin::enable_addon_code () {
	this->handle_addon_code = true;

	if (this->verbose) this->log_message("handling addon-codes enabled");
}


/* disable_addon_code ();
 * Addon-Codes will NOT be handled. Addon-Codes may be part of codes
 * in set_data but they will not be saved.
 */
void gtin::disable_addon_code () {
	this->handle_addon_code = false;

	if (this->verbose) this->log_message("handling addon-codes disabled");
}
