#ifndef APP_H
#define APP_H
#include <Windows.h>
#include <iostream>
#include "Seller.h"
#include "Custumer.h"
#include "Utils.h"
#include <vector>
using namespace std;

class App {
public:
	Utils* usingUtils;
	App();
	void loginScreen();
	int initialMenu();
	void run();
	void registerNewUser();
	void registerCustumer();
	void registerSeller();

	bool isEmailAvailable(string email);

	// Custumer login
	int foundCustumerAccount(string email, string password);
	bool foundCustumerEmail(string email, int custumer);
	bool foundCustumerPassword(string password, int custumer);
	int loginAsCustumer();
	
	// Seller login
	int foundSellerAccount(string email, string password);
	bool foundSellerEmail(string email, int seller);
	bool foundSellerPassword(string password, int seller);
	int loginAsSeller();

	// Custumer screen
	void custumerMainScreen(Custumer& custumer);
	bool wantContactSeller();
	void searchForBooks();
	void filterByGenre();
	void contactSeller(Custumer custumer);
	void displayAllMessages(Custumer custumer);
	void answerSeller(string sellerEmail, string custumerEmail);
	void reportSeller(Custumer custumer);

	// Seller screen
	void sellerMainScreen(Seller& seller);
	void answerCustumer(Seller& seller);
	
	// Exit message
	void exitMessage();
private:
	vector<Custumer> allCustumers;
	vector<Seller> allSellers;

};

#endif
