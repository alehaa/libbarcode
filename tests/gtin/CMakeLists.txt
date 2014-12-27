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


#
# charset
#
addTest("gtin_charset_NoError"
	"charset.c"
	"barcode-gtin"
	"../../src/gtin"
	""
	""
	""
)

addTest("gtin_charset_Alpha"
	"charset.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_CHARSET_1"
	""
	""
)

addTest("gtin_charset_Hyphen"
	"charset.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_CHARSET_2"
	""
	""
)



#
# length
#
addTest("gtin_length_8_NoError"
	"length.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_LENGTH_8"
	""
	""
)

addTest("gtin_length_11"
	"length.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_LENGTH_11"
	""
	""
)

addTest("gtin_length_12_NoError"
	"length.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_LENGTH_12"
	""
	""
)

addTest("gtin_length_13_NoError"
	"length.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_LENGTH_13"
	""
	""
)

addTest("gtin_length_14_NoError"
	"length.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_LENGTH_14"
	""
	""
)

addTest("gtin_length_15_NoError"
	"length.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_LENGTH_15"
	""
	""
)

addTest("gtin_length_16"
	"length.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_LENGTH_16"
	""
	""
)

addTest("gtin_length_18_NoError"
	"length.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_LENGTH_18"
	""
	""
)



#
# checksum
#
addTest("gtin_checksum_8_NoError"
	"checksum.c"
	"barcode-gtin"
	"../../src/gtin"
	""
	""
	""
)

addTest("gtin_checksum_8_Error"
	"checksum.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_CHECKSUM_8_ERR"
	""
	""
)

addTest("gtin_checksum_8_Swap"
	"checksum.c"
	"barcode-gtin"
	"../../src/gtin"
	"LIBBARCODE_GTIN_CHECKSUM_8_SWAP"
	""
	""
)
