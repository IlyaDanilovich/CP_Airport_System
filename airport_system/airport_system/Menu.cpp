#include "Menu.h"
#include "Database.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void waitenter();

Menu::Menu()
{
}

void Menu::start()
{
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << endl;
	cout << "                                                      ����  ������ �����                                                     " << endl;
	cout << "                                                     ��  ��   ��   ��  ��                                                    " << endl;
	cout << "                                                     ������   ��   �����                                                     " << endl;
	cout << "                                                     ��  ��   ��   ��  ��                                                    " << endl;
	cout << "                                                     ��  �� ������ ��  ��                                                    " << endl;
	cout << "                                                                                                                             " << endl;
	cout << "                                       ������ �����   ����  ������ ������ ������  ����                                       " << endl;
	cout << "                                         ��   ��  �� ��  �� ��     ��       ��   ��  ��                                      " << endl;
	cout << "                                         ��   �����  ������ ����   ����     ��   ��                                          " << endl;
	cout << "                                         ��   ��  �� ��  �� ��     ��       ��   ��  ��                                      " << endl;
	cout << "                                         ��   ��  �� ��  �� ��     ��     ������  ����                                       " << endl;
	cout << "                                                                                                                             " << endl;
	cout << "                                          ����   ����  ��  �� ������ �����   ����  ��                                        " << endl;
	cout << "                                         ��  �� ��  �� ��� ��   ��   ��  �� ��  �� ��                                        " << endl;
	cout << "                                         ��     ��  �� �� ���   ��   �����  ��  �� ��                                        " << endl;
	cout << "                                         ��  �� ��  �� ��  ��   ��   ��  �� ��  �� ��                                        " << endl;
	cout << "                                          ����   ����  ��  ��   ��   ��  ��  ����  ����                                      " << endl;
	cout << "                                                                                                                             " << endl;
	cout << "                                                                    �                                                        " << endl;
	cout << "                                                                     ���                                                     " << endl;
	cout << "                                                                        ���                                                  " << endl;
	cout << "                                                                         ����                                                " << endl;
	cout << "                                                                           ���                                               " << endl;
	cout << "                                                              �����         ���                                              " << endl;
	cout << "                                                           ���������         ���                                             " << endl;
	cout << "                                                          ����������         ���                                             " << endl;
	cout << " ���������_���������__������_�����_____�����������         ��������           �����������������������������������������������" << endl;
	cout << "       ��������������������������������������������            ���           ��������������������������������������_�����    " << endl;
	cout << "          �������                    ����������� ���            ���         ���  �������                         �����       " << endl;
	cout << "                ������������������������        �  ����           ����     ���  �       �������������������������            " << endl;
	cout << "                    �����         ����������������  ����           ����  ����  ���������������        ��������               " << endl;
	cout << "                           ��������������    �������  �����            ����  ������    ���������������                       " << endl;
	cout << "                               ��    ��������������     �����������������     ��������������   ����                          " << endl;
	cout << "                                       �������        ����   �������    ����       �������                                   " << endl;
	cout << "                                                       ��������������������                                                  " << endl;
	cout << "                                                      ���� ������������ ����                                                 " << endl;
	cout << "                                                     ����                ����                                                " << endl;
	cout << "                                                     ���                   �                                                 " << endl;
	waitenter();
}

void Menu::showMenu(int x)
{
	system("cls");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);

	cout << "\t\t����" << endl;
	for (int i = 1; i <= 8; i++)
	{
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " -> ";
		}
		else { cout << "    "; }
		switch (i)
		{
		case 1:
		{
			cout << "1. �������� ������ ������";
			break;
		}
		case 2:
		{
			cout << "2. �������� ����";
			break;
		}
		case 3:
		{
			cout << "3. ������ �� ������ ����";
			break;
		}
		case 4:
		{
			cout << "4. ���������� �� ����������";
			break;
		}
		case 5:
		{
			cout << "5. ����� �����";
			break;
		}
		case 6:
		{
			cout << "6. �������� �������";
			break;
		}
		case 7:
		{
			cout << "7. ���������";
			break;
		}
		case 8:
		{
			cout << "8. �����";
			break;
		}
		}
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " <- ";
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl;
	}
}

int Menu::main_click()
{
	int inpush;
	int option = 1;
	showMenu(option);
	bool ifexit = true;

	while (ifexit)
	{
		inpush = _getch();
		switch (inpush)
		{
		case 80:		// up
		{
			option++;
			if (option > 8) { option = 1; }
			showMenu(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 8; }
			showMenu(option);
			break;
		}
		case 13:		//enter
		{
			ifexit = false;
			break;
		}
		}
	}
	return option;
}

void Menu::showFind(int x)
{
	system("cls");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\t\t����� �� ��������" << endl;
	for (int i = 1; i <= 4; i++)
	{
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " -> ";
		}
		else { cout << "    "; }
		switch (i)
		{
		case 1:
		{
			cout << "1. ����� �� ��������";
			break;
		}
		case 2:
		{
			cout << "2. ����� �� �������������";
			break;
		}
		case 3:
		{
			cout << "3. ����� �� ����(������������/������������)";
			break;
		}
		case 4:
		{
			cout << "3. ����� �� ������";
			break;
		}
		}
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " <- ";
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl;
	}
}

int Menu::find_click()
{
	int inpush;

	int option = 1;
	showFind(option);
	bool ifexit = true;

	while (ifexit)
	{
		inpush = _getch();
		switch (inpush)
		{
		case 80:		// up
		{
			option++;
			if (option > 4) { option = 1; }
			showFind(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 4; }
			showFind(option);
			break;
		}
		case 13:		//enter
		{
			ifexit = false;
			break;
		}
		case 27:
		{
			option = 0;
			ifexit = false;
			break;
		}
		}
	}
	return option;
}

void Menu::showSort(int x)
{
	system("cls");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\t\t���������� �� ���������" << endl;
	for (int i = 1; i <= 4; i++)
	{
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " -> ";
		}
		else { cout << "    "; }
		switch (i)
		{
		case 1:
		{
			cout << "1. ���������� �� ��������";
			break;
		}
		case 2:
		{
			cout << "2. ���������� �� ���������";
			break;
		}
		case 3:
		{
			cout << "3. ���������� �� ����(������������/������������)";
			break;
		}
		case 4:
		{
			cout << "4. ���������� �� ������";
			break;
		}
		}
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " <- ";
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl;
	}
}

int Menu::sort_click()
{
	int inpush;

	int option = 1;
	showSort(option);
	bool ifexit = true;

	while (ifexit)
	{
		inpush = _getch();
		switch (inpush)
		{
		case 80:		// up
		{
			option++;
			if (option > 4) { option = 1; }
			showSort(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 4; }
			showSort(option);
			break;
		}
		case 13:		//enter
		{
			ifexit = false;
			break;
		}
		case 27:
		{
			option = 0;
			ifexit = false;
			break;
		}
		}
	}
	return option;
}

void Menu::showSetting(int x)
{
	system("cls");
	HANDLE h;
	cout << "\t\t���������" << endl;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 1; i <= 3; i++)
	{
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " -> ";
		}
		else { cout << "    "; }
		switch (i)
		{
		case 1:
		{
			cout << "1. �������� �������";
			break;
		}
		case 2:
		{
			cout << "2. �������� ������� ������";
			break;
		}
		case 3:
		{
			cout << "3. ��������� � ������� ����";
			break;
		}
		}
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " <- ";
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl;
	}
}

int Menu::setting_click()
{
	int inpush;

	int option = 1;
	showSetting(option);
	bool ifexit = true;

	while (ifexit)
	{
		inpush = _getch();
		switch (inpush)
		{
		case 80:		// up
		{
			option++;
			if (option > 3) { option = 1; }
			showSetting(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 3; }
			showSetting(option);
			break;
		}
		case 13:		//enter
		{
			ifexit = false;
			break;
		}
		case 27:
		{
			option = 4;
			ifexit = false;
			break;
		}
		}
	}
	return option;
}

void Menu::the_end()
{
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << endl;
	cout << " Made especially for the controllers and civil aviation officials...                                                         " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN);
	cout << "                                                                                                                             " << endl;
	cout << "                                                                    �                                                        " << endl;
	cout << "                                                                     ���                                                     " << endl;
	cout << "                                                                        ���                                                  " << endl;
	cout << "                                                                         ����                                                " << endl;
	cout << "                                                                           ���                                               " << endl;
	cout << "                                                              �����         ���                                              " << endl;
	cout << "                                                           ���������         ���                                             " << endl;
	cout << "                                                          ����������         ���                                             " << endl;
	cout << " ���������_���������__������_�����_____�����������         ��������           �����������������������������������������������" << endl;
	cout << "       ��������������������������������������������            ���           ��������������������������������������_�����    " << endl;
	cout << "          �������                    ����������� ���            ���         ���  �������                         �����       " << endl;
	cout << "                ������������������������        �  ����           ����     ���  �       �������������������������            " << endl;
	cout << "                    �����         ����������������  ����           ����  ����  ���������������        ��������               " << endl;
	cout << "                           ��������������    �������  �����            ����  ������    ���������������                       " << endl;
	cout << "                               ��    ��������������     �����������������     ��������������   ����                          " << endl;
	cout << "                                       �������        ����   �������    ����       �������                                   " << endl;
	cout << "                                                       ��������������������                                                  " << endl;
	cout << "                                                      ���� ������������ ����                                                 " << endl;
	cout << "                                                     ����                ����                                                " << endl;
	cout << "                                                     ���                   �           ";
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "     Project by Ilya danilovich   " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	waitenter();
	exit(1);
}

Menu::~Menu()
{
}
