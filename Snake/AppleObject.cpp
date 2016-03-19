#include "AppleObject.h"

std::uniform_int_distribution<int> distributionx(3, 31);
std::uniform_int_distribution<int> distributiony(2, 23);

AppleObject::AppleObject()
{
	apple.setSize({20, 20});
	apple.setPosition(reset());
}

AppleObject::~AppleObject()
{
}

void AppleObject::update(sf::RenderWindow &window)
{
}

void AppleObject::draw(sf::RenderWindow &window)
{
	window.draw(apple);
}

void AppleObject::setPosition(sf::Vector2f newpos)
{
	apple.setPosition(newpos);
}

sf::RectangleShape &AppleObject::getApple()
{
	return apple;
}

sf::Vector2f AppleObject::reset()
{
	generator.seed(time(0));
	int posx = distributionx(generator);
	int posy = distributiony(generator);

	return sf::Vector2f(posx * 20, posy * 20);
}