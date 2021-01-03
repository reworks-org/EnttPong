///
/// Sprite.cpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#include "Sprite.hpp"

namespace ep
{
	Sprite::Sprite(const int w, const int h, SDL_Colour col) noexcept
	    : m_width {w}, m_height {h}, m_colour {col}, m_radius {0}
	{
	}

	Sprite::Sprite(const int radius, SDL_Colour col) noexcept
	    : m_radius {radius}, m_colour {col}, m_width {0}, m_height {0}
	{
	}

	Sprite::Sprite(Sprite&& s) noexcept
	{
		this->m_colour = s.m_colour;
		this->m_height = s.m_height;
		this->m_radius = s.m_radius;
		this->m_width  = s.m_width;
	}

	Sprite& Sprite::operator=(Sprite&& s) noexcept
	{
		if (this != &s)
		{
			this->m_colour = s.m_colour;
			this->m_height = s.m_height;
			this->m_radius = s.m_radius;
			this->m_width  = s.m_width;
		}

		return *this;
	}
} // namespace ep