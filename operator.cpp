#include <iostream>
#include <iomanip>
#include "operator.h"

using namespace std;

//=, ==, +, -, *, +=, -=, *=


Currency::Currency()
{
    this->name="";
    this->shortcut="";
    this->exchange=0;
}

Currency::Currency (std::string name, std::string shortcut, float exchange)
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
    os<<trial.shortcut<<" Kurs:";
    os<<setprecision(3)<<trial.exchange<<endl;
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

Currency Currency::operator+ (const Currency &trial)
{
    return Currency(this->name, this->shortcut, this->exchange+trial.exchange);
}

Currency Currency::operator- (const Currency &trial)
{
    return Currency (this->name, this->shortcut, this->exchange-trial.exchange);
}

Currency Currency::operator* (const Currency &trial)
{
    return Currency (this->name, this->shortcut, this->exchange*trial.exchange);
}

void Currency::operator+= (const Currency &trial)
{
    this->exchange+=trial.exchange;
}

void Currency::operator-= (const Currency &trial)
{
    this->exchange-=trial.exchange;
}

void Currency::operator*= (const Currency &trial)
{
    this->exchange*=trial.exchange;
}
