#include "CurrencyOperator.h"
#include "WalletOperator.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
  //vector <Currency> cantor;
  //int decision;
  //char next;
  Currency example, example2, example3;

  /*
  for (;;)
  {
      system ("cls");
      cout<<"Co chcesz zrobic?"<<endl<<"1) Dodaj nowa walute"<<endl<<"2) Pokaz walty"<<endl<<"3) Zakoncz"<<endl;
      cin>>decision;
      if (decision%3==1) {example.Create(); cantor.push_back(example);}
          else if (decision%3==2) {for (int i=0; i<cantor.size(); i++) cantor[i].Show();  cin>>next;}
              else exit(0);
  }
  */

  example.name="euro";
  example.shortcut="EUR";
  example.exchange=100;
  example2.name="funt";
  example2.shortcut="GPB";
  example2.exchange=450;

  Wallet w1 = Wallet(example, 100);
  Wallet w2 = Wallet(example2, 1000);

  Wallet w3;

  example3=example*2;
  example3+=1;
  cout<<example3;

  return 0;
}
