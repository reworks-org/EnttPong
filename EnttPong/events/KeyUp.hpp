///
/// KeyUp.hpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_EVENTS_KEYUP_HPP_
#define ENTTPONG_EVENTS_KEYUP_HPP_

namespace ep
{
	///
	/// Simple keydown event.
	///
	struct KeyUp final
	{
		///
		/// Argument constructor.
		///
		inline KeyUp(int key_code)
		    : m_keycode(key_code)
		{
		}

		///
		/// \brief SDL2 Key code.
		///
		/// Defaults to invalid -1.
		///
		int m_keycode = -1;
	};
} // namespace ep

#endif