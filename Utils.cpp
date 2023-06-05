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
bool Utils::shorterThan(string& string) { 
	if (string.size() > 80) {
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


// This are more specific utils

string Utils::setAuthorName() {
	string name;
	do {
		cout << "\n\nInsira o nome do autor: ";
		cin >> name;

		if (containsSpecialCharacters(name) || containsNumbers(name)) {
			cout << "Nome não pode conter caracteres especiais ou números.";
		}
	} while (containsSpecialCharacters(name) || containsNumbers(name));
	return name;
}
string Utils::setBookTitle() {
	string name;
	bool running = true;
	while (running) {
		cout << "\nInsira o título do livro: ";
		cin >> name;
		if (shorterThan(name)) {
			running = false;
		}
		else {
			cout << "\nO título deve conter no máximo " << 80 << " characteres.";
		}
	}
	return name;
}
// Tanto para gênero quanto condições, poderia criar uma classe com um array dentro e tirar as opções de la seria melhor? Ou assim é melhor?
string Utils::chooseFromAllAvailableGenres() {
	int choice;
	string genreChoice;
	bool running = true;
	cout << "\n\nEscolha o gênero a ser registrado: ";
	cout << "\n1. Romance";
	cout << "\n2. Fantasia";
	cout << "\n3. Terror";
	while (running) {
		cin >> choice;
		switch (choice) {
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
			cout << "\nValor inválido. Tente novamente.";
			break;
		}

	}
	return genreChoice;

}
string Utils::chooseFromAllConditions() {
	int choice;
	string conditionChoice;
	bool running = true;

	cout << "\n\nEscolha a condição do livro a ser registrado: ";
	cout << "\n1. Novo";
	cout << "\n2. Seminovo";
	cout << "\n3. Acabado";
	// depois a gente adiciona mais uns valores
	while (running) {
		cin >> choice;
		switch (choice) {
		case 1:
			conditionChoice = "Novo";
			running = false;
			break;
		case 2:
			conditionChoice = "Seminovo";
			running = false;
			break;
		case 3:
			conditionChoice = "Acabado";
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.";
			break;
		}

	}
	return conditionChoice;
}
bool Utils::isBargainable() {
	bool answer, running = true;
	int choice;

	cout << "\nO livro é negociável? ";
	cout << "\n1. Sim";
	cout << "\n2. Não";
	while (running) {
		cin >> choice;
		switch (choice) {
		case 1:
			answer = true;
			running = false;
			break;
		case 2:
			answer = false;
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.";
			break;
		}
	}
	return answer;
}
string Utils::setPublishingCompany() {
	bool running = false;
	string newPublishingCompany;
	while (running) {
		cout << "Insira o nome da editora: ";
		cin >> newPublishingCompany;
		if (!containsNumbers(newPublishingCompany) && !containsSpecialCharacters(newPublishingCompany)) {
			running = false;
		}
		else {
			cout << "Nome da editora não pode contar caracteres especiais ou números.";
		}
	} 
	return newPublishingCompany;
}
