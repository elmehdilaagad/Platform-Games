#ifndef JOUEUR_OTHELLO_HPP
#define JOUEUR_OTHELLO_HPP

#include"../base/Joueur.hpp"

class Joueur_Othello : public Joueur{

private:
  int score;
  
public:
  Joueur_Othello(string , int);
   ~Joueur_Othello();
  int getScore();
  void setScore(int);
};


#endif
