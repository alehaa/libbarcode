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


## \brief Build a new executeable for test-case
#
# \details Adds a new executable for a test to build it.
#
#
# \param p_testName name used for this test (must be unique)
# \param p_sourceList sources needed for the executeable
# \param p_libraries libraries to be linked to
# \param p_include_dirs include directories for headers
# \param p_compile_flags Additional compile-flags that should be used to build
#   the test-executable
#
function (addTest_Executable p_testName p_sourceList p_libraries p_include_dirs p_compile_flags)
	# add new executable
	add_executable("${p_testName}" "${p_sourceList}")

	# link libs and include headers
	target_link_libraries("${p_testName}" "${p_libraries}")
	target_include_directories("${p_testName}" PRIVATE "${p_include_dirs}")

	# add additional compile flags, if required
	if (NOT ${p_compile_flags} STREQUAL "")
		target_compile_definitions("${p_testName}" PRIVATE ${p_compile_flags})
	endif (NOT ${p_compile_flags} STREQUAL "")
endfunction (addTest_Executable)


## \brief Function to add a new test-case
#
# \details A new test-case will be build and a test-case added.
#
#
# \param p_testName name used for this test (must be unique)
# \param p_sourceList sources needed for the executeable
# \param p_libraries libraries to be linked to
# \param p_include_dirs include directories for headers
# \param p_passRegexp Regular expression needed to pass the test
# \param p_failRegexp Regular expression needed to fail the test
# \param p_compile_flags Flags that should be passed to the compiler to build
#   the specific error-case
#
function (addTest p_testName p_sourceList p_libraries p_include_dirs p_compile_flags p_passRegexp p_failRegexp)
	# add new executeable
	addTest_Executable("${p_testName}" "${p_sourceList}" "${p_libraries}" "${p_include_dirs}" "${p_compile_flags}")

	# add test-case
	get_target_property(test_bin "${p_testName}" LOCATION)

	add_test("${p_testName}" "${test_bin}")

	# set pass regular expression
	if (NOT "${p_passRegexp}" STREQUAL "")
		set_tests_properties("${p_testName}" PROPERTIES PASS_REGULAR_EXPRESSION "${p_passRegexp}")
	endif (NOT "${p_passRegexp}" STREQUAL "")

	# set fail regular expression
	if (NOT "${p_failRegexp}" STREQUAL "")
		set_tests_properties("${p_testName}" PROPERTIES FAIL_REGULAR_EXPRESSION "${p_failRegexp}")
	endif (NOT "${p_failRegexp}" STREQUAL "")
endfunction (addTest)



#
# recurse into subdirectories
#
add_subdirectory(gtin)
