#ifndef FIVE_OR_MORE_HPP
#define FIVE_OR_MORE_HPP



#include "../base/Partie.hpp"
#include <iostream>
#include <string>

class FiveOrMore : public Partie {

private :
  int nbColor;

public: 
  FiveOrMore();
  void choix_coordonnees();
  bool vertical(int);
  bool horizontal(int);
  int getCouleurs();
  int fin();
  virtual void start();
  void choix_utilisateurs();
};

#endif
