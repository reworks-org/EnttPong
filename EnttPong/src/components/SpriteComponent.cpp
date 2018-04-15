///
/// SpriteComponent.cpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include "SpriteComponent.hpp"

namespace ep
{
	SpriteComponent::SpriteComponent(int w, int h, SDL_Colour col) noexcept
		:m_width(w), m_height(h), m_colour(col), m_radius(0)
	{
	}

	SpriteComponent::SpriteComponent(int radius, SDL_Colour col) noexcept
		:m_radius(radius), m_colour(col), m_width(0), m_height(0)
	{
	}

	SpriteComponent& SpriteComponent::operator=(const SpriteComponent &) noexcept
	{
		return *this;
	}
}