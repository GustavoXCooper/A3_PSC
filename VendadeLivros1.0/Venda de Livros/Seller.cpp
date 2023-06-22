#include "Seller.h"
#include <Windows.h>
using namespace std;

Seller::Seller(
	string name, 
	string surname,
	Date birthDate, 
	string phoneNumber, 
	string email, 
	string password) : User(name, surname, birthDate, phoneNumber, email, password) {
	this->usingUtils = usingUtils;
}

// DEV/TESTER ONLY

void Seller::addNewBookTesters() {
	
	int genreDecision = rand() % 3;
	string genre;
	// "title teste", 10, "teste teste teste", "Seminovo", "Fantasia", true, 50, "teste", "teste"
	switch (genreDecision) {
	case 0:
		genre = "Fantasia";
		break;
	case 1:
		genre = "Terror";
		break;
	case 2:
		genre = "Romance";
		break;
	}
	Book book("title teste", 10, "teste teste teste", "Seminovo", genre, true, 50, "teste", "teste");

	books.push_back(book);
}

// end dev/test only

// book related
void Seller::addNewBook() {
	string bookTitle, bookSummary, genre, condition, authorName, publishingCompany;
	bool bargainable, running = true;
	float price;
	int pages;

	cout << "\n===== Registrando Livro =====";

	bookTitle = usingUtils->formatBookTitle();
	pages = usingUtils->formatPageNumber();

	cout << "\n\nInsira, em um parágrafo, o resumo do livro: ";
	cin.ignore();
	getline(cin, bookSummary);

	genre = usingUtils->chooseFromAllAvailableGenres();
	bargainable = usingUtils->isBargainable();
	condition = usingUtils->chooseFromAllConditions();
	
	cin.ignore();
	price = usingUtils->formatPrice();

	authorName = usingUtils->formatAuthorName();
	publishingCompany = usingUtils->formatPublishingCompany();

	Book *newBook = new Book(bookTitle, pages, bookSummary, condition, genre, bargainable, price, authorName, publishingCompany);
	books.push_back(*newBook);

}
void Seller::removeBook() {
	string choice;
	int trueChoice = 0;
	bool running = true;

	cout << "\n======== Removendo Livro ========";

	if (books.size() > 0) {
		cout << "\n\nLista de Livros:\n";
		for (int i = 0; i < books.size(); i++) { 
			cout << endl << (i + 1) << "." << books[i].getTitle(); 
		}
		cout << "\nQual livro deseja remover? "; 

		while (running) { 
			cin >> choice; 
			if (usingUtils->containsOnlyNumbers(choice)) { 
				trueChoice = stoi(choice);
				trueChoice--;
				if (trueChoice >= 0 && trueChoice <= books.size()) {
					running = false;
				} 
			}
			if (running) {
				cout << "\nValor inválido. Tente novamente.\n";
			}
		}
		books.erase(books.begin() + trueChoice); 
	}
	else {
		cout << "\nVocê não tem nenhum livro registrado\n";
		system("pause");
	}
	
}
void Seller::editBook() {
	int bookTrueChoice, dataTrueChoice = -1, truePages = 0;
	string string, pages, bookChoice, dataChoice;
	bool running = true;
	bool pagesIsNumber = false;
	bool isBookChoiceValid = false;

	cout << "\n====== Editando Livro ======";

	cout << "\n\nLista de Livros:\n ";
	for (int i = 0; i < books.size(); i++) {
		cout << endl << (i + 1) << "." << books[i].getTitle();
	}
	cout << "\n\nQual livro deseja editar?\nDigite 0 se quiser sair\n";
	while (!isBookChoiceValid) {
		cin >> bookChoice;
		if (usingUtils->containsOnlyNumbers(bookChoice)) {
			bookTrueChoice = stoi(bookChoice);
		}
		else {
			bookTrueChoice = -1;
		}
		if (bookTrueChoice < 0 || bookTrueChoice > books.size()) {
			cout << "\nValor inválido. Tente novamente.\n";
		}
		else {
			isBookChoiceValid = true;
		}
	}
	if (bookTrueChoice != 0) {
		bookTrueChoice--;

		cout << "\nQual informação deseja alterar? ";
		cout << "\n1. Título\n2. N° de páginas\n3. Condição\n4. Negociável\n5. Preço\n6. Autor\n7. Editora\n8. Adicionar novo gênero\n";

		while (running) {
			cin >> dataChoice;
			if (usingUtils->containsOnlyNumbers(dataChoice)) {
				dataTrueChoice = stoi(dataChoice);
			}
			else {
				dataTrueChoice = -1;
			}
			switch (dataTrueChoice) {
			case 1:
				books[bookTrueChoice].setTitle();
				running = false;
				break;
			case 2:
				books[bookTrueChoice].setPages(truePages);
				running = false;
				break;
			case 3:
				books[bookTrueChoice].setCondition();
				running = false;
				break;
			case 4:
				books[bookTrueChoice].setBargainable();
				running = false;
				break;
			case 5:
				books[bookTrueChoice].setPrice();
				running = false;
				break;
			case 6:
				books[bookTrueChoice].setAuthor();
				running = false;
				break;
			case 7:
				books[bookTrueChoice].setPublishingCompany();
				running = false;
				break;
			case 8:
				books[bookTrueChoice].addNewGenre();
				running = false;
				break;
			default:
				cout << "\nValor inválido, tente novamente.\n";
			}
		}
	}


}
int Seller::getHowManyBooks() {
	return static_cast<int>(books.size());
}
void Seller::showAvaiableBooksbyGenre(string genre) {
	int booksFound = 0;
	vector<Book> tempBooks;

	for (int i = 0; i < books.size(); i++) {
		for (int c = 0; c < books[i].getHowManyGenres(); c++) {
			if (books[i].getGenres(c) == genre) {
				booksFound++;
				tempBooks.push_back(books[i]);
			}
		}
	}

	if (booksFound > 0) {
		cout << "\n\n====================================";
		cout << "\nInformações do usuário vendedor:";
		cout << "\nNome: " << getName();
		cout << "\nEmail: " << getEmail();
		cout << "\nTelefone: " << getPhoneNumber();
		cout << "\n! == Reclamações: " << complaints.size() << " == !";
		cout << "\n\nInformações do livro:\n";
		for (int i = 0; i < booksFound; i++) {
			cout << "----------------------------------";
			tempBooks[i].showBookInfo();
		}
	}
}
Book Seller::getBook(int bookNumber) {
	return books[bookNumber];
}

// complaint related
void Seller::addNewComplaint() {
	string reason, description;
	cout << "\nInsira o motivo da denúncia: ";
	cin.ignore();
	getline(cin, reason);
	cout << "\nInsira uma descrição da denúncia: ";
	getline(cin, description);
	Complaint complaint(reason, description);
	complaints.push_back(complaint);
}
Complaint Seller::getComplaint(int complaintNumber) {
	return complaints[complaintNumber];
}
void Seller::displayComplaints() {
	bool running = true;
	string choice;
	int trueChoice = 2;
	cout << "\nEste usuário possuí as seguintes denúncias: ";
	for (int i = 0; i < complaints.size(); i++) {
		cout << "\nMotivo: " << complaints[i].getReason();
		cout << "\nDeseja saber mais a respeito?\n1. Para sim\n2. Para não\n";
		while (running) {
			cin >> choice;
			if (choice == "1" || choice == "2") {
				trueChoice = stoi(choice);
				running = false;
			}
			else {
				cout << "\nValor inválido. Tente novamente.\n";
			}

		}
	}
	if (trueChoice == 1) {
		for (int i = 0; i < complaints.size(); i++) {
			cout << "\n\nDenúncia: " << complaints[i].getReason();
			cout << "\nDescrição: " << complaints[i].getDescription() << endl;
		}
		system("pause");
	}
}

// Message related
void Seller::sendNewMessage(string text, int messageToAnswer) { 
	messages[messageToAnswer].sendMessage(text);
}
void Seller::receiveNewMessage(string text, int messageToAnswer){
	messages[messageToAnswer].receiveMessage(text);
}
void Seller::setNewMessage(string message, string email) {
	bool running = true;
	string choice;
	int trueChoice = 1;
	
	if (complaints.size() > 0) {
		displayComplaints();
		cout << "\nAinda deseja enviar uma mensagem?\n1. Para sim\n2. Para não\n";
		while (running) { 
			cin >> choice; 
			if (usingUtils->containsOnlyNumbers(choice)) { 
				trueChoice = stoi(choice); 
				running = false; 
				if (choice != "1" && choice != "2") { 
					cout << "\nValor inválido. Tente novamente.\n"; 
				} 
			}
			else {
				cout << "\nValor inválido. Tente novamente.\n"; 
			}
		}
	}
	
	if (trueChoice == 1) {
		Message* newMessage = new Message(email); 
		newMessage->receiveMessage(message); 
		messages.push_back(*newMessage); 
	}
}
int Seller::getHowManyMessages() {
	if (messages.size() > 0){
		return static_cast<int>(messages.size());
	}
	else {
		return 0;
	}
}
Message Seller::getMessages(int whichMessage) { return messages[whichMessage]; }
void Seller::displayAllMessages() {
	if (messages.size() > 0) {
		cout << "\nVocê tem mensagem com os usuários:\n";
		for (int i = 0; i < messages.size(); i++) {
			cout << "\n=============================\n";
			cout << endl << (i + 1) << ". " << messages[i].getBuyerContact();
			cout << endl << "Mensagens não lidas:";
			if (messages[i].getUnredMessages()) {
				cout << " Sim.\n";
			}
			else {
				cout << "Não.\n";
			}
			cout << endl;
		}
	}
	else {
		cout << "\nNão encontramos nenhuma mensagem.\n";
	}
	
	system("pause");
}

void Seller::displayUserInfo() {
	system("cls");
	string choice;
	cout << "=== Suas Informações ===\n";
	cout << "\n\nNome: " << nameComplete;
	cout << "\nData de nascimento:" << birthDate.GetFullDate();
	cout << "\nEmail: " << email;
	cout << "\n\n=== Livros ===\n";
	
	for (int i = 0; i < books.size(); i++) {
		books[i].showBookInfo();
	}
	cout << endl;

	system("pause");
}