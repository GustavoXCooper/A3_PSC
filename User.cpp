#include "User.h"
#include <cctype>

User::User(string name, string surname, Date birthDate, string phoneNumber, string email, string password) {
	this->name = name;
	this->surname = surname;
	setNameComplete(name, surname);
	this->birthDate = &birthDate;
	this->phoneNumber = phoneNumber;
	this->email = email;
	this->password = password;
	usingUtils = new Utils();
}


void User::setNameComplete(string name, string surname) { nameComplete = name + " " + surname; }
string User::getNameCompelte() { return nameComplete; }

void User::setName(string name) { 
	if (!usingUtils->containsSpecialCharacters(name) && !usingUtils->containsNumbers(name) && !usingUtils->containsSpace(name)) {
		this->name = name;
		setNameComplete(name, surname);
	}
	else {
		cout << "\nValor inv�lido. Nomes n�o podem conter n�meros, caracteres especiais ou espa�o.";
	}	
}
string User::getName() { return name; }

void User::setSurname(string surname) { 
	if (!usingUtils->containsSpecialCharacters(surname) && !usingUtils->containsNumbers(surname)) {
		this->surname = surname;
		setNameComplete(name, surname);
	}
	else {
		cout << "\nValor inv�lido. Nomes n�o podem conter n�meros ou caracteres especiais.";
	}
}
		

string User::getSurname() { return surname; }

void User::setPhoneNumber(string phoneNumber) {
	// FOR NOW it will only check if it has the right amount of numbers and if theres no letters or symbols
	if(!usingUtils->containsSpecialCharacters(phoneNumber) && !usingUtils->containsSpace(phoneNumber) && usingUtils->containsOnlyNumbers(phoneNumber)) {
		this->phoneNumber = phoneNumber;
	}
	else {
		cout << "\nN�mero de telefone inv�lido. N�mero de telefone s� pode conter n�meros.";
	}
}
string User::getPhoneNumber() { return phoneNumber; }

void User::setEmail(string email) { 
	if (usingUtils->isEmailValid(email)) {
		this->email = email;
	}
	else {
		cout << "Email inv�lido.";
	}
}
string User::getEmail() { return this->email; }

void User::setPassword(string password) { this->password = password; }
string User::getPassword() { return password; }