#ifndef PLATEAU_FIVE_HPP
#define PLATEAU_FIVE_HPP

#include "../base/Plateau.hpp"
#include <iostream>

using namespace std;

class Plateau_five : public Plateau {
protected:
  int couleur;
public :
  Plateau_five(int);
  ~Plateau_five();
  void affiche();

};


#endif

