#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "State.h"

class GameObject : public sf::Sprite
{
public:
	virtual void update(sf::RenderWindow &window) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
};

#endif

