#include "Date.h"

Date::Date(int day, int month, int year) {
	if (day > 1 && day < 31) {
		this->day = day;
	}
	else {
		this->day = 1;
	}

	if (month > 1 && month < 12) {
		this->month = month;
	}
	else {
		this->month = 1;
	}
	if (year < 1900) {
		this->year = 1900;
	}
	else {
		this->year = year;
	}
}

string Date::GetDay() {
	string dayString;
	if (day < 10) {
		dayString = "0" + std::to_string(day);
	}
	else {
		dayString = std::to_string(day);
	}
	return dayString;
}
void Date::SetDay(int day) {
	if (day > 0 && day <= 31) {
		this->day = day;
	}
	else {
		cout << "\nValor inserido é inválido1.";
	}
}

string Date::GetMonth() {
	string monthString;
	if (month < 10) {
		monthString = "0" + std::to_string(month);
	}
	else {
		monthString = std::to_string(month);
	}
	return monthString;
}

void Date::SetMonth(int month) {
	if (month > 0 && month <= 12) {
		this->month = month;
	}
	else {
		cout << "\nValor inserido é inválido2.";
	}
}

string Date::GetYear() {
	return to_string(year);
}

void Date::SetYear(int year) {
	if (year > 1500) {
		this->year = year;
	}
	else {
		cout << "\nValor inserido é inválido.3";
	}
}

string Date::GetFullDate() {
	string fullDate;

	fullDate = "\n" + GetDay() + "/" + GetMonth() + "/" + GetYear();

	return fullDate;
}
