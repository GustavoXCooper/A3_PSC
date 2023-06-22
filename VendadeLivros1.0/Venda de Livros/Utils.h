#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;


class Utils {
public:
	Utils();
	bool containsAt(string& string);
	bool higherThan(int number, int maxNumber);
	bool containsSpecialCharacters(string& string);
	bool containsNumbers(string& string);
	bool containsSpace(string& string);
	bool isEmailValid(string& email);
	bool containsOnlyNumbers(string& string);
	bool shorterThan(string& string, int maxSize);

	// bool foundSameString(string& stringBeingTested, string& existingString); Don't know if it'll be needed
	// utils for date
	bool isDayValid(string day);
	bool isMonthValid(string month);
	bool isYearValid(string year);

	// more specific utils
	string formatAuthorName();
	string formatBookTitle();
	string chooseFromAllAvailableGenres();
	string chooseFromAllConditions();
	bool isBargainable();
	string formatPublishingCompany();
	int formatPageNumber();
	float formatPrice();
	bool isPriceValid(string string);
	float formatPriceAgain();

	// utils specific for account creation
	string formatUserName();
	string formatUserSurname();
	Date formatUserBirthDate();
	string formatPhoneNumber();
	string formatEmail();
	string formatPassword();
};

#endif
