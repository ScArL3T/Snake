#ifndef GAME_H
#define GAME_H

#include "States.h"
#include "AppleObject.h"
#include "Score.h"

class Game: public State
{
public:
	void Initialize(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
private:
	SnakeObject SO;
	AppleObject AO;
	ResourceManager rm;
	Score score;

	bool paused, enterKey, spawned;
	sf::Text pausedText;
	sf::Text enterText, escText;
	sf::RectangleShape bg;
	sf::Vector2f newpos;
};

#endif