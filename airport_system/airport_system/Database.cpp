#include "Database.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.h"
#include "Date.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
#include "OpenFileExpception.h"

using namespace std;

template<typename T>
T fromString(const std::string& s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}

void waitenter()
{
	fflush(stdin);
	cout << "Нажмите enter";
	while (1)
	{
		int inpush;
		inpush = _getch();
		if (inpush == 13)
		{
			break;
		}
	}
}

Database::Database()
{
	size = 0;
}

void showTable()
{
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " Название:    |" << " Серийный номер:  |" << " Авиакомнаия:      |" << " Тип воздушного судна:  |" << " Данные о грузе:         |" << " Экипаж: |" << "  Прилет:    |" << "  Вылет:      " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Database::show_color()
{
	system("cls");
	cout << "Список рейсов\n";
	showTable();
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". ";
		arr[i].show();
	}
	waitenter();
}

void Database::showDocument()
{
	system("cls");
	cout << "Список рейсов\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". ";
		arr[i].showFlight();
	}
	waitenter();
}

int pass_and_cargo(int t)
{
	cin.ignore();
	int m;
	string mm;
	if (t == 1)
	{
		bool b = false;
		while (!b)
		{
			b = true;
			cout << "Введите количество пассажиров - ";
			getline(cin, mm, '\n');
			for (size_t i = 0; i < mm.size(); i++)
			{
				if (mm[i]<'0' || mm[i]>'9')
				{
					b = false;
					cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
					break;
				}
			}
		}
		m = fromString<int>(mm);
	}
	else {
		bool b = false;
		while (!b)
		{
			b = true;
			cout << "Введите массу груза(в тоннах) - ";
			getline(cin, mm, '\n');
			fflush(stdin);
			for (size_t i = 0; i < mm.size(); i++)
			{

				if (mm[i]<'0' || mm[i]>'9')
				{
					b = false;
					cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
					break;
				}
			}
		}
		m = fromString<int>(mm);
	}
	return m;
}

int personal()
{
	string cc;
	int c;
	bool b = false;
	while (!b)
	{
		b = true;
		cout << "Экипаж:";
		getline(cin, cc, '\n');
		for (size_t i = 0; i < cc.size(); i++)
		{
			if (cc[i]<'0' || cc[i]>'9')
			{
				b = false;
				cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
				break;
			}
		}
	}
	c = fromString<int>(cc);
	return c;
}

int distance()
{
	int S;
	string distance;
	bool b = false;
	while (!b)
	{
		b = true;
		cout << "Введите расстояние необходимое для полета(км) - ";
		getline(cin, distance, '\n');

		for (size_t i = 0; i < distance.size(); i++)
		{
			if (distance[i]<'0' || distance[i]>'9')
			{
				b = false;
				cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
				break;
			}
		}
	}
	S = fromString<int>(distance);
	return S;
}

int speed()
{
	int V;
	string speed;
	bool b = false;
	while (!b)
	{
		b = true;
		cout << "Введите среднепутевую скорость(км/ч) - ";
		getline(cin, speed, '\n');

		for (size_t i = 0; i < speed.size(); i++)
		{
			if (speed[i]<'0' || speed[i]>'9')
			{
				b = false;
				cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
				break;
			}
		}
	}
	V = fromString<int>(speed);
	return V;
}

int fuel()
{
	int Fuel;
	string fuel;
	bool b = false;
	while (!b)
	{
		b = true;
		cout << "Удельный расход топлива от 1000 до 15000 г/кгс·ч - ";
		getline(cin, fuel, '\n');

		for (size_t i = 0; i < fuel.size(); i++)
		{
			if (fuel[i]<'0' || fuel[i]>'9')
			{
				b = false;
				cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
				break;
			}
		}
	}
	Fuel = fromString<int>(fuel);
	return Fuel;
}

int mass_plane()
{
	int mass_plane;
	string m_p;
	bool b = false;
	while (!b)
	{
		b = true;
		cout << "Масса самолета (в тоннах) - ";
		getline(cin, m_p, '\n');

		for (size_t i = 0; i < m_p.size(); i++)
		{
			if (m_p[i]<'0' || m_p[i]>'9')
			{
				b = false;
				cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
				break;
			}
		}
	}
	mass_plane = fromString<int>(m_p);
	return mass_plane;

}

void Database::addObject()
{
	system("cls");

	cout << "Введите название самолета: ";
	char ch, name_plane[30], ch_seria, name_plane_seria[30], ch_company, company[30];
	int t = -1, ts = -1, tc = -1, m, m_p, c, t2;
	int S, V, Fuel;
	string mm;
	fflush(stdin);
	cin.get(ch);
	while (ch == '\n')
		cin.get(ch);
	while (ch != '\n')
	{
		t++;
		name_plane[t] = ch;
		cin.get(ch);
	}
	while (name_plane[t] == ' ')
	{
		t--;
	}
	t++; name_plane[t] = '\n';

	cout << "Введите серийный номер воздушного судна:";
	fflush(stdin);
	cin.get(ch_seria);
	while (ch_seria == '\n')
		cin.get(ch_seria);
	while (ch_seria != '\n')
	{

		ts++;
		name_plane_seria[ts] = ch_seria;
		cin.get(ch_seria);
	}
	while (name_plane_seria[ts] == ' ')
	{
		ts--;
	}
	ts++; name_plane_seria[ts] = '\n';

	cout << "Введите Авиакомпанию: ";
	fflush(stdin);
	cin.get(ch_company);
	while (ch_company == '\n')
		cin.get(ch_company);
	while (ch_company != '\n')
	{
		tc++;
		company[tc] = ch_company;
		cin.get(ch_company);
	}
	while (company[tc] == ' ')
	{
		tc--;
	}
	tc++; company[tc] = '\n';

	cout << "Тип воздушного судна (0 - транспортный (грузовой), 1 - пассажирский):";
	do {
		cin >> t;
	} while (!(t == 0 || t == 1));
	m = pass_and_cargo(t);
	c = personal();
	char flight[10];

	cout << "Введите для прилета - 0, для вылета - 1: " << endl;
	do {
		cin >> t2;
	} while (!(t2 == 0 || t2 == 1));
	if (t == 1)
	{
		cout << "Введите дату вылета (ДД.ММ.ГГ):";
		fflush(stdin);
		ch = cin.get();
		if (ch == '\n')
		{
			for (int i = 0; i < 10; i++)
			{
				cin.get(flight[i]);
			}
		}
		else
		{
			flight[0] = ch;
			for (int i = 1; i < 10; i++)
			{
				cin.get(flight[i]);
			}
		}
	}
	else
	{
		cout << "Введите дату прилета (ДД.ММ.ГГ):";
		fflush(stdin);
		ch = cin.get();
		if (ch == '\n')
		{
			for (int i = 0; i < 10; i++)
			{
				cin.get(flight[i]);
			}
		}
		else
		{
			flight[0] = ch;
			for (int i = 1; i < 10; i++)
			{
				cin.get(flight[i]);
			}
		}
	}
	cin.ignore();
	S = distance();
	V = speed();
	Fuel = fuel();
	m_p = mass_plane();
	arr[size] = Flight(name_plane, name_plane_seria, company, S, V, Fuel, t, t2, m, m_p, c, flight);
	size++;
}

void Database::delObject()
{
	system("cls");
	fflush(stdin);
	cout << "Введите название воздушного судна: ";
	char name, name_plane[30], ch_seria, name_plane_seria[30]; int t = -1, ts = -1;
	cin.get(name);
	while (name == '\n')
	{
		cin.get(name);
	}
	while (name != '\n')
	{
		t++;
		name_plane[t] = name;
		cin.get(name);
	}
	while (name_plane[t] == ' ')
	{
		t--;
	}
	t++; name_plane[t] = '\n';
	cout << "Введите серийный номер воздушного судна:";
	fflush(stdin);
	cin.get(ch_seria);
	while (ch_seria == '\n')
		cin.get(ch_seria);
	while (ch_seria != '\n')
	{

		ts++;
		name_plane_seria[ts] = ch_seria;
		cin.get(ch_seria);
	}
	while (name_plane_seria[ts] == ' ')
	{
		ts--;
	}
	ts++; name_plane_seria[ts] = '\n';
	bool fin = false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].check_name(name_plane))
		{
			if (strcmp(name_plane_seria, arr[i].getName_seria()) != 0)
			{
				fin = true;
				arr[i] = arr[size - 1];
				size--;
			}
		}
	}
	if (fin == false) { cout << "Этот рейс не найден\n"; waitenter(); }
}

void Database::sort()
{
	Menu menu;
	int pick = menu.sort_click();
	system("cls");
	switch (pick)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		Flight p;

		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				string s1 = arr[j].getName();
				string s2 = arr[j + 1].getName();
				if (s1 > s2)
				{
					p = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = p;
				}
			}
		}
		break;
	}
	case 2:
	{
		Flight p;
		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				string s1 = arr[j].getCompany();
				string s2 = arr[j + 1].getCompany();
				if (s1 > s2)
				{
					p = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = p;
				}
			}
		}
		break;
	}
	case 3:
	{
		Flight p;
		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				int a1 = arr[j].getType();
				int a2 = arr[j + 1].getType();
				if (a1 > a2)
				{
					p = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = p;
				}
			}
		}
		break;
	}
	case 4:
	{
		Flight p;
		Date d;

		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				char* s1 = arr[j].getDate();
				char* s2 = arr[j + 1].getDate();
				if (d.compare(s1, s2))
				{
					p = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = p;
				}
			}
		}
		break;
	}
	default:
		break;
	}
	if (pick != 0) {
		cout << "Сортировка по заданному параметру произведена" << endl;
		waitenter();
	}
}

void Database::find()
{
	Menu menu;
	int pick = menu.find_click();
	system("cls");
	COORD crd = { 65, 100 };
	SMALL_RECT src = { 0, 0, crd.X, crd.Y };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), crd);
	switch (pick)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		cout << "Введите название интересующего вам воздушного судна - ";
		char name, name_plane[30]; int i = -1;
		fflush(stdin);
		cin.get(name);
		while (name == '\n')
			cin.get(name);
		while (name != '\n')
		{
			i++;
			name_plane[i] = name;
			cin.get(name);
		}
		while (name_plane[i] == ' ')
		{
			i--;
		}
		i++; name_plane[i] = '\n'; cout << endl;
		bool b = true;
		for (i = 0; i < size; i++)
		{
			if (arr[i].check_name(name_plane))
			{
				arr[i].showFlight();
				b = false;
				cout << endl;
			}
		}
		if (b) { cout << "Данный рейс не найден" << endl; }
		waitenter();
		break;
	}
	case 2:
	{
		cout << "Введите название авивкомпании - ";
		char ch_company, company[30]; int j = -1;
		fflush(stdin);
		cin.get(ch_company);
		while (ch_company == '\n')
			cin.get(ch_company);
		while (ch_company != '\n')
		{
			j++;
			company[j] = ch_company;
			cin.get(ch_company);
		}
		while (company[j] == ' ')
		{
			j--;
		}
		j++; company[j] = '\n'; cout << endl;
		bool b = true;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].check_company(company))
			{
				arr[i].showFlight();
				b = false;
				cout << endl;
			}
		}
		if (b) { cout << "Данный рейс не найден" << endl; }
		waitenter();
		break;
	}
	case 3:
	{
		int a;
		cout << "Введите интересующий вас тип(транспортный(0)/пассажирский(1)) - ";
		fflush(stdin);
		cin >> a; cout << endl;
		bool b = true;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].check_type(a))
			{
				arr[i].showFlight();
				b = false;
				cout << endl;
			}
		}
		if (b) { cout << "Данный рейс не найден" << endl; }
		waitenter();
		break;
	}
	case 4:
	{
		char life[10], ch;
		cout << "Введите интересующую дату  (ДД.ММ.ГГ):";
		fflush(stdin);
		ch = cin.get();
		if (ch == '\n')
		{
			for (int i = 0; i < 10; i++)
			{
				cin.get(life[i]);
			}
		}
		else
		{
			life[0] = ch;
			for (int i = 1; i < 10; i++)
			{
				cin.get(life[i]);
			}
		}
		bool b = true;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].check_date(life))
			{
				arr[i].showFlight();
				b = false;
				cout << endl;
			}
		}
		if (b) { cout << "Данный рейс не найден" << endl; }
		waitenter();
		break;
	}
	default:
		break;
	}
}

void Database::read_database()
{
	ifstream fin("C:\\Users\\Laptop\\Vegan\\Database.bin", ios::binary);
	if (!fin.is_open()) throw new OpenFileExpception("File don't open!!!");
	char name[30], name_seria[30], company[30], waitingtime[10];
	int type, type2, air_cargo, count, i = -1, V, S, Fuel, mass_plane;
	fin.seekg(0, ios::end);
	int en = (int)fin.tellg();
	fin.seekg(0, ios::beg);
	int a = (int)fin.tellg();
	while ((fin) && (!fin.eof()) && ((en - a) > 2))
	{
		i++;
		fin.read(reinterpret_cast<char*>(&name), sizeof(char[30]));
		fin.read(reinterpret_cast<char*>(&name_seria), sizeof(char[30]));
		fin.read(reinterpret_cast<char*>(&company), sizeof(char[30]));
		fin.read(reinterpret_cast<char*>(&S), sizeof(int));
		fin.read(reinterpret_cast<char*>(&V), sizeof(int));
		fin.read(reinterpret_cast<char*>(&Fuel), sizeof(int));
		fin.read(reinterpret_cast<char*>(&type), sizeof(int));
		fin.read(reinterpret_cast<char*>(&type2), sizeof(int));
		fin.read(reinterpret_cast<char*>(&air_cargo), sizeof(int));
		fin.read(reinterpret_cast<char*>(&mass_plane), sizeof(int));
		fin.read(reinterpret_cast<char*>(&count), sizeof(int));
		fin.read(reinterpret_cast<char*>(&waitingtime), sizeof(char[10]));
		arr[i] = Flight(name, name_seria, company, S, V, Fuel, type, type2, air_cargo, mass_plane, count, waitingtime);
		a = (int)fin.tellg();
	}
	i++;
	size = i;
	fin.close();
}

void Database::save_in_database()
{
	ofstream fout("Database.bin", ios::binary | ios::trunc);
	if (!fout.is_open()) throw new OpenFileExpception("File don't open!!!");
	char* name, *name_seria, *company, *flight;
	int type, type2, air_cargo, count, S, V, Fuel, mass_plane;
	for (int i = 0; i < size; i++)
	{
		name = arr[i].getName();
		name_seria = arr[i].getName_seria();
		company = arr[i].getCompany();
		S = arr[i].getS();
		V = arr[i].getV();
		Fuel = arr[i].getFuel();
		type = arr[i].getType();
		type2 = arr[i].getType2();
		air_cargo = arr[i].getAir_cargo();
		mass_plane = arr[i].getMass_plane();
		count = arr[i].getCount();
		flight = arr[i].getDate();
		fout.write(reinterpret_cast<char*>(name), sizeof(char[30]));
		fout.write(reinterpret_cast<char*>(name_seria), sizeof(char[30]));
		fout.write(reinterpret_cast<char*>(company), sizeof(char[30]));
		fout.write(reinterpret_cast<char*>(&S), sizeof(int));
		fout.write(reinterpret_cast<char*>(&V), sizeof(int));
		fout.write(reinterpret_cast<char*>(&Fuel), sizeof(int));
		fout.write(reinterpret_cast<char*>(&type), sizeof(int));
		fout.write(reinterpret_cast<char*>(&type2), sizeof(int));
		fout.write(reinterpret_cast<char*>(&air_cargo), sizeof(int));
		fout.write(reinterpret_cast<char*>(&mass_plane), sizeof(int));
		fout.write(reinterpret_cast<char*>(&count), sizeof(int));
		fout.write(reinterpret_cast<char*>(flight), sizeof(char[10]));
	}
	fout.close();
}

void Database::history()
{
	system("cls");
	ifstream fin("history.bin", ios::binary);
	if (!fin.is_open()) throw new OpenFileExpception("File don't open!!!");
	char name[30], name_seria[30], company[30], waitingtime[10];
	int type, type2, air_cargo, count, i = -1, S, V, Fuel, mass_plane;
	fin.seekg(0, ios::end);
	int en = (int)fin.tellg();
	fin.seekg(0, ios::beg);
	int a = (int)fin.tellg();
	Flight ar; bool b = true;
	while ((fin) && (!fin.eof()) && ((en - a) > 2))
	{
		i++;
		if (b) { b = false; cout << endl << " История: " << endl << endl; }
		fin.read(reinterpret_cast<char*>(&name), sizeof(char[30]));
		fin.read(reinterpret_cast<char*>(&name_seria), sizeof(char[30]));
		fin.read(reinterpret_cast<char*>(&company), sizeof(char[30]));
		fin.read(reinterpret_cast<char*>(&V), sizeof(int));
		fin.read(reinterpret_cast<char*>(&S), sizeof(int));
		fin.read(reinterpret_cast<char*>(&Fuel), sizeof(int));
		fin.read(reinterpret_cast<char*>(&type), sizeof(int));
		fin.read(reinterpret_cast<char*>(&type2), sizeof(int));
		fin.read(reinterpret_cast<char*>(&air_cargo), sizeof(int));
		fin.read(reinterpret_cast<char*>(&mass_plane), sizeof(int));
		fin.read(reinterpret_cast<char*>(&count), sizeof(int));
		fin.read(reinterpret_cast<char*>(&waitingtime), sizeof(char[10]));
		ar = Flight(name, name_seria, company, S, V, Fuel, type, type2, air_cargo, mass_plane, count, waitingtime);
		ar.show();
		a = (int)fin.tellg();
	}
	if (b) { cout << "История - пуста." << endl; }
	fin.close();
	waitenter();
}

void Database::setting()
{
	Menu m;
	int a = m.setting_click();

	switch (a)
	{
	case 1:
	{
		ofstream fout("history.bin", ios::trunc);
		fout.close();
		break;

	}
	case 2:
	{
		ofstream fout("Database.bin", ios::trunc);
		fout.close();
		size = 0;
		break;
	}
	case 3:
	{
		break;
	}
	default:
		break;
	}
}

Database::~Database()
{
}
