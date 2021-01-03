///
/// AISystem.hpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_SYSTEMS_AISYSTEM_HPP_
#define ENTTPONG_SYSTEMS_AISYSTEM_HPP_

#include <entt/fwd.hpp>

namespace ep
{
	///
	/// This system will ensure the ai is always following the ball, by centering the ai paddle
	/// onto the ball.
	///
	class AISystem final
	{
	public:
		///
		/// Default constructor.
		///
		AISystem() = default;

		///
		/// Default destructor.
		///
		~AISystem() = default;

		///
		/// Process events and update entities accordingly.
		///
		/// \param time Update loop delta time.
		/// \param registry The registry to retrieve entities from.
		///
		void update(const double time, entt::registry& registry);
	};
} // namespace ep

#endif