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
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			m_movingNorth = true;
			break;

		case SDLK_s:
			m_movingSouth = true;
			break;
		}
	}

	void MoveSystem::update(entt::DefaultRegistry& registry)
	{
		// We only need to update the player position, since the ai wil be managed by the aisystem.
		// Here, we can retrieve the player entity, because only ONE entity can have a single instance component (tag).
		auto player = registry.attachee<PlayerTag>();
		PositionComponent &pc = registry.get<PositionComponent>(player);

		if (m_movingNorth)
		{
			pc.m_y -= 5;
			m_movingNorth = false;
		}

		if (m_movingSouth)
		{
			pc.m_y += 5;
			m_movingSouth = false;
		}
	}
}