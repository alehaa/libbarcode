/* include header files */
#include "gtin.h"

#include <cmath>

/* cstr_to_chararray ();
 * Diese Funktion ueberprueft, ob die Zeichenkette im ersten Argument nur aus
 * Ziffern besteht. Ist diese Vorraussetzung erfuellt, werden die ASCII-Chars
 * in richtige Ziffern umgewandelt und ein Array zu diesen Ziffern zurueck
 * gegeben, sodass set_data und set_addon diese verwenden koennen.
 * Da mit set_data auch GTIN ohne Checksumme uebergeben werden koennen, ist die
 * Laenge p_data_length groesser als p_data an Zeichen enthaelt. Ebenso hoert
 * der Bereich fuer buffer bei GTIN mit Addon-Code schon auf, bevor p_data zu
 * Ende ist. Durch die Logik wird dann vorher aufgehoert bzw. die weiteren Werte
 * mit '255' aufgefuellt.
 */
unsigned char * gtin::cstr_to_chararray (const char *p_data, unsigned char p_data_length) {
	/* gehe durch das Array p_data, schaue ob nur legale Zeichen vorhanden sind und
	 * wandle die Zeichen in echte Ziffern um. */
	unsigned char c = 0;
	unsigned char *buffer = new unsigned char[p_data_length];
	for (const char *p = p_data; *p; p++) {
		/* befinden wir uns noch im gewuenschten Bereich? Sonst verlasse nun die Schleife */
		if (c >= p_data_length) break;

		/* Pruefe, ob es sich um eine Ziffer handelt. Ziffern sind die ASCII-Zeichen
		 * 48-57, d.h. es reicht zu pruefen, ob *p in diesem Bereich liegt. */
		if ((*p >= 48) && (*p <= 57)) {
			/* Das zeichen ist eine Ziffer, also kann es in den Buffer aufgenommen werden*/
			buffer[c] = *p - 48;
			c++;

		/* es handelt sich um keine Ziffer, also breche die Funktion vorzeitig ab */
		} else {
			/* loesche den bereits reservierten Datenbereich wieder */
			delete[] buffer;

			return nullptr;
		}
	}

	/* wenn z.B. keine Pruefziffer uebergeben wurde, dann fuelle die letzte Stelle
	 * mit einer 0 auf. */
	if ((c + 1) == p_data_length) buffer[c] = 255;

	/* return pointer to buffer */
	return buffer;
}


/* chararray_to_cstr ();
 * gibt die Daten aus p_data als cstring zurueck.
 * Die Endwanwendung muss dabei beachten, dass nur ein Pointer zurueckgegeben
 * wird, welcher nach erfolgreicher Verwendung mit delete[] geloescht werden
 * muss.
 */
const char * gtin::chararray_to_cstr (unsigned char *p_data, unsigned char p_data_length) {
	if (p_data != nullptr) {
		/* reserviere neuen Speicherbereich. Dabei muss beachtet werden, dass ein Zeichen
		 * mehr gebraucht wird, als p_data lang ist, da am Ende ein '\0' zur Terminierung
		 * des cstrings angefügt wird. */
		char *buffer = new char[p_data_length + 1];

		/* gehe mit *p durch das Array, bis die letzte Stelle (destiny) erreicht ist */
		unsigned char *destiny = p_data + p_data_length;
		do {
			*buffer = *p_data + 48;
			buffer++;
			p_data++;
		} while (p_data != destiny);

		/* add NULL at end of cstring */
		*buffer = '\0';

		return (buffer - p_data_length);
	}

	/* p_data verweist auf den nullptr, d.h. es sind keine Daten da, welche um-
	 * gewandelt werden koennen. Gebe den nullptr zurueck. */
	return nullptr;
}


/* chararray_to_int ();
 * gibt die Daten in p_data als integer zurueck.
 */
int gtin::chararray_to_int (unsigned char *p_data, unsigned char p_data_length) {
	if (p_data != nullptr) {
		int buffer = 0;

		/* gehe das Array von hinten nach vorne durch und multipliziere mit steigendem
		 * Exponenten */
		char exponent = 0;
		unsigned char *p = p_data + p_data_length;
		do {
			p--;
			buffer = buffer + ((int)*p * pow(10, exponent));
			exponent++;
		} while (p != p_data);

		return buffer;
	}

	/* p_data verweist auf den nullptr, d.h. es sind keine Daten da, welche um-
	 * gewandelt werden koennen. Gebe -1 als Fehlermeldung zurueck. */
	return -1;
}
