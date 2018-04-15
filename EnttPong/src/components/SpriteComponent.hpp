///
/// SpriteComponent.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_SPRITECOMPONENT_HPP_
#define ENTTPONG_SPRITECOMPONENT_HPP_

#include <SDL2/SDL_rect.h>

namespace ep
{
	///
	/// A component that describes a sprite or texture.
	/// In this case our 'sprites' are coloured rectangles and circles.
	///
	class SpriteComponent final
	{
	public:
		///
		/// Rectangle Constructor.
		///
		/// \param w Width of the sprite.
		/// \param h Height of the sprite.
		/// \param col The colour you want the sprite to be (RGBA, 0 - 255).
		///
		SpriteComponent(int w, int h, SDL_Colour col) noexcept;

		///
		/// Circle Constructor.
		///
		/// \param radius Radius of the circle to draw.
		/// \param col The colour you want the sprite to be (RGBA, 0 - 255).
		///
		SpriteComponent(int radius, SDL_Colour col) noexcept;

		///
		/// Default destructor.
		///
		~SpriteComponent() = default;

		///
		/// Move assignment overload.
		///
		SpriteComponent& operator=(const SpriteComponent &) noexcept;

	public:
		///
		/// Stores how wide the rectangle is.
		///
		int m_width;
		
		///
		/// Stores how high the rectangle is.
		///
		int m_height;
		
		///
		/// Stores the radius of a circle.
		///
		int m_radius;

		///
		/// Stores the colour of the sprite.
		///
		SDL_Colour m_colour;
	};
}

#endif