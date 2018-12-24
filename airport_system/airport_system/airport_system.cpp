#include <iostream>
#include "Menu.h"
#include "Database.h"
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "OpenFileExpception.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Database data;
	Menu menu;
	try
	{
		data.read_database();
		system("mode 127,40");
		menu.start();
		system("mode 50,11");
		int pick = menu.main_click();
		while (pick != 8)
		{
			switch (pick)
			{
			case 1:
			{
				system("mode 147,20");
				COORD crd = { 147, 100 };
				SMALL_RECT src = { 0, 0, crd.X, crd.Y };
				SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), crd);
				data.show_color();
				break;
			}
			case 2:
			{
				system("mode 72,15");
				data.addObject();
				break;
			}
			case 3:
			{
				system("mode 78,20");
				data.delObject();
				break;
			}
			case 4:
			{
				system("mode 56,15");
				data.sort();
				break;
			}
			case 5:
			{
				system("mode 65,20");
				data.find();
				break;
			}
			case 6:
			{
				system("mode 145,20");
				COORD crd = { 145, 100 };
				SMALL_RECT src = { 0, 0, crd.X, crd.Y };
				SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), crd);
				data.history();
				break;
			}
			case 7:
			{
				system("mode 46,10");
				data.setting();
				break;
			}
			default:
			{
				system("cls");
				cout << "Произошла ошибка. Запрос неизвестной операции.\nНажмите ENTER чтобы вернуться в главное меню или ESC для выхода";
				bool ifexit = true;
				while (ifexit)
				{
					int inpush;
					inpush = _getch();
					switch (inpush)
					{
					case 13:
					{
						ifexit = false;
						break;
					}
					case 27:
					{
						ifexit = false;
						exit(1);
					}
					}
				}
			}
			}
			system("mode 50,11");
			pick = menu.main_click();
		}
		data.save_in_database();
		system("mode 129,25");
		menu.the_end();
	}
	catch (OpenFileExpception *a)
	{
		cout << a->what() << endl; system("pause");
	}
	catch (bad_alloc)
	{
		cout << "Error memory!!!" << endl; system("pause");
	}
	catch (...)
	{
		cout << "Unknow Error!!!" << endl; system("pause");
	}
	return 0;
}