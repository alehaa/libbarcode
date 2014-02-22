AC_INIT([libbarcode], [2.1.1], [alexander.haase@rwth-aachen.de], [libbarcode], [https://github.com/lx-icewave/libbarcode])
AC_PREREQ([2.59])

AC_CONFIG_SRCDIR([src/gtin/gtin.cpp])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign])

AC_PROG_CXX

LT_INIT

# Define these substitions here to keep all version information in one place.
# For information on how to properly maintain the library version information,
# refer to the libtool manual, section "Updating library version information":
# http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
AC_SUBST([BARCODE_SO], [2:0:0])

# Override the template file name of the generated .pc file, so that there
# is no need to rename the template file when the API version changes.
AC_CONFIG_FILES([Makefile barcode.pc:barcode.pc.in])

AC_OUTPUT
