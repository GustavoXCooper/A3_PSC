#ifndef COMPLAINT_H
#define COMPLAINT_H
#include <iostream>
using namespace std;

class Complaint {
public:
	Complaint(string reason, string description);

	// void setReason(string reason); n�o sei se � necess�rio set aqui
	string getReason();

	// void setDescription(string description); n�o sei se � necess�rio set aqui
	string getDescription();
private:
	string reason;
	string description;

};

#endif


