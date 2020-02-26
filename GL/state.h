#pragma once

#include <string>
#include "symbole.h"

using namespace std;

class Automate;

class State {
protected:
    string name;
public:
    State(string name);
    string getName(){return name;}
    virtual ~State();
    void print() const;
    virtual bool transition(Automate & automate,Symbole* s) = 0;
};
