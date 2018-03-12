///
/// MoveSystem.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

// #include "../tags/PlayerTag.hpp"

#include "MoveSystem.hpp"

namespace ep
{
	void MoveSystem::event(SDL_Event& event, entt::DefaultRegistry& registry)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:

			break;

		case SDLK_s:

			break;
		}
	}

	void MoveSystem::update()
	{
	}
}