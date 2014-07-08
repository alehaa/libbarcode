# This file is part of libbarcode.
#
# libbarcode is free software: you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <http://www.gnu.org/licenses/>.
#
#
# Copyright (C)
#   2013-2014 Alexander Haase <alexander.haase@rwth-aachen.de>
#


# include paths for tests
include_directories("${PROJECT_SOURCE_DIR}/src/barcode_base")
include_directories("${PROJECT_SOURCE_DIR}/src/barcode_numeric")
include_directories("${PROJECT_SOURCE_DIR}/src/gtin")


# test of function set_data()
addTestExecutable("barcode_gtin_set_data_valid" "set_data_valid.cpp")
foreach (i 7 8 11 12 13 14 15 18)
	addSimpleTestByTarget ("barcode_gtin_set_data_valid_${i}" "barcode_gtin_set_data_valid" "${i}")
endforeach ()

addTestExecutable("barcode_gtin_set_data_invalid" "set_data_invalid.cpp")
foreach (i 5 6 9 10 16 17 19 20)
	addSimpleTestByTarget ("barcode_gtin_set_data_invalid_${i}" "barcode_gtin_set_data_invalid" "${i}")
endforeach ()
