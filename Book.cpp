#include "Book.h"

// Tem que revisar isso aqui, se to utilizando tudo possível de usingUtils;

Book::Book(string title, int pages, string bookSummary, string condition, string genre, bool bargainable, float price, string author, string publishingCompany) {
	this->title = title;
	this->pages = pages;
	// Maybe this should start empty, and then we fill with an array of strings. Each array is one paragraph, and the seller can exlude and add new paragraphs idk i'll think about it later
	this->bookSummary = bookSummary;
	this->condition = condition;
	this->genres.push_back(genre);
	this->bargainable = bargainable;
	// Não consegui fazer ficar só c 2 casas decimais 
	// se mudar aqui tem q mudar no set também
	this->price = round(price);
	this->author = author;
	this->publishingCompany = publishingCompany;
	Utils *usingUtils = new Utils();
}

void Book::setTitle() { usingUtils->setBookTitle(); }
string Book::getTitle() { return title; }

void Book::setCondition() { condition = usingUtils->chooseFromAllConditions(); }
string Book::getCondition() { return condition; }

// Esses métodos eu vou ter que refazer depois, talvez inserir um número X de gêneros PRÉ DEFINIDOS no construtor mesmo e não alterar mais depois;.
void Book::addNewGenre(){
	// revisar !!!!!
	string newGenre;
	bool foundSameGenre = false;
	for(int i = 0; i < genres.size(); i++){
		newGenre = usingUtils->chooseFromAllAvailableGenres();
		if (genres[i] == newGenre) {
			cout << "\nGênero já inserido.";
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

void Book::setBargainable() { bargainable = usingUtils->isBargainable(); }
bool Book::getBargainable() { return bargainable; }

void Book::setPrice(float price) { this->price = round(price); }
float Book::getPrice() { return price; }

void Book::setAuthor() { usingUtils->setAuthorName(); }
string Book::getAuthor() { return author; }

void Book::setPublishingCompany() { usingUtils->setPublishingCompany(); }
string Book::getPublishingCompany() { return publishingCompany; }

void Book::setPages(int pages) {
	if (pages > 0) {
		this->pages = pages;
	}
	else {
		cout << "\nNúmero de páginas não pode ser menor ou igual a 0.";
	}
}
int Book::getPages() { return pages; }

string Book::getBookSummary() { return bookSummary; }

void Book::showBookInfo() {
	cout << "\nTítulo: " << title;
	cout << "\nResumo: " << bookSummary;
	cout << "\nGêneros: ";
	for (int i = 0; i < genres.size(); i++) {
		cout << genres[i];
	}
	cout << "\nAutor: " << author;
	cout << "\nEditora: " << publishingCompany;
	cout << "\nPreço: " << price;

}
