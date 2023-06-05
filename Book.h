#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include "Utils.h"


class Book {
public:
	Book(string title, int pages, string bookSummary, string condition, string genre, bool bargainable, float price, string author, string publishingCompany);
	Utils *usingUtils;

	void setTitle();
	string getTitle();
	
	void setPages(int pages);
	int getPages();

	//void setBookSummary(); tem q ver como vamos fazer isso
	string getBookSummary();

	void setCondition();
	string getCondition();

	void addNewGenre();
	string getGenres(int whichGenre);

	void setBargainable();
	bool getBargainable();

	void setPrice(float price);
	float getPrice();

	void setAuthor();
	string getAuthor();

	void setPublishingCompany();
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
