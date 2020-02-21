#include <iostream>
#include "lexer.h"
#include "etats.h"
#include "automate.h"

int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   //Symbole * s;
   Etat * e0 = new E0();
   Automate(e0,&l);
   /*while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }*/
   return 0;
}

