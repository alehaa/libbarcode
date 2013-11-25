/* include header files */
#include "gtin.h"

#include <cstdarg>
#include <cstdio>


/* set_verbose_handler();
 * This function sets the pointer for verbose printing. It is used to
 * forward internal log messages to a global log function of the App-
 * lication that uses this library.
 */
void gtin::set_verbose_handler(void (*p_handler) (const char * message)) {
	/* The Compiler tests if the pointer is valid. Also p_handler could be NULL
	 * so forwarding could be disabled again. */
	this->log_message_handler = p_handler;

	if (this->verbose) this->log_message("log-message-handler changed to function pointer: %p", p_handler);
}


/* set_verbose();
 * This function activates by default verbose output. If first parameter
 * is false, verbose output will be disabled.
 */
void gtin::set_verbose(bool p_verbose) {
	/* check if status would be changed or not. */
	if (this->verbose != p_verbose) {
		/* write begin/end message */
		if (p_verbose) this->log_message("verbose output enabled");
		else this->log_message("verbose output disabled");

		/* set status */
		this->verbose = p_verbose;
	}
}


/* log_message();
 * This function is used to parse all arguments like printf to get a
 * complete sting. If a handler was set, the array of char (cstring)
 * will be forwarded to it - otherwise the message will be printed to
 * stdout.
 * This function is based on http://stackoverflow.com/questions/69738#69911
 * and improved to not having to use strings.
 */
void gtin::log_message (const char* message, ...) {
	va_list args;
	size_t buffer_size = 50;
	char * dynamic_buffer = nullptr;

	/* init argument list after argument message */
	va_start(args, message);

	/* try to execute with buffer_size. If buffer_size is to small,
	 * repeat with bigger buffer. */
	while (true) {
		/* create new buffer */
		dynamic_buffer = new char[buffer_size];

		/* Try to vsnprintf into our buffer. */
		int needed = vsnprintf(&dynamic_buffer[0], buffer_size, message, args);

		/* in C99 Standard (which modern Linux and OSX follow) says vsnprintf
		 * failure returns the length it would have needed. But older glibc and
		 * current Windows return -1 for failure and not telling us how much
		 * was needed. */
		if (needed > (int)buffer_size || needed < 0) {
			/* vnsprintf reported, that it wanted to write more characters than we
			 * allocated. Set new buffer_size, delete used buffer and try to return
			 * operation. */
			buffer_size = (size_t)(needed + 1);
			delete[] dynamic_buffer;
		} else {
			/* parsed string fitted in buffer - exit while loop */
			break;
		}
	}

	/* end parser for message */
	va_end(args);

	/* if this->log_message_handler is NULL the if clause would be 'false'
	 * and we know we have to print it on stdout. */
	if (this->log_message_handler) this->log_message_handler(dynamic_buffer);
	else printf("libgtin:\t%s\n", dynamic_buffer);

	/* delete dynamic_buffer */
	delete[] dynamic_buffer;
}
