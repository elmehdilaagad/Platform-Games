#ifndef DAME_HPP
#define DAME_HPP

#include "../base/Joueur.hpp"
#include "../base/Plateau.hpp"
#include "../base/Partie.hpp"
#include <iostream>

class Dame : public Partie {
private :
   Joueur *j1,*j2;
   Plateau *pla;
public: 
   Dame(Plateau *p, Joueur *jo1, Joueur *jo2);
   virtual ~Dame();
   void start();
};


#endif
