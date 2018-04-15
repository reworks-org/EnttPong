///
/// Window.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "../core/BasicLog.hpp"

#include "Window.hpp"

namespace ep
{
	Window::Window(const std::string& title, int w, int h, Uint32 flags)
		:m_isOpen(true), m_window(nullptr), m_renderer(nullptr)
	{
		// Here the window and renderer are being created.
		// If they fail to create, we throw an exception to be caught in main.cpp
		
		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);

		if (!m_window)
		{
			std::string message = "Window failed to be created! SDL: ";
			message += SDL_GetError();
			throw std::runtime_error(message);
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (!m_renderer)
		{
			std::string message = "Renderer failed to be created! SDL: ";
			message += SDL_GetError();
			throw std::runtime_error(message);
		}
	}

	Window::~Window()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
	}

	SDL_Renderer* Window::getRenderer() const noexcept
	{
		return m_renderer;
	}
}