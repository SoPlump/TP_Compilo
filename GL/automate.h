#pragma once

#include <string>
#include <stack>

#include "symbole.h"
#include "state.h"
#include "lexer.h"

using namespace std;

class Automate {
private:
    stack<Symbole *> symbolStack;
    stack<State *> stateStack;
    bool reussi =1;
    Lexer * lexer;
    int resultat =0;
    void deleteTop(int n);
public:
    Automate(State * e, Lexer * l);
    bool start();
    void decalage(Symbole*s, State*e);
    void reduction(int n);
    void setReussi(bool r) { reussi=r; }
    int getResult() { return resultat; }
    void afficheArbre();
};
