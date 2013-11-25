/* libgtin2
 *
 * This class is used to de - and encoding of GTIN codes.
 *
 * In the design of the class was taken to use as little space as well as calc-
 * ulations. Therefore pointers are frequently used. This class breaks down the
 * codes in their composition only in general, since there are too many app-
 * lication areas, which would affect the size of the class otherwise prevail.
 * Thus, with this class only convert the data in the bar code and vice versa,
 * and the ranges for the data output. For special cases one daughter class can
 * be developed in the final then that meets the specific requirements.
 *
 * This class has been optimized as far as possible, but it may still not be
 * perfect. It would be nice to report better solutions by email so that the
 * error can be fixed centrally. If someone better English than I can, he may
 * also like to correct my English ;)
 *
 * Alexander Haase <alexander.haase@rwth-aachen.de>
 */

#ifndef LIBGTIN_H
#define LIBGTIN_H

class gtin {
	public:
		~gtin ();

		void set_verbose_handler (void (*p_handler) (const char* message));
		void set_verbose (bool p_verbose = true);

		void set_handle_addon_codes (bool p_handle);

		bool set_data (const char* p_data, bool p_contains_checksum = true);
		bool set_addon_code (const char* p_data);
		const char * get_data ();
		const char * get_addon_code ();

		enum class gtin_type {
			ERR = -1,
			NONE = 0,
			STOREINTERNAL = 1,
			PRESSCODE_GERMANY = 2,
			ISSN = 3,
			ISBN = 4,
			ISMN = 5,
			REFUND_RECEIPT = 6,
			COUPON = 7,
			COMMON_CURRENCY_COUPON = 8,
		};

		const short get_gtin_gs1_prefix ();
		const gtin::gtin_type get_gtin_type ();
		const int get_gtin_section_articlenumber ();
		const short get_gtin_section_amount ();

		void reset ();


	protected:
		unsigned char * cstr_to_chararray (const char *p_data, unsigned char p_data_length);
		const char * chararray_to_cstr (unsigned char *p_data, unsigned char p_data_length);
		int chararray_to_int (unsigned char *p_data, unsigned char p_data_length = 1);

		unsigned char* data_gtin = nullptr, data_gtin_length;
		unsigned char* data_addon_code = nullptr, data_addon_code_length;

		bool verbose = false;
		void log_message (const char* message, ...);

		bool checksum ();

		bool handle_addon_code = true;


	private:
		void (*log_message_handler) (const char* message) = nullptr;

		short gtin_buff_gs1_prefix = 0;
		int gtin_buff_section_articlenumber = 0;
		short gtin_buff_section_amount = 0;
};

#endif // LIBGTIN_H
