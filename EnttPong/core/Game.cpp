///
/// Game.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include <SDL.h>

#include "../components/All.hpp"

#include "../Log.hpp"

#include "Game.hpp"

namespace ep
{
	Game::Game(std::string_view title, const int w, const int h, std::uint32_t flags)
	    : m_window {}
	{
		// Setup SDL2 and stuff.
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		{
			throw_sdl2_exception("Failed to init SDL2.");
		}

		m_window.create(title, w, h, flags);

		// Here, we are creating the entities using EnTT and attaching the relevant components and tags.
		// We can invoke the constructor of the component or tag in the assign() and attach() methods of the registry.

		const auto player_paddle = m_registry.create();
		const auto ai_paddle     = m_registry.create();
		const auto ball          = m_registry.create();

		// Assign component data to entitys.
		m_registry.emplace<Sprite>(player_paddle, 12, 96, SDL_Colour {255, 255, 255, 255});
		m_registry.emplace<Position>(player_paddle, 20.0, 20.0);
		m_registry.emplace<Player>(player_paddle);

		m_registry.emplace<Sprite>(ai_paddle, 12, 96, SDL_Colour {255, 255, 255, 255});
		m_registry.emplace<Position>(ai_paddle, w - 30.0, 20.0);
		m_registry.emplace<AI>(ai_paddle, w - 30.0, 20.0);

		m_registry.emplace<Sprite>(ball, 8, SDL_Colour {255, 255, 255, 255});
		m_registry.emplace<Position>(ball, (w / 2.0) - 16.0, (h / 2.0) - 16.0);
		m_registry.emplace<Ball>(ball, 0.12, 0.12);

		// Assign events to systems.
		m_dispatcher.sink<KeyDown>().connect<&MoveSystem::on_key_down>(m_move_system);
		m_dispatcher.sink<KeyUp>().connect<&MoveSystem::on_key_up>(m_move_system);

		// Assign events to window.
		m_dispatcher.sink<KeyDown>().connect<&Window::on_key_down>(m_window);

		// Set up collideables
		m_collideables.ai        = ai_paddle;
		m_collideables.player    = player_paddle;
		m_collideables.ball      = ball;
		m_collideables.registery = &m_registry;
	}

	Game::~Game() noexcept
	{
		SDL_Quit();
	}

	const int Game::run()
	{
		// 60 updates per second. We divide 1000 by 60 instead of 1 because sdl operates on milliseconds
		// not nanoseconds.
		const constexpr double dt = 1000.0 / 60.0;

		// This is a fixed-step gameloop.
		// See https://gafferongames.com/post/fix_your_timestep/
		// For an explanation.
		double time         = 0.0;
		double accumulator  = 0.0;
		double current_time = SDL_GetTicks();
		double new_time     = 0.0;
		double frame_time   = 0.0;

		while (m_window.is_open())
		{
			new_time     = SDL_GetTicks();
			frame_time   = new_time - current_time;
			current_time = new_time;

			accumulator += frame_time;

			events();

			while (accumulator >= dt)
			{
				update(accumulator);

				accumulator -= dt;
				time += dt;
			}

			render();
		}

		return EXIT_SUCCESS;
	}

	void Game::events()
	{
		// Process all user and system events.
		while (SDL_PollEvent(&m_window.m_event) != 0)
		{
			switch (m_window.m_event.type)
			{
				case SDL_QUIT:
					m_window.close();
					break;

				case SDL_KEYDOWN:
					m_dispatcher.trigger<KeyDown>(m_window.m_event.key.keysym.sym);
					break;

				case SDL_KEYUP:
					m_dispatcher.trigger<KeyUp>(m_window.m_event.key.keysym.sym);
					break;
			}
		}
	}

	void Game::update(const double time)
	{
		m_move_system.update(time, m_registry);
		m_ai_system.update(time, m_registry);
		m_collision_system.update(time, m_collideables);
	}

	void Game::render()
	{
		// Flush renderer.
		SDL_SetRenderDrawColor(m_window.renderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(m_window.renderer());

		m_render_system.render(m_window, m_registry);

		// Draw everything.
		SDL_RenderPresent(m_window.renderer());
	}
} // namespace ep