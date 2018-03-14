///
/// VelocityComponent.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "VelocityComponent.hpp"

namespace ep
{
	VelocityComponent::VelocityComponent(float velX, float velY)
		:m_x(velX), m_y(velY)
	{
	}

	VelocityComponent& VelocityComponent::operator=(const VelocityComponent &)
	{
		return *this;
	}
}