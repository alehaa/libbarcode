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
#
# \param p_testName Name used for this test (must be unique)
# \param p_sourceList Sources needed for the executeable
#
function (addTestExecutable p_testName p_sourceList)
	# add new executeable
	add_executable("${p_testName}" "${p_sourceList}")
	target_link_libraries("${p_testName}" barcode)
endfunction (addTestExecutable)


## \brief Adds a new test and uses target \p p_target for it.
#
#
# \param p_testName Name used for this test (must be unique)
# \param p_target Target to be used for test
# \param p_args Arguments that should be passed to test executable
#
function (addSimpleTestByTarget p_testName p_target p_args)
	# setup test
	get_target_property(bin_path "${p_target}" LOCATION)
	add_test("${p_testName}" ${bin_path} ${p_args})
endfunction (addSimpleTestByTarget)


## \brief Adds a new test and invokes the build of it.
#
#
# \param p_testName Name used for this test (must be unique)
# \param p_sourceList Sources needed for the executeable
# \param p_args Arguments that should be passed to test executable
#
function (addSimpleTest p_testName p_sourceList p_args)
	# build test executable
	addTestExecutable("${p_testName}" "${p_sourceList}")

	# setup test
	addSimpleTestByTarget("${p_testName}" "${p_testName}" "${p_args}")
endfunction (addSimpleTest)





# recurse into subdirectories
add_subdirectory(barcode_base)
add_subdirectory(barcode_numeric)
#add_subdirectory(gtin)
