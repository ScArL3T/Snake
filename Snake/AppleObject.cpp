#include "AppleObject.h"

std::uniform_int_distribution<int> distributionx(3, 31);
std::uniform_int_distribution<int> distributiony(2, 23);

AppleObject::AppleObject()
{
	texture.loadFromFile("data/apple.png");
	apple.setTexture(&texture);
	apple.setSize(sf::Vector2f(SNAKE_WIDTH, SNAKE_HEIGHT));

	generator.seed(time(0));
	posx = distributionx(generator);
	posy = distributiony(generator);

	apple.setPosition(sf::Vector2f(posx*SNAKE_WIDTH, posy*SNAKE_HEIGHT));
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

sf::Vector2f AppleObject::reset()
{
	generator.seed(time(0));
	int posx = distributionx(generator);
	int posy = distributiony(generator);

	return sf::Vector2f(posx*SNAKE_WIDTH, posy*SNAKE_HEIGHT);
}

void AppleObject::setPosition(sf::Vector2f newpos)
{
	apple.setPosition(newpos);
}

