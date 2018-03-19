///
/// RenderSystem.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include <SDL2/SDL_render.h>

#include "../components/SpriteComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../libs/SDL2_gfx/SDL2_gfxPrimitives.h"

#include "RenderSystem.hpp"

namespace ep
{
	void RenderSystem::render(Window* window, entt::DefaultRegistry& registry)
	{
		// First we retrieve a view of the entitys we want to process.
		// Then we iterate over each one and update the appropriate data.
		registry.view<SpriteComponent, PositionComponent>().each([&](auto entity, SpriteComponent& sc, PositionComponent& pc)
		{
			if (sc.m_radius != 0)
			{
				// We use SDL2_gfx to make drawing circles easier.
				filledCircleRGBA(window->getRenderer(), static_cast<Sint16>(pc.m_x), static_cast<Sint16>(pc.m_y), sc.m_radius, sc.m_colour.r, sc.m_colour.g, sc.m_colour.b, sc.m_colour.a);
			}
			else
			{
				// First we set the rectangle fill colour to that of the spritecomponents.
				SDL_SetRenderDrawColor(window->getRenderer(), sc.m_colour.r, sc.m_colour.g, sc.m_colour.b, sc.m_colour.a);
				// Then we create the actual rectangle.
				SDL_Rect rectToDraw{ static_cast<int>(pc.m_x), static_cast<int>(pc.m_y), sc.m_width, sc.m_height };
				// Now the rectangle gets renderered with the appropriate colours and position data to the window.
				SDL_RenderFillRect(window->getRenderer(), &rectToDraw);
			}
		});
	}
}