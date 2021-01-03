///
/// RenderSystem.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include <entt/entt.hpp>
#include <SDL_render.h>
#include <SDL2_gfxPrimitives.h>

#include "../components/Position.hpp"
#include "../components/Sprite.hpp"

#include "RenderSystem.hpp"

namespace ep
{
	void RenderSystem::render(Window& window, entt::registry& registry)
	{
		// First we retrieve a view of the entitys we want to process, specifying which components.
		// Then we iterate over each one and utilize the components.

		auto view = registry.view<Sprite, Position>();
		view.each([&](const auto& spr, auto& pos) {
			if (spr.m_radius != 0)
			{
				// We use SDL2_gfx to make drawing circles easier.
				filledCircleRGBA(window.renderer(), static_cast<Sint16>(pos.m_x), static_cast<Sint16>(pos.m_y), spr.m_radius, spr.m_colour.r, spr.m_colour.g, spr.m_colour.b, spr.m_colour.a);
			}
			else
			{
				// First we set the rectangle fill colour to that of the spritecomponents.
				SDL_SetRenderDrawColor(window.renderer(), spr.m_colour.r, spr.m_colour.g, spr.m_colour.b, spr.m_colour.a);

				// Then we create the actual rectangle.
				const SDL_Rect draw_rect {static_cast<int>(pos.m_x), static_cast<int>(pos.m_y), spr.m_width, spr.m_height};

				// Now the rectangle gets renderered with the appropriate colours and position data to the window.
				SDL_RenderFillRect(window.renderer(), &draw_rect);
			}
		});
	}
} // namespace ep