
#include <string>
#include <iostream>
#include "automate.h"
#include "symbole.h"

using namespace std;


Automate::Automate(Etat * e, Lexer * l){
    stateStack.push(e);
    lexer = l;
    accepter = false;
    while(){

    }
    e->transition(*this,lexer->Consulter());
}

void Automate::deleteTop(int n){
    for(int i=0;i<n;i++){
        delete(symbolStack.top());
        symbolStack.pop();
        delete(stateStack.top());
        stateStack.pop();
    }
}


void Automate::decalage(Symbole* s, Etat* e)
{
    cout << "Décalage vers ";
    e->print();
    symbolStack.push(s);
    stateStack.push(e);
    if(s->isTerminal())
    {

        lexer->Avancer();
    }
    e->transition(*this,lexer->Consulter());
}

void Automate::reduction(int n) {

    int valeur = 0;

    Etat * e = stateStack.top();
    if(e->getName().compare("E3")==0){
        valeur = ((Entier *)symbolStack.top())->getValeur();
        deleteTop(1);
    }
    if(e->getName().compare("E7")==0){
        int valeur1 = ((Expr *)symbolStack.top())->getValeur();
        deleteTop(2);
        int valeur2 = ((Expr *)symbolStack.top())->getValeur();
        deleteTop(1);
        valeur = valeur1+valeur2;
    }
    if(e->getName().compare("E8")==0){
        int valeur1 = ((Expr *)symbolStack.top())->getValeur();
        deleteTop(2);
        int valeur2 = ((Expr *)symbolStack.top())->getValeur();
        deleteTop(1);
        valeur = valeur1*valeur2;
    }
    // Si on vient de l'état 9 -> Réduction par la règle 3
    if(e->getName().compare("E9")==0){
        // On enlève la parenthèse fermante
        deleteTop(1);
        // On récupère la valeur
        valeur = ((Expr *)symbolStack.top())->getValeur();
        deleteTop(1);
        // On enlève la parenthèse ouvrante
        deleteTop(1);
    }

    Symbole *s = new Expr(valeur);
    clog << "Valeur de E:" << valeur << endl;
    stateStack.top()->print();
    stateStack.top()->transition(*this,s);
}

