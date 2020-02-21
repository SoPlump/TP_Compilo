#include <string>
#include <iostream>
#include "etats.h"

using namespace std;




//OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR
bool E0::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case INT:
        automate.decalage(s,new E3());
        break;
    case OPENPAR:
        automate.decalage(s,new E2());
        break;
    case EXPR:
        automate.decalage(s, new E1());
    default:
        cerr << "erreur" << endl;
        cerr << "Symbole recu: ";
        s->Affiche();
        break;
    }
    return false;
}


/*** Etat E1 ******/

bool E1::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.decalage(s,new E4());
        break;
    case MULT:
        automate.decalage(s,new E5());
        break;
    case FIN:
        cout << "ACCEPTER" << endl;
        return true;
        break;
    default:
        cerr << "  erreur" << endl;
        break;
    }
    return false;
}

/*** Etat E2 ******/

bool E2::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case INT:
        automate.decalage(s,new E3());
        break;
    case OPENPAR:
        automate.decalage(s,new E2());
        break;
    case EXPR:
        automate.decalage(s,new E6());
        break;
    default:
        cerr << "erreur" << endl;
        break;
    }
    return false;
}

/*** Etat E3 ******/

bool E3::transition(Automate & automate,Symbole* s)
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
        cerr << "erreur" << endl;
        break;
    }
    return false;
}

/*** Etat E4 ******/

bool E4::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case INT:
        automate.decalage(s,new E3());
        break;
    case OPENPAR:
        automate.decalage(s,new E2());
        break;
    case EXPR:
        automate.decalage(s,new E7());
        break;
    default:
        cerr << "erreur" << endl;
        break;
    }
    return false;
}

/*** Etat E5 ******/

bool E5::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case INT:
        automate.decalage(s,new E3());
        break;
    case OPENPAR:
        automate.decalage(s,new E2());
        break;
    case EXPR:
        automate.decalage(s,new E8());
        break;
    default:
        cerr << "erreur" << endl;
        break;
    }
    return false;
}


/*** Etat E6 ******/

bool E6::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.decalage(s,new E4());
        break;
    case MULT:
        automate.decalage(s,new E5());
        break;
    case CLOSEPAR:
        automate.decalage(s,new E9());
        break;
    default:
        cerr << "erreur" << endl;
        break;
    }
    return false;
}

/*** Etat E7 ******/

bool E7::transition(Automate & automate,Symbole* s)
{
    switch(*s)
    {
    case PLUS:
        automate.reduction(3);
        break;
    case MULT:
        automate.decalage(s,new E5());
        break;
    case CLOSEPAR:
        automate.reduction(3);
        break;
    case FIN:
        automate.reduction(3);
        break;
    default:
        cerr << "erreur" << endl;
        break;
    }
    return false;
}

/*** Etat E8 ******/

bool E8::transition(Automate & automate,Symbole* s)
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
        cerr << "erreur" << endl;
        break;
    }
    return false;
}
/*** Etat E9 ******/

bool E9::transition(Automate & automate,Symbole* s)
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
        cerr << "erreur" << endl;
        break;
    }
    return false;
}
