///
/// main.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "core/Game.hpp"
#include "core/BasicLog.hpp"

///
/// Entry Point.
///
int main(int argsc, char *argsv[])
{
	auto success = EXIT_FAILURE;
	
	// This will allow us to catch and log any exceptions thrown.
	try
	{
		ep::Game pong("Entt Pong", 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_ALLOW_HIGHDPI);
		success = pong.run();
	}
	catch(const std::exception& e)
	{
		LOG_ERROR << "Exception: " << e.what() << FLUSH_LOG;
	}
	catch (...)
	{
		LOG_ERROR << "Threw an unknown exception. Please derive from std::exception." << FLUSH_LOG;
	}

	return success;
}