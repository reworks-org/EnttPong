///
/// PositionComponent.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_POSITIONCOMPONENT_HPP_
#define ENTTPONG_POSITIONCOMPONENT_HPP_

namespace ep
{
	///
	/// A component that describes the position of something on the screen.
	///
	class PositionComponent final
	{
	public:
		///
		/// Main Constructor.
		///
		/// \param initialX The starting x-pos on screen.
		/// \param initialY The starting y-pos on screen.
		///
		PositionComponent(int initialX, int initialY);

		///
		/// Default destructor.
		///
		~PositionComponent() = default;

		///
		/// Move assignment overload.
		///
		PositionComponent& operator=(const PositionComponent &);

	public:
		///
		/// x pos on screen.
		///
		int m_x;
		
		///
		/// y pos on screen.
		///
		int m_y;
	};
}

#endif