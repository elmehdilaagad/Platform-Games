#include <vector>
#include <iostream>
#include "Plateau_puissance.hpp"
#include "Joueur_puissance.hpp"


using namespace std;


Plateau_puissance::Plateau_puissance() {
      nbLignes = 6;
      nbCols = 7;
       
       
   grille = new int*[nbLignes];
      for(int i = 0; i < nbLignes; i++) { 
      grille[i] = new int[nbCols];
    } 

      for(int i = 0; i < nbLignes; i++) {
	for(int j = 0; j < nbCols; j++) {
	    grille[i][j] = 0;
	}
    }    
}


Plateau_puissance::~Plateau_puissance(){
 for(int i = 0; i < nbCols; i++) {
	delete [] grille[i];
    }
    delete [] grille;
}


void Plateau_puissance::affiche(){

   cout<<"    1      2    3    4    5    6    7\n";
   
   for(int row = 0; row < nbLignes; row++ ){
     
     cout<< "     ___________________________________\n";
     cout<<row+1 <<"   |";;
      for(int col = 0; col < nbCols; col++){
         
	if(grille[row][col]== 0 ){
	  cout<<"    |";
	}
	else if(grille[row][col] == 1){
	  cout <<" ○  |";
	}
	else if(grille[row][col] == 2){
	  cout <<" ●  |";
	}
      }
      cout << endl;
    }
     cout<< "     ___________________________________\n";

   
}
