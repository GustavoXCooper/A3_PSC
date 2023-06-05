#ifndef SELLER_H
#define SELLER_H
#include "User.h"
#include "Utils.h"
#include "Complaint.h"
#include "Book.h"
#include <vector>

class Seller : public User {
public:
	Utils* usingUtils;
	Seller(string name, string surname, Date birthDate, string phoneNumber, string email, string password);
	void addNewBook(Book book);
	void removeBook();
	void editBook();
	Book getBook(int bookNumber);

	void addNewComplaint();
	Complaint getComplaint(int complaintNumber);

	string setBookName();

private:
	vector<Complaint> complaints;
	vector<Book> books;
	//vector<Message> messages; criar

};


#endif
