#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Score
{
public:
	Score();
	~Score();

	void Update();
	void Increment();
	void Draw(sf::RenderWindow &window);
	sf::Text score;

	int count;
private:
	
	int offsetX, offsetY;
};

#endif