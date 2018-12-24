#pragma once
class Flight
{
private:
	char name[30]; //�������� ��������
	char name_seria[30]; //�������� �����
	char company[30]; //��������
	int S; //����������
	int V; //��������
	int Fuel; //������ ������� 
	int type; //������������
	int type2; //��������
	int air_cargo; //����������������
	int mass_plane; //����� ��������
	int count; //������
	char waitingtime[10]; //���� 
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

