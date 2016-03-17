#include "GameOver.h"
#include "Menu.h"


GameOver::GameOver(StateManager &stack, sf::RenderWindow &window)
	: State(stack, window)
{
	font.loadFromFile("data/font.ttf");
	music.openFromFile("data/gameover.ogg");

	music.play();

	gameover.setString("GAME OVER");
	gameover.setColor(sf::Color::Red);
	gameover.setCharacterSize(100);
	gameover.setFont(font);
	gameover.setPosition(sf::Vector2f(window.getSize().x / 2 - gameover.getLocalBounds().width / 2,
		window.getSize().y / 2 - gameover.getLocalBounds().height / 2));

	enter.setString("ENTER Menu");
	enter.setCharacterSize(30);
	enter.setFont(font);
	enter.setPosition(sf::Vector2f(window.getSize().x / 2 - enter.getLocalBounds().width / 2,
		window.getSize().y / 2 + enter.getLocalBounds().height));
}

GameOver::~GameOver()
{

}

void GameOver::handleEvent(const sf::Event &event)
{

}

void GameOver::update(sf::Time dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		popState();
		pushState(States::ID::Menu);
	}
}

void GameOver::draw()
{
	getWindow().draw(gameover);
	getWindow().draw(enter);
}