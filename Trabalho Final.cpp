
#include <iostream>
#include "Date.h";

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
}
