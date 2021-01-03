///
/// AISystem.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include <entt/entt.hpp>

#include "../components/AI.hpp"
#include "../components/Ball.hpp"
#include "../components/Position.hpp"

#include "AISystem.hpp"

namespace ep
{
	void AISystem::update(const double time, entt::registry& registry)
	{
		// Center the ai to the ball so it is always in the right position.
		// we want to increase or decrese ai position based on if the ball is above or below it.
		// so something like:
		/*
			if ball position is above ai:
				move ai smoothly up towards ball so middle of ai paddle is at ball pos.
		*/

		// Takes advantage of the fact that there is only 1 AI and 1 Ball.
		auto ai_view   = registry.view<AI, Position>();
		auto ball_view = registry.view<Ball, Position>();

		ai_view.each([&](auto& ai, auto& ai_pos) {
			ai.m_x = ai_pos.m_x;
			ai.m_y = ai_pos.m_y;

			ball_view.each([&](auto& ball, auto& ball_pos) {
				if (ball_pos.m_y > ai_pos.m_y)
				{
					ai_pos.m_y += 2.5;
				}
				else if (ball_pos.m_y < ai_pos.m_y)
				{
					ai_pos.m_y -= 2.5;
				}
			});
		});
	}
} // namespace ep