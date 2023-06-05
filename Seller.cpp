#include "Seller.h"

Seller::Seller(string name, string surname, Date birthDate, string phoneNumber, string email, string password) : User(name, surname, birthDate, phoneNumber, email, password) {
	Utils* usingUtils = new Utils();
}



void Seller::addNewBook(Book book){
	string bookTitle, bookSummary, genre, condition, authorName, publishingCompany;
	bool bargainable;
	float price;
	int pages;

	// talvez transformar isso em uma fun��o de utils, ai s� entra com o t�tulo (que no caso � resigtrando livro)
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
	cout << "\n=-=-=-=-= Registrando Livro =-=-=-=-=-=";
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";

	bookTitle = usingUtils->setBookTitle();

	cout << "\n\nInsira o n�mero de p�ginas do livro: ";
	cin >> pages;
	
	// Talvez criar uma classe s� pra isso, com alguns arrays, sendo cada um deles 1 paragr�fo
	cout << "\n\nInsira o resumo do livro: ";
	cin >> bookSummary;

	genre = usingUtils->chooseFromAllAvailableGenres();
	bargainable = usingUtils->isBargainable();
	condition = usingUtils->chooseFromAllConditions();

	cout << "\nInsira o valor de venda: ";
	cin >> price;

	authorName = usingUtils->setAuthorName();
	publishingCompany = usingUtils->setPublishingCompany();

	Book newBook(bookTitle, pages, bookSummary, condition, genre, bargainable, price, authorName, publishingCompany);
	books.push_back(newBook);

}
void Seller::removeBook(){
	int choice;
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
	cout << "\n=-=-=-=-=  Removendo Livro  =-=-=-=-=-=";
	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";

	cout << "\n\nLista de Livros: ";
	for (int i = 0; i < books.size(); i++) {
		cout << (i + 1) << "." << books[i].getTitle();
	}
	cout << "Qual livro deseja remover?";
	cin >> choice;
	choice--;

	books.erase(books.begin() + choice);
}
void Seller::editBook(){
	int bookChoice, dataOption, pages;
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

	cout << "\nQual informa��o deseja alterar? "; 
	cout << "\n1. T�tulo\n2. N� de p�ginas\n3. Condi��o\n4. Negoci�vel\n5. Pre�o\n6. Autor\n7. Editora";
	cin >> dataOption;
	while (running) {
		switch (dataOption) {
		case 1:
			books[bookChoice].setTitle();
			running = false;
			break;
		case 2:
			cout << "\nInsira o n�mero de p�ginas: ";
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
			cout << "\nInsira o valor: ";
			cin >> price;
			books[bookChoice].setPrice(price);
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
			cout << "Valor inv�lido, tente novamente;";
		}
	}
	
}
Book Seller::getBook(int bookNumber){
	return books[bookNumber];
}

void Seller::addNewComplaint(){
	string reason, description;
	cout << "\nInsira o motivo da den�ncia: ";
	cin >> reason;
	cout << "\nInsira uma descri��o da den�ncia; ";
	cin >> description;
	Complaint complaint(reason, description);
	complaints.push_back(complaint);
}
Complaint Seller::getComplaint(int complaintNumber){
	return complaints[complaintNumber];
}