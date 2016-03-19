#ifndef SNAKEOBJECT_H
#define SNAKEOBJECT_H

#define SNAKE_WIDTH 20
#define SNAKE_HEIGHT 20

#include "GameObject.h"
#include "State.h"
#include "Score.h"
#include "GameOver.h"

class SnakeObject final : public GameObject
{
public:
	SnakeObject();
	~SnakeObject();

	bool gameOver(sf::RenderWindow &window);

	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	bool selfCollide(sf::RectangleShape &s);
	bool appleCollide(sf::RectangleShape &s);
	void add();
	
private:
	void input();
	void setPosition();
	void move();

	std::vector<sf::RectangleShape> snake;
	
	sf::RectangleShape shape;
	sf::Clock clock, time;
	float procent;
	float timp;

	enum class Directie {UP, DOWN, LEFT, RIGHT};
	Directie dir;
};

#endif