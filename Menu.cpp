#include "Menu.h"


void Menu::Initialize(sf::RenderWindow &window)
{
	/*
	Initializam meniul:
	Font, text, imagini.
	*/
	//Font
	rm.LoadFont(1, "data/font.ttf");

	//Initializam sf::Text play.
	play.setString("Play");
	play.setCharacterSize(50);
	play.setFont(rm.FontHold[1]);
	play.setPosition(sf::Vector2f(window.getSize().x / 2 - play.getLocalBounds().width / 2, 180));
	
	//Initializam sf::Text quit.
	quit.setString("Quit");
	quit.setCharacterSize(50);
	quit.setFont(rm.FontHold[1]);
	quit.setPosition(sf::Vector2f(window.getSize().x / 2 - quit.getLocalBounds().width / 2, 250));
}

void Menu::Draw(sf::RenderWindow &window)
{
	/*
	Desenam pe ecran.
	*/
	window.draw(play);
	window.draw(quit);

	//Butonul pentru quit.
	if (button.Hover(window, quit) == true)
	{
		quit.setColor(sf::Color::Red);
	}
	else quit.setColor(sf::Color::White);

	//Butonul pentru play.
	if (button.Hover(window, play) == true)
	{
		play.setColor(sf::Color::Red);
	}
	else play.setColor(sf::Color::White);
}

void Menu::Update(sf::RenderWindow &window)
{
	/*
	Functia update.
	Play: setState(new Game());
	Exit: window.close(), quit_game = true (extern bool in States.h -> main.cpp)
	*/

	//Verificam daca a fost apasat un buton.
	if (button.TextPressed(quit) == true)
	{
		window.close();
	}
	
	if (button.TextPressed(play) == true)
	{
		rm.FontHold.release(1);
		engine.SetState(new Game());
	}
}