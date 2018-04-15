///
/// AISystem.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_AISYSTEM_HPP_
#define ENTTPONG_AISYSTEM_HPP_

#include "../libs/entt/entity/registry.hpp"

namespace ep
{
	///
	/// This system will ensure the ai is always following the ball, by centering the ai paddle
	/// onto the ball.
	///
	class AISystem
	{
	public:
		///
		/// Default Constructor.
		///
		AISystem() = default;

		///
		/// Default Destructor.
		///
		~AISystem() = default;

		///
		/// Process events and update entities accordingly.
		///
		/// \param registry The registry to retrieve entities from.
		///
		void update(entt::DefaultRegistry& registry) noexcept;
	};
}

#endif