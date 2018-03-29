/*
 * clockUtils
 * Copyright (2017) Michael Baer, Daniel Bonrath, All rights reserved.
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

#include <functional>
#include <locale>

namespace clockUtils {

	/**
	 * \brief trims whitespace from the beginning
	 */
	static inline void ltrim(std::string & s) {
		// careful with ::iswspace. There is a second version outside namespace std with different types
		auto it =  std::find_if(s.begin(), s.end(), [](char ch) { return !std::isspace<char>(ch , std::locale::classic()); });
		s.erase(s.begin(), it);
	}

	/**
	 * \brief trims whitespace from the end
	 */
	static inline void rtrim(std::string & s) {
		// careful with ::iswspace. There is a second version outside namespace std with different types
		auto it =  std::find_if(s.rbegin(), s.rend(), [](char ch) { return !std::isspace<char>(ch , std::locale::classic()); });
		s.erase(it.base(), s.end());
	}

	/**
	 * \brief trims whitespace from both sides
	 */
	static inline void trim(std::string & s) {
		ltrim(s);
		rtrim(s);
	}

} /* namespace clockUtils */