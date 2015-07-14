#include "AppleObject.h"

std::uniform_int_distribution<int> distributionx(3, 31);
std::uniform_int_distribution<int> distributiony(2, 23);

AppleObject::AppleObject()
{
	rm.LoadTexture(3, "data/apple.png");
	apple.setTexture(&rm.TextureHold[3]);
	apple.setSize(sf::Vector2f(SNAKE_WIDTH, SNAKE_HEIGHT));

	generator.seed(time(0));
	posx = distributionx(generator);
	posy = distributiony(generator);

	apple.setPosition(sf::Vector2f(posx*SNAKE_WIDTH, posy*SNAKE_HEIGHT));
}

AppleObject::~AppleObject()
{
}

void AppleObject::Update(sf::RenderWindow &window)
{
}

void AppleObject::Draw(sf::RenderWindow &window)
{
	window.draw(apple);
}

sf::Vector2f AppleObject::Reset()
{
	generator.seed(time(0));
	int posx = distributionx(generator);
	int posy = distributiony(generator);

	return sf::Vector2f(posx*SNAKE_WIDTH, posy*SNAKE_HEIGHT);
}

void AppleObject::SetPos(sf::Vector2f newpos)
{
	apple.setPosition(newpos);
}

