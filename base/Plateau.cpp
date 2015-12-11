#include <vector>
#include "Plateau.hpp"
using namespace std;


Plateau::~Plateau(){};

int Plateau::getNbLignes(){
	return nbLignes;
}

int Plateau::getNbCols(){
	return nbCols;
}

void Plateau::setNbLignes(int _nbLignes){
	nbLignes = _nbLignes;
}

void Plateau::setNbCols(int _nbCols){
	nbCols = _nbCols;
}

int** Plateau::getPlateau(){
 return grille;
}

void Plateau::affiche(){}

