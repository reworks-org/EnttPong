///
/// Player.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include "Player.hpp"

namespace ep
{
	Player::Player() noexcept
	    : m_movement {MoveDirection::STOPPED}
	{
	}

	Player::Player(Player&& p) noexcept
	{
		this->m_movement = p.m_movement;
		p.m_movement     = MoveDirection::STOPPED;
	}

	Player& Player::operator=(Player&& p) noexcept
	{
		if (this != &p)
		{
			this->m_movement = p.m_movement;
			p.m_movement     = MoveDirection::STOPPED;
		}

		return *this;
	}
} // namespace ep