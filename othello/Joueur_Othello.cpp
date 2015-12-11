#include "Joueur_Othello.hpp"


Joueur_Othello::Joueur_Othello(string nom_, int num) : Joueur(nom_,num) {

  this->score = 0;
}

Joueur_Othello::~Joueur_Othello(){}
/*
Joueur::Joueur(int num, Partie *p) {
    this->score = 0;
    this->numero = num;
    this->p = p;
}

*/


int Joueur_Othello::getScore() { 
    return score;
}

void Joueur_Othello::setScore(int s){
  score = s;
}
