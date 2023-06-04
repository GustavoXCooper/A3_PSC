#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class Book {
public:
	Book(string title, int pages, string bookSummary, string condition, string genre, bool bargainable, float price, string author, string publishingCompany);
	Utils *usingUtils;

	void setTitle(string title);
	string getTitle();
	
	void setPages(int pages);
	int getPages();

	//void setBookSummary(); tem q ver como vamos fazer isso
	string getBookSummary();

	void setCondition();
	string getCondition();

	void addNewGenre(string newGenre);
	string getGenres(int whichGenre);

	void setBargainable(bool bargainable);
	bool getBargainable();

	void setPrice(float price);
	float getPrice();

	void setAuthor(string author);
	string getAuthor();

	void setPublishingCompany(string publishingCompany);
	string getPublishingCompany();

	void showBookInfo();
private:
	string title;
	int pages;
	string bookSummary;
	string condition;
	vector<string> genres;
	float price;
	bool bargainable;
	string author;
	string publishingCompany;
};




#endif
