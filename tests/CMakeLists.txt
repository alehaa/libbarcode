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


## \file
#
# \brief CMakeLists.txt for tests directory.
#
# \details Contains basic functions to add tests and recurses into the
#   subdirectories, where all tests are.
#
#
# \copyright 2013-2014 Alexander Haase <alexander.haase@rwth-aachen.de>
#
# \date 07.07.2014
#


## \brief Adds a new executable for a test to build it.
#
# \attention The name of the executable will be \p p_TestName followed by
#   _test.
#
#
# \param p_testName name used for this test (must be unique)
# \param p_sourceList sources needed for the executeable
# \param p_include include directory in /src to build test
# \param p_libs target of library that should be linked
#
function (addSimpleTest p_testName p_sourceList p_include p_libs)
	# include directorys to build test
	if (NOT "${p_include}" STREQUAL "")
		include_directories("${PROJECT_SOURCE_DIR}/src/${p_include}")
	endif (NOT "${p_include}" STREQUAL "")

	# add new executeable
	add_executable("${p_testName}_test" "${p_sourceList}")

	# link libraries
	if (NOT "${p_libs}" STREQUAL "")
		target_link_libraries("${p_testName}_test" "${p_libs}")
	endif (NOT "${p_libs}" STREQUAL "")

	get_target_property(bin_path "${p_testName}_test" LOCATION)
	add_test("${p_testName}" ${bin_path})
endfunction (addSimpleTest)



#
# recurse into subdirectories
#
add_subdirectory(barcode)
