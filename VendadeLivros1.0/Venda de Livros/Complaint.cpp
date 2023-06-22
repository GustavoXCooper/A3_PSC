#include "Complaint.h"

Complaint::Complaint(string reason, string description) {
	this->reason = reason;
	this->description = description;
}

string Complaint::getReason() { return reason; }
string Complaint::getDescription() { return description; }