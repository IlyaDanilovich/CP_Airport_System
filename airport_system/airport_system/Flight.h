#pragma once
class Flight
{
private:
	char name[30]; //Название самолета
	char name_seria[30]; //Серийный номер
	char company[30]; //Компания
	int S; //Расстояние
	int V; //Скорость
	int Fuel; //Расход топлива 
	int type; //пассажирский
	int type2; //грузовой
	int air_cargo; //Грузоподъемность
	int mass_plane; //Масса самолета
	int count; //экипаж
	char waitingtime[10]; //Дата 
public:
	Flight();
	Flight(char*, char*, char *, int, int, int, int, int, int, int, int, char*);
	void show();
	void showFlight();
	bool check_name(char*);
	bool check_company(char*);
	bool check_type(int);
	bool check_date(char*);
	char* getName();
	char* getName_seria();
	char* getCompany();
	int getS();
	int getV();
	int getFuel();
	int getType();
	int getType2();
	int getAir_cargo();
	int getMass_plane();
	int getCount();
	char* getDate();
	~Flight();
};

