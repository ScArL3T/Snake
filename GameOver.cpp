#include "GameOver.h"
#include "Menu.h"


void GameOver::Initialize(sf::RenderWindow &window)
{
	rm.LoadFont(1, "data/font.ttf");
	rm.LoadSound(1, "data/gameover.ogg");

	rm.SoundHold[0].play();

	gameover.setString("GAME OVER");
	gameover.setColor(sf::Color::Red);
	gameover.setCharacterSize(100);
	gameover.setFont(rm.FontHold[1]);
	gameover.setPosition(sf::Vector2f(window.getSize().x / 2 - gameover.getLocalBounds().width / 2,
		window.getSize().y / 2 - gameover.getLocalBounds().height / 2));

	enter.setString("ENTER Menu");
	enter.setCharacterSize(30);
	enter.setFont(rm.FontHold[1]);
	enter.setPosition(sf::Vector2f(window.getSize().x / 2 - enter.getLocalBounds().width / 2,
		window.getSize().y / 2 + enter.getLocalBounds().height));
}

void GameOver::Update(sf::RenderWindow &window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		rm.SoundBufferHold.release(1);
		rm.SoundHold.clear();
		rm.FontHold.release(1);
		engine.SetState(new Menu());
	}
}

void GameOver::Draw(sf::RenderWindow &window)
{
	window.draw(gameover);
	window.draw(enter);
}