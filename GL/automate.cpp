
#include <string>
#include <iostream>
#include "automate.h"
#include "symbole.h"

using namespace std;



/**********/
// C++ program to print the elements of a
// stack from bottom to top
// Copied from StackOverflow
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

Automate::Automate(State * e, Lexer * l) {
    stateStack.push(e);
    lexer = l;
}

bool Automate::start() {
    bool accepter = false;
    while(!accepter){
        accepter = stateStack.top()->transition(*this,lexer->Consulter());
    }
    if (reussi) {
        resultat = ((Expr*)symbolStack.top())->eval();
    }
    return reussi;
}

void Automate::deleteTop(int n){
    for(int i=0;i<n;i++){
        symbolStack.pop();
        delete(stateStack.top());
        stateStack.pop();
    }
}


void Automate::decalage(Symbole* s, State* e)
{
    //cout << "Décalage vers ";
    //e->print();
  //  clog << "Decalage vers " << e->getName() <<  "avec le Symbole  " << *s  << endl;
    symbolStack.push(s);
    stateStack.push(e);
    if(s->isTerminal())
    {

        lexer->Avancer();
    }
}
void Automate::afficheArbre(){
  ((Expr*)symbolStack.top())->AfficheArbre(0);
}

void Automate::reduction(int n) {

    Expr *s;
    State * e = stateStack.top();
    if(e->getName().compare("S3")==0){
        Entier *a = (Entier *)symbolStack.top();
        s = new IntExpr(a);
        deleteTop(1);
    }
    if(e->getName().compare("S7")==0){

        Expr * a = (Expr *)symbolStack.top();
        deleteTop(2);
        Expr * b = (Expr *)symbolStack.top();
        deleteTop(1);
        s = new AddExpr(a,b);
    }
    if(e->getName().compare("S8")==0){
        Expr * a = (Expr *)symbolStack.top();
        deleteTop(2);
        Expr * b = (Expr *)symbolStack.top();
        deleteTop(1);
        s = new MultExpr(a,b);
    }
    // Si on vient de l'état 9 -> Réduction par la règle 3
    if(e->getName().compare("S9")==0){
        // On enlève la parenthèse fermante
        deleteTop(1);
        // On récupère la valeur
        s = new ParExpr((Expr *)symbolStack.top());
        deleteTop(1);
        // On enlève la parenthèse ouvrante
        deleteTop(1);
    }
    //@TODO Implement tree
    //Symbole *s = new Expr(EXPR,valeur);
    //clog << "Réduction depuis " << stateStack.top()->getName() <<  "- Symbole  " << *s  << endl;
    stateStack.top()->transition(*this,s);
}
