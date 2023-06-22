#ifndef MESSAGE_H
#define MESSAGE_H
#include <vector>
#include <iostream>
using namespace std;

class Message {
public:
	Message(string email);
	void showAllMessages();
	void sendMessage(string message);
	void receiveMessage(string message);
	int getHowManyMessagesSent();
	int getHowManyMessagesReceived();
	bool getUnredMessages();
	string getBuyerContact();
private:
	vector<string> sentMessages; 
	vector<string> receivedMessages; 
	string buyerEmail;
	bool unredMessages;
};

#endif