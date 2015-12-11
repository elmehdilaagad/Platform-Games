#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>
#include "Joueur.hpp"
#include "Plateau.hpp"

class Partie {
  
protected:
    int nbJoueurs;
    Plateau *plateau;
    vector<Joueur *> joueurs;
    int numJoueurCourant;
public: 
  Partie();
  virtual ~Partie();
  virtual int getNbJoueurs();
  virtual Plateau *getPlateau();
  virtual int getNumJoueurCourant();
  virtual vector<Joueur*> getJoueurs();
  Joueur *nextJoueur();
  void ajouteJoueur(Joueur *j);
  virtual void start() = 0;
     
   
};


#endif
