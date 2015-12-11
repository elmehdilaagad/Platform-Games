#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>
using namespace std;

class Joueur{
public:
  string nom;
  int numero;
public:
  Joueur();
  Joueur(string n, int id);
  ~Joueur();
  string getNom();
  void setNom(string nom);
  int getNumero();
  void setNumero(int i);
};


#endif
