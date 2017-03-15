#include "operator.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
  vector <Currency> cantor;
  int decision;
  char next;
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

  example.exchange=1.2;
  example.name="euro";
  example.shortcut="EUR";
  example2.exchange=2.8;
  example2.name="zloty";
  example2.shortcut="PLN";
  //example*=example2;

  //example.Show();
  cin>>example3;
  //cout<<example<<example2;
  return 0;
}
