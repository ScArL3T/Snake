#include "SnakeObject.h"


SnakeObject::SnakeObject()
{
	//Stocam obiectul.
	head.loadFromFile("data/snakehead.png");
	tail.loadFromFile("data/snakebody.png");

	sshape.setSize(sf::Vector2f(SNAKE_WIDTH, SNAKE_HEIGHT));
	sshape.setTexture(&head);
	sshape.setPosition(sf::Vector2f(320, 320));
	snake.push_back(sshape);
	//snake.setTexture(sshape);
	sshape.setTexture(&tail);
	sshape.setPosition(sf::Vector2f(320, 320 + SNAKE_HEIGHT));
	snake.push_back(sshape);
	//Directia initiala
	dir = UP;

	timp = 0.3;
	procent = 0.05;
}


SnakeObject::~SnakeObject()
{
}

void SnakeObject::update(sf::RenderWindow &window)
{
	input();
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//	timp = 0.07;
	//else timp = 0.1;
	
	if (clock.getElapsedTime().asSeconds() >= timp)
	{

		clock.restart();

		if (time.getElapsedTime().asSeconds() > 6.f)
		{
			timp -= procent;
			procent -= procent * 0.05;
			time.restart();
			if (timp < 0.04)
				timp = 0.04;
		}
		/*if (timp > 0.2)
			timp = timp - 0.003;
		else if (timp > 0.1)
			timp = timp - 0.001;
		else timp = timp - 0.0009;
		if (timp < 0.05)
			timp = 0.05;*/
		move();
	}
}

void SnakeObject::draw(sf::RenderWindow &window)
{
	for (auto i = 0; i < snake.size(); i++)
		window.draw(snake[i]);
}

void SnakeObject::input()
{
	/*
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::W && dir != DOWN)
				dir = UP;
			else if (event.key.code == sf::Keyboard::S && dir != UP)
				dir = DOWN;
			else if (event.key.code == sf::Keyboard::A && dir != RIGHT)
				dir = LEFT;
			else if (event.key.code == sf::Keyboard::D && dir != LEFT)
				dir = RIGHT;
		}
	}*/
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && dir != DOWN)
		dir = UP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dir != UP)
		dir = DOWN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && dir != RIGHT)
		dir = LEFT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dir != LEFT)
		dir = RIGHT;
}

void SnakeObject::setPosition()
{
	for (auto i = snake.size() - 1; i > 0; i--)
	{
		snake[i].setPosition(snake.at(i - 1).getPosition());
	}
}

void SnakeObject::move()
{
	setPosition();
	switch (dir)
	{
	case UP:
		snake[0].move(0, -SNAKE_HEIGHT);
		break;
	case DOWN:
		snake[0].move(0, SNAKE_HEIGHT);
		break;
	case LEFT:
		snake[0].move(-SNAKE_WIDTH, 0);
		break;
	case RIGHT:
		snake[0].move(SNAKE_WIDTH, 0);
		break;
	}
}

bool SnakeObject::gameOver(sf::RenderWindow &window)
{
	//Daca primul block din sarpe iese de pe ecran => inchidem jocul

	if (snake[0].getPosition().x < 0 || snake[0].getPosition().x + SNAKE_WIDTH > window.getSize().x
		|| snake[0].getPosition().y < 0 || snake[0].getPosition().y + SNAKE_HEIGHT > window.getSize().y)
	{
		return true;
	}

	for (auto i = 1; i < snake.size(); ++i)
		if (selfCollide(snake[i]))
			return true;

	return false;
}

bool SnakeObject::selfCollide(sf::RectangleShape &s)
{
	if (s.getGlobalBounds().intersects(snake.front().getGlobalBounds()))
		return true;
	else return false;
}

bool SnakeObject::appleCollide(sf::RectangleShape &s)
{
	for (auto i = 0; i < snake.size(); i++)
		if (s.getGlobalBounds().intersects(snake[i].getGlobalBounds()))
			return true;
	
	return false;
}

void SnakeObject::add()
{
	/*
	Daca marul a fost mancat adaugam un block la sarpe
	in functie de directia ultimului block.
	Determinam directia ultimului block in functie de pozitia sa cu penultimul.
	*/
	if (snake[snake.size() - 1].getPosition().x < snake[snake.size() - 2].getPosition().x
		&& snake[snake.size() - 1].getPosition().y == snake[snake.size() - 2].getPosition().y)
	{
		sshape.setPosition(sf::Vector2f(snake[snake.size() - 1].getPosition().x - SNAKE_WIDTH,
			snake[snake.size() - 1].getPosition().y));
	}
	else if (snake[snake.size() - 1].getPosition().x > snake[snake.size() - 2].getPosition().x
		&& snake[snake.size() - 1].getPosition().y == snake[snake.size() - 2].getPosition().y)
	{
		sshape.setPosition(sf::Vector2f(snake[snake.size() - 1].getPosition().x + SNAKE_WIDTH,
			snake[snake.size() - 1].getPosition().y));
	}
	else if (snake[snake.size() - 1].getPosition().y < snake[snake.size() - 2].getPosition().y
		&& snake[snake.size() - 1].getPosition().x == snake[snake.size() - 2].getPosition().x)
	{
		sshape.setPosition(sf::Vector2f(snake[snake.size() - 1].getPosition().x,
			snake[snake.size() - 1].getPosition().y - SNAKE_HEIGHT));
	}
	else if (snake[snake.size() - 1].getPosition().y > snake[snake.size() - 2].getPosition().y
		&& snake[snake.size() - 1].getPosition().x == snake[snake.size() - 2].getPosition().x)
	{
		sshape.setPosition(sf::Vector2f(snake[snake.size() - 1].getPosition().x,
			snake[snake.size() - 1].getPosition().y + SNAKE_HEIGHT));
	}

	snake.push_back(sshape);
}