#include "Menu.h"

Menu::Menu(StateManager &stack, sf::RenderWindow &window)
	: State(stack, window)
{
	/*
	Initializam meniul:
	Font, text, imagini.
	*/
	//Font
	font.loadFromFile("data/font.ttf");

	//Initializam sf::Text play.
	play.setString("Play");
	play.setCharacterSize(50);
	play.setFont(font);
	play.setPosition(sf::Vector2f(window.getSize().x / 2 - play.getLocalBounds().width / 2, 180));
	
	//Initializam sf::Text quit.
	quit.setString("Quit");
	quit.setCharacterSize(50);
	quit.setFont(font);
	quit.setPosition(sf::Vector2f(window.getSize().x / 2 - quit.getLocalBounds().width / 2, 250));
}

Menu::~Menu()
{
}

void Menu::handleEvent(const sf::Event &event)
{

}

void Menu::update(sf::Time dt)
{
	/*
	Functia update.
	Play: setState(new Game());
	Exit: window.close(), quit_game = true (extern bool in States.h -> main.cpp)
	*/
	
	//Verificam daca a fost apasat un buton.
	if (button.TextPressed(quit))
	{
		getWindow().close();
	}

	if (button.TextPressed(play))
	{
		popState();
		pushState(States::ID::Game);
	}
	
	// Verificam daca mouse-ul se afla peste un buton
	if (button.Hover(getWindow(), quit))
	{
		quit.setColor(sf::Color::Red);
	}
	else quit.setColor(sf::Color::White);

	if (button.Hover(getWindow(), play))
	{
		play.setColor(sf::Color::Red);
	}
	else play.setColor(sf::Color::White);
}

void Menu::draw()
{
	/*
	Desenam pe ecran.
	*/
	getWindow().draw(play);
	getWindow().draw(quit);
}