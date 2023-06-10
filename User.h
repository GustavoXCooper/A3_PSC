#ifndef USER_H
#define USER_H
#include <iostream>
#include "Date.h"
#include "Utils.h"

class User {
public:
	User(string name, string surname, Date birthDate, string phoneNumber, string email, string password);
	Utils* usingUtils;

	void setNameComplete(string name, string surname);
	string getNameCompelte();

	void setName(string name);
	string getName();

	void setSurname(string surname);
	string getSurname();

	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();

	void setEmail(string email);
	string getEmail();

	void setPassword(string password);
	string getPassword();
private:
	string name;
	string surname;
	string nameComplete;
	Date* birthDate;
	string phoneNumber;
	string email;
	string password;
};

#endif
