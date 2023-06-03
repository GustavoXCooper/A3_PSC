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
};


#endif
