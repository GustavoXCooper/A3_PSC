#ifndef SELLER_H
#define SELLER_H
#include "User.h"
#include "Utils.h"
#include "Complaint.h"
#include "Book.h"
#include "Message.h"
#include <vector>

class Seller : public User {
public:
	Seller(string name, string surname, Date birthDate, string phoneNumber, string email, string password);
	// book related
	void addNewBook();
	void removeBook();
	void editBook();
	Book getBook(int bookNumber);
	void addNewComplaint();
	Complaint getComplaint(int complaintNumber);
	int getHowManyBooks();
	// messages
	Message getMessages(int whichMessage);
	void setNewMessage(string message, string email);
	void sendNewMessage(string text, int messageToAnswer);
	void receiveNewMessage(string text, int messageToAnswer);
	int getHowManyMessages();

	// other
	void showAvaiableBooksbyGenre(string genre);
	void displayUserInfo();
	void displayAllMessages();
	// complaints
	void displayComplaints();
	// Avaiable for the devs/testers
	void addNewBookTesters();

private:
	vector<Complaint> complaints;
	vector<Book> books;
	vector<Message> messages;

};


#endif

