#include <vector>
#include <iostream>
#include "Plateau_five.hpp"


using namespace std;

Plateau_five::Plateau_five(int couleur) {
  cout << "Entrez le nombre de ligne de la grille : "<<endl;
  cin >> nbLignes;
  if(nbLignes < 5){
    cout << "Il n'y a pas assez de colonnes" << endl;
    nbLignes = 5;
    cout << "Vous aurez "<< nbLignes<< "lignes "<<endl;    
  }  
  cout << "Entrez le nombre de colonnes :"  << endl;
  cin >> nbCols;
  if(nbCols < 5){
    cout << "Il n'y a pas assez de colonnes" << endl;
    nbCols = 5;
    cout << "Vous aurez "<< nbCols << "colonnes " <<endl;    
  }
  
  cout << "Entrez le nombre de couleur :"  << endl;
  cin >> this->couleur;
  if(couleur > nbCols){
    cout << "Trop de couleur " << endl;
    this->couleur = nbCols-1;
    cout << "Vous aurez " << couleur << endl;
  }
  // nbLignes = 9 ;
  // nbCols = 9;
  // this->couleur = couleur;
  grille = new int*[nbLignes];
  for(int i = 0; i < nbLignes; i++) { 
 	grille[i] = new int[nbCols];
  }
   
  for(int i = 0; i < nbCols ; i++){
    for(int j = 0; j < nbLignes; j++){
      grille[i][j] = -1;
    }
  }
}

Plateau_five::~Plateau_five(){
 for(int i = 0; i < nbCols; i++) {
	delete [] grille[i];
    }
    delete [] grille;
}


void Plateau_five::affiche(){
  int lignes= 0;
  int cases;
  cout<<endl;
  cout << " |";
  for(int i = 0; i < nbCols; i++){
    cout << i <<" ";
  }
  cout << endl;
  cout << "  ";
  for(int i = 0; i < nbCols; i++){
    cout <<"_ "<<"" ;
  }
  cout << endl;
  for(int i = 0; i < nbLignes; i++){
    cout << lignes++ <<"|";
    for(int j = 0 ; j < nbCols; j++){
      if(j!=0)
	cout << "|";
      cases = grille[i][j];
      if(cases == -1)
	cout <<' ';
      else
	cout << cases;
    }
    cout << endl;
  }
  cout<<endl;
  cout<<endl;

}
