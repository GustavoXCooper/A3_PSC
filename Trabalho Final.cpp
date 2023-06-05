
#include <iostream>
#include "Date.h";
#include "Book.h";

int main()
{
    Date date(1, 9, 2001);
    cout << date.GetDay() << endl;
    cout << date.GetMonth() << endl;
    cout << date.GetYear() << endl;
    cout << date.GetFullDate() << endl;
    date.SetDay(35);
    date.SetMonth(0);
    date.SetYear(1499);
    cout << date.GetFullDate() << endl;
    date.SetDay(1);
    date.SetMonth(11);
    date.SetYear(1501);
    cout << date.GetFullDate() << endl;
    
    Book* bookTeste = new Book("title", 100, "só testando o livro", "inteiro", "genreTest", true, 10.03, "Eu Mesmo", "Euzinho");

   // Dúvida! As restrições foram todas feitas nos métodos set, mas o construtot não recebe essas restrições. O que eu faço? Criar restrições novamente quando for chamar o construtor??
    bookTeste->addNewGenre("Teste Gênero");
    bookTeste->showBookInfo();
}
