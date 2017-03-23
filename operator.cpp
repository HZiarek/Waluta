#include <iostream>
#include <iomanip>
#include "operator.h"

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

void Currency::Create()
    {
        cout<<"DODAWANIE NOWEJ WALUTY: "<<endl;
        cout<<"Podaj nazwe waluty: "<<endl;
        cin>>name;
        cout<<"Podaj skrot waluty: "<<endl;
        cin>>shortcut;
        cout<<"Podaj kurs waluty: "<<endl;
        cin>>exchange;
    }

void Currency::Show()
    {
        cout<<"Nazwa: "<<name<<endl<<"Skrot: "<<shortcut<<endl<<"Kurs: "<<exchange;
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


istream& operator>> (istream &is, Currency &trial)
{
    cout<<"Podaj nazwe: ";
    is>>trial.name;
    cout<<"Podaj skrot: ";
    is>>trial.shortcut;
    cout<<"Podaj kurs: ";
    is>>trial.exchange;
    return is;
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
