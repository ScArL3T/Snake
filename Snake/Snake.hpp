#ifndef SNAKE_HPP
#define SNAKE_HPP

#define SNAKE_WIDTH 20
#define SNAKE_HEIGHT 20

#include "Entity.hpp"
#include "State.hpp"

#include <queue>

class Snake final : public Entity
{
public:
	Snake();

	bool gameOver(sf::RenderWindow &window);

	void handleEvent(const sf::Event &event) override;
	void update(sf::Time dt) override;
	bool selfCollide(const sf::RectangleShape &s);
	void add();

	const std::vector<sf::RectangleShape> &getSnake() const;
	
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setPosition();
	void move();

	std::vector<sf::RectangleShape> snake;

	float speed;
	sf::Time delta;

	enum class Direction {UP, DOWN, LEFT, RIGHT};
	std::queue<Direction> queue;
	Direction dir;
};

#endif