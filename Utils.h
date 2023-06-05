#ifndef UTILS_H
#define UTILS_H
#include <iostream>
using namespace std;


class Utils {
public:
	Utils();
	bool containsSpecialCharacters(string& string);
	bool containsNumbers(string& string);
	bool containsSpace(string& string);
	bool isEmailValid(string& email);
	bool containsOnlyNumbers(string& string);
	bool shorterThan(string& string);

	// bool foundSameString(string& stringBeingTested, string& existingString); Don't know if it'll be needed

	// more specific utils
	string setAuthorName();
	string setBookTitle();
	string chooseFromAllAvailableGenres();
	string chooseFromAllConditions();
	bool isBargainable();
	string setPublishingCompany();
};

#endif
