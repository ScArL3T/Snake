#ifndef BUTTON_H
#define BUTTON_H

#include "State.h"

class Button
{
public:
	//Button(sf::RenderWindow &window, sf::Text text, sf::Color color);
	//Button(sf::RenderWindow &window, sf::Image image1, sf::Image image2);
	Button();
	~Button();

	bool TextPressed(sf::Text text);
	bool SpritePressed(sf::RenderWindow &window, sf::Sprite sprite);
	bool Hover(sf::RenderWindow &window, sf::Text text);
	bool Hover(sf::RenderWindow &window, sf::Sprite sprite);
private:
	
	sf::Vector2i mouse_pos;
	int startposX, startposY, width, height;
};

#endif