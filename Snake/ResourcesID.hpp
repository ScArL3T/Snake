#ifndef RESOURCESID_HPP
#define RESOURCESID_HPP

#include "ResourceManager.hpp"

namespace Fonts
{
	enum class ID
	{
		GUI
	};
}

namespace SoundEffects
{
	enum class ID
	{
		ButtonHover,
		ButtonClick,
		EatApple
	};
}

namespace Textures
{
	enum class ID
	{
		ButtonGreen,
		ButtonRed,
		Panel
	};
}

namespace sf
{
	class Font;
	class SoundBuffer;
	class Texture;
}

using FontManager = ResourceManager<sf::Font, Fonts::ID>;
using SoundBufferManager = ResourceManager<sf::SoundBuffer, SoundEffects::ID>;
using TextureManager = ResourceManager<sf::Texture, Textures::ID>;

#endif