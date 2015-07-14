#include "SnakeObject.h"


SnakeObject::SnakeObject()
{
	//Stocam obiectul.
	rm.LoadTexture(1, "data/snakehead.png");
	rm.LoadTexture(2, "data/snakebody.png");

	sshape.setSize(sf::Vector2f(SNAKE_WIDTH, SNAKE_HEIGHT));
	sshape.setTexture(&rm.TextureHold[1]);
	sshape.setPosition(sf::Vector2f(320, 320));
	snake.push_back(sshape);
	//snake.setTexture(sshape);
	sshape.setTexture(&rm.TextureHold[2]);
	sshape.setPosition(sf::Vector2f(320, 320 + SNAKE_HEIGHT));
	snake.push_back(sshape);
	//Directia initiala
	dir = UP;

	timp = 0.3;
	move = false;
	procent = 0.05;
}


SnakeObject::~SnakeObject()
{
}

void SnakeObject::Update(sf::RenderWindow &window)
{
	Input();
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
		Move();
	}
	CheckWindow(window);
	SelfCollide();
}

void SnakeObject::Draw(sf::RenderWindow &window)
{
	for (auto i = 0; i < snake.size(); i++)
		window.draw(snake[i]);
}

void SnakeObject::Input()
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

void SnakeObject::SetPos()
{
	for (auto i = snake.size() - 1; i > 0; i--)
	{
		snake[i].setPosition(snake.at(i - 1).getPosition());
	}
}

void SnakeObject::Move()
{
	SetPos();
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

void SnakeObject::CheckWindow(sf::RenderWindow &window)
{
	//Daca primul block din sarpe iese de pe ecran => inchidem jocul

	if (snake[0].getPosition().x < 0)
	{
		engine.SetState(new GameOver());
		//snake[0].setPosition(sf::Vector2f(window.getSize().x - SNAKE_WIDTH, snake[0].getPosition().y));
	}
	else if (snake[0].getPosition().x + SNAKE_WIDTH > window.getSize().x)
	{  
		engine.SetState(new GameOver());
		//snake[0].setPosition(sf::Vector2f(SNAKE_WIDTH, snake[0].getPosition().y));
	}
	else if (snake[0].getPosition().y < 0)
	{
		engine.SetState(new GameOver());
	}
	else if (snake[0].getPosition().y + SNAKE_HEIGHT > window.getSize().y)
	{
		engine.SetState(new GameOver());
	}
}

bool SnakeObject::Collide(sf::RectangleShape s, sf::RectangleShape a)
{
	if (s.getGlobalBounds().intersects(a.getGlobalBounds()))
		return true;
	else return false;
}

bool SnakeObject::Collide(sf::RectangleShape s, std::vector<sf::RectangleShape> a)
{
	for (auto i = 0; i < a.size(); i++)
	{
		if (s.getGlobalBounds().intersects(a[i].getGlobalBounds()))
			return true;
	}
	
	return false;
}

void SnakeObject::Add()
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

void SnakeObject::SelfCollide()
{
	for (auto i = 1; i < snake.size(); i++)
	{
		if (Collide(snake[0], snake[i]) == true)
			engine.SetState(new GameOver());
	}
}