#include <iostream>
#include <iomanip>
#include "WalletOperator.h"
#include "CurrencyOperator.h"

using namespace std;

//=, ==, +, -, *, +=, -=, *=


Currency::Currency()
{
    this->name="zloty";
    this->shortcut="PLN";
    this->exchange=1;
}


Currency::Currency (std::string name, std::string shortcut, int exchange)
{
    this->name=name;
    this->shortcut=shortcut;
    this->exchange=exchange;
}


ostream& operator<< (ostream &os, const Currency &trial)
{
    os<<"Nazwa:";
    os.width(8);
    os<<trial.name<<" Skrot:  ";
    os.width(3);
    os<<trial.shortcut<<" Kurs: "<<trial.exchange/100<<'.'<<trial.exchange%100<<endl;
    return os;
}


bool Currency::operator==(const Currency &trial)
{
    if(( this->name == trial.name ) &&( this->shortcut == trial.shortcut ) && (this->exchange == trial.exchange) )
         return true;
    else
         return false;
}

void Currency::operator= (const Currency &trial)
{
    this->name=trial.name;
    this->shortcut=trial.shortcut;
    this->exchange=trial.exchange;
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



