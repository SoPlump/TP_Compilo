#pragma once

#include <string>
#include <map>

using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Symbole {
public:
    Symbole(int i,bool terminal) : ident(i), terminal(terminal){  }
    virtual ~Symbole() { }
    operator int() const { return ident; }
    bool isTerminal(){ return terminal; }
    virtual void Affiche();

protected:
    int ident;
    bool terminal;
};

class Expr : public Symbole {
public:
    Expr(int valeur):Symbole(EXPR,false),valeur(valeur) {}
     ~Expr() {}
    int getValeur() {return valeur;}
   // double eval(const map<string,double>& valeurs) = 0;
protected:
    int valeur;
};

class Entier : public Symbole {
public:
    Entier(int v) : Symbole(INT,true), valeur(v) { }
    int getValeur() {return valeur;}
    ~Entier() { }
    virtual void Affiche();
protected:
    int valeur;
};

