#pragma once
#include "Flight.h"

class Database
{
private:
	Flight arr[128];
	int size;
public:
	Database();
	void show_color();
	void showDocument();
	void addObject();
	void delObject();
	void sort();
	void find();
	void read_database();
	void save_in_database();
	void history();
	void setting();
	~Database();
};