#pragma once
class Menu
{
public:
	Menu();
	void start();
	void showMenu(int);
	int main_click();
	void showFind(int);
	int find_click();
	int sort_click();
	void showSort(int);
	void showSetting(int);
	int setting_click();
	void the_end();
	~Menu();
};

