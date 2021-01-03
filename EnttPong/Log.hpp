///
/// Log.hpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_LOG_HPP_
#define ENTTPONG_LOG_HPP_

#include <iostream>
#include <string_view>

#include <SDL_error.h>

/**
* Example usage:
* LOG_ERROR << "Woops." << LOG_NEWLINE;
* OR
* LOG_ERROR << "Woops." << LOG_FLUSH;
* OR
* LOG(LOG_ERROR, "Woops.");
*/

///
/// Log something to console.
///
#define LOG(level, msg) level << msg << std::endl

///
/// Log an error message.
///
#define LOG_ERROR std::cout << "[ERROR]:    "

///
/// Log a warning.
///
#define LOG_WARNING std::cout << "[WARNING]:  "

///
/// Log some information.
///
#define LOG_INFO std::cout << "[INFO]:     "

///
/// Flush the log. Also ends the current line.
///
#define LOG_FLUSH std::endl

///
/// Provide a NewLine in a log.
///
#define LOG_NEWLINE "\n"

namespace ep
{
	///
	/// Convenience function.
	///
	inline void throw_sdl2_exception(std::string_view message)
	{
		auto str = static_cast<std::string>(message);
		str += "\n[SDL2]:   ";
		str += SDL_GetError();

		LOG(LOG_ERROR, str);
		throw std::runtime_error(str);
	}
} // namespace ep

#endif