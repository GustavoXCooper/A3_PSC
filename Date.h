#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date {
public:
	Date(int day, int month, int year);
	string GetDay();
	void SetDay(int day);
	string GetMonth();
	void SetMonth(int month);
	string GetYear();
	void SetYear(int year);
	string GetFullDate();


private:
	int day;
	int month;
	int year;
};

#endif
