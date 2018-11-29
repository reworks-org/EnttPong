///
/// BallTag.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "../utils/RandomVelocity.hpp"

#include "BallTag.hpp"

namespace ep
{
	BallTag::BallTag(double velX, double velY) noexcept
		:m_startingVelX(velX), m_startingVelY(velY)
	{
		// Randomize intial movement.
		m_velX = randomVelocitySign(velX);
		m_velY = randomVelocitySign(velY);
	}

	BallTag& BallTag::operator=(const BallTag &) noexcept
	{
		return *this;
	}
}