#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Widget.hpp"

class Container : public Widget
{
public:
	explicit Container();

	void handleEvent(const sf::Event &event) override;
	const bool isSelectable() const override;

	void addWidget(Widget::Ptr widget);
	void removeWidget(Widget::Ptr widget);
	void clear();

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	const bool hasSelection() const;

	void select(unsigned int index);
	void selectNext();
	void selectPrevious();

private:
	std::vector<Widget::Ptr> widgets;
	int selectedWidget;
};

#endif