/*
 * clockUtils
 * Copyright (2015) Michael Baer, Daniel Bonrath, All rights reserved.
 *
 * This file is part of clockUtils; clockUtils is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
 * \addtogroup iniParser
 * @{
 */

#ifndef __CLOCKUTILS_INIPARSER_INIPARSERPARAMETERS_H__
#define __CLOCKUTILS_INIPARSER_INIPARSERPARAMETERS_H__

#include "clockUtils/SystemParameters.h"

// Dynamic library import/export macro
#ifndef CLOCK_INIPARSER_API
	#if CLOCKUTILS_PLATFORM == CLOCKUTILS_PLATFORM_WIN32
		#ifdef CLOCKUTILS_BUILD_SHARED
			#ifdef clock_iniParser_EXPORTS
				#define CLOCK_INIPARSER_API __declspec(dllexport)
			#else
				#define CLOCK_INIPARSER_API __declspec(dllimport)
			#endif
		#else
			#define CLOCK_INIPARSER_API
		#endif
	#elif CLOCKUTILS_PLATFORM == CLOCKUTILS_PLATFORM_LINUX
		#define CLOCK_INIPARSER_API
	#else
		#define CLOCK_INIPARSER_API
	#endif
#endif

#endif /* __CLOCKUTILS_INIPARSER_INIPARSERPARAMETERS_H__ */

/**
 * @}
 */
