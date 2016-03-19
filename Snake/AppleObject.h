#ifndef APPLEOBJECT_H
#define APPLEOBJECT_H

#include "GameObject.h"
#include <random>
#include <ctime>

class AppleObject : public GameObject
{
public:
	AppleObject();
	~AppleObject();

	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setPosition(sf::Vector2f newpos);

	sf::RectangleShape &getApple();
	sf::Vector2f reset();

private:
	sf::RectangleShape apple;
	//std::default_random_engine generator;
	std::minstd_rand0 generator;
};

#endif