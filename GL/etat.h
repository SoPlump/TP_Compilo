#pragma once

#include <string>
#include "symbole.h"

using namespace std;

class Automate;

class Etat {
protected:
    string name;
public:
    Etat(string name);
    string getName(){return name;}
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate,Symbole* s) = 0;
};
