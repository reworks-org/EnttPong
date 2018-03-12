///
/// Game.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_GAME_HPP_
#define ENTTPONG_GAME_HPP_

#include "../systems/RenderSystem.hpp"

namespace ep
{
	///
	/// This class will manage our game data and game loop.
	///
	class Game
	{
	public:
		///
		/// Main constructor.
		///
		/// \param title Title of the window.
		/// \param w Width of the window.
		/// \param h Height of the window.
		/// \param flags SDL2 Window flags.
		///
		Game(const std::string& title, int w, int h, Uint32 flags);

		///
		/// Default destructor.
		///
		~Game() = default;

		///
		/// Run the game loop.
		///
		int run();

	private:
		///
		/// Recieve and process game events.
		///
		void event();

		///
		/// Process game data.
		///
		void update();

		///
		/// Render everything to the window.
		///
		void render();

	private:
		///
		/// Our main window.
		///
		Window m_window;

		///
		/// The default entt registry to hold and manage our entities.
		///
		entt::DefaultRegistry m_registry;

		///
		/// Our RenderSystem
		///
		RenderSystem m_renderSystem;
	};
}

#endif