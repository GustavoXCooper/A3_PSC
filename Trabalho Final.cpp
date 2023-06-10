#include <iostream>
#include "Seller.h"
#include "Book.h"
#include <iomanip>

int main()
{
	Date* dateTeste = new Date(10, 9, 2001);
	User* teste = new User("gustavo", "cooper", *dateTeste, "51993855818", "gusxavie8@gmail.com", "123");
	Book bookTeste("Teste", 10, "texto texto", "inteiro", "fantasia", true, 10.2, "teste Autor", "qualquer Uma");
	Seller* sellerTeste = new Seller("gustavo", "cooper", *dateTeste, "51993855818", "gusxavie8@gmail.com", "123");

	cout << sellerTeste->getName() << endl;
	cout << sellerTeste->getSurname() << endl;
	cout << sellerTeste->getNameCompelte() << endl;
	cout << sellerTeste->getPassword() << endl;
	cout << sellerTeste->getEmail() << endl;
	cout << sellerTeste->getPhoneNumber() << endl;


	sellerTeste->addNewBook();
	//sellerTeste->addNewBook();
	sellerTeste->editBook();
	//sellerTeste->removeBook();


	for (int i = 0; i < 1; i++) {
		cout << "\nTitle: " << sellerTeste->getBook(i).getTitle();
		cout << "\nPages: " << sellerTeste->getBook(i).getPages();
		cout << "\nCondição: " << sellerTeste->getBook(i).getCondition();
		cout << "\nGênero: " << sellerTeste->getBook(i).getGenres(0);
		cout << "\nNegociável? " << sellerTeste->getBook(i).getBargainable();
		cout << "\nPreço: " << fixed << setprecision(sellerTeste->getBook(i).getPrice());
		cout << "\nAutor: " << sellerTeste->getBook(i).getAuthor();
		cout << "\nEditora: " << sellerTeste->getBook(i).getPublishingCompany();
	}

	/*
	cout << teste->getName() << endl;
	cout << teste->getSurname() << endl;
	cout << teste->getNameCompelte() << endl;
	cout << teste->getPassword() << endl;
	cout << teste->getEmail() << endl;
	cout << teste->getPhoneNumber() << endl;


	teste->setName("test @");
	teste->setSurname("tes@te");
	teste->setPassword("1234");
	teste->setEmail("teste");
	teste->setPhoneNumber("12a31");

	cout << teste->getName() << endl;
	cout << teste->getSurname() << endl;
	cout << teste->getNameCompelte() << endl;
	cout << teste->getPassword() << endl;
	cout << teste->getEmail() << endl;
	cout << teste->getPhoneNumber() << endl;
	*/
	/*
	cout << bookTeste.getTitle() << endl;
	cout << bookTeste.getBookSummary() << endl;
	cout << bookTeste.getBargainable() << endl;
	cout << bookTeste.getCondition()<< endl;
	cout << bookTeste.getPages() << endl;
	cout << bookTeste.getPrice() << endl;
	cout << bookTeste.getPublishingCompany() << endl;
	cout << bookTeste.getAuthor() << endl;
	//cout << bookTeste.getGenres[0]<< endl;

	bookTeste.setTitle();
	bookTeste.setPublishingCompany();
	bookTeste.setCondition();
	bookTeste.setBargainable();
	bookTeste.setPages(1000);
	bookTeste.setPrice();


	cout << bookTeste.getTitle() << endl;
	cout << bookTeste.getBookSummary() << endl;
	cout << bookTeste.getBargainable() << endl;
	cout << bookTeste.getCondition() << endl;
	cout << bookTeste.getPages() << endl;
	cout << bookTeste.getPrice() << endl;
	cout << bookTeste.getPublishingCompany() << endl;
	cout << bookTeste.getAuthor() << endl;
	*/



}
