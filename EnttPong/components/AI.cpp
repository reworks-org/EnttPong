///
/// AI.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include "AI.hpp"

namespace ep
{
	AI::AI(const double x, const double y) noexcept
	    : m_x {x}, m_y {y}
	{
	}

	AI::AI(AI&& ai) noexcept
	{
		this->m_x = ai.m_x;
		this->m_y = ai.m_y;
	}

	AI& AI::operator=(AI&& ai) noexcept
	{
		if (this != &ai)
		{
			this->m_x = ai.m_x;
			this->m_y = ai.m_y;
		}

		return *this;
	}
} // namespace ep