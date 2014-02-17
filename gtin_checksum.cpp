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
#include "gtin.h"


/* checksum berechnet die Checksumme fuer GTIN-Codes. Wird diese Funktion ohne
 * Argumente aufgerufen, wird die Pruefsumme fuer den in this->data_gtin befind-
 * lichen GTIN berechnet und die Pruefzimmer angehaengt. Wird dagegen ein
 * Pointer zu anderen Daten uebergeben, wird die darin enthaltene Pruefsumme auf
 * Richtigkeit getestet. Da zu diesem Zeitpunkt evtl. auch ein Addon-Code in dem Array enthalten ist, muss die Laenge
 * fuer den Datenbereich mit angegeben werden. */
bool gtin::checksum () {
	/* berechne die Pruefziffer. Gehe dafuer von rechts nach links durch das Array
	 * und berechne abwechselnd mit *1 oder *3 und addiere die Ergebnisse. */
	unsigned char checksum = 0;
	bool multiplicate = true;
	unsigned char *p = this->data_gtin + (this->data_gtin_length - 1);
	do {
		p--;

		/* wenn es sich um eine 0 handelt, koennen wir diese ueberspringen, da diese
		 * IMMER null ergeben wird (1*0=0, 3*0=0) und das Ergebnis somit nicht beeinflusst. */
		if (*p) {
			if (multiplicate) checksum = checksum + (3 * *p);
			else checksum = checksum + *p;
		}

		/* schalte den multiplikator um, damit anschliessend wieder mit dem anderen
		 * Multiplikator multipliziert wird. */
		if (multiplicate) multiplicate = false;
		else multiplicate = true;
	} while (p != this->data_gtin);

	/* Die Pruefziffer ergibt sich nun aus dem Differenzbetrag zwischen
	 * dem errechneten Wert in buffer und der naechsten Zehnerstelle.
	 * buffer % 10 ergibt dabei den Rest von buffer der nicht durch 10
	 * teilbar ist, es wird dann 10 minus diesen Wert gerechnet. Sollte
	 * das Ergebnis 10 sein, z.B. weil buffer komplett durch 10 teilbar war,
	 * so wird es in 0 geaendert. */
	checksum = 10 - (checksum % 10);
	if (checksum == 10) checksum = 0;

	/* wenn die Pruefziffer nur geprueft werden sollte, dann tue dies nun. Andernfalls
	 * soll die Pruefziffer in die letzte Stelle von this->data_gtin eingetragen werden. */
	p = &this->data_gtin[this->data_gtin_length - 1];
	if (*p != 255) {
		if (checksum == *p) return true;
		else return false;
	} else {
		*p = checksum;
		return true;
	}

	/* sollte etwas auftreten was bisher nicht vorgesehen war, dann gebe false zurueck */
	return false;
}
