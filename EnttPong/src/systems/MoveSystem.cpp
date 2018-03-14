///
/// MoveSystem.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

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

	void MoveSystem::update()
	{
		// We only need to update the player position, since the ai wil be managed by the aisystem.
		
		m_movingNorth = false;
		m_movingSouth = false;
	}
}