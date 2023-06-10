#include "Seller.h"
#include <Windows.h>

Seller::Seller(string name, string surname, Date birthDate, string phoneNumber, string email, string password) : User(name, surname, birthDate, phoneNumber, email, password) {
	this->usingUtils = usingUtils;
}



void Seller::addNewBook() {
	string bookTitle, bookSummary, genre, condition, authorName, publishingCompany;
	bool bargainable, running = true;
	float price;
	int pages;

	// talvez transformar isso em uma função de utils, ai só entra com o título (que no caso é resigtrando livro)
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
	cout << "\n=-=-=-=-= Registrando Livro =-=-=-=-=-=";
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";

	bookTitle = usingUtils->formatBookTitle();
	pages = usingUtils->formatPageNumber();

	// Talvez criar uma classe só pra isso, com alguns arrays, sendo cada um deles 1 paragráfo
	// Ou um array dentro de livro mesmo
	cout << "\n\nInsira o resumo do livro: ";
	getline(cin, bookSummary);

	genre = usingUtils->chooseFromAllAvailableGenres();
	bargainable = usingUtils->isBargainable();
	condition = usingUtils->chooseFromAllConditions();
	// nao aceita float só int
	cin.ignore();
	price = usingUtils->formatPrice();

	authorName = usingUtils->formatAuthorName();
	publishingCompany = usingUtils->formatPublishingCompany();

	Book newBook(bookTitle, pages, bookSummary, condition, genre, bargainable, price, authorName, publishingCompany);
	books.push_back(newBook);

}
void Seller::removeBook() {
	int choice;
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
	cout << "\n=-=-=-=-=  Removendo Livro  =-=-=-=-=-=";
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";

	cout << "\n\nLista de Livros: ";
	for (int i = 0; i < books.size(); i++) {
		cout << endl << (i + 1) << "." << books[i].getTitle();
	}
	cout << "\nQual livro deseja remover? ";
	cin >> choice;
	choice--;

	books.erase(books.begin() + choice);
}
void Seller::editBook() {
	int bookChoice, dataOption, pages;
	string string;
	float price;
	bool running = true;
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
	cout << "\n=-=-=-=-=-= Editando Livro =-=-=-=-=-=-=";
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";

	cout << "\n\nLista de Livros: ";
	for (int i = 0; i < books.size(); i++) {
		cout << (i + 1) << "." << books[i].getTitle();
	}
	cout << "\nQual livro deseja editar?";
	cin >> bookChoice;
	bookChoice--;

	cout << "\nQual informação deseja alterar? ";
	cout << "\n1. Título\n2. N° de páginas\n3. Condição\n4. Negociável\n5. Preço\n6. Autor\n7. Editora";
	cin >> dataOption;
	while (running) {
		switch (dataOption) {
		case 1:
			books[bookChoice].setTitle();
			running = false;
			break;
		case 2:
			cout << "\nInsira o número de páginas: ";
			cin >> pages;
			books[bookChoice].setPages(pages);
			running = false;
			break;
		case 3:
			books[bookChoice].setCondition();
			running = false;
			break;
		case 4:
			books[bookChoice].setBargainable();
			running = false;
			break;
		case 5:
			books[bookChoice].setPrice();
			running = false;
			break;
		case 6:
			books[bookChoice].setAuthor();
			running = false;
			break;
		case 7:
			books[bookChoice].setPublishingCompany();
			running = false;
			break;
		default:
			cout << "Valor inválido, tente novamente.4";
		}
	}

}
Book Seller::getBook(int bookNumber) {
	return books[bookNumber];
}
void Seller::addNewComplaint() {
	string reason, description;
	cout << "\nInsira o motivo da denúncia: ";
	cin >> reason;
	cout << "\nInsira uma descrição da denúncia; ";
	cin >> description;
	Complaint complaint(reason, description);
	complaints.push_back(complaint);
}
Complaint Seller::getComplaint(int complaintNumber) {
	return complaints[complaintNumber];
}
