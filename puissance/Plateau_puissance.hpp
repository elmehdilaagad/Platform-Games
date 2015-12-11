#ifndef PLATEAU_PUISSANCE_HPP
#define PLATEAU_PUISSANCE_HPP

#include <string>
#include "../base/Plateau.hpp"
#include "../base/Joueur.hpp"
using namespace std;

class Plateau_puissance : public Plateau{
public: 
	Plateau_puissance();
	virtual ~Plateau_puissance();
	virtual void affiche();
};

#endif
