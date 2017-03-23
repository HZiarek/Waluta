#ifndef operator_h
#define operator_h
#include <iomanip>
#include <string>
#include <iostream>


//=, ==, +, -, *, +=, -=, *=

class Currency
{
public:
    std::string name;
    std::string shortcut;
    int exchange;


    Currency();
    Currency (std::string name, std::string shortcut, int exchange);


    void Create();
    void Show();
    bool operator==(const Currency &trial);
    void operator= (const Currency &trial);
    Currency operator* (const double x);
    void operator+= (const int x);
    void operator-= (const int x);
    void operator*= (const double x);


    friend
    std::ostream& operator<< (std::ostream &os, const Currency &trial);
    friend
    std::istream& operator>> (std::istream &is, Currency &trial);
};

class Wallet
{
private:
    //std::string name_of_currency;
    Currency type;
    int value;

public:
    Wallet();
    Wallet(Currency type, int value);

    bool operator==(const Wallet &trial);
    void operator= (const Wallet &trial);
    Wallet operator+ (const Wallet &trial);
    Wallet operator- (const Wallet &trial);
    void operator+= (const Wallet &trial);
    void operator-= (const Wallet &trial);


    friend
    std::ostream& operator<< (std::ostream &os, const Wallet &trial);
    //friend
    //std::istream& operator>> (std::istream &is, Currency &trial);
};

#endif
