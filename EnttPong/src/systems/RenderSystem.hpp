///
/// RenderSystem.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_RENDERSYSTEM_HPP_
#define ENTTPONG_RENDERSYSTEM_HPP_

#include "../graphics/Window.hpp"
#include "../libs/entt/entity/registry.hpp"

namespace ep
{
	///
	/// This class will take data from the appropriate components
	/// and render them to the screen.
	///
	class RenderSystem
	{
	public:
		///
		/// Default Constructor.
		///
		RenderSystem() = default;

		///
		/// Default Destructor.
		///
		~RenderSystem() = default;

		///
		/// Renders the entities.
		///
		/// \param window The Window to render to.
		/// \param registry The registry to retrieve entities from.
		///
		void render(Window* window, entt::DefaultRegistry& registry);
	};
}

#endif