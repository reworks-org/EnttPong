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
	void CollisionSystem::update(double time, entt::DefaultRegistry& registry)
	{
		// First we retrieve all the relevant entities.
		// We do this rather than iterate because each component has to be acted on specficially.

		auto ball = registry.attachee<BallTag>();
		BallTag& ballTag = registry.get<BallTag>();
		PositionComponent& ballPos = registry.get<PositionComponent>(ball);
		SpriteComponent& ballSprite = registry.get<SpriteComponent>(ball);

		auto player = registry.attachee<PlayerTag>();
		PositionComponent& playerPos = registry.get<PositionComponent>(player);
		SpriteComponent& playerSprite = registry.get<SpriteComponent>(player);

		auto ai = registry.attachee<AITag>();
		PositionComponent& aiPos = registry.get<PositionComponent>(ai);
		SpriteComponent& aiSprite = registry.get<SpriteComponent>(ai);

		// Ball bounding box.
		SDL_Rect BallBB{ static_cast<int>(ballPos.m_x), static_cast<int>(ballPos.m_y), ballSprite.m_radius, ballSprite.m_radius };

		// Player bounding box.
		SDL_Rect PlayerBB{ static_cast<int>(playerPos.m_x), static_cast<int>(playerPos.m_y), playerSprite.m_width, playerSprite.m_height };

		// AI bounding box
		SDL_Rect AIBB{ static_cast<int>(aiPos.m_x), static_cast<int>(aiPos.m_y), aiSprite.m_width, aiSprite.m_height };

		// calculate collisions and act on them
		if (SDL_HasIntersection(&PlayerBB, &BallBB) == SDL_TRUE)
		{
			// bounce ball
			ballPos.m_x = 0.0;
			ballTag.m_velX = -ballTag.m_velX;
		}
		else if (SDL_HasIntersection(&AIBB, &BallBB) == SDL_TRUE)
		{
			// bounce ball
			ballPos.m_x = (480.0 - 16.0);
			ballTag.m_velX = -ballTag.m_velX;
		}
	}
}