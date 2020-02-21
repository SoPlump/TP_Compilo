#include <string>
#include <iostream>
#include "etat.h"
#include "symbole.h"

using namespace std;


Etat::Etat(string name){
    this->name=name;
}
Etat::~Etat(){}
void Etat::print() const
{
    cout << name << endl;
}
//bool Etat::transition(Automate & automate,Symbole * s){return true;}

