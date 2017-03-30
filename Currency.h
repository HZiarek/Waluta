#ifndef CURRENCY_H
#define CURRENCY_H
#include <iomanip>
#include <string>
#include <iostream>


//=, ==, +, -, *, +=, -=, *=

class Currency
{
private:
    std::string name;
    std::string shortcut;
    int exchange;

public:
    Currency();
    Currency (std::string name, std::string shortcut, int exchange);

   //friend int getExchange()const;

    bool operator==(const Currency &trial);
    Currency& operator= (const Currency &trial);
    Currency operator* (const double x);
    void operator+= (const int x);
    void operator-= (const int x);
    void operator*= (const double x);
    int get_exchange() const;

};


#endif
