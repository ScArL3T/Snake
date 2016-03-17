#include "Game.h"
#include "Menu.h"

Game::Game(StateManager &stack, sf::RenderWindow &window)
	: State(stack, window)
{
	/*
	Initializam jocul:
	Font, text, imagini
	Animatii
	Sprites
	*/
	font.loadFromFile("data/font.ttf");
	buffer.loadFromFile("data/eat.ogg");
	sound.setBuffer(buffer);

	score.score.setFont(font);

	pausedText.setString("PAUSE");
	pausedText.setCharacterSize(50);
	pausedText.setFont(font);
	pausedText.setPosition(sf::Vector2f(window.getSize().x / 2 - pausedText.getLocalBounds().width / 2,
		window.getSize().y / 2 - pausedText.getLocalBounds().height / 2));

	enterText.setString("ENTER Menu");
	enterText.setCharacterSize(15);
	enterText.setFont(font);
	enterText.setPosition(sf::Vector2f(window.getSize().x - enterText.getLocalBounds().width - 20,
		window.getSize().y - enterText.getLocalBounds().height));

	escText.setString("ESC Resume");
	escText.setCharacterSize(15);
	escText.setFont(font);
	escText.setPosition(sf::Vector2f(20, window.getSize().y - escText.getLocalBounds().height));

	bg.setPosition({ 0, 0 });
	bg.setSize({ 640, 480});
	bg.setFillColor(sf::Color(0, 0, 0, 200));

	paused = false;
	enterKey = false;
	spawned = false;
}

Game::~Game()
{

}

void Game::handleEvent(const sf::Event &event)
{

}

void Game::draw()
{
	/*
	Desenam pe ecran.
	*/
	
	AO.draw(getWindow());
	SO.draw(getWindow());
	score.draw(getWindow());
	if (paused)
	{
		getWindow().draw(bg);
		getWindow().draw(pausedText);
		getWindow().draw(enterText);
		getWindow().draw(escText);
	}
}

void Game::update(sf::Time dt)
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
			popState();
			pushState(States::ID::Menu);
		}
	}
	else
	{
		SO.update(getWindow());
		score.update();

		if (SO.gameOver(getWindow()))
		{
			popState();
			pushState(States::ID::GameOver);
		}

		//Resetam marul
		if (SO.selfCollide(AO.apple))//, SO.snake[0]))
		{
			sound.play();
			SO.add();
			score.Increment();

			while (SO.appleCollide(AO.apple))
			{
				newpos = AO.reset();
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