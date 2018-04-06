///
/// main.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include <ctime>
#include <SDL2/SDL.h>

#include "core/Game.hpp"
#include "core/BasicLog.hpp"

///
/// Entry Point.
///
int main(int argsc, char *argsv[])
{
	std::srand(std::time(nullptr)); // set random seed

	auto success = EXIT_FAILURE;
	
	// This will allow us to catch and log any exceptions thrown.
	try
	{
		// Init SDL2.
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		{
			std::string message = "Failed to init SDL2! Error: " + std::string(SDL_GetError());
			throw std::runtime_error(message);
		}
		
		ep::Game pong("Entt Pong", 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_ALLOW_HIGHDPI);
		success = pong.run();

		SDL_Quit();
	}
	catch(const std::exception& e)
	{
		LOG_ERROR << "Exception: " << e.what() << FLUSH_LOG;
		std::cin.get();
	}
	catch (...)
	{
		LOG_ERROR << "Threw an unknown exception. Please derive from std::exception." << FLUSH_LOG;
		std::cin.get();
	}

	return success;
}