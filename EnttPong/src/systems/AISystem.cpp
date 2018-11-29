///
/// AISystem.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "../tags/AITag.hpp"
#include "../tags/BallTag.hpp"
#include "../components/PositionComponent.hpp"

#include "AISystem.hpp"

namespace ep
{
	void AISystem::update(double time, entt::DefaultRegistry& registry) noexcept
	{
		// First we retrieve the appropriate entities.
		const auto ai = registry.attachee<AITag>();
		const auto ball = registry.attachee<BallTag>();

		// Then their position components.
		PositionComponent& aiPC = registry.get<PositionComponent>(ai);
		const PositionComponent& ballPC = registry.get<PositionComponent>(ball);

		// And now we center the ai to the ball so it is always in the right position.
		// we want to increase or decrese ai position based on if the ball is above or below it.
		// so something like:
		/*
		if (ball position is above ai)
		{
			// move ai smoothly up towards ball so middle of ai paddle is at ball pos.
		}
		*/

		if (ballPC.m_y > aiPC.m_y)
		{
			aiPC.m_y += 2.5;
		}
		else if (ballPC.m_y < aiPC.m_y)
		{
			aiPC.m_y -= 2.5;
		}
	}
}