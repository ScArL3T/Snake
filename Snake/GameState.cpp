#include "GameState.hpp"

GameState::GameState(StateManager &stack, States::Context context)
	: State(stack, context)
{
	sf::RenderWindow &window = *context.window;

	font.loadFromFile("data/font.ttf");
	buffer.loadFromFile("data/eat.ogg");
	sound.setBuffer(buffer);

	Score &score = *context.score;
	score.setPosition({ 10, -2 });
	score.resetScore();

	float lineHeight = 1.f;
	line.setFillColor(sf::Color::Black);
	line.setSize({ static_cast<float>(window.getSize().x), lineHeight });
	line.setPosition({ 0, SNAKE_HEIGHT });

	float offset = -10.f;
	infoText.setString("Press ESC to Pause");
	infoText.setCharacterSize(20);
	infoText.setFont(font);
	infoText.setColor(sf::Color::Black);
	infoText.setPosition({ static_cast<float>(window.getSize().x - infoText.getLocalBounds().width + offset), -2.f });
}

bool GameState::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::Escape)
	{
		pushState(States::ID::Pause);
	}

	snake.handleEvent(event);
	return false;
}

bool GameState::update(sf::Time dt)
{
	if (snake.gameOver(*getContext().window))
	{
		popState();
		pushState(States::ID::GameOver);
	}

	snake.update(dt);
	
	if (appleOnHead())
	{
		snake.add();
		getContext().score->addScore();
		sound.play();

		do
			apple.setPosition(apple.reset());
		while (appleOnSnake());
	}

	return false;
}

void GameState::draw()
{
	sf::RenderWindow &window = *getContext().window;

	window.draw(*getContext().score);
	window.draw(apple);
	window.draw(snake);
	window.draw(line);
	window.draw(infoText);
}

bool GameState::appleOnHead()
{
	auto head = snake.getSnake().front();
	auto appleBody = apple.getApple();

	if (head.getGlobalBounds().intersects(appleBody.getGlobalBounds()))
		return true;

	return false;
}

bool GameState::appleOnSnake()
{
	auto snakeBody = snake.getSnake();
	auto appleBody = apple.getApple();

	for (const auto &shape : snakeBody)
		if (shape.getGlobalBounds().intersects(appleBody.getGlobalBounds()))
			return true;
	
	return false;
}
