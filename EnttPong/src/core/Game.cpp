///
/// Game.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include <cstdlib>
#include <SDL2/SDL_timer.h>

#include "../core/BasicLog.hpp"
#include "../components/SpriteComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/VelocityComponent.hpp"

#include "Game.hpp"

namespace ep
{
	Game::Game(const std::string& title, int w, int h, Uint32 flags)
		:m_window(title, w, h, flags)
	{
		auto player = m_registry.create();
		m_registry.assign<SpriteComponent>(player, 12, 96, SDL_Colour{ 255, 255, 255, 255 });
		m_registry.assign<PositionComponent>(player, 20, 20);

		auto ai = m_registry.create();
		m_registry.assign<SpriteComponent>(ai, 12, 96, SDL_Colour{ 255, 255, 255, 255 });
		m_registry.assign<PositionComponent>(ai, w - 30, 20);

		auto ball = m_registry.create();
		m_registry.assign<SpriteComponent>(ball, 16, SDL_Colour{ 255, 255, 255, 255 });
		m_registry.assign<PositionComponent>(ball, (w / 2) - 16, (h / 2) - 16);
		m_registry.assign<VelocityComponent>(ball, 2.0f, 1.0f);
	}

	int Game::run()
	{
		// This is a fixed-step gameloop.
		// See https://gafferongames.com/post/fix_your_timestep/
		// For an explanation.

		double time = 0;
		double accumulator = 0.0;
		const double deltaTime = 0.01;

		double currentTime = SDL_GetTicks();
		while (m_window.m_isOpen)
		{
			double newTime = SDL_GetTicks();
			double frameTime = newTime - currentTime;
			currentTime = newTime;

			accumulator += frameTime;

			while (accumulator >= deltaTime)
			{
				event();
				update();

				accumulator -= deltaTime;
				time += deltaTime;
			}

			render();

			LOG_INFO << "Time: " << time << "\n";
			LOG_INFO << "Aclr: " << accumulator << "\n";
		}

		return EXIT_SUCCESS;
	}

	void Game::event()
	{
		// Process game events
		while (SDL_PollEvent(&m_window.m_event) != 0)
		{
			switch (m_window.m_event.type)
			{
			case SDL_QUIT:
				m_window.m_isOpen = false;
				break;

			case SDL_KEYDOWN:
				switch (m_window.m_event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					m_window.m_isOpen = false;
					break;
				}
				break;
			}

			// Process system events.
			m_moveSystem.event(m_window.m_event, m_registry);
		}
	}

	void Game::update()
	{
		m_moveSystem.update();
	}

	void Game::render()
	{
		SDL_SetRenderDrawColor(m_window.getRenderer(), 0, 0, 0, 255);
		SDL_RenderClear(m_window.getRenderer());

		m_renderSystem.render(&m_window, m_registry);

		SDL_RenderPresent(m_window.getRenderer());
	}
}