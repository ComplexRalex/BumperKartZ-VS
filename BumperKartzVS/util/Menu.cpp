#include "Menu.hpp"

Option::Option(std::string name, void* font, bool selectable)
{
	this->name = name;
	this->font = font;
	this->selectable = selectable;
}

Option::~Option(){}

std::string Option::getName() { return name; }
void Option::setName(std::string n) { name = n; }
void* Option::getFont() { return font; }
void Option::setFont(void* f) { font = f; }
bool Option::getSelectable() { return selectable; }
void Option::setSelectable(bool s) { selectable = s; }

Menu::Menu(std::string name)
{
	this->name = name;
	selected = 0;
	locked = false;
	gap = 28;

	for(int i = 0; i < 3; i++)
		s_color[i] = ns_color[i] = 1.0f;
}

Menu::~Menu()
{
	for(int i = 0; i < options.size(); i++)
	{
		delete options[i];
	}
}

std::string Menu::getName()
{
	return name;
}

void Menu::addOption(Option* op)
{
	options.push_back(op);
}

Option* Menu::getOption()
{
	return options[selected];
}

int Menu::getSelected()
{
	return selected;
}

void Menu::setSelected(int index)
{
	if(!locked)
	{
		selected = (index < 0 ? 0 : index);
		selected = (index >= options.size() ? options.size()-1 : index);
	}
}

void Menu::lockSelected(bool flag)
{
	locked = flag;
}

void Menu::moveUp()
{
	if(!locked)
		selected = (selected == 0 ? options.size()-1 : selected-1);
}

void Menu::moveDown()
{
	if(!locked)
		selected = (selected == options.size()-1 ? 0 : selected+1);
}

void Menu::setSelectedColor(float r, float g, float b)
{
	s_color[0] = r;
	s_color[1] = g;
	s_color[2] = b;
}

void Menu::setUnselectedColor(float r, float g, float b)
{
	ns_color[0] = r;
	ns_color[1] = g;
	ns_color[2] = b;
}

void Menu::display(int pos_x, int pos_y, int width, int height)
{
	Text::setDisplaySize(width, height);
	for(int i = 0; i < options.size(); i++)
		Text::draw
		(
			options[i]->getName(),
			options[i]->getFont(),
			pos_x,
			pos_y + gap*i,
			selected == i ? s_color[0] : ns_color[0],
			selected == i ? s_color[1] : ns_color[1],
			selected == i ? s_color[2] : ns_color[2]
		);
}