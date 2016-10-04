#include "Snake.hpp"

Snake::Snake()
	: snake()
	, speed(0.06f)
	, delta()
	, queue()
	, dir(Direction::UP)
{
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(SNAKE_WIDTH, SNAKE_HEIGHT));
	shape.setOutlineThickness(-1);
	shape.setOutlineColor(sf::Color(210, 210, 210));

	shape.setFillColor(sf::Color(105, 105, 105));
	shape.setPosition(sf::Vector2f(320, 320));
	snake.push_back(shape);

	shape.setFillColor(sf::Color::Black);
	shape.setPosition(sf::Vector2f(320, 320 + SNAKE_HEIGHT));
	snake.push_back(shape);
}

void Snake::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::W:
		case sf::Keyboard::Up:
			if(dir != Direction::DOWN && dir != Direction::UP)
				queue.push(Direction::UP);
			break;
		case sf::Keyboard::S:
		case sf::Keyboard::Down:
			if (dir != Direction::UP && dir != Direction::DOWN)
				queue.push(Direction::DOWN);
			break;
		case sf::Keyboard::A:
		case sf::Keyboard::Left:
			if (dir != Direction::RIGHT && dir != Direction::LEFT)
				queue.push(Direction::LEFT);
			break;
		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			if (dir != Direction::LEFT && dir != Direction::RIGHT)
				queue.push(Direction::RIGHT);
			break;
		}
	}
}

void Snake::update(sf::Time dt)
{
	delta += dt;
	if (delta.asSeconds() >= speed)
	{
		delta = delta - sf::seconds(speed);

		if (!queue.empty())
		{
			dir = queue.front();
			queue.pop();
		}	
		
		move();
	}
	
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	for (const auto &shape : snake)
		target.draw(shape, states);
}

void Snake::setPosition()
{
	for (auto i = snake.size() - 1; i > 0; i--)
	{
		snake[i].setPosition(snake[i - 1].getPosition());
	}
}

void Snake::move()
{
	setPosition();
	switch (dir)
	{
	case Direction::UP:
		snake[0].move(0, -SNAKE_HEIGHT);
		break;
	case Direction::DOWN:
		snake[0].move(0, SNAKE_HEIGHT);
		break;
	case Direction::LEFT:
		snake[0].move(-SNAKE_WIDTH, 0);
		break;
	case Direction::RIGHT:
		snake[0].move(SNAKE_WIDTH, 0);
		break;
	}
}

bool Snake::gameOver(sf::RenderWindow &window)
{
	// Check screen bounds
	if (snake[0].getPosition().x < 0 || snake[0].getPosition().x + SNAKE_WIDTH > window.getSize().x
		|| snake[0].getPosition().y < SNAKE_HEIGHT || snake[0].getPosition().y + SNAKE_HEIGHT > window.getSize().y)
		return true;

	// Check snake collision with itself
	for (unsigned int i = 1; i < snake.size(); ++i)
		if (selfCollide(snake[i]))
			return true;

	return false;
}

bool Snake::selfCollide(const sf::RectangleShape &s)
{
	if (s.getGlobalBounds().intersects(snake.front().getGlobalBounds()))
		return true;

	return false;
}

void Snake::add()
{
	// Add a new block to the snake depending on its direction
	sf::RectangleShape shape;
	if (snake[snake.size() - 1].getPosition().x < snake[snake.size() - 2].getPosition().x
		&& snake[snake.size() - 1].getPosition().y == snake[snake.size() - 2].getPosition().y)
	{
		shape.setPosition(sf::Vector2f(snake[snake.size() - 1].getPosition().x - SNAKE_WIDTH,
			snake[snake.size() - 1].getPosition().y));
	}
	else if (snake[snake.size() - 1].getPosition().x > snake[snake.size() - 2].getPosition().x
		&& snake[snake.size() - 1].getPosition().y == snake[snake.size() - 2].getPosition().y)
	{
		shape.setPosition(sf::Vector2f(snake[snake.size() - 1].getPosition().x + SNAKE_WIDTH,
			snake[snake.size() - 1].getPosition().y));
	}
	else if (snake[snake.size() - 1].getPosition().y < snake[snake.size() - 2].getPosition().y
		&& snake[snake.size() - 1].getPosition().x == snake[snake.size() - 2].getPosition().x)
	{
		shape.setPosition(sf::Vector2f(snake[snake.size() - 1].getPosition().x,
			snake[snake.size() - 1].getPosition().y - SNAKE_HEIGHT));
	}
	else if (snake[snake.size() - 1].getPosition().y > snake[snake.size() - 2].getPosition().y
		&& snake[snake.size() - 1].getPosition().x == snake[snake.size() - 2].getPosition().x)
	{
		shape.setPosition(sf::Vector2f(snake[snake.size() - 1].getPosition().x,
			snake[snake.size() - 1].getPosition().y + SNAKE_HEIGHT));
	}

	snake.push_back(shape);
}

const std::vector<sf::RectangleShape> &Snake::getSnake() const
{
	return snake;
}
