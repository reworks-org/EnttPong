///
/// CollisionSystem.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "../tags/AITag.hpp"
#include "../tags/BallTag.hpp"
#include "../tags/PlayerTag.hpp"
#include "../components/SpriteComponent.hpp"
#include "../components/PositionComponent.hpp"

#include "CollisionSystem.hpp"

namespace ep
{
	void CollisionSystem::update(entt::DefaultRegistry& registry)
	{
		auto ball = registry.attachee<BallTag>();
		PositionComponent& ballPos = registry.get<PositionComponent>(ball);
		SpriteComponent& ballSprite = registry.get<SpriteComponent>(ball);

		// Ball bounding box.
		SDL_Rect BallBB{ static_cast<int>(ballPos.m_x), static_cast<int>(ballPos.m_y), ballSprite.m_width, ballSprite.m_height };

		// First we retrieve a view of the entitys we want to process.
		// Then we iterate over each one and update the appropriate data.
		registry.view<SpriteComponent, PositionComponent>().each([&](auto entity, SpriteComponent& sc, PositionComponent& pc)
		{
			// entity bb
			SDL_Rect aabb{ static_cast<int>(pc.m_x), static_cast<int>(pc.m_y), sc.m_width, sc.m_height };

			if (entity != ball)
			{
				if (SDL_HasIntersection(&BallBB, &aabb))
				{
					// do something???
				}
			}
		});
	}
}