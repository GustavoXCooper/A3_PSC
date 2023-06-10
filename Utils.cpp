#include "Utils.h"

Utils::Utils() {}

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

string Utils::formatAuthorName() {
	bool running = true;

	string name;
	cout << "\nInsira o nome do autor: ";
	// pedir pro sor explicar isso tava dando um erro insuportável sem isso
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (running) {
		getline(cin, name);
		if (containsSpecialCharacters(name) || containsNumbers(name)) {
			cout << "\nNome não pode conter caracteres especiais ou números.\n";
		}
		else {
			running = false;
		}
	}

	return name;

}
string Utils::formatBookTitle() {
	string name;

	cout << "\nInsira o título do livro: ";
	getline(cin, name);

	if (!shorterThan(name)) {
		cout << "\nO título deve conter no máximo " << 80 << " characteres.\n";
		name = formatBookTitle();
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
	cout << "\n3. Terror\n";
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
			cout << "\nValor inválido. Tente novamente.\n";
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
	cout << "\n3. Acabado\n";
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
			cout << "\nValor inválido. Tente novamente.8";
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
	cout << "\n2. Não\n";
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
			cout << "\nValor inválido. Tente novamente.\n";
			break;
		}
	}
	return answer;
}
string Utils::formatPublishingCompany() {
	bool running = true;
	string newPublishingCompany;

	cout << "Insira o nome da editora: ";
	// pedir pro sor explicar isso tava dando um erro insuportável sem isso

	do {
		getline(cin, newPublishingCompany);

		// Chat gpt salvando vidas perguntar pro sor isso tava dando erro 
		if (!cin) {
			cout << "\nErro na leitura da entrada.\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (containsNumbers(newPublishingCompany) || containsSpecialCharacters(newPublishingCompany)) {
			cout << "\nNome da editora não pode contar caracteres especiais ou números.\n";
		}
		else {

			running = false;
		}
	} while (running);

	return newPublishingCompany;

}
int Utils::formatPageNumber() {
	string pages;
	int returnPages;
	bool running = true;

	cout << "\nInsira o número de páginas do livro:\n ";

	while (running) {
		cin >> pages;
		if (!containsOnlyNumbers(pages)) {
			cout << "\nValor inválido. O número de páginas deve ser positivo.\n";
		}
		else {
			returnPages = stoi(pages);
			if (returnPages > 0) {
				running = false;
			}
			else {
				cout << "\nValor inválido. O número de páginas deve ser positivo.\n";
			}
		}
	}

	return returnPages;
}
float Utils::formatPrice() {
	string price;
	float returnPrice;
	bool running = true;

	cout << "\nInsira o valor do livro: ";
	while (running) {
		cin >> price;
		if (!containsOnlyNumbers(price)) {
			cout << "\nValor inválido. O preço deve ser positivo.\n";
		}
		else {
			returnPrice = stof(price);
			if (returnPrice > 0) {
				running = false;
			}
			else {
				cout << "\nValor inválido. O preço deve ser positivo.\n";
			}
		}
	}
	return returnPrice;
}
