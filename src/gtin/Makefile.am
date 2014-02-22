# Make file template by https://gitorious.org/openismus-playground/examplelib/
#
# Place all generated object files into the directory, where their source-file
# is, to avoid collisions
# AUTOMAKE_OPTIONS = subdir-objects

# Additional flags to pass to aclocal when it is invoked automatically at make
# time. The ${ACLOCAL_FLAGS} variable is picked up from the environment to
# provide a way for the user to supply additional arguments.
# ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}


lib_LTLIBRARIES = libgtin-2.la

libgtin_2_la_SOURCES = gtin.cpp gtin_chararray.cpp gtin_checksum.cpp \
	gtin_data.cpp

libgtin_2_la_LDFLAGS = -version-info 2:1:1


# header files
gtin_includedir = $(barcode_includedir)
gtin_include_HEADERS = gtin.h
