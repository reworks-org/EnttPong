///
/// Sprite.hpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_COMPONENTS_SPRITE_HPP_
#define ENTTPONG_COMPONENTS_SPRITE_HPP_

#include <SDL_pixels.h>

namespace ep
{
	///
	/// A component that describes a sprite or texture.
	/// In this case our 'sprites' are coloured rectangles and circles.
	///
	class Sprite final
	{
	public:
		///
		/// Rectangle Constructor.
		///
		/// \param w Width of the sprite.
		/// \param h Height of the sprite.
		/// \param col The colour you want the sprite to be (RGBA, 0 - 255).
		///
		Sprite(const int w, const int h, SDL_Colour col) noexcept;

		///
		/// Circle Constructor.
		///
		/// \param radius Radius of the circle to draw.
		/// \param col The colour you want the sprite to be (RGBA, 0 - 255).
		///
		Sprite(const int radius, SDL_Colour col) noexcept;

		///
		/// Move constructor.
		///
		Sprite(Sprite&&) noexcept;

		///
		/// Default destructor.
		///
		~Sprite() noexcept = default;

		///
		/// Move assignment overload.
		///
		Sprite& operator=(Sprite&&) noexcept;

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
} // namespace ep

#endif