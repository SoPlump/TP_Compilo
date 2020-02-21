#pragma once

#include <string>
#include <stack>

#include "symbole.h"
#include "etat.h"
#include "lexer.h"

using namespace std;

class Automate {
private:
    stack<Symbole *> symbolStack;
    stack<Etat *> stateStack;
    Lexer * lexer;
    int resultat =0;
    void deleteTop(int n);
public:
    Automate(Etat * e, Lexer * l);

    void decalage(Symbole*s, Etat*e);
    void reduction(int n);


};
