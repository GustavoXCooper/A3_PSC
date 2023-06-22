#include "User.h"
#include <cctype>

User::User(string name, string surname, Date birthDate, string phoneNumber, string email, string password) {
	this->name = name;
	this->surname = surname;
	setNameComplete(name, surname);
	this->birthDate = birthDate;
	this->phoneNumber = phoneNumber;
	this->email = email;
	this->password = password;
	usingUtils = new Utils();
}


void User::setNameComplete(string name, string surname) { nameComplete = name + " " + surname; }
string User::getNameComplete() { return nameComplete; }

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
	// FOR NOW it will only check if theres no letters or symbols
	if (usingUtils->containsOnlyNumbers(phoneNumber)) {
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

// Talvez os m�todos set tenham ficado sem uso por conta desses pr�ximos, 
// posso apagar os antigos e chamar esses novos de set?

void User::changeUserInfo(){
	system("cls");

	// Receber string e mudar p int depois!! tem q fazer isso no c�pdigo inteiro

	int trueChoice = 0;
	string choice;
	bool running = true;

	cout << "=== Editar Perfil ===\n";
	cout << "Voc� deseja editar\n1. Nome\n2. Data de nascimento\n3. Sua senha\n";

	while (running) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
			switch (trueChoice) {
			case 1:
				changeName();
				running = false;
				break;
			case 2:
				changeBirthDate();
				running = false;
				break;
			case 3:
				changePassword();
				running = false;
				break;
			default:
				cout << "\nValor inv�lido. Tente novamente.\n";
			}
		}
		else {
			cout << "\nValor inv�lido. Tente novamente.\n";
		}
		
	}

}
void User::changePassword(){
	string checkingPassword, newPassword;
	bool running = true;

	cout << "\nInsira sua senha atual: ";

	while (running) {
		cin >> checkingPassword;
		if (checkingPassword == password) {
			newPassword = usingUtils->formatPassword();
			running = false;
		}
		else {
			cout << "\nSenha incorreta. Tente novamente.\n";
		}
	}
	password = newPassword;
}
void User::changeBirthDate(){
	// Isso aqui foi testando loucamente n sei se funciona mas o compilador n ta gritando na minha cara
	// � um bom sinal
	// n�?
	// N�???
	Date date = usingUtils->formatUserBirthDate();
	birthDate = date;
}
void User::changeName(){
	name = usingUtils->formatUserName();
	surname = usingUtils->formatUserSurname();
	setNameComplete(name, surname);
}
void User::displayUserInfo(){
	system("cls");
	string choice;
	cout << "=== Suas Informa��es ===";
	cout << "\n\nNome: " << nameComplete;
	cout << "\nData de nascimento:" << birthDate.GetFullDate();
	cout << "\nEmail: " << email;
	// the idea is to wait for the user to press ENTER, so they can see their info for as long as they want
	cout << "\nAperte ENTER para continuar. ";
	system("pause");
}