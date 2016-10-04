#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Widget.hpp"

#include <SFML/Audio.hpp>

#include <functional>

class SoundPlayer;

class Button : public Widget
{
public:
	using Callback = std::function<void()>;

	enum Type
	{
		Normal = 0,
		Selected,
		Pressed
	};

	explicit Button(SoundPlayer &soundPlayer);

	void setCallback(Callback callback);
	void setTexture(const sf::Texture &texture);
	void setText(const std::string &text);
	void setFont(const sf::Font &font);

	void handleEvent(const sf::Event &event) override;
	const bool isSelectable() const override;

	void select() override;
	void deselect() override;

	void activate() override;
	void deactivate() override;

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void changeTexture(Type type);
	void centerText();

	Callback callback;
	sf::Sprite sprite;
	sf::Text text;

	SoundPlayer &soundPlayer;

	bool toggle;
};

#endif;