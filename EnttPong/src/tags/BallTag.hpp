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
		/// \param velX Initial X Velocity.
		/// \param velY Initial Y Velocity.
		///
		BallTag(double velX, double velY);

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
		/// The X velocity of the ball.
		///
		double m_velX;

		///
		/// The Y velocity of the ball.
		///
		double m_velY;

		///
		/// The original X velocity of the ball.
		///
		const double m_startingVelX;

		///
		/// The original Y velocity of the ball.
		///
		const double m_startingVelY;
	};
}

#endif