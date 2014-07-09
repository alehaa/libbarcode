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


# test constructor
addSimpleTest("barcode_constructor" "constructor.cpp" "")
addSimpleTest("barcode_constructor_string" "constructor_assign_string.cpp" "")
addSimpleTest("barcode_constructor_substring" "constructor_assign_substring.cpp" "")

# test of operators
addSimpleTest("barcode_operator_assign" "operator_assign_string.cpp" "")

# test of function set_data()
addSimpleTest("barcode_assign_data_string" "assign_data_string.cpp" "")
addSimpleTest("barcode_assign_data_substring" "assign_data_substring.cpp" "")

# test of function get_data()
addSimpleTest("barcode_get_data" "get_data.cpp" "")
