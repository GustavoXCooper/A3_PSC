#include "Utils.h"

Utils::Utils() {}

bool Utils::containsSpecialCharacters(string& string) {
	for (char c : string) {
		if (!isalpha(c)) {
			return true;
		}
	}
	return false;
}
bool Utils::containsNumbers(string& string) {
	for (char c : string) {
		if (!isdigit(c)) {
			return true;
		}
	}
	return false;
}
bool Utils::containsSpace(string& string) {
	for (char c : string) {
		if (!isspace(c)) {
			return true;
		}
	}
	return false;
}
bool Utils::isEmailValid(string& email) {
	// FOR NOW, the only thing it will look for is if theres the character "@" and ".". I'll improve this later
	for (char c : email) {
		if (c == '@') { return true; }
	}
	return false;
}
bool Utils::containsOnlyNumbers(string& string) {
	for (char c : string) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}
bool Utils::shorterThan(string& string, int maxSize) { 
	if (string.size() > maxSize) {
		return false;
	}
	else {
		return true;
	}
}

/*  Dont know if it'll be needed
bool foundSameString(string& stringBeingTested, string& existingString) {
	if (existingString == stringBeingTested ? true : false);
}
*/
