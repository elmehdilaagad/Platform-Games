#ifndef PLATEAU_DAME_HPP
#define PLATEAU_DAME_HPP


#include "../base/Joueur.hpp"
#include "../base/Plateau.hpp"

class Plateau_dame : public Plateau {
   int l,c;
   public:   
	Plateau_dame(Joueur *j1, Joueur *j2);
	virtual ~Plateau_dame();
 	virtual void affiche();
        virtual void modifPiece(int origx,int origy,int destx,int desty);
       	

};


#endif
