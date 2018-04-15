///
/// BallTag.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "BallTag.hpp"

namespace ep
{
	BallTag::BallTag(double velX, double velY) noexcept
		:m_velX(velX), m_velY(velY), m_startingVelX(velX), m_startingVelY(velY)
	{
	}

	BallTag& BallTag::operator=(const BallTag &) noexcept
	{
		return *this;
	}
}