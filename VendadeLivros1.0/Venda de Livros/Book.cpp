#include "Book.h"
#include <iomanip>

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
	Utils* usingUtils = new Utils();
}

void Book::setTitle() {
	
	this->title = usingUtils->formatBookTitle();
}
string Book::getTitle() { return title; }

void Book::setCondition() {
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	condition = usingUtils->chooseFromAllConditions();
}
string Book::getCondition() { return condition; }

void Book::addNewGenre() {
	string newGenre;
	bool foundSameGenre = false;

	newGenre = usingUtils->chooseFromAllAvailableGenres();
	for (int i = 0; i < genres.size(); i++) {
		if (genres[i] == newGenre) {
			cout << "\nGênero já inserido.\n";
			foundSameGenre = true;
			system("pause");
			i = genres.size();
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
int Book::getHowManyGenres() {
	return static_cast<int>(genres.size());
}

void Book::setBargainable() {
	bargainable = usingUtils->isBargainable();
}
bool Book::getBargainable() { return bargainable; }

void Book::setPrice() {
	this->price = usingUtils->formatPrice();
}
float Book::getPrice() { return price; }

void Book::setAuthor() {
	this->author = usingUtils->formatAuthorName();
}
string Book::getAuthor() { return author; }

void Book::setPublishingCompany() {
	publishingCompany = usingUtils->formatPublishingCompany();
}
string Book::getPublishingCompany() { return publishingCompany; }

void Book::setPages(int pages) {
	this->pages = usingUtils->formatPageNumber();
}
int Book::getPages() { return pages; }

string Book::getBookSummary() { return bookSummary; }

void Book::showBookInfo() {
	cout << "\nTítulo: " << title;
	cout << "\nResumo: " << bookSummary;
	cout << "\nGêneros:";
	for (int i = 0; i < genres.size(); i++) {
		cout << genres[i] << endl;
	}
	cout << "N° de páginas: " << pages;
	cout << "\nValor negociável?: ";
	if (bargainable) {
		cout << "Sim.";
	}
	else {
		cout << "Não.";
	}
	cout << "\nAutor: " << author;
	cout << "\nEditora: " << publishingCompany;
	cout << "\nPreço: " << fixed << setprecision(2) << price;
	cout << "\n-----------------------------\n";

	
}