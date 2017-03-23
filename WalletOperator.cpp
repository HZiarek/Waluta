#include <iostream>
#include <iomanip>
#include "WalletOperator.h"
#include "CurrencyOperator.h"

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
    if(this->type==trial.type && (this->value == trial.value) )
         return true;
    else
         return false;
}

void Wallet::operator= (const Wallet &trial)
{
    this->type=trial.type;
    this->value=trial.value;
}

Wallet Wallet::operator+ (const Wallet &trial)
{
    if (this->type==trial.type) return Wallet(this->type, this->value+trial.value);
    else return Wallet(this->type, (this->value*this->type.exchange+trial.value*trial.type.exchange)/this->type.exchange);
}


Wallet Wallet::operator- (const Wallet &trial)
{
    Wallet tmp = Wallet (this->type, this->value);
    if (tmp.type==trial.type) tmp.value=tmp.value-trial.value;
    else tmp.value=(tmp.value*tmp.type.exchange-trial.value*trial.type.exchange)/tmp.type.exchange;
    if (tmp.value<0) tmp.value=0;
    return tmp;
}



void Wallet::operator+= (const Wallet &trial)
{
    this->value=(this->value*this->type.exchange+trial.value*trial.type.exchange)/this->type.exchange;
}


void Wallet::operator-= (const Wallet &trial)
{
    this->value=(this->value*this->type.exchange-trial.value*trial.type.exchange)/this->type.exchange;
    if (this->value<0) this->value=0;
}


ostream& operator<< (ostream &os, const Wallet &trial)
{
    os<<"Masz "<<trial.value/100<<"."<<trial.value%100<<" w "<<trial.type.name<<endl;
    return os;
}

