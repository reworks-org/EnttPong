///
/// MoveSystem.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_MOVESYSTEM_HPP_
#define ENTTPONG_MOVESYSTEM_HPP_

#include <SDL2/SDL_events.h>

#include "../libs/entt/entity/registry.hpp"

namespace ep
{
	///
	/// This class will take data from the appropriate components
	/// and update the position based on input.
	///
	class MoveSystem
	{
	public:
		///
		/// Default Constructor.
		///
		MoveSystem() = default;

		///
		/// Default Destructor.
		///
		~MoveSystem() = default;

		///
		/// Process user input.
		///
		/// \param event Structure containing event data.
		/// \param registry The registry to retrieve entities from.
		///
		void event(SDL_Event& event, entt::DefaultRegistry& registry);

		///
		/// Process events and update entities accordingly.
		///
		/// \param registry The registry to retrieve entities from.
		///
		void update(entt::DefaultRegistry& registry);

	private:
		///
		/// Is the player moving north?
		///
		bool m_movingNorth = false;

		///
		///
		/// Is the player moving south?
		///
		bool m_movingSouth = false;
	};
}

#endif