#include "Utils.h"

Utils::Utils() {}
bool Utils::isPriceValid(string string) {
	for (char c : string) {
		if (!isdigit(c) && c != '.') { 
			return false;
		}
	}
	return true;
}
bool Utils::containsAt(string& string) {
	for (char c : string) {
		if (c == '@') {
			return true;
		}
	}
	return false;
}
bool Utils::higherThan(int number, int maxNumber) {
	bool isNumberHigher;

	if (number > maxNumber) {
		isNumberHigher = true;
	}
	else {
		isNumberHigher = false;
	}

	return isNumberHigher;
}
bool Utils::containsSpecialCharacters(string& string) {
	for (char c : string) {
		if (!isspace(c)) {
			if (!isalpha(c)) {
				return true;
			}
		}
	}
	return false;
}
bool Utils::containsNumbers(string& string) {
	for (char c : string) {
		if (isdigit(c)) {
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


// This are more specific utils

string Utils::formatAuthorName() {
	bool running = true;

	string name;
	cout << "\nInsira o nome do autor: ";
	// pedir pro sor explicar isso tava dando um erro insuport�vel sem isso
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.ignore();
	while (running) {
		getline(cin, name);
		if (containsSpecialCharacters(name) || containsNumbers(name)) {
			cout << "\nNome n�o pode conter caracteres especiais ou n�meros.\n";
		}
		else {
			running = false;
		}
	}

	return name;

}
string Utils::formatBookTitle() {
	string name;
	int const maxSize = 80;

	cout << "\nInsira o t�tulo do livro: ";
	cin.ignore();
	getline(cin, name);

	if (!shorterThan(name, maxSize)) {
		cout << "\nO t�tulo deve conter no m�ximo " << maxSize << " characteres.\n";
		name = formatBookTitle();
	}

	return name;
}
string Utils::chooseFromAllAvailableGenres() {
	int trueChoice = -1;
	string genreChoice, choice;
	bool running = true;
	cout << "\n\nEscolha o g�nero a ser registrado: ";
	cout << "\n1. Romance";
	cout << "\n2. Fantasia";
	cout << "\n3. Terror\n";
	while (running) {
		cin >> choice;
		if (containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = -1;
		}
		switch (trueChoice) { 
		case 1:
			genreChoice = "Romance";
			running = false;
			break;
		case 2:
			genreChoice = "Fantasia";
			running = false;
			break;
		case 3:
			genreChoice = "Terror";
			running = false;
			break;
		default:
			cout << "\nValor inv�lido. Tente novamente.\n";
			break;
		}
	}
	return genreChoice;

}
string Utils::chooseFromAllConditions() {
	int trueChoice;
	string choice;
	string conditionChoice;
	bool running = true;

	cout << "\n\nEscolha a condi��o do livro a ser registrado: ";
	cout << "\n1. Novo";
	cout << "\n2. Seminovo";
	cout << "\n3. Usado\n";
	// depois a gente adiciona mais uns valores
	while (running) {

		cin >> choice;
		if (containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = -1;
		}

		switch (trueChoice) {
		case 1:
			conditionChoice = "Novo";
			running = false;
			break;
		case 2:
			conditionChoice = "Seminovo";
			running = false;
			break;
		case 3:
			conditionChoice = "Usado";
			running = false;
			break;
		default:
			cout << "\nValor inv�lido. Tente novamente.\n";
			break;
		}

	}
	return conditionChoice;
}
bool Utils::isBargainable() {
	bool answer, running = true;
	string choice;
	int trueChoice;

	cout << "\nO livro � negoci�vel? ";
	cout << "\n1. Sim";
	cout << "\n2. N�o\n";
	while (running) {

		cin >> choice;
		if (containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = -1;
		}
		switch (trueChoice) {
		case 1:
			answer = true;
			running = false;
			break;
		case 2:
			answer = false;
			running = false;
			break;
		default:
			cout << "\nValor inv�lido. Tente novamente.\n";
			break;
		}
	}
	return answer;
}
string Utils::formatPublishingCompany() {
	bool running = true;
	string newPublishingCompany;

	cout << "Insira o nome da editora: ";

	do {
		getline(cin, newPublishingCompany);

		// Chat gpt salvando vidas perguntar pro sor isso tava dando erro 
		if (!cin) {
			cout << "\nErro na leitura da entrada.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (containsNumbers(newPublishingCompany) || containsSpecialCharacters(newPublishingCompany)) {
			cout << "\nNome da editora n�o pode contar caracteres especiais ou n�meros.\n";
		}
		else {

			running = false;
		}
	} while (running);

	return newPublishingCompany;

}
int Utils::formatPageNumber() {
	string pages;
	int truePages;
	bool running = true;

	cout << "\nInsira o n�mero de p�ginas do livro: ";

	while (running) {
		cin >> pages;
		if (!containsOnlyNumbers(pages)) {
			cout << "\nValor inv�lido. O n�mero de p�ginas deve ser positivo.\n";
		}
		else {
			truePages = stoi(pages);
			if (truePages > 0) {
				running = false;
			}
			else {
				cout << "\nValor inv�lido. O n�mero de p�ginas deve ser positivo.\n";
			}
		}
	}

	return truePages;
}
float Utils::formatPrice() {
	float price;
	cout << "\nInsira o valor do livro: ";
	cin >> price;
	return price;
		
	

	// For whatever reason this didn't work
	// couldn't make the string turn to float idk why
	/*
	string price;
	double truePrice=0;
	bool running = true;

	
	cout << "\nInsira o valor do livro: ";
	while (running) {
		cin >> price;
		if (isPriceValid(price)) {
			truePrice = stod(price);
			if (truePrice > 0) {
				running = false;
			}
			else {
				cout << "\nValor inv�lido. O pre�o deve ser positivo.\n";
			}
		}
		else {
			cout << "\nValor inv�lido. Tente novamente.\n";
			cout << "\nExemplo de formato v�lido: 5.99\n";
		}
	}
	return truePrice;
	*/
}

// Utils for date
bool Utils::isDayValid(string day) {
	int dayInt;

	if (!containsOnlyNumbers(day)) {
		return false;
	}
	dayInt = stoi(day); 
	return (higherThan(dayInt, 0) && !higherThan(dayInt, 31)); 
}
bool Utils::isMonthValid(string month) { 
	int monthInt; 
	if (!containsOnlyNumbers(month)) { 
		return false;
	} else{
		monthInt = stoi(month);
		return (!higherThan(monthInt, 12) && higherThan(monthInt, 0));
	}
	
}
bool Utils::isYearValid(string year) {
	int yearInt;
	if (!containsOnlyNumbers(year)) {
		return false;
	}
	else {
		yearInt = stoi(year);
		if (!higherThan(yearInt, 1900)) {
			return false;
		}
	}
	return true;
}
// Utils for accounts 
string Utils::formatUserName() {
	bool running = true;

	string name;
	cout << "\nInsira seu nome: ";
	cin.ignore();
	while (running) {
		getline(cin, name);
		if (containsSpecialCharacters(name) || containsNumbers(name) || name.size() < 1) {
			cout << "\nNome n�o pode conter caracteres especiais ou n�meros.\n";
		}
		else {
			running = false;
		}
	}

	return name;
}
string Utils::formatUserSurname() {
	string surname;
	bool running = true;
	int const maxSize = 40;

	cout << "\nInsira seu sobrenome: ";
	while (running) {
		getline(cin, surname);
		if (
			(shorterThan(surname, maxSize) &&
			containsNumbers(surname) &&
			containsSpecialCharacters(surname)) ||
			surname.size() < 1
			) 
		{
			cout << "\nO sobrenome deve conter no m�ximo " << maxSize << " characteres e n�o pode conter n�meros ou caracteres especiais.\n";
		}
		else {
			running = false;
		}
	}

	return surname;
}
Date Utils::formatUserBirthDate() {
	string day, year, month;
	int dayInt, yearInt, monthInt;
	
	for (int i = 0; i < 3; i++) {
		switch (i) {
		case 0:
			cout << "\nInsira o dia de anivers�rio: ";
			cin >> day;
			if (!isDayValid(day)) {
				i--;
				cout << "\nValor inv�lido. Tente novamente.\n";
			}
			break;
		case 1:
			cout << "Insira o m�s: ";
			cin >> month;
			if (!isMonthValid(month)) {
				i--;
				cout << "\nValor inv�lido. Tente novamente.\n";
			}
			break;
		case 2:
			cout << "Insira o ano: ";
			cin >> year;
			if (!isYearValid(year)) {
				i--;
				cout << "\nValor inv�lido. Tente novamente.\n";
			}
			break;
		}
	}

	dayInt = stoi(day);
	monthInt = stoi(month);
	yearInt = stoi(year);

	Date* date = new Date(dayInt, monthInt, yearInt);
	return *date;
}
string Utils::formatPhoneNumber(){
	string phoneNumber;
	bool running = true;
	cout << "Insira o n�mero de telefone: ";
	while (running) {
		cin >> phoneNumber;
		if (!containsOnlyNumbers(phoneNumber)) {
			cout << "\nN�mero de telefone pode conter apenas n�meros. Tente novamente.\n";
		}
		else {
			running = false;
		}
	}
	return phoneNumber;
}
string Utils::formatEmail() {
	string email;
	bool running = true;
	cout << "Insira seu email: ";
	while (running) {
		cin >> email;
		if (!containsAt(email)) {
			cout << "\nEmail inv�lido. Tente novamente.\n";
		}
		else {
			running = false;
		}
	}
	return email;
}
string Utils::formatPassword() {
	string password; 
	int passwordSize;
	bool running = true; 
	cout << "Insira sua senha: ";
	while (running) { 
		cin >> password;
		// Perguntar pq static_cast<int>
		passwordSize = static_cast<int>(password.size());
		// Testar esse neg�cio da senha ! Ver se ta tudo certo
		if (!containsSpecialCharacters(password) || !containsNumbers(password) || !higherThan(passwordSize, 4)) {
			cout << "\nA senha deve conter caracteres especiais, n�meros e ao menos 4 caracteres.\n"; 
		}
		else { 
			running = false; 
		}
	}
	return password;
}