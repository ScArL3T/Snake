#include "Apple.hpp"

Apple::Apple()
	: mt()
	, distributionx(0, 31)
	, distributiony(1, 23)
{
	apple.setPosition({20, 40});
	apple.setSize({20, 20});
	apple.setFillColor(sf::Color(255, 51, 51));

	mt.seed(rd());
}

void Apple::handleEvent(const sf::Event &event)
{
}

void Apple::update(sf::Time dt)
{
}

void Apple::setPosition(const sf::Vector2f &pos)
{
	apple.setPosition(pos);
}

const sf::RectangleShape &Apple::getApple() const
{
	return apple;
}

sf::Vector2f Apple::reset()
{
	int posx = distributionx(mt);
	int posy = distributiony(mt);
	sf::Vector2f newPos(static_cast<float>(posx * 20), static_cast<float>(posy * 20));

	return newPos;
}

void Apple::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//states.transform *= getTransform();
	target.draw(apple, states);
}
