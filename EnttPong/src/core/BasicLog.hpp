///
/// BasicLog.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

/**
* Example usage:
* LOG_ERROR << "Woops. You broke something!" << "\n";
* OR
* LOG_ERROR << "Woops. You broke something!" << FLUSH_LOG;
*/
#ifndef ENTTPONG_BASICLOG_HPP_
#define ENTTPONG_BASICLOG_HPP_

#include <iostream>

///
/// Log an error message.
///
#define LOG_ERROR std::cout << "ERROR:    "

///
/// Log a warning.
///
#define LOG_WARNING std::cout << "WARNING:  "

///
/// Log some information.
///
#define LOG_INFO std::cout << "INFO:     "

///
/// Flush the log. Also ends the current line.
///
#define FLUSH_LOG std::endl

#endif