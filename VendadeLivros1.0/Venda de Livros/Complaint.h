#ifndef COMPLAINT_H
#define COMPLAINT_H
#include <iostream>
using namespace std;

class Complaint {
public:
	Complaint(string reason, string description);

	// void setReason(string reason); não sei se é necessário set aqui
	string getReason();

	// void setDescription(string description); não sei se é necessário set aqui
	string getDescription();
private:
	string reason;
	string description;

};

#endif


