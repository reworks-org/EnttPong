///
/// Ball.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include "../Random.hpp"

#include "Ball.hpp"

namespace ep
{
	Ball::Ball(const double vel_x, const double vel_y) noexcept
	    : m_initial_vel_x {vel_x}, m_initial_vel_y {vel_y}, m_bounce_immune_ticks {0}
	{
		// Determines the random starting direction of the ball.
		switch (random(0, 3))
		{
			case 0:
				m_vel_x = m_initial_vel_x;
				break;

			case 1:
				m_vel_x = -m_initial_vel_x;
				break;

			case 2:
				m_vel_y = m_initial_vel_y;
				break;

			case 3:
				m_vel_y = -m_initial_vel_y;
				break;
		}
	}

	Ball::Ball(Ball&& b) noexcept
	{
		this->m_bounce_immune_ticks = b.m_bounce_immune_ticks;
		this->m_initial_vel_x       = b.m_initial_vel_x;
		this->m_initial_vel_y       = b.m_initial_vel_y;
		this->m_vel_x               = b.m_vel_x;
		this->m_vel_y               = b.m_vel_y;
	}

	Ball& Ball::operator=(Ball&& b) noexcept
	{
		if (this != &b)
		{
			this->m_bounce_immune_ticks = b.m_bounce_immune_ticks;
			this->m_initial_vel_x       = b.m_initial_vel_x;
			this->m_initial_vel_y       = b.m_initial_vel_y;
			this->m_vel_x               = b.m_vel_x;
			this->m_vel_y               = b.m_vel_y;
		}

		return *this;
	}

	const double Ball::initial_x_vel() const noexcept
	{
		return m_initial_vel_x;
	}

	const double Ball::initial_y_vel() const noexcept
	{
		return m_initial_vel_y;
	}
} // namespace ep