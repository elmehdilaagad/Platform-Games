#ifndef JOUEUR_DAME_HPP
#define JOUEUR_DAME_HPP

#include <string>
#include "../base/Joueur.hpp"

using namespace std;


class Joueur_dame : public Joueur {
public:
	Joueur_dame(string _nom, int _numero);
	virtual ~Joueur_dame();
};

#endif
