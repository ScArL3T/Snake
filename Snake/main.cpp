#include <SFML/Audio.hpp>

#include "StateManager.h"
#include "StatesID.h"
#include "SplashScreen.h"

int main()
{
	//Splash
	/*unsigned char opacity = 255;
	float duration = 4.5;
	SplashScreen ss;
	ss.Create(opacity, duration);*/

	sf::RenderWindow window(sf::VideoMode(640, 480), "Snake");
	std::cout << "Window created." << std::endl;
	
	sf::Image icon;
	icon.loadFromFile("data/icon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	StateManager state(window);
	state.pushState(States::ID::Menu);


	const sf::Time m_frameTime = sf::seconds(1.f / 30.f);
	sf::Clock clock;
	sf::Time passedTime = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		passedTime += elapsedTime;

		while (passedTime > m_frameTime)
		{
			passedTime -= m_frameTime;

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				state.handleEvent(event);
			}
			state.update(m_frameTime);
		}

		window.clear();
		state.draw();
		window.display();
	}

	return 0;
}