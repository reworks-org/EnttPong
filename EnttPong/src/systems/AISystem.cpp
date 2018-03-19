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
	void AISystem::update(entt::DefaultRegistry& registry)
	{
		// First we retrieve the appropriate entities.
		auto ai = registry.attachee<AITag>();
		auto ball = registry.attachee<BallTag>();

		// Then their position components.
		PositionComponent& aiPC = registry.get<PositionComponent>(ai);
		PositionComponent& ballPC = registry.get<PositionComponent>(ball);

		// And now we center the ai to the ball so it is always in the right position.
		// we want to increase or decrese ai position based on if the ball is above or below it.
		// so something like:
		/*
		if (ball position is above ai)
		{
			// move ai smoothly up towards ball so middle of ai paddle is at ball pos.
		}
		*/
	}
}