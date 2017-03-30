#include <iostream>
#include <iomanip>
#include "Wallet.h"
#include "Currency.h"

using namespace std;

//=, ==, +, -, *, +=, -=, *=

Wallet::Wallet()
{
    this->type=Currency();
    this->value=100;
}

Wallet::Wallet (Currency type, int value)
{
    this->type=type;
    this->value=value;
}

bool Wallet::operator==(const Wallet &trial)
{
    return (this->type==trial.type && (this->value == trial.value));
}

Wallet& Wallet::operator= (const Wallet &trial)
{
    this->type=trial.type;
    this->value=trial.value;
    return *this;
}

Wallet Wallet::operator+ (const Wallet &trial)
{
    if (this->type==trial.type) return Wallet(this->type, this->value+trial.value);
    else return Wallet(this->type, (this->value*(this->type).get_exchange()+trial.value*trial.type.get_exchange())/(this->type).get_exchange());
}


Wallet Wallet::operator- (const Wallet &trial)
{
    Wallet tmp = Wallet (this->type, this->value);
    if (tmp.type==trial.type) tmp.value=tmp.value-trial.value;
    else tmp.value=(tmp.value*tmp.type.get_exchange()-trial.value*trial.type.get_exchange())/tmp.type.get_exchange();
    if (tmp.value<0) tmp.value=0;
    return tmp;
}



void Wallet::operator+= (const Wallet &trial)
{
    this->value=(this->value*(this->type).get_exchange()+trial.value*trial.type.get_exchange())/(this->type).get_exchange();
}


void Wallet::operator-= (const Wallet &trial)
{
    this->value=(this->value*(this->type).get_exchange()-trial.value*trial.type.get_exchange())/(this->type).get_exchange();
    if (this->value<0) this->value=0;
}

int Wallet::get_value() const
{
    return this->value;
}

