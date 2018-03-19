///
/// MoveSystem.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "../tags/PlayerTag.hpp"
#include "../components/PositionComponent.hpp"

#include "MoveSystem.hpp"

namespace ep
{
	void MoveSystem::event(SDL_Event& event, entt::DefaultRegistry& registry)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				m_movingNorth = true;
				break;

			case SDLK_s:
				m_movingSouth = true;
				break;
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				m_movingNorth = false;
				break;

			case SDLK_s:
				m_movingSouth = false;
				break;
			}
			break;
		}
	}

	void MoveSystem::update(double time, entt::DefaultRegistry& registry)
	{
		// We only need to update the player position, since the ai wil be managed by the aisystem.
		// Here, we can retrieve the player entity, because only ONE entity can have a single instance component (tag).
		auto player = registry.attachee<PlayerTag>();
		PositionComponent &pc = registry.get<PositionComponent>(player);

		if (m_movingNorth)
		{
			pc.m_y -= 0.15 * time;
		}

		if (m_movingSouth)
		{
			pc.m_y += 0.15 * time;
		}

		// lock to screen
		if (pc.m_y < 0)
		{
			pc.m_y = 0;
		}
		else if (pc.m_y > (480 - 96)) // screen width - sprite width
		{
			pc.m_y = (480 - 96);
		}
	}
}