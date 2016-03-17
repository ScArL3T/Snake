#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Score
{
public:
	Score();
	~Score();

	void update();
	void Increment();
	void draw(sf::RenderWindow &window);
	sf::Text score;

	int count;
private:
	
	int offsetX, offsetY;
};

#endif