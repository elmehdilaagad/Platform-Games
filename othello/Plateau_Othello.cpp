#include <vector>
#include <iostream>
#include "Plateau_Othello.hpp"


using namespace std;


Plateau_Othello::Plateau_Othello()  {

  nbLignes = 8;
  nbCols = 8 ;
  
  this->grille = new int*[nbLignes];
  
  for(int i = 0; i < nbLignes; i++) { 
    grille[i] = new int[nbCols];
  }
  
  for(int i = 0; i < this->nbLignes; i++) {
    for(int j = 0; j < this->nbCols; j++) {
      grille[i][j] = 0;
    }
  }
  
  grille[3][4] = grille[4][3] = 1;
  grille[3][3] = grille[4][4] = 2;
}

Plateau_Othello::~Plateau_Othello(){}

void Plateau_Othello::affiche(){
  
  cout<<"      0    1    2    3    4     5    6   7\n";
  
  for(int row = 0; row < nbLignes; row++ ){
    
    cout<< "     ________________________________________\n";
    cout<<row <<"   |";;
    for(int col = 0; col < nbCols; col++){
      
      if(grille[row][col]== 0 ){
	cout<<"    |";
      }
      else if(grille[row][col] == 1){ //1
	cout <<" ●  |";
      }
      else if(grille[row][col] == 2){
	cout <<" ○  |";
      }
    }
    cout << endl;
  }
  cout<< "     ________________________________________\n";
  
  
}
