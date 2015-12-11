#include "Joueur.hpp"
#include <string>
using namespace std;

Joueur::Joueur(string n, int id){
  this->nom = n;
  this->numero = id;
}
Joueur::Joueur(){}
Joueur::~Joueur(){}

string Joueur::getNom(){ return nom ; }
int Joueur::getNumero(){ return numero ; }

void Joueur::setNom(string nom){
  this->nom = nom;
}

void Joueur::setNumero(int numero){
  this->numero = numero;
}
