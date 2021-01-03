///
/// main.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include <ctime>
#include <iostream>

#include "core/Game.hpp"

int main(int argsc, char* argsv[])
{
	// Seeds RNG.
	std::srand(std::time(nullptr));

	try
	{
		ep::Game pong("Entt Pong", 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_ALLOW_HIGHDPI);
		return pong.run();
	}
	catch (const std::exception& e)
	{
		// Error message printed to console, dont need to reprint exception,
		// just wait for player input.

		std::cin.get();
		return EXIT_FAILURE;
	}
	catch (...)
	{
		// Error message printed to console, dont need to reprint exception,
		// just wait for player input.

		std::cin.get();
		return EXIT_FAILURE;
	}
}