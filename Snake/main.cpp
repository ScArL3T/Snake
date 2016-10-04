#include "StateManager.hpp"
#include "SplashScreen.h"

#include "MenuState.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "PauseState.hpp"

int main()
{
	// Splash
#ifdef _WIN32
	unsigned char opacity = 255;
	float duration = 1.5f;
	SplashScreen ss;
	ss.create(opacity, duration);
#endif

	sf::RenderWindow window;
	window.create({ 640, 480 }, "Snake", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	FontManager fontManager;
	fontManager.load(Fonts::ID::GUI, "data/font.ttf");

	SoundPlayer soundPlayer;
	soundPlayer.load();

	TextureManager textureManager;
	textureManager.load(Textures::ID::ButtonGreen, "data/button_green.png");
	textureManager.load(Textures::ID::ButtonRed, "data/button_red.png");
	textureManager.load(Textures::ID::Panel, "data/panel.png");

	Score score(fontManager.get(Fonts::ID::GUI));

	States::Context context(window, soundPlayer, fontManager, textureManager, score);
	StateManager manager(context);

	// Registering available states
	manager.registerState<MenuState>(States::ID::Menu);
	manager.registerState<GameState>(States::ID::Game);
	manager.registerState<GameOverState>(States::ID::GameOver);
	manager.registerState<PauseState>(States::ID::Pause);
	manager.pushState(States::ID::Menu);

	const sf::Time frameTime = sf::seconds(1.f / 30.f);
	sf::Clock clock;
	sf::Time passedTime = sf::Time::Zero;

	// Main loop
	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		passedTime += elapsedTime;
		
		// Event loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			manager.processEvents(event);
		}

		// Physics, logics etc
		while (passedTime > frameTime)
		{
			passedTime -= frameTime;
			manager.update(frameTime);

			if (manager.isEmpty())
				window.close();
		}

		// Rendering
		window.clear(sf::Color(210, 210, 210));
		manager.draw();
		window.display();
	}

	return 0;
}