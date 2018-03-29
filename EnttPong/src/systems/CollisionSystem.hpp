///
/// CollisionSystem.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_COLLISIONSYSTEM_HPP_
#define ENTTPONG_COLLISIONSYSTEM_HPP_

#include "../libs/entt/entity/registry.hpp"

namespace ep
{
	///
	/// This system will ensure the ai is always following the ball, by centering the ai paddle
	/// onto the ball.
	///
	class CollisionSystem
	{
	public:
		///
		/// Default Constructor.
		///
		CollisionSystem() = default;

		///
		/// Default Destructor.
		///
		~CollisionSystem() = default;

		///
		/// Process events and update entities accordingly.
		///
		/// \param time DeltaTime or something similar from fixed-timestep gameloop.
		/// \param registry The registry to retrieve entities from.
		///
		void update(double time, entt::DefaultRegistry& registry);
	};
}

#endif