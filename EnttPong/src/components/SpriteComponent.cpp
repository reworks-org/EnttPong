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
	SpriteComponent::SpriteComponent(int w, int h, SDL_Colour col)
		:m_width(w), m_height(h), m_colour(col)
	{
	}

	SpriteComponent& SpriteComponent::operator=(const SpriteComponent &)
	{
		return *this;
	}
}