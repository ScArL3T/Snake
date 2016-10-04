#include "Widget.hpp"

Widget::Widget()
	: selected(false)
	, active(true)
	, parent(nullptr)
{
}

void Widget::setParent(Container *parent)
{
	this->parent = parent;
}

void Widget::select()
{
	selected = true;
}

void Widget::deselect()
{
	selected = false;
}

void Widget::activate()
{
	active = true;
}

void Widget::deactivate()
{
	active = false;
}

const bool Widget::isSelected() const
{
	return selected;
}

const bool Widget::isActive() const
{
	return active;
}