#include "Book.h"
const int titleMaxSize = 80;

Book::Book(string title, int pages, string bookSummary, string condition, string genre, bool bargainable, float price, string author, string publishingCompany) {
	this->title = title;
	this->pages = pages;
	// Maybe this should start empty, and then we fill with an array of strings. Each array is one paragraph, and the seller can exlude and add new paragraphs idk i'll think about it later
	this->bookSummary = bookSummary;
	this->condition = condition;
	this->genres.push_back(genre);
	this->bargainable = bargainable;
	// N�o consegui fazer ficar s� c 2 casas decimais 
	// se mudar aqui tem q mudar no set tamb�m
	this->price = round(price);
	this->author = author;
	this->publishingCompany = publishingCompany;
	usingUtils = new Utils();
}

void Book::setTitle(string title) {
	// Donno if would be better to declare titleMaxSize here, ask professor later
	if (usingUtils->shorterThan(title, titleMaxSize)) { this->title = title; }
	else {
		cout << "\nO t�tulo deve conter no m�ximo " << titleMaxSize << " characteres.";
	}
}
string Book::getTitle() { return title; }

void Book::setCondition() {
	int newConditionChoice;
	string newCondition;
	cout << "\nQual a condi��o do livro?\n1. Novo\n2. Seminovo\n3. Usado\n4. Velho";
	cin >> newConditionChoice;
	switch (newConditionChoice) {
	case 1:
		newCondition = "Novo";
		break;
	case 2:
		newCondition = "Seminovo";
		break;
	case 3:
		newCondition = "Usado";
		break;
	case 4:
		newCondition = "Velho";
		break;
	default:
		newCondition = condition;
		cout << "\nValor inv�lido.";
	}
	condition = newCondition;
}
string Book::getCondition() { return condition; }

void Book::addNewGenre(string newGenre){
	bool foundSameGenre = false;
	for(int i = 0; i < genres.size(); i++){
		if (genres[i] == newGenre) {
			cout << "\nG�nero j� inserido.";
			foundSameGenre = true;
			break;
		}
	}
	if (!foundSameGenre) {
		genres.push_back(newGenre);
	}
}
string Book::getGenres(int whichGenre) {
	// Will need loops to be used
	return genres[whichGenre];
}

void Book::setBargainable(bool bargainable){
	this->bargainable = bargainable;
}
bool Book::getBargainable() { return bargainable; }

void Book::setPrice(float price) { this->price = round(price); }
float Book::getPrice() { return price; }

void Book::setAuthor(string author){ 
	if (!usingUtils->containsNumbers(author) && !usingUtils->containsSpecialCharacters(author)) {
		this->author = author;
	}
	else {
		cout << "\nNome inv�lido. Nomes n�o podem ter caracteres especiais ou n�meros.";
	}
}
string Book::getAuthor() { return author; }

void Book::setPublishingCompany(string publishingCompany){
	if (!usingUtils->containsNumbers(publishingCompany) && !usingUtils->containsSpecialCharacters(publishingCompany)) {
		this->publishingCompany = publishingCompany;
	}
}
string Book::getPublishingCompany() { return publishingCompany; }

void Book::setPages(int pages) {
	if (pages > 0) {
		this->pages = pages;
	}
	else {
		cout << "\nN�mero de p�ginas n�o pode ser menor ou igual a 0.";
	}
}
int Book::getPages() { return pages; }

string Book::getBookSummary() { return bookSummary; }

void Book::showBookInfo() {
	cout << "\nT�tulo: " << title;
	cout << "\nResumo: " << bookSummary;
	cout << "\nG�neros: ";
	for (int i = 0; i < genres.size(); i++) {
		cout << genres[i];
	}
	cout << "\nAutor: " << author;
	cout << "\nEditora: " << publishingCompany;
	cout << "\nPre�o: " << price;

}