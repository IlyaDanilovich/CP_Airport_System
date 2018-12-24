#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <ctime>
#include <iostream>


using namespace std;

Date::Date()
{
}

bool Date::isEqual(char *str1, char *str2)
{
	bool answer = true;
	for (int i = 0; i < 10; i++)
		if (str1[i] != str2[i])
		{
			answer = false;
		}
	return answer;
}

int Date::dataIdentity(char *str2)
{
	char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	strftime(buffer, 80, "%d.%m.%Y", timeinfo);
	int month1 = (buffer[3] - '0') * 10 + (buffer[4] - '0');
	int day1 = (buffer[0] - '0') * 10 + (buffer[1] - '0');
	int year1 = (buffer[6] - '0') * 1000 + (buffer[7] - '0') * 100 + (buffer[8] - '0') * 10 + (buffer[9] - '0');
	int day2 = (str2[0] - '0') * 10 + (str2[1] - '0');
	int month2 = (str2[3] - '0') * 10 + (str2[4] - '0');
	int year2 = (str2[6] - '0') * 1000 + (str2[7] - '0') * 100 + (str2[8] - '0') * 10 + (str2[9] - '0');

	int answer;

	if ((month1 == month2) && (year1 == year2)) { answer = day2 - day1; }
	if ((month1 == month2) && (year1 > year2)) { answer = year2 - year1; }
	if ((month1 == month2) && (year1 < year2)) { answer = year2 - year1; }
	if ((month2 > month1) && (year1 == year2)) { answer = 31 - day1 + (month2 - month1 - 1) * 31 + day2; }
	if ((month2 > month1) && (year1 > year2)) { answer = -(day1 + (month1 - 1) * 31 + (13 - month2 - 1) * 31 + (31 - day2)); }
	if ((month2 > month1) && (year1 < year2)) { answer = day2 + (month2 - 1) * 31 + (13 - month1 - 1) * 31 + (31 - day1);; }
	if ((month2 < month1) && (year1 == year2)) { answer = -(day1 + (month1 - month2 - 1) * 31 + (31 - day2)); }
	if ((month2 < month1) && (year1 < year2)) { answer = day2 + (month2 - 1) * 31 + (13 - month1 - 1) * 31 + (31 - day1); }
	if ((month2 < month1) && (year1 > year2)) { answer = -(day1 + (month1 - 1) * 31 + (13 - month2 - 1) * 31 + (31 - day2)); }

	return answer;
}

bool Date::compare(char *s1, char *s2)
{
	int month1 = (s1[3] - '0') * 10 + (s1[4] - '0');
	int day1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int year1 = (s1[6] - '0') * 1000 + (s1[7] - '0') * 100 + (s1[8] - '0') * 10 + (s1[9] - '0');
	int day2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	int month2 = (s2[3] - '0') * 10 + (s2[4] - '0');
	int year2 = (s2[6] - '0') * 1000 + (s2[7] - '0') * 100 + (s2[8] - '0') * 10 + (s2[9] - '0');

	if (year1 > year2) { return true; }
	if (year1 < year2) { return false; }
	if (month1 > month2) { return true; }
	if (month1 < month2) { return false; }
	if (day1 > day2) { return true; }
	else { return false; }
}

Date::~Date()
{
}
