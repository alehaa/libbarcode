# Make file template by https://gitorious.org/openismus-playground/examplelib/

# Place all generated object files into the directory, where their source-file
# is, to avoid collisions
AUTOMAKE_OPTIONS = subdir-objects

# Additional flags to pass to aclocal when it is invoked automatically at make
# time. The ${ACLOCAL_FLAGS} variable is picked up from the environment to
# provide a way for the user to supply additional arguments.
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}


# directory for header files
barcode_includedir = $(includedir)/libbarcode
barcode_include_HEADERS = src/gtin/gtin.h


lib_LTLIBRARIES = libbarcode.la

libbarcode_la_SOURCES = src/gtin/gtin.cpp src/gtin/gtin_chararray.cpp \
	src/gtin/gtin_checksum.cpp src/gtin/gtin_data.cpp

libbarcode_la_LDFLAGS = -version-info @BARCODE_SO@ -Xlinker --as-needed


# PKG-Config
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = barcode.pc


# Define an independent executable script for inclusion in the distribution
# archive.  However, it will not be installed on an end user's system due to
# the noinst_ prefix.
dist_noinst_SCRIPTS = autogen.sh
