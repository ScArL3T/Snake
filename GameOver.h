#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "States.h"
#include "ResourceManager.h"
#include "Score.h"
#include <iostream>

class GameOver: public State
{
public:
	void Initialize(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);

private:
	sf::Text gameover, enter;
	ResourceManager rm;
};

#endif