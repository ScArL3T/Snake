#include "Container.hpp"

Container::Container()
	: widgets()
	, selectedWidget(-1)
{
}

void Container::handleEvent(const sf::Event &event)
{
	for (const Widget::Ptr &w : widgets)
		w->handleEvent(event);
}

const bool Container::isSelectable() const
{
	return false;
}

void Container::addWidget(Widget::Ptr widget)
{
	widgets.push_back(widget);
	widgets.back()->setParent(this);
}

void Container::removeWidget(Widget::Ptr widget)
{
	for (unsigned int i = 0; i<widgets.size(); ++i)
	{
		if (widgets[i] == widget)
		{
			if (selectedWidget == i)
			{
				widgets[i]->deselect();
				if (widgets.size() > 1)
					selectNext();
				else selectedWidget = -1;
			}
			else if (selectedWidget > static_cast<int>(i))
				selectedWidget--;

			widgets.erase(widgets.begin() + i);
			return;
		}
	}
}

void Container::clear()
{
	if (hasSelection())
		widgets[selectedWidget]->deselect();

	widgets.clear();
	selectedWidget = -1;
}

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	for (const Widget::Ptr &w : widgets)
		target.draw(*w, states);
}

const bool Container::hasSelection() const
{
	return selectedWidget >= 0;
}

void Container::select(unsigned int index)
{
	if (widgets[index]->isSelectable())
	{
		if (hasSelection())
			widgets[selectedWidget]->deselect();

		widgets[index]->select();
		selectedWidget = index;
	}
}

void Container::selectNext()
{
	if (!hasSelection())
		return;
	
	int next = selectedWidget;
	do
		next = (next + 1) % widgets.size();
	while (!widgets[next]->isSelectable());

	select(next);
}

void Container::selectPrevious()
{
	if (!hasSelection())
		return;

	int prev = selectedWidget;
	do
		prev = (prev + widgets.size() - 1) % widgets.size();
	while (!widgets[prev]->isSelectable());

	select(prev);
}