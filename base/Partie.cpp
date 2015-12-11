#include <iostream>
#include "Partie.hpp"

using namespace std;


Partie::Partie(){
  this->numJoueurCourant = 1;
}

Partie::~Partie(){}

Plateau *Partie::getPlateau(){
	return plateau;
}

int Partie::getNbJoueurs(){
	return nbJoueurs;
}

int Partie::getNumJoueurCourant(){
	return numJoueurCourant;
}

vector<Joueur *> Partie::getJoueurs(){
	return joueurs;
}

Joueur *Partie::nextJoueur(){
	int next = numJoueurCourant + 1;
	numJoueurCourant = next % nbJoueurs;
	return joueurs[numJoueurCourant];
}

void Partie::ajouteJoueur(Joueur *j){
  joueurs.push_back(j);
}
