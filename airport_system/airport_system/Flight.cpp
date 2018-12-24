#include "Flight.h"
#include <iostream>
#include "Date.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include "OpenFileExpception.h"

using namespace std;

Flight::Flight()
{
}

Flight::Flight(char *n, char *ns, char*com, int s, int v, int f, int t, int t2, int m, int m_p, int c, char *l)
{
	type = t;
	type2 = t2;
	air_cargo = m;
	mass_plane = m_p;
	count = c;
	S = s;
	V = v;
	Fuel = f;
	int i = 0;
	while (n[i] != '\n')
	{
		name[i] = n[i];
		i++;
	}
	name[i] = '\n';
	int j = 0;

	while (ns[j] != '\n')
	{
		name_seria[j] = ns[j];
		j++;
	}
	name_seria[j] = '\n';
	int j1 = 0;

	while (com[j1] != '\n')
	{
		company[j1] = com[j1];
		j1++;
	}
	company[j1] = '\n';
	for (int j = 0; j < 10; j++)
	{
		waitingtime[j] = l[j];
	}
	ofstream outfile("C:\\Users\\Laptop\\Vegan\\history.bin", ios::binary | ios::app);
	if (!outfile.is_open()) throw new OpenFileExpception("File don't open!!!");
	outfile.write(reinterpret_cast<char*>(n), sizeof(char[30]));
	outfile.write(reinterpret_cast<char*>(ns), sizeof(char[30]));
	outfile.write(reinterpret_cast<char*>(com), sizeof(char[30]));
	outfile.write(reinterpret_cast<char*>(&t), sizeof(int));
	outfile.write(reinterpret_cast<char*>(&t2), sizeof(int));
	outfile.write(reinterpret_cast<char*>(&S), sizeof(int));
	outfile.write(reinterpret_cast<char*>(&V), sizeof(int));
	outfile.write(reinterpret_cast<char*>(&Fuel), sizeof(int));
	outfile.write(reinterpret_cast<char*>(&m), sizeof(int));
	outfile.write(reinterpret_cast<char*>(&m_p), sizeof(int));
	outfile.write(reinterpret_cast<char*>(&c), sizeof(int));
	outfile.write(reinterpret_cast<char*>(l), sizeof(char[10]));
	outfile.close();
}

void Flight::show()
{
	Date d;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = d.dataIdentity(waitingtime);
	int i = 0;
	while (name[i] != '\n')
	{
		cout << name[i]; i++;
	}
	cout << setw(13 - i) << "";// -3
	int j = 0;
	while (name_seria[j] != '\n')
	{
		cout << name_seria[j]; j++;
	}
	cout << setw(19 - j) << "";

	int j1 = 0;
	while (company[j1] != '\n')
	{
		cout << company[j1]; j1++;
	}
	cout << setw(20 - j1) << "";
	if (type == 1) { 
		cout << left << setw(25) << "Пассажирский"; 
	}
	else { 
		cout << left << setw(25)<< "Транспортный"; 
	}
	if (type == 1) { 
		cout  << "Кол-во пассаж - " << left << setw(10) << air_cargo;
	}
	else { 
		cout  << "Масса груза(т) - " << left << setw(9) << air_cargo;
	}
	cout << setw(10) << count;
	SetConsoleTextAttribute(h, 15);
	if (a > 1 || a == 1)
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	if (a < 0) {
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	if (type2 == 1)
	{
		cout << setw(15) << "";
		for (i = 0; i < 10; i++)
		{
			cout << waitingtime[i];
		}
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			cout << waitingtime[i];
		}
	}
	cout << endl;
	SetConsoleTextAttribute(h, 15);
}

void Flight::showFlight()
{
	cout << "Name: ";
	int i = 0;
	while (name[i] != '\n')
	{
		cout << name[i]; i++;
	}
	cout << endl;
	cout << "Series number: ";
	int j = 0;
	while (name_seria[j] != '\n')
	{
		cout << name_seria[j]; j++;
	}
	cout << endl;
	int j1 = 0;
	cout << "Company: ";
	while (company[j1] != '\n')
	{
		cout << company[j1]; j1++;
	}
	cout << endl;
	if (type == 1) { cout << "Passeger: " << air_cargo << " чел" << endl; }
	else { cout << "Weight: " << air_cargo << " тонн" << endl; }
	cout << "Weight plane: " << mass_plane << " ton" << endl;
	cout << "Aircrew: " << count << endl;

	if (type2 == 1)
	{
		cout << "Takeoff: ";
		for (i = 0; i < 10; i++)
		{
			cout << waitingtime[i];
		}
	}
	else
	{
		cout << "Arrival:";
		for (i = 0; i < 10; i++)
		{
			cout << waitingtime[i];
		}
	}
	double t, f = 0, f2 = 0;
	cout << endl;
	cout << "Way: " << S << "км" << endl;
	cout << "Speed: " << V << "км/ч" << endl;
	double fuel_ness;
	if (type == 1)
	{
		f = Fuel * 0.0001;
		fuel_ness = (double)mass_plane - (air_cargo * 0.085);
		cout << "Fuel consumption: " << fuel_ness * f << "ton" << endl;

		t = ((double)S / (double)V)*f;
		cout << "Flight Time: " << t << " ч" << endl;
		f2 = fuel_ness - (f*fuel_ness);
		cout << "Remainder Fuel: " << f2 << "ton" << endl;
	}
	else
	{
		f = Fuel * 0.0001;
		fuel_ness = (double)mass_plane - (double)air_cargo;
		cout << "Fuel consumption: " << fuel_ness * f << "ton" << endl;// neobhodimoe

		t = (double)S / (double)V * f;
		cout << "Flight Time: " << t << " ч" << endl;
		f2 = fuel_ness - (f*fuel_ness);
		cout << "Remainder Fuel: " << f2 << "ton" << endl;// ostatok
	}



}

bool Flight::check_name(char *n)
{
	bool answer = true;
	int i = 0;
	while (1)
	{
		if ((n[i] == '\n') && (name[i] == '\n')) { break; }
		if ((n[i] == '\n') || (name[i] == '\n')) { answer = false; break; }
		if (n[i] != name[i]) { answer = false; break; }
		i++;
	}
	return answer;
}

bool Flight::check_company(char *n)
{
	bool answer = true;
	int i = 0;
	while (1)
	{
		if ((n[i] == '\n') && (company[i] == '\n')) { break; }
		if ((n[i] == '\n') || (company[i] == '\n')) { answer = false; break; }
		if (n[i] != company[i]) { answer = false; break; }
		i++;
	}
	return answer;
}

bool Flight::check_type(int a)
{
	bool answer = true;
	if (a != type) { answer = false; }
	return answer;
}

bool Flight::check_date(char *l)
{
	Date d;
	bool answer = d.isEqual(waitingtime, l);
	return answer;
}

char* Flight::getName()
{
	return name;
}

char* Flight::getName_seria()
{
	return name_seria;
}

char* Flight::getCompany()
{
	return company;
}

int Flight::getS()
{
	return S;
}

int Flight::getV()
{
	return V;
}

int Flight::getFuel()
{
	return Fuel;
}

int Flight::getType()
{
	return type;
}

int Flight::getType2()
{
	return type2;
}

int Flight::getAir_cargo()
{
	return air_cargo;
}

int Flight::getMass_plane()
{
	return mass_plane;
}

int Flight::getCount()
{
	return count;
}

char* Flight::getDate()
{
	return waitingtime;
}

Flight::~Flight()
{
}
