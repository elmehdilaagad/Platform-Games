#ifndef OTHELLO_HPP
#define OTHELLO_HPP

#include "../base/Partie.hpp"
#include "../base/Joueur.hpp"


class Othello : public Partie {

private:
  
  int score;

public:
  Othello();
  virtual ~Othello();
  void jouer(int);
  void start();
  void mouvement();
  bool verification(int x, int y,int j);
  int confirme(int,int,int,int,bool);
  int MovePossible(int,int,int,int,bool);
  bool est_remplie();
  int vainqueur();
  int nbr_case_vide();

};

#endif
