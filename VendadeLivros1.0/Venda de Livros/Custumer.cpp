#include "Custumer.h"

Custumer::Custumer(
	string name,
	string surname,
	Date birthDate,
	string phoneNumber,
	string email,
	string password) :User(name, surname, birthDate, phoneNumber, email, password) {
	this->usingUtils = usingUtils;
}

void Custumer::displayMessagedSeller() {
	if (messagedSellers.size() < 1) {
		cout << "\nNenhuma mensagem encontrada.\n";
	}
	else {
		for (int i = 0; i < messagedSellers.size(); i++) {
			cout << endl << messagedSellers[i];
		}
	}
	cout << "Pressione ENTER para prosseguir.";
	system("pause");
}
void Custumer::setNewMessagedSeller(string email) { messagedSellers.push_back(email); }