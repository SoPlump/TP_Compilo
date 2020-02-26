#include <string>
#include <iostream>
#include "states.h"

using namespace std;




//OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR
bool S0::transition(Automate & automate,Symbole* s)
{

    switch(*s)
    {
    case INT:
        automate.decalage(s,new S3());
        break;
    case OPENPAR:
        automate.decalage(s,new S2());
        break;
    case EXPR: case ADDEXPR: case MULTEXPR: case PAREXPR: case INTEXPR:
        automate.decalage(s, new S1());
        break;
    default:
        automate.setReussi(false);
        cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
        cerr << "Symbole attendu: entier,( ou une expression" << endl;
        return true;
    }
    return false;
}


/*** state S1 ******/

bool S1::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.decalage(s,new S4());
        break;
    case MULT:
        automate.decalage(s,new S5());
        break;
    case FIN:
        return true;
        break;
    default:
      automate.setReussi(false);
      cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
      cerr << "Symbole attendu: +,* ou fin" << endl;
      return true;
    }
    return false;
}

/*** state S2 ******/

bool S2::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case INT:
        automate.decalage(s,new S3());
        break;
    case OPENPAR:
        automate.decalage(s,new S2());
        break;
    case EXPR: case ADDEXPR: case MULTEXPR: case PAREXPR: case INTEXPR:
        automate.decalage(s,new S6());
        break;
    default:
      automate.setReussi(false);
      cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
      cerr << "Symbole attendu: entier,( ou expression" << endl;
      return true;
    }
    return false;
}

/*** state S3 ******/

bool S3::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.reduction(1);
        break;
    case MULT:
        automate.reduction(1);
        break;
    case CLOSEPAR:
        automate.reduction(1);
        break;
    case FIN:
        automate.reduction(1);
        break;
    default:
        automate.setReussi(false);
        cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
        cerr << "Symbole attendu: +,*,) ou fin" << endl;
        return true;
    }
    return false;
}

/*** state S4 ******/

bool S4::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case INT:
        automate.decalage(s,new S3());
        break;
    case OPENPAR:
        automate.decalage(s,new S2());
        break;
    case EXPR: case ADDEXPR: case MULTEXPR: case PAREXPR: case INTEXPR:
        automate.decalage(s,new S7());
        break;
    default:
      automate.setReussi(false);
    cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
    cerr << "Symbole attendu: entier,( ou expression" << endl;
      return true;
    }
    return false;
}

/*** state S5 ******/

bool S5::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case INT:
        automate.decalage(s,new S3());
        break;
    case OPENPAR:
        automate.decalage(s,new S2());
        break;
    case EXPR: case ADDEXPR: case MULTEXPR: case PAREXPR: case INTEXPR:
        automate.decalage(s,new S8());
        break;
    default:
      automate.setReussi(false);
      cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
      cerr << "Symbole attendu: entier,( ou expression" << endl;
      return true;
    }
    return false;
}


/*** state S6 ******/

bool S6::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.decalage(s,new S4());
        break;
    case MULT:
        automate.decalage(s,new S5());
        break;
    case CLOSEPAR:
        automate.decalage(s,new S9());
        break;
    default:
      automate.setReussi(false);
    cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
    cerr << "Symbole attendu: +,* ou )" << endl;
        return true;
    }
    return false;
}

/*** state S7 ******/

bool S7::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.reduction(3);
        break;
    case MULT:
        automate.decalage(s,new S5());
        break;
    case CLOSEPAR:
        automate.reduction(3);
        break;
    case FIN:
        automate.reduction(3);
        break;
    default:
      automate.setReussi(false);
        cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
        cerr << "Symbole attendu: +,*,) ou fin" << endl;
        return true;
    }
    return false;
}

/*** state S8 ******/

bool S8::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.reduction(3);
        break;
    case MULT:
        automate.reduction(3);
        break;
    case CLOSEPAR:
        automate.reduction(3);
        break;
    case FIN:
        automate.reduction(3);
        break;
    default:
      automate.setReussi(false);
        cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
        cerr << "Symbole attendu: +,*,) ou fin" << endl;
        return true;
    }
    return false;
}
/*** state S9 ******/

bool S9::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.reduction(3);
        break;
    case MULT:
        automate.reduction(3);
        break;
    case CLOSEPAR:
        automate.reduction(3);
        break;
    case FIN:
        automate.reduction(3);
        break;
    default:
      automate.setReussi(false);
        cerr << "Erreur - Symbole inattendu" << s->getName() << endl;
        cerr << "Symbole attendu: +,*,) ou fin" << endl;
        return true;
    }
    return false;
}
