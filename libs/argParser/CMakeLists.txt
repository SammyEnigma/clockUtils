# clockUtils
# Copyright (2015) Michael Baer, Daniel Bonrath, All rights reserved.
#
# This file is part of clockUtils; clockUtils is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

################################
# argParser cmake
################################

set(srcdir ./src)

set(argParserSrc
	${srcdir}/ArgumentList.cpp
	${srcdir}/BasicVariable.cpp
	${srcdir}/Parser.cpp
)

SOURCE_GROUP(argParser FILES ${argParserSrc})

IF(CLOCKUTILS_BUILD_SHARED)
	add_library(clock_argParser SHARED ${argParserSrc})
ELSE(CLOCKUTILS_BUILD_SHARED)
	add_library(clock_argParser STATIC ${argParserSrc})
ENDIF(CLOCKUTILS_BUILD_SHARED)

IF(WIN32 AND ${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC AND CLOCKUTILS_BUILD_SHARED)
	add_custom_command(TARGET clock_argParser POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>/clock_argParser.dll ${CMAKE_BINARY_DIR}/bin)
ENDIF(WIN32 AND ${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC AND CLOCKUTILS_BUILD_SHARED)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/clockUtils/argParser
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include/clockUtils
	COMPONENT devel)

install(TARGETS clock_argParser
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin	COMPONENT libs
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib	COMPONENT libs
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib	COMPONENT libs
)
