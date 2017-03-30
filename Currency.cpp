#include <iostream>
#include <iomanip>
#include "Wallet.h"
#include "Currency.h"

using namespace std;

//=, ==, +, -, *, +=, -=, *=


Currency::Currency()
{
    this->name="zloty";
    this->shortcut="PLN";
    this->exchange=100;
}


Currency::Currency (std::string name, std::string shortcut, int exchange)
{
    this->name=name;
    this->shortcut=shortcut;
    this->exchange=exchange;
}

bool Currency::operator==(const Currency &trial)
{
    return (( this->name == trial.name ) &&( this->shortcut == trial.shortcut ) && (this->exchange == trial.exchange));
}

Currency& Currency::operator= (const Currency &trial)
{
    this->name=trial.name;
    this->shortcut=trial.shortcut;
    this->exchange=trial.exchange;
    return *this;
}


Currency Currency::operator* (const double x)
{
    return Currency (this->name, this->shortcut, this->exchange*x);
}

void Currency::operator+= (const int x)
{
    this->exchange+=x;
    if (this->exchange<0) this->exchange=0;
}

void Currency::operator-= (const int x)
{
    this->exchange-=x;
    if (this->exchange<0) this->exchange=0;
}

void Currency::operator*= (const double x)
{
    this->exchange*=x;
}

int Currency::get_exchange() const
{
    return this->exchange;
}


