#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Symbole::AfficheArbre(int profondeur) {
  for(int i=0;i<profondeur;i++){
    cout << "\t";
  }
   cout<<Etiquettes[ident]<<endl;
}

void AddExpr::AfficheArbre(int profondeur) {
  a->AfficheArbre(profondeur+1);
  for(int i=0;i<profondeur;i++){
    cout << "\t";
  }
  cout<<"+"<<endl;
  b->AfficheArbre(profondeur+1);
}

void MultExpr::AfficheArbre(int profondeur) {
  a->AfficheArbre(profondeur+1);
  for(int i=0;i<profondeur;i++){
    cout << "\t";
  }
  cout<<"x"<<endl;
  b->AfficheArbre(profondeur+1);
}

void ParExpr::AfficheArbre(int profondeur) {
  a->AfficheArbre(profondeur);
}

void IntExpr::AfficheArbre(int profondeur) {
    a->AfficheArbre(profondeur);
}

void Entier::AfficheArbre(int profondeur) {
  for(int i=0;i<profondeur;i++){
    cout << "\t";
  }
  cout<<valeur<<endl;
}

ostream& operator<<(ostream &out,Symbole * s){
    out << Etiquettes[s->ident];
    return out;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}
