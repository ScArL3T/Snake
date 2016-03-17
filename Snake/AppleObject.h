#ifndef APPLEOBJECT_H
#define APPLEOBJECT_H

#include "GameObject.h"
#include "SnakeObject.h"
#include <random>
#include <ctime>


class AppleObject : public GameObject
{
public:
	AppleObject();
	~AppleObject();

	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	sf::Vector2f reset();
	void setPosition(sf::Vector2f newpos);

	sf::RectangleShape apple;
private:
	//std::default_random_engine generator;
	std::minstd_rand0 generator;

	//std::uniform_int_distribution<int> distribution; moved in cpp
	int posx, posy;
	sf::Texture texture;
};

#endif