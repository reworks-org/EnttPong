///
/// BallTag.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_BALLTAG_HPP_
#define ENTTPONG_BALLTAG_HPP_

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
		BallTag();

		///
		/// Default destructor.
		///
		~BallTag() = default;

		///
		/// Move assignment overload.
		///
		BallTag& operator=(const BallTag &);

	public:
		///
		/// The X direction the ball is moving in.
		///
		double m_XDirection;

		///
		/// The Y direction the ball is moving in.
		///
		double m_YDirection;
	};
}

#endif