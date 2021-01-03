///
/// MoveSystem.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include <entt/entt.hpp>

#include "../components/Ball.hpp"
#include "../components/Position.hpp"
#include "../Random.hpp"

#include "MoveSystem.hpp"

[[nodiscard]] const double randomize_velocity_dir(const double vel)
{
	switch (ep::random(0, 1))
	{
		case 0:
			return vel;
			break;

		case 1:
			return -vel;
			break;
	}
}

namespace ep
{
	void MoveSystem::on_key_down(const KeyDown& key_down) noexcept
	{
		switch (key_down.m_keycode)
		{
			case SDLK_w:
				m_player_movement = Player::MoveDirection::NORTH;
				break;

			case SDLK_s:
				m_player_movement = Player::MoveDirection::SOUTH;
				break;
		}
	}

	void MoveSystem::on_key_up(const KeyUp& key_up) noexcept
	{
		if (key_up.m_keycode == SDLK_w || key_up.m_keycode == SDLK_s)
		{
			m_player_movement = Player::MoveDirection::STOPPED;
		}
	}

	void MoveSystem::update(const double time, entt::registry& registry)
	{
		// We only need to update the player position, since the ai wil be managed by the ai system.
		auto player_view = registry.view<Player, Position>();
		player_view.each([&](auto& plr, auto& pos) {
			plr.m_movement = m_player_movement;

			if (plr.m_movement == Player::MoveDirection::NORTH)
			{
				pos.m_y -= 0.15 * time;
			}
			else if (plr.m_movement == Player::MoveDirection::SOUTH)
			{
				pos.m_y += 0.15 * time;
			}

			// Lock to screen.
			if (pos.m_y < 0.0)
			{
				pos.m_y = 0.0;
			}
			else if (pos.m_y > (480.0 - 96.0)) // screen width - sprite width
			{
				pos.m_y = (480.0 - 96.0);
			}
		});

		// Next, we want to update the balls position and move it according to the directions its currently travelling.
		auto ball_view = registry.view<Ball, Position>();
		ball_view.each([&](auto& ball, auto& pos) {
			// Allow the ball to move based on a fixed-timestep loop.
			pos.m_x += ball.m_vel_x * time;
			pos.m_y += ball.m_vel_y * time;

			// Ensure ball can be reset.
			if (pos.m_x < 0.0)
			{
				// Ball passed the player paddle, reset it.
				pos.m_x = (640.0 / 2.0) - 16.0;
				pos.m_y = (480.0 / 2.0) - 16.0;

				ball.m_vel_x = randomize_velocity_dir(ball.initial_x_vel());
				ball.m_vel_y = randomize_velocity_dir(ball.initial_y_vel());
			}
			else if (pos.m_x > (640.0 - 16.0)) // screen width - sprite width
			{
				// Ball passed the ai paddle, reset it.
				pos.m_x = (640.0 / 2.0) - 16.0;
				pos.m_y = (480.0 / 2.0) - 16.0;

				ball.m_vel_x = randomize_velocity_dir(ball.initial_x_vel());
				ball.m_vel_y = randomize_velocity_dir(ball.initial_y_vel());
			}

			// Lock to screen.
			if (pos.m_y < 0.0)
			{
				// Reverse ball, "bouncing" it.
				pos.m_y = 0.0;
				ball.m_vel_y *= -1;
			}
			else if (pos.m_y > (480.0 - 16.0)) // screen height - sprite height
			{
				// Reverse ball, "bouncing" it.
				pos.m_y = (480.0 - 16.0);
				ball.m_vel_y *= -1;
			}
		});
	}
} // namespace ep