/* include header files */
#include "gtin.h"

#include <cstring>


/* set_data();
 * Diese Funktion setzt die Daten des Codes. Dabei werden zunaechst alle
 * Zeichen geprueft, ob sie auch Ziffern sind. Anschliessend wird die
 * Laenge ueberprueft und (falls mit uebergeben laut 2. Parameter) die
 * Pruefsumme auf Richtigkeit geprueft. Sollte ein Addon-Code mit ueber-
 * geben worden sein und wurde dieser nicht deaktiviert, wird dieser
 * genau so wie der eigentliche GTIN in "richtige" Ziffern umgewandelt
 * und im internen Speicher gespeichert.
 */
bool gtin::set_data (const char* p_data, bool p_contains_checksum) {
	/* wenn noch intern Daten gespeichert sind, so lasse keine neue Speicherung zu.
	 * Es muss dann erst this->reset(); ausgefuehrt werden. */
	if (this->data_gtin == nullptr) {
		/* schaue wie lang p_data ist. */
		unsigned int p_data_length = strlen(p_data);

		/* ueberpruefe die Laenge von p_data. Gueltige Laengen sind 8, 12, 13 und 14.
		 * Bei 13 kann evtl. noch ein Addon-Code kommen, also auch 15 und 18. Wurde
		 * keine Pruefziffer mitgegeben, muss diese Stelle noch abgezogen werden.
		 * Erlaubt sind dann 7, 11, 12 und 13. */
		if ((p_contains_checksum && (p_data_length == 8 || (p_data_length >= 12 && p_data_length <= 15) || p_data_length == 18)) || (!p_contains_checksum && (p_data_length == 7 || (p_data_length >= 11 && p_data_length <= 13)))) {
			/* wie lang ist der GTIN? Ist ein Addon-Code vorhanden und wie lang ist dieser?
			 * Wir wissen schon, dass es sich um eine gueltige Laenge handelt, somit muss
			 * diese also nur noch den einzelnen Codes zugeordnet werden. Ein Addon-Code
			 * gibt es nur bei 15 oder 18 stellen, da dieser nur uebergeben wird, wenn auch
			 * eine Pruefziffer uebergeben wird. Zudem gibt es diesen nur bei GTIN-13 Codes.
			 *  Bei allen anderen laengen ist kein Addon-Code vorhanden und die Laenge des
			 * GTIN entspricht p_data_length. Wurde keine Pruefziffer uebergeben, so muss
			 * noch 1 addiert werden. */
			this->data_addon_code_length = 0;
			if (p_data_length == 15 || p_data_length == 18) {
				this->data_addon_code_length = p_data_length - 13;
				this->data_gtin_length = 13;
			} else {
				this->data_gtin_length = p_data_length;
				if (!p_contains_checksum) this->data_gtin_length++;
			}

			/* Wandle den GTIN- Datenbereich aus p_data in Zahlen um. Pruefe dabei auch,
			 * dass es sich wirklich um Zahlen handelt. */
			if ((this->data_gtin = this->cstr_to_chararray(p_data, this->data_gtin_length))) {
				/* wenn eine checksumme mit uebergeben wurde, dann ueberpruefe diese und kopiere
				 * danach evtl. auch einen Addon-Code. Wurde keine uebergeben, so ueberspringe
				 * diesen Schritt. Ein Addon-Code kann dann ebenfalls nicht uebergeben worden
				 * sein, weshalb diese Funktion dann erfolgreich beendet ist. */
				if (p_contains_checksum) {
					if (this->checksum()) {
						if (this->data_addon_code_length > 0) {
							if (this->handle_addon_code) {
								if (this->set_addon_code(&p_data[this->data_gtin_length])) return true;
							} else {
								return true;
							}
						}
					}
				} else {
					return true;
				}
			}
		}
	}

	return false;
}


/* get_data();
 * gibt die Daten aus this->data_gtin als cstring zurueck.
 * Die Endwanwendung muss dabei beachten, dass nur ein Pointer zurueckgegeben
 * wird, welcher nach erfolgreicher Verwendung mit delete[] geloescht werden
 * muss.
 */
const char * gtin::get_data () {
	return this->chararray_to_cstr(this->data_gtin, this->data_gtin_length);
}


/* set_addon();
 * Waerend Anwendungen wie Kassensysteme den Addon-Code in einem mit dem GTIN
 * aufnehmen, wird dieser in Anwendungen, die nur zum generieren von GTIN-Codes
 * gedacht sind, seperat uebergeben. Fuer diese Programme dient diese Funktion
 * als schnittstelle. */
bool gtin::set_addon_code (const char *p_data) {
	/* wenn noch intern Daten gespeichert sind, so lasse keine neue Speicherung zu.
	 * Es muss dann erst this->reset(); ausgefuehrt werden. */
	if (this->data_addon_code == nullptr) {
		/* schaue wie lang p_data ist. */
		unsigned int p_data_length = strlen(p_data);
		if (p_data_length == 2 || p_data_length == 5) {
			if ((this->data_addon_code = this->cstr_to_chararray(p_data, p_data_length))) {
				this->data_addon_code_length = p_data_length;
				return true;
			}
		}
	}

	return false;
}


/* get_addon_code();
 * gibt die Daten aus this->data_addon_code als cstring zurueck.
 * Die Endwanwendung muss dabei beachten, dass nur ein Pointer zurueckgegeben
 * wird, welcher nach erfolgreicher Verwendung mit delete[] geloescht werden
 * muss.
 */
const char * gtin::get_addon_code () {
	return this->chararray_to_cstr(this->data_addon_code, this->data_addon_code_length);
}


/* get_gtin_gs1_prefix ();
 * gibt die ersten 3 Stellen von this->data_gtin als short zurueck.
 */
const short gtin::get_gtin_gs1_prefix () {
	if (this->data_gtin != nullptr) {
		if (this->data_gtin_length == 13) {
			if (this->gtin_buff_gs1_prefix == 0) {
				this->gtin_buff_gs1_prefix = (short)this->chararray_to_int(this->data_gtin, 3);
			}

			return this->gtin_buff_gs1_prefix;
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

	return gtin::gtin_type::ERR;
}


/* get_gtin_section_articlenumber ();
 * gibt die Stellen 4-8 als int zurueck.
 */
const int gtin::get_gtin_section_articlenumber () {
	if (this->data_gtin != nullptr) {
		if (this->data_gtin_length == 13) {
			if (this->gtin_buff_section_articlenumber == 0) {
				this->gtin_buff_section_articlenumber = this->chararray_to_int(&this->data_gtin[3], 5);
			}

			return this->gtin_buff_section_articlenumber;
		}
	}

	/* Es konnte keine section article number ermittelt werden, also gebe -1 zurueck. */
	return -1;
}


/* get_gtin_section_amount ();
 * gibt die Stellen 9-12 als short zurueck.
 */
const short gtin::get_gtin_section_amount () {
	if (this->data_gtin != nullptr) {
		if (this->data_gtin_length == 13) {
			if (this->gtin_buff_section_amount == 0) {
				this->gtin_buff_section_amount = (short)this->chararray_to_int(&this->data_gtin[8], 4);
			}

			return this->gtin_buff_section_amount;
		}
	}

	/* Es konnte keine section article number ermittelt werden, also gebe -1 zurueck. */
	return -1;
}
