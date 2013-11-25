/* include header files */
#include "gtin.h"


/* get_gtin_gs1_prefix ();
 * gibt die ersten 3 Stellen von this->data_gtin als short zurueck.
 */
const short gtin::get_gtin_gs1_prefix () {
	/* sind auch Daten in this->data_gtin gespeichert? */
	if (this->data_gtin != nullptr) {
		/* Nur GTIN8 und GTIN13 haben einen Laenderprefix. Dabei ist dieser nur beim
		 * GTIN13 exakt definiert und wird auch nur in diesem ausgewertet. */
		if (this->data_gtin_length == 13) {
			/* wandle die ersten 3 Ziffern aus this->data_gtin in einen short um und gebe
			 * diesen zurueck. */
			return (short)this->chararray_to_int(this->data_gtin, 3);
		}
	}

	/* Es konnte kein GS1-Praefix ermittelt werden, also gebe -1 zurueck. */
	return -1;
}


/* get_gtin_type();
 * wertet den GS1-Prefix aus und gibt fuer die Sonderpraefixe den entsprechenden
 * Typ zurueck.
 */
const gtin::gtin_type gtin::get_gtin_type () {
	/* ermittle den GS1-Prefix. Eine Ueberpruefung, ob auch tatsaechlich Daten in
	 * this->data_gtin existieren, muss nicht erfolgen, da dies schon durch die
	 * ermittlung des GS1-Prefix automatisch geschieht. */
	short gs1_prefix = this->get_gtin_gs1_prefix();
	if (gs1_prefix != -1) {
		/* Storeinternal-Codes 200-299 */
		if (gs1_prefix >= 200 && gs1_prefix <= 299) return gtin::gtin_type::STOREINTERNAL;

		/* other, special codes */
		switch (gs1_prefix) {
			case 414: case 419: case 434: case 439:
				return gtin::gtin_type::PRESSCODE_GERMANY;

			case 977:
				return gtin::gtin_type::ISSN;

			case 978:
				return gtin::gtin_type::ISBN;

			case 979:
				if (this->data_gtin[3] == 0) return gtin::gtin_type::ISMN;
				return gtin::gtin_type::ISBN;

			case 980:
				return gtin::gtin_type::REFUND_RECEIPT;

			case 981: case 982: case 983:
				return gtin::gtin_type::COMMON_CURRENCY_COUPON;

			case 990: case 991: case 992: case 993: case 994:
			case 995: case 996: case 997: case 998: case 999:
				return gtin::gtin_type::COUPON;

			default:
				return gtin::gtin_type::NONE;
		}
	}

	/* Es ist ein Fehler aufgetreten */
	return gtin::gtin_type::ERR;
}


/* get_gtin_section_articlenumber ();
 * gibt die Stellen 4-8 als int zurueck.
 */
const int gtin::get_gtin_section_articlenumber () {
	/* sind auch Daten in this->data_gtin gespeichert? */
	if (this->data_gtin != nullptr) {
		/* Nur GTIN8 und GTIN13 haben einen Laenderprefix. Dabei ist dieser nur beim
		 * GTIN13 exakt definiert und wird auch nur in diesem ausgewertet. */
		if (this->data_gtin_length == 13) {
			/* wandle die ersten 3 Ziffern aus this->data_gtin in einen short um und gebe
			 * diesen zurueck. */
			return (short)this->chararray_to_int(&this->data_gtin[3], 5);
		}
	}

	/* Es konnten keine Daten aus dieser Section ermittelt werden, also gebe -1 zurueck. */
	return -1;
}


/* get_gtin_section_amount ();
 * gibt die Stellen 9-12 als short zurueck.
 */
const short gtin::get_gtin_section_amount () {
	/* sind auch Daten in this->data_gtin gespeichert? */
	if (this->data_gtin != nullptr) {
		/* Nur GTIN8 und GTIN13 haben einen Laenderprefix. Dabei ist dieser nur beim
		 * GTIN13 exakt definiert und wird auch nur in diesem ausgewertet. */
		if (this->data_gtin_length == 13) {
			/* wandle die ersten 3 Ziffern aus this->data_gtin in einen short um und gebe
			 * diesen zurueck. */
			return (short)this->chararray_to_int(&this->data_gtin[8], 4);
		}
	}

	/* Es konnten keine Daten aus dieser Section ermittelt werden, also gebe -1 zurueck. */
	return -1;
}
