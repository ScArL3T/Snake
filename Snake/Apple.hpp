#ifndef APPLE_HPP
#define APPLE_HPP

#include "Entity.hpp"
#include <random>
#include <ctime>

class Apple final : public Entity
{
public:
	Apple();

	void handleEvent(const sf::Event &event) override;
	void update(sf::Time dt) override;

	void setPosition(const sf::Vector2f &pos);

	const sf::RectangleShape &getApple() const;
	sf::Vector2f reset();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::RectangleShape apple;

	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> distributionx;
	std::uniform_int_distribution<int> distributiony;
};

#endif