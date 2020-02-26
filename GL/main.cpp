#include <iostream>
#include "lexer.h"
#include "states.h"
#include "automate.h"


int main(void) {
  cout << "Tapez q pour quitter" << endl;
  string chaine="";
  cout << "Entrez une expression (tapez q pour quitter):" << endl;

  cin >> chaine;


  while(chaine.compare("q")!=0){


     Lexer l(chaine);

     State * s0 = new S0();
     Automate a = Automate(s0,&l);


    if(a.start()){
      cout << "Arbre fini !" <<  endl;
      cout << "Resultat: " << a.getResult() << endl;

     cout << "Voulez vous afficher l'arbre (o/n) ?" << endl;

     cin >> chaine;
     while(chaine.compare("o")!=0&&chaine.compare("n")!=0){
        cout << "???" << endl;
        cin >> chaine;
     }
     if(chaine.compare("o")==0){
       a.afficheArbre();
     }
   }


     cout << "Entrez une expression (tapez q pour quitter):" << endl;

     cin >> chaine;

  }

   return 0;
}
