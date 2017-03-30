#ifndef WALLET_H
#define WALLET_H
#include <iomanip>
#include <string>
#include <iostream>

#include "Currency.h"

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
    Wallet& operator= (const Wallet &trial);
    Wallet operator+ (const Wallet &trial);
    Wallet operator- (const Wallet &trial);
    void operator+= (const Wallet &trial);
    void operator-= (const Wallet &trial);
    int get_value() const;

};

#endif

