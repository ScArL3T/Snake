#ifndef APPLEOBJECT_H
#define APPLEOJECT_H

#include "GameObject.h"
#include "SnakeObject.h"
#include <random>
#include <ctime>


class AppleObject: public GameObject
{
public:
	AppleObject();
	~AppleObject();

	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	sf::Vector2f Reset();
	void SetPos(sf::Vector2f newpos);

	sf::RectangleShape apple;
private:
	//std::default_random_engine generator;
	std::minstd_rand0 generator;

	//std::uniform_int_distribution<int> distribution; moved in cpp
	ResourceManager rm;
	int posx, posy;
};

#endif