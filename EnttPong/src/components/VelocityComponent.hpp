///
/// VelocityComponent.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_VELOCITYCOMPONENT_HPP_
#define ENTTPONG_VELOCITYCOMPONENT_HPP_

namespace ep
{
	///
	/// A component that describes the velocity of a moving object.
	///
	class VelocityComponent final
	{
	public:
		///
		/// Main Constructor.
		///
		/// \param velX The velocity to travel at on the x-axis.
		/// \param velY The velocity to travel at on the y-axis.
		///
		VelocityComponent(float velX, float velY);

		///
		/// Default destructor.
		///
		~VelocityComponent() = default;

		///
		/// Move assignment overload.
		///
		VelocityComponent& operator=(const VelocityComponent &);

	public:
		///
		/// x velocity.
		///
		float m_x;
		
		///
		/// y velocity.
		///
		float m_y;
	};
}

#endif