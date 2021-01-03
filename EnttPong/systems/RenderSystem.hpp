///
/// RenderSystem.hpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_SYSTEMS_RENDERSYSTEM_HPP_
#define ENTTPONG_SYSTEMS_RENDERSYSTEM_HPP_

#include <entt/fwd.hpp>

#include "../core/Window.hpp"

namespace ep
{
	///
	/// This class will take data from the appropriate components
	/// and render them to the screen.
	///
	class RenderSystem final
	{
	public:
		///
		/// Default constructor.
		///
		RenderSystem() = default;

		///
		/// Default destructor.
		///
		~RenderSystem() = default;

		///
		/// Renders all entities.
		///
		/// \param window The Window to render to.
		/// \param registry The registry to retrieve entities from.
		///
		void render(Window& window, entt::registry& registry);
	};
} // namespace ep

#endif