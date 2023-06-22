#ifndef CUSTUMER_H
#define CUSTUMER_H
#include "User.h"
#include <vector>

class Custumer : public User {
public:
	Custumer(string name, string surname, Date birthDate, string phoneNumber, string email, string password);
	void displayMessagedSeller();
	void setNewMessagedSeller(string email);
private:
	vector<string> messagedSellers;
};

#endif;
