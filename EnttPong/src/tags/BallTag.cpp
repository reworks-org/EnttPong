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
	BallTag::BallTag()
		:m_XDirection(1.0), m_YDirection(1.0)
	{
	}

	BallTag& BallTag::operator=(const BallTag &)
	{
		return *this;
	}
}