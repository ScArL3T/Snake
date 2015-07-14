#ifndef SNAKEOBJECT_H
#define SNAKEOBJECT_H

#define SNAKE_WIDTH 20
#define SNAKE_HEIGHT 20

#include "GameObject.h"
#include "States.h"
#include "Score.h"
#include "GameOver.h"

class SnakeObject: public GameObject
{
public:
	SnakeObject();
	~SnakeObject();

	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	bool Collide(sf::RectangleShape s, sf::RectangleShape a);
	bool Collide(sf::RectangleShape s, std::vector<sf::RectangleShape> a);
	void Add();

	std::vector<sf::RectangleShape> snake;
	
private:
	void Input();
	void SetPos();
	void Move();
	void CheckWindow(sf::RenderWindow &window);
	void SelfCollide();
	
	sf::RectangleShape sshape;
	sf::Clock clock, time;
	float procent;
	float timp;
	bool move;
	ResourceManager rm;

	enum directie {UP, DOWN, LEFT, RIGHT};
	int dir;
};

#endif