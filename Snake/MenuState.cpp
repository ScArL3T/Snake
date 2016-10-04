#include "MenuState.hpp"
#include "Button.hpp"

MenuState::MenuState(StateManager &stack, States::Context context)
	: State(stack, context)
{
	sf::RenderWindow &window = *getContext().window;

	title.setFont(getContext().fontManager->get(Fonts::ID::GUI));
	title.setColor(sf::Color::White);
	title.setCharacterSize(30);
	title.setString("Snake");
	title.setPosition({ window.getSize().x / 2 - title.getLocalBounds().width / 2,
		window.getSize().y / 2 - title.getLocalBounds().height * 5.65f });

	sf::Texture &panelTexture = getContext().textureManager->get(Textures::ID::Panel);
	panelSprite.setTexture(panelTexture);
	panelSprite.setPosition({ static_cast<float>(window.getSize().x / 2 - panelTexture.getSize().x / 2),
		static_cast<float>(window.getSize().y / 2 - panelTexture.getSize().y / 2) });

	auto play = std::make_shared<Button>(*getContext().soundPlayer);
	play->setTexture(getContext().textureManager->get(Textures::ID::ButtonGreen));
	play->setPosition({ static_cast<float>(window.getSize().x / 2 - 190 / 2),
		static_cast<float>(window.getSize().y / 2 - 49 / 4 * 3) });
	play->setFont(getContext().fontManager->get(Fonts::ID::GUI));
	play->setText("Play");
	play->setCallback([this]()
	{
		popState();
		pushState(States::ID::Game);
	});

	auto quit = std::make_shared<Button>(*getContext().soundPlayer);
	quit->setTexture(getContext().textureManager->get(Textures::ID::ButtonRed));
	quit->setPosition({ static_cast<float>(window.getSize().x / 2 - 190 / 2),
		static_cast<float>(window.getSize().y / 2 + 49 / 4 * 3) });
	quit->setFont(getContext().fontManager->get(Fonts::ID::GUI));
	quit->setText("Quit");
	quit->setCallback([this]()
	{
		popState();
	});

	container.addWidget(play);
	container.addWidget(quit);
}

bool MenuState::handleEvent(const sf::Event &event)
{
	container.handleEvent(event);
	return false;
}

bool MenuState::update(sf::Time dt)
{
	return false;
}

void MenuState::draw()
{
	getContext().window->draw(panelSprite);
	getContext().window->draw(title);
	getContext().window->draw(container);
}