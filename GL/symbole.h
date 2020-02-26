#pragma once

#include <string>
#include <map>
#include <iostream>

using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR, ADDEXPR, MULTEXPR, PAREXPR, INTEXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" , "EXPR","ADDEXPR", "MULTEXPR", "PAREXPR", "INTEXPR"};

class Symbole {
public:
    Symbole(int i,bool terminal) : ident(i), terminal(terminal){  }
    virtual ~Symbole() { }
    operator int() const { return ident; }
    bool isTerminal(){ return terminal; }
    virtual void AfficheArbre(int profondeur) ;
    void Affiche();
    string getName() {return Etiquettes[ident];}
    friend ostream& operator<<(ostream &out,Symbole * s);
protected:
    int ident;
    bool terminal;


};

class Expr : public Symbole {
public:
    Expr(int i,int valeur):Symbole(i,false),valeur(valeur) {}
     ~Expr() {}
    int getValeur() {return valeur;}
    virtual int eval() = 0;
protected:
    int valeur;
};

/*** Symbole addition
 *
 *AddExpr = a + b avec a et b des expressions
 *
 */
class AddExpr: public Expr {
public:
    AddExpr(Expr * a, Expr * b):Expr(ADDEXPR,false),a(a),b(b) {}
    virtual void AfficheArbre(int profondeur);
    //@TODO add destructeur
    int eval() { return a->eval() + b->eval();}
protected:
    Expr * a;
    Expr * b;
};

/*** Symbole multiplication
 *
 *AddExpr = a*b avec a et b des expressions
 *
 */
class MultExpr: public Expr {
public:
    MultExpr(Expr * a, Expr * b):Expr(MULTEXPR,false),a(a),b(b) {}
    virtual void AfficheArbre(int profondeur);
    //@TODO add destructeur
    int eval() { return a->eval()*(b->eval());}
protected:
    Expr * a;
    Expr * b;
};

/*** Symbole parenthèse
 *
 *ParExpr = (a) avec a une expression
 *
 */
class ParExpr: public Expr {
public:
    ParExpr(Expr * a):Expr(PAREXPR,false),a(a) {}
    virtual void AfficheArbre(int profondeur);
    //@TODO add destructeur
    int eval() { return a->eval();}
protected:
    Expr * a;
};




class Entier : public Symbole {
public:
    Entier(int v) : Symbole(INT,true), valeur(v) { }
    int getValeur() {return valeur;} // @TODO remove
    virtual void AfficheArbre(int profondeur);
    int eval() { return valeur;}
    ~Entier() { }
    virtual void Affiche();
protected:
    int valeur;
};

/*** Expression numérique
 *
 *IntExpr = a avec a un entier
 *
 */
class IntExpr: public Expr {
public:
    IntExpr(Entier* a):Expr(INTEXPR,false),a(a) {}
    virtual void AfficheArbre(int profondeur);
    //@TODO add destructeur
    int eval() { return a->getValeur();}
protected:
    Entier * a;
};
