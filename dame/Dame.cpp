#include <iostream>
#include "Dame.hpp"

using namespace std;

Dame::Dame(Plateau *p, Joueur *jo1, Joueur *jo2){
	this->j1  = jo1 ;
        this->j2  = jo2 ;
        this->pla  = p ;
}


Dame::~Dame(){}


void Dame::start(){
   
   //bool winner; 
   pla->affiche();
   


}
