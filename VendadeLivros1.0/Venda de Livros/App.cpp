#include "App.h"

App::App() {
	this->usingUtils = usingUtils;
	Date date(10, 9, 2001);
	Custumer custumer("Gustavo", "Cooper", date, "51", "gustavo@gmail.com", "teste@123");
	Custumer custumer2("Gustavo", "Cooper", date, "51", "teste@123", "teste@123");

	Seller seller("Sofia", "Teste", date, "51", "sofia@gmail.com", "teste@123");
	
	Seller seller2("Henry", "Teste", date, "51", "henry@gmail.com", "teste@123");

	Seller seller3("Leo", "Teste", date, "51", "leo@gmail.com", "teste@123");
	

	allCustumers.push_back(custumer2);
	allCustumers.push_back(custumer);
	allSellers.push_back(seller);
	allSellers.push_back(seller2);
	allSellers.push_back(seller3);

	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 5; j++) {
			allSellers[i].addNewBookTesters();
		}
	}
}

int App::initialMenu() {
	system("cls");
	int trueChoice = -1;
	string choice;

	cout << "======= Menu Incial =======";
	cout << "\n\n1. Fazer login\n2. Criar conta\n3. Sair\n";

	while (trueChoice == -1) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) { 
			trueChoice = stoi(choice); 
		}
		else {
			return 0;
		}
	}
	
	if (trueChoice > 0 && trueChoice < 4) {
		return trueChoice;
	}
	else {
		return 0;
	}
}
void App::run(){
	system("cls");
	int choice;
	do {
		choice = initialMenu();
		switch (choice) {
		case 1:
			loginScreen();
			break;
		case 2:
			registerNewUser();
			break;
		case 3:
			exitMessage();
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n\n";
			system("pause");
		}
	} while (choice != 3);
}

void App::loginScreen(){
	string choice;
	int trueChoice = -1; 
	int user;
	bool running = true;

	system("cls");
	cout << "====== Login ======";
	cout << "\n\nDeseja logar como:\n1. Conta para vendas\n2. Conta para compras\n3. Sair\n";

	while (running) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = -1;
		}
		switch (trueChoice) {
		case 1:
			user = loginAsSeller();
			if (user >= 0) {
				sellerMainScreen(allSellers[user]);
			}
			else if (user == -2) {
				running = false;
			}
			else {
				cout << "\nEmail ou senha incorretos.\n";
				system("pause");
			}
			running = false;
			break;
		case 2:
			user = loginAsCustumer();
			if (user >= 0) {
				custumerMainScreen(allCustumers[user]);
			}
			else if (user == -2) {
				running = false;
			}
			else {
				cout << "\nEmail ou senha incorretos.\n";
				system("pause");
			}
			running = false;
			break;
		case 3:
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n\n";
		} 
	}
}

// login for custumers
int App::loginAsCustumer() {
	string email, password, choice;
	int custumer = -1;
	bool running = true;
	int trueChoice;
	system("cls");
	cout << "== Login ==";
	cout << "\n\nDeseja continuar com o login?\n1. Sim\n2. Não\n";
	
	while (running) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = 0;
		}
		switch (trueChoice) {
		case 1:
			cout << "\nInsira seu email: ";
			cin >> email;
			cout << "\nInsira sua senha: ";
			cin >> password;
			custumer = foundCustumerAccount(email, password);
			running = false;
			break;
		case 2:
			custumer = -2;
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
		}

	}
	return custumer;
}
int App::foundCustumerAccount(string email, string password) {
	int foundCustumer = -1;
	for (int i = 0; i < allCustumers.size(); i++) {
		if (foundCustumerEmail(email, i) && foundCustumerPassword(password, i)) {
			return i;
		}
		else {
			
			foundCustumer = -1;
		}
	}
	return foundCustumer;
}
bool App::foundCustumerEmail(string email, int custumer) {
	bool foundEmail;
	if (email == allCustumers[custumer].getEmail()) {
		foundEmail = true;
	}
	else {
		foundEmail = false;
	}
	return foundEmail;
}
bool App::foundCustumerPassword(string password, int custumer){
	if (password == allCustumers[custumer].getPassword()) {
		return true;
	}
	return false;
}

// login for sellers
int App::loginAsSeller() {
	string email, password;
	bool running = true;
	int seller = -1;
	string choice;
	int trueChoice; 

	system("cls");
	cout << "== Login ==";
	cout << "\n\nDeseja continuar com o login?\n1. Sim\n2. Não\n";

	while(running) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice); 
		}
		else {
			trueChoice = 0; 
		} 
		switch (trueChoice) { 
		case 1:
			cout << "\nInsira seu email: ";
			cin >> email;
			cout << "\nInsira sua senha: ";
			cin >> password;
			seller = foundSellerAccount(email, password);
			running = false;
			break;
		case 2:
			seller = -2;
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
		}
	}
	return seller;
}
int App::foundSellerAccount(string email, string password){
	int foundSeller = -1;
	for (int i = 0; i < allSellers.size(); i++) {
		if (foundSellerEmail(email, i) && foundSellerPassword(password, i)) {
			return i;
		}
		else {
			foundSeller = -1;
		}
	}
	return foundSeller;
}
bool App::foundSellerEmail(string email, int seller){
	bool foundEmail;
	if (email == allSellers[seller].getEmail()) {
		foundEmail = true;
	}
	else {
		foundEmail = false;
	}
	return foundEmail;
}
bool App::foundSellerPassword(string password, int seller){
	if (password == allSellers[seller].getPassword()) {
		return true;
	}
	return false;
}

// Logged in screen for custumers
void App::custumerMainScreen(Custumer& custumer) {
	
	string choice;
	int trueChoice = 0;
	bool running = true;

	while (running) {
		system("cls");
		cout << "Bem vindo, " << custumer.getName() << "!";
		cout << "\n\nVocê deseja:\n1. Pesquisar livros\n2. Alterar suas informações\n3. Ver suas informações\n";
		cout << "4. Ver suas mensagens\n5. Denunciar um vendedor\n6. Sair\n";
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = 0;
		}
		switch (trueChoice) {
		case 1:
			searchForBooks();
			if (wantContactSeller()) {
				contactSeller(custumer);
			}
			break;
		case 2:
			custumer.changeUserInfo();
			break;
		case 3:
			custumer.displayUserInfo();
			break;
		case 4:
			displayAllMessages(custumer);
			break;
		case 5:
			reportSeller(custumer);
			break;
		case 6:
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
			Sleep(200);
		}
	}
}
bool App::wantContactSeller() {
	string choice;
	int trueChoice = 0;
	bool running = true;
	bool wantContactSeller;

	cout << "\nVocê deseja entrar em contato com algum destes vendedores?\n1. Sim\n2. Não\n";
	while (running) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = 0;
		}
		switch (trueChoice) {
		case 1:
			wantContactSeller = true;
			running = false; 
			break;
		case 2:
			wantContactSeller = false;
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
		}
	}
	return wantContactSeller;
}
void App::searchForBooks() {
	string choice;
	int trueChoice = -1;
	int booksFound = 0;
	bool running = true;
	cout << "\nVocê deseja filtrar por\n1. Gênero\n";
	while (running) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = -1;
		}
		switch (trueChoice) {
		case 1:
			filterByGenre();
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
		}
	}
}
void App::filterByGenre() {
	vector<Book> tempBooks;
	int trueChoice = -1;
	string genre, choice;
	bool runningGenre = true;
	bool running = true;
	cout << "\nEscolha o gênero: ";
	cout << "\n1. Romance";
	cout << "\n2. Fantasia";
	cout << "\n3. Terror\n";

	while (runningGenre) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = -1;
		}
		switch (trueChoice){
		case 1:
			genre = "Romance";
			runningGenre = false;
			break;
		case 2:
			genre = "Fantasia";
			runningGenre = false;
			break;
		case 3:
			genre = "Terror";
			runningGenre = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
		}
	}

	cout << "\nLivros encontrados:\n ";
	for (int i = 0; i < allSellers.size(); i++) {
		allSellers[i].showAvaiableBooksbyGenre(genre);
	}

}
void App::contactSeller(Custumer custumer) {
	string message;
	string email; 
	bool running = true; 
	bool foundEmail = false; 
	bool hasSendMessage = false;
	int sellerToContact, howManyMessagesSellerHas;
	cout << "\nSe deseja voltar, digite 0.";
	cout << "\nInsira o email do vendedor que deseja entrar em contato: ";

	while (running) { 
		cin >> email; 

		if (email == "0") { 
			running = false; 
		}
		else {
			for (int i = 0; i < allSellers.size(); i++) {
				if (allSellers[i].getEmail() == email) {
					foundEmail = true;
					sellerToContact = i;
					howManyMessagesSellerHas = allSellers[i].getHowManyMessages();
				}
			}

			if (foundEmail) {
				for (int i = 0; i < howManyMessagesSellerHas; i++) {
					if (allSellers[sellerToContact].getMessages(i).getBuyerContact() == custumer.getEmail()) {
						hasSendMessage = true;
					}
				}
				running = false;
			}
			else {
				cout << "\nEmail não encontrado. Tente novamente.\n";
			}
		}
	}
	if (email != "0") {
		if (foundEmail && !hasSendMessage) {
			system("cls");
			cout << "=== Enviando Mensagem ===";
			cout << "\nVocê só poderá enviar outra mensagem a este usuário quando receber uma resposta.\n";
			cout << "\nInsira sua mensagem e aperte ENTER quando desejar enviá-la: ";
			cin.ignore();
			getline(cin, message);
			if (message.size() > 0) {
				for (int i = 0; i < allSellers.size(); i++) {
					if (allSellers[i].getEmail() == email) {
						allSellers[i].setNewMessage(message, custumer.getEmail());
					}
				}
				cout << "\nMensagem enviada com sucesso!\n";
			}
			else {
				cout << "\nVocê não pode enviar uma mensagem vazia.\n";

			}
		}
		else if (hasSendMessage) {
			cout << "\nVocê já contatou este usuário.\n";
		}
		system("pause");
	}
}
void App::displayAllMessages(Custumer custumer) {
	string email;
	bool running = true;
	bool foundEmail = false;
	vector<string> emailsFound;
	system("cls");
	cout << "==== Mensagens ====\n";
	for(int i = 0; i < allSellers.size(); i++){
		for (int j = 0; j < allSellers[i].getHowManyMessages(); j++) {
			if (allSellers[i].getMessages(j).getBuyerContact() == custumer.getEmail()) {
				cout << "\n\nContato do vendedor: " << allSellers[i].getEmail();
				emailsFound.push_back(allSellers[i].getEmail());
				allSellers[i].getMessages(j).showAllMessages();
				cout << "\n----------------------------------------------------------------";
			}
		}
	}
	if (emailsFound.size() > 0) {
		cout << "\nDeseja responder uma das mensagens?\nSe sim, insira o email do vendedor que deseja responder";
		cout << "\nSe não, insira 0\n";
		while (running) {
			cin >> email;
			if (email == "0") {
				running = false;
			}
			for (int i = 0; i < emailsFound.size(); i++) {
				if (email == emailsFound[i]) {
					answerSeller(email, custumer.getEmail());
					foundEmail = true;
				}
			} 
			if (foundEmail) {
				running = false;
			}
			else {
				cout << "\nValor inválido. Tente novamente.\n";
			}
			
		}
		
	}
	else {
		cout << "\nNão foram encontradas mensagens.\n";
		system("pause");
	}
}
void App::answerSeller(string sellerEmail, string custumerEmail) {
	string message;
	bool foundEmail = false;
	cout << "=== Enviando Mensagem ===";
	cout << "\nVocê só poderá enviar outra mensagem a este usuário quando receber uma resposta.\n";
	cout << "\nInsira sua mensagem e aperte ENTER quando desejar enviá-la: ";
	while (!foundEmail) {
		cin.ignore();
		getline(cin, message);
		if (message.size() > 0) {
			for (int i = 0; i < allSellers.size(); i++) {
				if (allSellers[i].getEmail() == sellerEmail) {
					for (int j = 0; j < allSellers[i].getHowManyMessages(); j++) {
						if (allSellers[i].getMessages(j).getBuyerContact() == custumerEmail) {
							allSellers[i].receiveNewMessage(message, j);
						}
					}
					foundEmail = true;
				}
			}
			if (!foundEmail) {
				cout << "\nEmail não encontrado. Tente novamente.\n";
			}
		}
		else { 
			cout << "\nVocê não pode enviar uma mensagem vazia.\n";
		}
	}
}
void App::reportSeller(Custumer custumer) {
	string email;
	bool foundEmail = false;
	cout << "==== Denuncia ====";
	cout << "\nVocê trocou mensagem com os seguintes vendedores: ";
	for (int i = 0; i < allSellers.size(); i++) { 
		for (int j = 0; j < allSellers[i].getHowManyMessages(); j++) { 
			if (allSellers[i].getMessages(j).getBuyerContact() == custumer.getEmail()) { 
				cout << "\nContato do vendedor: " << allSellers[i].getEmail();
			}
		}
	}
	cout << "\n\nDeseja denunciar algum deles?\n\nSe sim, insira o email de quem deseja denunciar.\nSe não, digite 0\n";
	
	while (!foundEmail) {
		cin >> email; 
		if (email != "0") { 
			for (int i = 0; i < allSellers.size(); i++) { 
				if (allSellers[i].getEmail() == email) { 
					allSellers[i].addNewComplaint(); 
					foundEmail = true; 
				} 
			} 
		}
		else {
			foundEmail = true;
		}
		if (!foundEmail) { 
			cout << "\nEmail não encontrado. Tente novamente.\n"; 
		}
	}

}

// Logged in screen for sellers
void App::sellerMainScreen(Seller& seller) {
	string choice; 
	int trueChoice = 0; 
	bool running = true; 

	while (running) {
		system("cls");
		cout << "Bem vindo, " << seller.getName() << "!";
		cout << "\n\nVocê deseja:\n\n1. Registrar um livro novo\n2. Alterar suas informações\n3. Ver suas informações\n4. Ver suas mensagens\n";
		cout << "5. Editar um livro\n6. Remover um livro\n7. Sair\n";
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) { 
			trueChoice = stoi(choice); 
		}
		else {
			trueChoice = 0; 
		}
		switch (trueChoice) { 
		case 1:
			seller.addNewBook();
			break;
		case 2:
			seller.changeUserInfo();
			break;
		case 3:
			seller.displayUserInfo();
			break;
		case 4:
			seller.displayAllMessages();
			answerCustumer(seller);
			break;
		case 5:
			seller.editBook();
			break;
		case 6:
			seller.removeBook();
			break;
		case 7:
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
			Sleep(200);
		}
	}
}
void App::answerCustumer(Seller& seller) {
	string email, message;
	int custumerToAnswer = -1;
	int totalMessages;
	bool running = true;
	bool foundCustumer = false;
	
	
	totalMessages = seller.getHowManyMessages();
	if (totalMessages == 0) {
		running = false; 
	}
	else {
		cout << "\nSe não deseja responder nenhuma mensagem, digite 0.";
		cout << "\nInsira o email do usuário que deseja entrar em contato: ";
	}

	while (running) {
		cin >> email;

		if (email == "0") {
			running = false;
		}

		for (int i = 0; i < seller.getHowManyMessages(); i++) {
			if (seller.getMessages(i).getBuyerContact() == email) {
				custumerToAnswer = i;
				foundCustumer = true;
				i = seller.getHowManyMessages();
				running = false;
			}
		}
		if (!foundCustumer) {
			cout << "\nUsuário não encontrado. Tente novamente.\n";
		}
	}

	if (custumerToAnswer > -1) {
		seller.getMessages(custumerToAnswer).showAllMessages();
		cout << "\n\n";
		system("pause");
		system("cls");
		cout << "=== Enviando Mensagem ==="; 
		cout << "\nVocê só poderá enviar outra mensagem a este usuário quando receber uma resposta.\n"; 
		cout << "\nInsira sua mensagem e aperte ENTER quando desejar enviá-la: "; 
		cin.ignore(); 
		getline(cin, message); 
		if (message.size() > 0) {
			seller.sendNewMessage(message, custumerToAnswer);
		}
		else {
			cout << "\nVocê não pode enviar uma mensagem vazia.\n";
			system("pause");
		}
		
		
	}
}

// Account creation
void App::registerNewUser(){
	system("cls");
	bool running = true;
	int trueChoice;
	string choice;
	cout << "========= Cadastro =========";
	cout << "\n\nVocê deseja registrar:\n1. Conta para vendas\n2. Conta para compra\n3. Sair\n";
	
	while(running){
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = -1;
		}
		switch (trueChoice) {
		case 1:
			registerSeller();
			running = false;
			break;
		case 2:
			registerCustumer();
			running = false;
			break;
		case 3:
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
		}
	}
}
void App::registerCustumer(){
	string name, surname, phoneNumber, email, password;
	bool running = true;
	bool emailAvailable = false;
	int choice;
	system("cls");
	cout << "===== Cadastro Conta para Compras =====";

	name = usingUtils->formatUserName();
	surname = usingUtils->formatUserSurname();
	Date date = usingUtils->formatUserBirthDate();
	phoneNumber = usingUtils->formatPhoneNumber();

	while (!emailAvailable) {
		email = usingUtils->formatEmail();
		if (!isEmailAvailable(email)) {
			cout << "\nEmail já registrado. Tente novamente.\n";
		}
		else {
			emailAvailable = true;
		}
	}
	
	 
	password = usingUtils->formatPassword(); 

	cout << "\nDeseja registrar essa conta?";
	cout << "\nNome:" << name << " " << surname;
	cout << "\nEmail " << email;
	cout << "\nTelefone: " << phoneNumber;
	cout << "\nSenha: " << password;

	cout << "\n1. Registrar essa conta\n2. Voltar ao menu inicial\n";
	running = true;
	while (running) {
		cin >> choice;
		switch (choice) {
		case 1: {
			Custumer* custumer = new Custumer(name, surname, date, phoneNumber, email, password);
			allCustumers.push_back(*custumer);
			cout << "Sua conta foi criada com sucesso! ";
			Sleep(200);
			running = false;
			break;
		}
		case 2:
			cout << "\nVoltando ao menu inicial.\n";
			system("pause");
			running = false;
			break;
		default:
			cout << "\nValor inválido. Tente novamente.\n";
		}
	}
}
void App::registerSeller() {
	system("cls");
	string name, surname, phoneNumber, email, password, choice;  
	bool running = true;  
	bool emailAvailable = false;
	int trueChoice;  
	system("cls");  
	cout << "===== Cadastro Conta para Vendas ====="; 
	name = usingUtils->formatUserName();  
	surname = usingUtils->formatUserSurname();  
	Date date = usingUtils->formatUserBirthDate();   
	phoneNumber = usingUtils->formatPhoneNumber();   
	

	while (!emailAvailable) {
		email = usingUtils->formatEmail();
		if (!isEmailAvailable(email)) {
			cout << "\nEmail já registrado. Tente novamente.\n";;
		}
		else {
			emailAvailable = true;
		}
	}

	password = usingUtils->formatPassword(); 
	cout << "\n1. Registrar essa conta\n2. Voltar ao menu inicial\n";

	while (running) {
		cin >> choice;
		if (usingUtils->containsOnlyNumbers(choice)) {
			trueChoice = stoi(choice);
		}
		else {
			trueChoice = -1;
		}

		if (trueChoice == 1) { 
			Seller* seller = new Seller(name, surname, date, phoneNumber, email, password); 
			allSellers.push_back(*seller); 
			cout << "\nSua conta foi criada com sucesso!\n"; 
			system("pause"); 
			running = false; 
		}
		else if (trueChoice == 2) {
			cout << "\nVoltando ao menu inicial.\n";
			system("pause");
			running = false;
		}
		else {
			cout << "\nValor inválido. Tente novamente.\n";
		}
	}
	
}
bool App::isEmailAvailable(string email) {
	bool emailAvailable = true;
	bool custumer = false;
	bool seller = false;

	for (int i = 0; i < allCustumers.size(); i++) {
		if (foundCustumerEmail(email, i)) {
			custumer = true;
			i = allCustumers.size(); 
		}
	}
	for (int i = 0; i < allSellers.size(); i++) {
		if (foundSellerEmail(email, i)) {
			seller = true;
			i = allSellers.size();
		}
	}

	if (seller || custumer) {
		emailAvailable = false;
	}

	return emailAvailable;
}

// Exit message

void App::exitMessage() {
	system("cls");
	cout << "Obrigado por utilizar nosso sistema!\n";
	cout << "\nEste projeto foi desenvolvido para UC de Programação de Solução Computacionais\n";
	cout << "\n-------------------------------------------------\n";
	cout << "\nProfessores:\n\nAntonio Leães\n\nVinicius Cassol\n";
	cout << "\n-------------------------------------------------\n";
	cout << "\nProjeto desenovilvido por:\n";
	cout << "\nNome: Gustavo Cooper\nRA: 1292313178\n";
	cout << "\nNome: Sofia Carbonera\nRA: 12923112259\n";
	cout << "\nNome: Leonardo Menezes\nRA: 1292315212\n";
	cout << "\nNome: Henrique Doria\nRA: 1292317204\n";

}