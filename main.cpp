#include "States.h"
#include "Menu.h"
#include "GameObject.h"
#include "SplashScreen.h"
//clona pt jocul de pe android - MEMENTO
//TODO
//event manager; virtual void events(window, event);
//Sound

#define WIDTH 640
#define HEIGHT 480

GameState engine;
bool quit_game = false;

void HandleEvents(sf::RenderWindow &window);

int main()
{
	sf::Music intro;
	intro.openFromFile("data/intromusic.ogg");
	intro.play();

	//Splash
	unsigned char opacity = 255;
	float duration = 4.5;
	SplashScreen ss;
	ss.Create(opacity, duration);

	//Jocul
	sf::Texture texture;
	texture.loadFromFile("data/bg.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::RectangleShape mask;
	mask.setSize({ WIDTH, HEIGHT });
	mask.setFillColor(sf::Color(0, 0, 0, 200));

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake");
	std::cout << "Window created." << std::endl;
	
	sf::Image icon;
	icon.loadFromFile("data/icon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	engine.SetWindow(window);
	engine.SetState(new Menu());


	while (window.isOpen())
	{
		HandleEvents(window);

		window.clear();
		window.draw(sprite);
		window.draw(mask);

		engine.Update();
		engine.Draw();

		window.display();

		if (quit_game == true)
		{
			window.close();
		}
	}

	return 0;
}

void HandleEvents(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}