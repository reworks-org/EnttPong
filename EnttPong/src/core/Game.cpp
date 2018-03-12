///
/// Game.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include <cstdlib>
#include <SDL2/SDL_timer.h>

#include "Game.hpp"

namespace ep
{
	Game::Game(const std::string& title, int w, int h, Uint32 flags)
		:m_window(title, w, h, flags)
	{
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
		}

		return EXIT_SUCCESS;
	}

	void Game::event()
	{
		while (SDL_PollEvent(&m_window.m_event) != 0)
		{
			switch (m_window.m_event.type)
			{
			case SDL_QUIT:
				m_window.m_isOpen = false;
				break;
			}
		}
	}

	void Game::update()
	{
	}

	void Game::render()
	{
		SDL_RenderClear(m_window.getRenderer());

		SDL_RenderPresent(m_window.getRenderer());
	}
}