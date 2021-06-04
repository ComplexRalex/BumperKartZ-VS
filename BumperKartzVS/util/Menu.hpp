#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <vector>
#include <iostream>

#include "Text.hpp"

class Option
{
	private:
		std::string name;
		void* font;
		bool selectable;
	public:
		Option(std::string,void*,bool);
		~Option();

		std::string getName();
		void setName(std::string);
		void* getFont();
		void setFont(void*);
		bool getSelectable();
		void setSelectable(bool);
};

class Menu
{
	private:
		std::string name;
		std::vector<Option*> options;
		int selected;

		float s_color[3], ns_color[3];
		bool locked;
		
		int gap;
	public:
		Menu(std::string);
		~Menu();

		std::string getName();
		void addOption(Option*);
		Option* getOption();
		int getSelected();
		void setSelected(int);
		void lockSelected(bool);
		void moveUp();
		void moveDown();

		void setSelectedColor(float,float,float);
		void setUnselectedColor(float,float,float);

		void display(int,int,int,int);
};

#endif // MENU_HPP_INCLUDED