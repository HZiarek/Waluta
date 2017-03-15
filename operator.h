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
    float exchange;


    Currency();
    Currency (std::string name, std::string shortcut, float exchange);


    void Create();
    void Show();
    bool operator==(const Currency &trial);
    void operator= (const Currency &trial);
    Currency operator+ (const Currency &trial);
    Currency operator- (const Currency &trial);
    Currency operator* (const Currency &trial);
    void operator+= (const Currency &trial);
    void operator-= (const Currency &trial);
    void operator*= (const Currency &trial);


    friend
    std::ostream& operator<< (std::ostream &os, const Currency &trial);
    friend
    std::istream& operator>> (std::istream &is, Currency &trial);
};

#endif
