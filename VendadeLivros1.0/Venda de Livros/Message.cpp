#include "Message.h"
Message::Message(string buyerEmail) {
	this->buyerEmail = buyerEmail;
	unredMessages = true;
}
void Message::showAllMessages(){
	unredMessages = false;
	int totalMessages = static_cast<int>(receivedMessages.size());
	int sentMessages = static_cast<int>(this->sentMessages.size());
	int receivedMessages = static_cast<int>(this->receivedMessages.size());

	for (int i = 0; i < totalMessages; i++) {
		if (receivedMessages >= 0 && i < receivedMessages) {
			cout << "\nCliente:  ";
			cout << this->receivedMessages[i];
		}
		if (sentMessages >= 0 && i < sentMessages) {
			cout << "\nVendedor: ";
			cout << this->sentMessages[i];
		}
	}
}

// Sellers can send messages only if they receive one first. Buyers can send messages again if the last one was answered
// This is because we can't keep track of the hour it was sent, so when we show them it would be out of order
void Message::sendMessage(string message){
	if (receivedMessages.size() == (sentMessages.size() + 1)) { 
		sentMessages.push_back(message); 
	}
	else {
		cout << "\nVocê deve esperar uma resposta para enviar outra mensagem.\n\n";
		system("pause");
	}
}
void Message::receiveMessage(string message) {
	if (sentMessages.size() == receivedMessages.size()) {
		unredMessages = true;
		receivedMessages.push_back(message);
	}
	else {
		cout << "\nVocê deve esperar uma resposta para enviar outra mensagem.\n\n";
		system("pause");
	}
}
string Message::getBuyerContact() { return buyerEmail; }
bool Message::getUnredMessages() { return this->unredMessages; }

int Message::getHowManyMessagesSent() { return sentMessages.size(); }
int Message::getHowManyMessagesReceived() { return receivedMessages.size(); }