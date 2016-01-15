#include <iostream>
#include <vector>
#include "base/Joueur.hpp"
#include "base/Plateau.hpp"
#include "base/Partie.hpp"
#include "puissance/Puissance.hpp"
#include "puissance/Joueur_puissance.hpp"
#include "puissance/Plateau_puissance.hpp"

#include "othello/Othello.hpp"
#include "othello/Joueur_Othello.hpp"
#include "othello/Plateau_Othello.hpp"

#include "fiveormore/FiveOrMore.hpp"
#include "fiveormore/Plateau_five.hpp"

#include "dame/Dame.hpp"
#include "dame/Joueur_dame.hpp"
#include "dame/Plateau_dame.hpp"

using namespace std;

void lancerJeuPuissance(){
  Joueur *j1 = new Joueur_puissance("noir" , 1);
  Joueur *j2 = new Joueur_puissance("blanc",2);
 
  Puissance *p4 = new Puissance();
  p4->ajouteJoueur(j1);
  p4->ajouteJoueur(j2);
  p4->start();
}


void lancerJeuDame(){
  Joueur *j1 = new Joueur_dame("noir" , 1);
  Joueur *j2 = new Joueur_dame("blanc",2);
  Plateau *plateau = new Plateau_dame(j1,j2);
  Dame *d = new Dame(plateau,j1,j2);
  d->start();
}

void lancerJeuOthello(){

  Joueur *j1 = new Joueur_Othello("noir",1);
  Joueur *j2 = new Joueur_Othello("blanc",2);
  Othello *o = new Othello();
  o->ajouteJoueur(j1);
  o->ajouteJoueur(j2);

  cout << " Jeu Othello Started " << endl;
  o->start();
  
}

void lancerFiveOrMore(){
  FiveOrMore *f = new FiveOrMore();
  f->start();
}

int main(void){
  int in = 0;
  while(in == 0){
    cout<<endl;
    cout<<"Choice jeu ? :"<<endl;
    cout<<"1: Jeu de Puissance4"<<endl;
    cout<<"2: Five Or More"<<endl;
    cout<<"3: Othelo "<<endl;
    cout<<"4: Jeu dame "<<endl;
    cout<<"> ";
    cin>>in;
    if(in==1 || in==2 || in==3 || in == 4) break;
    else in = 0;
  }
  if(in==1) lancerJeuPuissance();
  else if(in==2)  lancerFiveOrMore();
  else if(in==3)  lancerJeuOthello(); 
  else if(in==4) lancerJeuDame();
 

  return 0;
}

