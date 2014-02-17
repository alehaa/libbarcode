/* This file is part of libgtin.
 *
 * libgtin is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Copyright 2013-2014 Alexander Haase <alexander.haase@rwth-aachen.de>
 */

/* include header files */
#include <cstring>
#include "gtin.h"


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
			/* Pruefe mit Hilfe von p_data_length, ob ein Addon-Code mit uebergeben wurde
			 * und wie lang dieser und der Datenbereich sind. */
			this->data_addon_code_length = 0;
			if (p_data_length == 15 || p_data_length == 18) {
				/* Addon-Codes existieren nur bei GTIN-13-Codes. Die Laenge des Addon-Codes ist
				 * somit ist die Laenge des Addon-Codes p_data_length - 13 und die Laenge des
				 * GTIN fixiert auf 13. */
				this->data_addon_code_length = p_data_length - 13;
				this->data_gtin_length = 13;
			} else {
				/* Es ist kein Addon-Code vorhanden. Daher ist dessen Laenge 0 und die des GTIN
				 * ist gleich p_data_length. */
				this->data_gtin_length = p_data_length;

				/* wenn keine Checksumme mit uebertragen wurde, dann erhoehe die Laenge des GTIN
				 * um eins, da diese spaeter auch einen Speicherplatz benoetigt. */
				if (!p_contains_checksum) this->data_gtin_length++;
			}

			/* Wandle den GTIN-Datenbereich aus p_data in Zahlen um. Pruefe dabei auch,
			 * dass es sich wirklich um Zahlen handelt. */
			if ((this->data_gtin = this->cstr_to_chararray(p_data, this->data_gtin_length))) {
				if (!p_contains_checksum) {
					/* wenn keine checksumme uebergeben wurde, ist die Ueberpruefung der Eingabe
					 * hiermit beendet und es kann ein return true erfolgen. */
					return true;
				} else {
					/* Es wurde eine Checksumme mit uebertragen. Ueberpruefe diese auf ihre Richtig-
					 * keit. */
					if (this->checksum()) {
						if (this->data_addon_code_length <= 0) {
							/* Es wurde kein Addon-Code mit uebergeben. Daher ist kein weiterer Check noetig
							 * und die Funktion kann erfolgreich verlassen werden. */
							return true;
						} else {
							if (!this->handle_addon_code) {
								/* Addon-Codes sollen nicht verarbeitet werden. Ignoriere diesen daher und
								 * verlasse die Funktion erfolgreich. */
								return true;
							} else {
								/* verarbeite den Addon-Code */
								if (this->set_addon_code(&p_data[this->data_gtin_length])) return true;
							}
						}
					}
				}
			}
		}
	}

	/* An einer Stelle ist ein Fehler aufgetreten. */
	return false;
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

		/* es gibt nur Addon-Codes mit der Laenge 2 oder 5. Entspricht die Laenge nicht
		 * diesen Werten, so ist ein fortfuehren der Funktion nicht moeglich. */
		if (p_data_length == 2 || p_data_length == 5) {
			/* Wandle p_data in Zahlen um. Pruefe dabei auch, ob es sich wirklich um Zahlen
			 * handelt. */
			if ((this->data_addon_code = this->cstr_to_chararray(p_data, p_data_length))) {
				/* Die Daten wurden erfolgreich umgewandelt und gespeichert. Verlasse die
				 * Funktion erfolgreich. */
				this->data_addon_code_length = p_data_length;
				return true;
			}
		}
	}

	/* An einer Stelle ist ein Fehler aufgetreten. */
	return false;
}


/* get_data();
 * gibt die Daten aus this->data_gtin als cstring zurueck.
 * Die Endwanwendung muss dabei beachten, dass nur ein Pointer zurueckgegeben
 * wird, welcher nach erfolgreicher Verwendung mit delete[] geloescht werden
 * muss.
 */
const char * gtin::get_data () {
	/* Eine Ueberpruefung, ob auch wirklich Daten gespeiuchert sind, muss nicht
	 * erfolgen, da dies schon durch die aufgerufene Funktion erledigt wird. */
	return this->chararray_to_cstr(this->data_gtin, this->data_gtin_length);
}


/* get_addon_code();
 * gibt die Daten aus this->data_addon_code als cstring zurueck.
 * Die Endwanwendung muss dabei beachten, dass nur ein Pointer zurueckgegeben
 * wird, welcher nach erfolgreicher Verwendung mit delete[] geloescht werden
 * muss.
 */
const char * gtin::get_addon_code () {
	/* Eine Ueberpruefung, ob auch wirklich Daten gespeiuchert sind, muss nicht
	 * erfolgen, da dies schon durch die aufgerufene Funktion erledigt wird. */
	return this->chararray_to_cstr(this->data_addon_code, this->data_addon_code_length);
}
