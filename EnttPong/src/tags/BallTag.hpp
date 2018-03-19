///
/// BallTag.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_BALLTAG_HPP_
#define ENTTPONG_BALLTAG_HPP_

#include <cstdint>

namespace ep
{
	///
	/// Literally an identifier class.
	/// Used to retrieve the ball entity.
	///
	class BallTag final
	{
	public:
		///
		/// Main Constructor.
		///
		///
		BallTag() = default;

		///
		/// Default destructor.
		///
		~BallTag() = default;

		///
		/// Move assignment overload.
		///
		BallTag& operator=(const BallTag &);
	};
}

#endif