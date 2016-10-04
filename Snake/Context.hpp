#pragma once

#include <SFML/Graphics.hpp>

#include "SoundPlayer.hpp"
#include "ResourcesID.hpp"
#include "Score.hpp"

namespace States
{
	class Context
	{
	public:
		explicit Context(sf::RenderWindow &window
						, SoundPlayer &soundPlayer
						, FontManager &fontManager
						, TextureManager &textureManager
						, Score &score)
			: window(&window)
			, soundPlayer(&soundPlayer)
			, fontManager(&fontManager)
			, textureManager(&textureManager)
			, score(&score)
		{};

		sf::RenderWindow *window;
		SoundPlayer *soundPlayer;
		FontManager *fontManager;
		TextureManager *textureManager;
		Score *score;
	};
}