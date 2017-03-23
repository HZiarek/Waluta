
#ifndef WALLETOPERATOR_H
#define WALLETOPERATOR_H
#include <iomanip>
#include <string>
#include <iostream>

#include "CurrencyOperator.h"

//=, ==, +, -, *, +=, -=, *=


class Wallet
{
private:
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

