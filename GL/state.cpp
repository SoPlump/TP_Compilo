#include <string>
#include <iostream>
#include "state.h"
#include "symbole.h"

using namespace std;


State::State(string name){
    this->name=name;
}
State::~State(){}
void State::print() const
{
    cout << name << endl;
}
//bool State::transition(Automate & automate,Symbole * s){return true;}
