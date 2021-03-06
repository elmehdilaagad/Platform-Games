#include <iostream>
#include "FiveOrMore.hpp"
#include "Plateau_five.hpp"
#include <stdlib.h>
#include <map>

int score = 0;
FiveOrMore::FiveOrMore(){
    this->nbColor = 5;
    plateau = new Plateau_five(5);
}

int FiveOrMore::getCouleurs(){
  return nbColor;
}

int FiveOrMore::fin(){
  for(int i = 0; i < plateau->getNbLignes() ; i++){
    for(int j = 0; j <plateau->getNbCols(); j++){
      if(plateau->getPlateau()[i][j] == -1)
	return -1; // pas fini
     
    }

  }
  return 0;
}

//choisi 3 point et 3 couleurs aléatoirement et enregistre les points
void FiveOrMore::choix_coordonnees(){
  int x,y,c;
  
  int flag = 1;
  srand (time(NULL));
  cout << "COUP ORDI" << endl;
  while(flag == 1){
    for(int i = 0; i < 3; i++){
      x = rand()%plateau->getNbCols(); // colonnes
      y = rand()%plateau->getNbLignes(); // lignes
      c = rand()%this->getCouleurs(); // couleurs
      // cout <<"x : " << x <<" y : " << y <<" c : " << c << endl;
      if(plateau->getPlateau()[x][y] != -1)
	flag = 1;
      else{
	plateau->getPlateau()[x][y] = c;
	flag = 0;
      }
    }
  }
}
/* demande a l'utilisateur de choisir le point à déplacer 
   et son nouvelle emplacement */
void FiveOrMore::choix_utilisateurs(){
  int flag = 1;
  int flag2 = 1;
  int x,y,new_x,new_y;
  while(flag == 1){
    cout << "Choisissez la ligne du point à déplacer : " << endl;
    cin >> x;
    cout << "Choisissez la colonne du point à déplacer : " << endl;
    cin >> y;
    if(plateau->getPlateau()[x][y] == -1){
      cout << "Les coordonées choisi ne sont pas bon" << endl;
      flag = 1;
    }else
      flag = 0;
  }
  if(flag == 0){
    while(flag2 == 1){
      cout << "Choisissez la ligne de l'empacement du nouveau point : " << endl;
      cin >> new_x;
      cout << "Choisissez la colonne de l'emplacement du nouveau point: " << endl;
      cin >> new_y;
      if(plateau->getPlateau()[new_x][new_y] != -1){
	cout << "Il y a une grille a cet emplacement " << endl;
	cout << "RECOMMENCEZ" << endl;
	flag2 = 1;
	  
      }else{
	plateau->getPlateau()[new_x][new_y] = plateau->getPlateau()[x][y];
	plateau->getPlateau()[x][y] = -1;
	flag2 = 0;
      }
      
    }
  }
}
bool FiveOrMore::horizontal(int j){
 
  map<int, int> coord;
  map<int,int>::iterator im;
  int compt = 1;
  for(int i = 0; i < plateau->getNbCols(); i++){
    if(plateau->getPlateau()[i][j] == -1)
      return false;
    if(plateau->getPlateau()[i][j] == plateau->getPlateau()[i][j+1]){
      compt++;
      coord[i]= j;
      // cout << "compt " << compt << endl;
    }
    if(compt == 5 || compt > 5){
      coord[i+1] = j;
      for(im = coord.begin(); im != coord.end(); im++){
  	plateau->getPlateau()[(*im).first][(*im).second] = -1;
      }
      score = compt*2;
      cout << "Vous avez  un score de : " << score << endl;
      return true;      
    }
  }
  return false;
}

bool FiveOrMore::vertical(int j){

  map<int, int> coord;
  map<int,int>::iterator im;
  int compt = 1;
  for(int i = 0; i < plateau->getNbLignes(); i++){
    if(plateau->getPlateau()[i][j] == -1)
      return false;
    if(plateau->getPlateau()[i][j] == plateau->getPlateau()[i+1][j]){
      compt++;
      coord[i]= j;
      // cout << "compt " << compt << endl;
    }
    if(compt == 5 || compt > 5){
      coord[i+1] = j;
      for(im = coord.begin(); im != coord.end(); im++){
  	plateau->getPlateau()[(*im).first][(*im).second] = -1;
      }
      score = compt*2;
      cout << "Vous avez  un score de : " << score << endl;
      return true;      
    }
  }
  return false;
}
void FiveOrMore::start(){
  
  while(fin() !=  0){
    choix_coordonnees();
    plateau->affiche();
    choix_utilisateurs();
    cout << "Joueur " << endl;
    plateau->affiche();
    for(int i = 0 ; i < plateau->getNbCols(); i++){
      vertical(i);
    }
 
  }

}

