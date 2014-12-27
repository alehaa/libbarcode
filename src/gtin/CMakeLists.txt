# This file is part of libbarcode.
#
# libbarcode is free software: you can restribute it and/or modify it under the
# terms of the GNU Lesser General Public license as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful,but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License and GNU
# Lesser General Public License along with this program. If not, see
#
#  http://www.gnu.org/licenses/
#
#
# Copyright (C)
#   2013-2014 Alexander Haase <alexander.haase@rwth-aachen.de>
#

# build libbarcode-gtin
add_library(barcode-gtin SHARED
	checksum.c
	validate_charset.c
	validate_length.c
	validate.c
)

# set SO-Version
set_target_properties(barcode-gtin PROPERTIES
	VERSION 1.0.0
	SOVERSION 1
)

# install library
install(TARGETS barcode-gtin DESTINATION ${LIBBARCODE_LIB_PATH})

# install header file
install(FILES gtin.h DESTINATION ${LIBBARCODE_INC_PATH})
