#ifndef MENU_H
#define MENU_H


#include "ResourceManager.h"
#include "Button.h"
#include "Game.h"

class Menu: public State
{
public:
	void Initialize(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	
private:
	sf::Text play, quit;
	ResourceManager rm;
	Button button;

};

#endif