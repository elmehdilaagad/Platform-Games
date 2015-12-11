#ifndef PUISSANCE_HPP
#define PUISSANCE_HPP


#include "../base/Joueur.hpp"
#include "../base/Plateau.hpp"
#include "../base/Partie.hpp"
#include <iostream>

class Puissance : public Partie {

private :
  
   int X,Y;
public: 
   Puissance();
   virtual ~Puissance();
   void start();
   void movement(int joId);
   bool Horizontale();
   bool Verticale();
   bool Diagonale1();
   bool Diagonale2();
   bool gagner();
};

#endif
