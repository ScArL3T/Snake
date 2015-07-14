#include "Game.h"
#include "Menu.h"

void Game::Initialize(sf::RenderWindow &window)
{
	/*
	Initializam jocul:
	Font, text, imagini
	Animatii
	Sprites
	*/
	rm.LoadFont(1, "data/font.ttf");
	rm.LoadSound(1, "data/eat.ogg");

	score.score.setFont(rm.FontHold[1]);

	pausedText.setString("PAUSE");
	pausedText.setCharacterSize(50);
	pausedText.setFont(rm.FontHold[1]);
	pausedText.setPosition(sf::Vector2f(window.getSize().x / 2 - pausedText.getLocalBounds().width / 2,
		window.getSize().y / 2 - pausedText.getLocalBounds().height / 2));

	enterText.setString("ENTER Menu");
	enterText.setCharacterSize(15);
	enterText.setFont(rm.FontHold[1]);
	enterText.setPosition(sf::Vector2f(window.getSize().x - enterText.getLocalBounds().width - 20,
		window.getSize().y - enterText.getLocalBounds().height));

	escText.setString("ESC Resume");
	escText.setCharacterSize(15);
	escText.setFont(rm.FontHold[1]);
	escText.setPosition(sf::Vector2f(20, window.getSize().y - escText.getLocalBounds().height));

	bg.setPosition({ 0, 0 });
	bg.setSize({ 640, 480});
	bg.setFillColor(sf::Color(0, 0, 0, 200));

	paused = false;
	enterKey = false;
	spawned = false;
}

void Game::Draw(sf::RenderWindow &window)
{
	/*
	Desenam pe ecran.
	*/
	
	AO.Draw(window);
	SO.Draw(window);
	score.Draw(window);
	if (paused)
	{
		window.draw(bg);
		window.draw(pausedText);
		window.draw(enterText);
		window.draw(escText);
	}
}

void Game::Update(sf::RenderWindow &window)
{
	/*
	Functia update.
	Pause: setState(new Menu());
	Exit: window.close(), quit_game = true (extern bool in States.h -> main.cpp)
	*/
	
	//Daca ESC este apasat -> pause.
	if (paused)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !enterKey)
		{	
			paused = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			rm.SoundBufferHold.release(1);
			rm.SoundHold.clear();
			rm.FontHold.release(1);
			engine.SetState(new Menu());
		}
	}
	else
	{
		SO.Update(window);
		score.Update();

		//Resetam marul
		if (SO.Collide(AO.apple, SO.snake[0]))
		{
			rm.SoundHold[0].play();
			SO.Add();
			score.Increment();

			while (SO.Collide(AO.apple, SO.snake))
			{
				newpos = AO.Reset();
				AO.apple.setPosition(newpos);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !enterKey)
		{
			paused = true;
		}
	}

	enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}