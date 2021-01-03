///
/// Position.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include "Position.hpp"

namespace ep
{
	Position::Position(const double x, const double y) noexcept
	    : m_x {x}, m_y {y}
	{
	}

	Position::Position(Position&& p) noexcept
	{
		this->m_x = p.m_x;
		this->m_y = p.m_y;
	}

	Position& Position::operator=(Position&& p) noexcept
	{
		if (this != &p)
		{
			this->m_x = p.m_x;
			this->m_y = p.m_y;
		}

		return *this;
	}
} // namespace ep