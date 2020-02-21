#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}
ostream& operator<<(ostream &out,Symbole s){
    out << Etiquettes[s.ident];
    return out;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

