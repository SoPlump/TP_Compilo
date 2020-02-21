
#include <string>
#include <iostream>
#include "automate.h"
#include "symbole.h"

using namespace std;



/**********/
// C++ program to print the elements of a
// stack from bottom to top
#include <bits/stdc++.h>
using namespace std;

// Recursive function to print stack elements
// from bottom to top without changing
// their order
void PrintStack(stack<Symbole *> s)
{
        // If stack is empty then return
        if (s.empty())
                return;


        Symbole * x = s.top();

        // Pop the top element of the stack
        s.pop();

        // Recursively call the function PrintStack
        PrintStack(s);

        // Print the stack element starting
        // from the bottom
        cout << *x << " ";

        // Push the same element onto the stack
        // to preserve the order
        s.push(x);
}


/*******/

Automate::Automate(Etat * e, Lexer * l){
    stateStack.push(e);
    lexer = l;
     bool accepter = false;
    while(!accepter){
        accepter = stateStack.top()->transition(*this,lexer->Consulter());
        PrintStack(symbolStack);
        cout <<  endl;
    }
    cout << "Arbre fini !" <<  endl;
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
    cout <<  endl;
    stateStack.top()->transition(*this,s);
}

