#include "Button.h"

//thor::Action mouseClick(sf::Mouse::Button::Left, thor::Action::ReleaseOnce);

Button::Button()
{
	//map["click"] = mouseClick;
}

Button::~Button()
{
}

//Verificam daca mouse-ul se afla peste text.
bool Button::Hover(sf::RenderWindow &window, sf::Text text)
{
	mouse_pos = sf::Mouse::getPosition(window);
	startposX = text.getPosition().x;
	startposY = text.getPosition().y - 20; //Daca inaltimea nu e buna => -20
	width = text.getLocalBounds().width;
	height = text.getLocalBounds().height;

	if (mouse_pos.x >= startposX && mouse_pos.x <= startposX + width 
		&& mouse_pos.y >= startposY && mouse_pos.y <= startposY + height)
	{
		return true;
	}
	return false;
}

//Verificam daca textul a fost apasat.
bool Button::TextPressed(sf::Text text)
{
	if (text.getColor() == sf::Color::Red && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		return true;
	}
	return false;
}

//Verificam daca mouse-ul se afla peste sprite
bool Button::Hover(sf::RenderWindow &window, sf::Sprite sprite)
{
	mouse_pos = sf::Mouse::getPosition(window);
	startposX = sprite.getPosition().x;
	startposY = sprite.getPosition().y - 20; //Daca inaltimea nu e buna => -20
	width = sprite.getLocalBounds().width;
	height = sprite.getLocalBounds().height;

	if (mouse_pos.x >= startposX && mouse_pos.x <= startposX + width
		&& mouse_pos.y >= startposY && mouse_pos.y <= startposY + height)
	{
		return true;
	}
	return false;
}
//Verificam daca sprite-ul a fost apasat.
bool Button::SpritePressed(sf::RenderWindow &window, sf::Sprite sprite)
{
	if (Hover(window, sprite) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		return true;
	}
	return false;
}