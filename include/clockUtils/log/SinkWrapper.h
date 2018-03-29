/*
 * clockUtils
 * Copyright (2016) Michael Baer, Daniel Bonrath, All rights reserved.
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
 * \addtogroup log
 * @{
 */

#ifndef __CLOCKUTILS_LOG_SINKWRAPPER_H__
#define __CLOCKUTILS_LOG_SINKWRAPPER_H__

#include <string>

#include "clockUtils/log/LogParameters.h"

namespace clockUtils {
namespace log {

	/**
	 * \brief this class is the abstract interface wrapping sinks
	 * every sink has just to implement the stream operator using std::string as parameter
	 */
	class SinkWrapper {
	public:
		virtual ~SinkWrapper() {
		}

		/**
		 * \brief called when logging something
		 */
		virtual SinkWrapper & operator<<(const std::string &) = 0;

		/**
		 * \brief check whether two sinks are the same so e.g. two times std::cout isn't added twice
		 */
		virtual bool isSame(void * sink) const = 0;
	};

	/**
	 * \brief templated implementation of SinkWrapper
	 */
	template<typename T>
	class SinkWrapperImplementation : public SinkWrapper {
	public:
		SinkWrapperImplementation(T * sink) : SinkWrapper(), _sink(sink) {
		}

		/**
		 * \brief forwards message to concrete sink implementation
		 */
		SinkWrapper & operator<<(const std::string & message) override {
			*_sink << message;
			return *this;
		}

		/**
		 * \brief compares stored sink with parameter
		 */
		bool isSame(void * sink) const override {
			return sink == _sink;
		}

	private:
		T * _sink;
	};

} /* namespace log */
} /* namespace clockUtils */

#endif /* __CLOCKUTILS_LOG_SINKWRAPPER_H__ */

/**
 * @}
 */