#include"Othello.hpp"
#include"Plateau_Othello.hpp"
#include<iostream>
#include"Joueur_Othello.hpp"

using namespace std;

Othello::Othello(){
  
  score = 0;
  nbJoueurs = 2;
  numJoueurCourant = 1; 
  plateau = new Plateau_Othello();
  
}

Othello::~Othello(){}

void Othello::start(){

  int winner = -3;
  bool flag = false;
  Joueur *player =  new Joueur();
  player = nextJoueur();
  while(!flag){
    plateau->affiche();
    jouer(player->getNumero());
    winner = vainqueur();
    if(winner == 1){
      plateau->affiche();
      cout<< " Player 1 is winner " << endl;
      flag = true;
    }else if(winner == 2){
      plateau->affiche();
      cout<< " Player 2 is winner " << endl;
      flag = true;
    }else if(winner == 0){
      plateau->affiche();
      cout << " Egalité " <<endl;
      flag = true;
    }
    player = nextJoueur();

  }
 
 
}
void Othello::jouer(int j){

  int player = j;
  string entree;
  string::iterator t;
  int flag = 0;
  while(flag != 1 ){
    cout<< " Player "<< player << " : ";
    getline(cin,entree);
    int x = -1;
    int y = -1;
    t = entree.begin();
    x = (*t) - 48;
    y = *(t+2) - 48;
    
    if(verification(x,y,player))
      flag = 1;
    else if( (!verification(x,y,player)) && (nbr_case_vide() < 10 ))
      flag = 1;
    else{
	cout << " Ce n'est pas comme ça qu'on joue "<<endl;
      
    }
    
  }

}

bool Othello::verification(int x_,int y_,int j){
  
  int x = x_;
  int y = y_;
  int player = j;
  int ret = 0;
 
  if(x>=0 && x<8 && y>=0 && y<8 && plateau->getPlateau()[x][y] == 0){
      int n = 0;
      int c = 0;
      while(c < 8){
      	ret = MovePossible(x,y,c,player,true);
	if(ret != -1)
	  n+=ret;
	c++;
      }
      if(n<=0) return false;
      plateau->getPlateau()[x][y] = player;
      if(player == 1){
	//first->setScore(first->getScore()+n+1);
	//second->setScore(second->getScore()-n);
      }
      else{
	//first->setScore(first->getScore()+n+1);
	//second->setScore(second->getScore()-n);
      }
      return true;
  }else 
    return false;
    
}

int Othello::MovePossible(int i, int j, int dir, int player,bool act){
  switch(dir){
  case 0:
    if(i>0 && j>0)
      return confirme(i-1,j-1,dir,(player==1)?2:1,act);
    break;
  case 1:
    if(i>0)
      return confirme(i-1,j,dir,(player==1)?2:1,act);
    break;
  case 2:
    if(i>0 && j+1<8)
      return confirme(i-1,j+1,dir,(player==1)?2:1,act);
    break;
  case 3:
    if(j+1<8)
      return confirme(i,j+1,dir,(player==1)?2:1,act);
    break;
  case 4:
    if(i+1<8 && j+1<8)
      return confirme(i+1,j+1,dir,(player==1)?2:1,act);
    break;
  case 5:
    if(i+1<8)
      return confirme(i+1,j,dir,(player==1)?2:1,act);
    break;
  case 6:
    if(i+1<8 && j>0)
      return confirme(i+1,j-1,dir,(player==1)?2:1,act);
    break;
  case 7:
    if(j>0)
      return confirme(i,j-1,dir,(player==1)?2:1,act);
    break;
  default:
    return -1;
  }
  return -1;
}

int Othello::confirme(int i, int j, int dir, int player, bool act){
  int n = -1;
  switch(dir){
  case 0:
    if(plateau->getPlateau()[i][j] == ((player==1)?2:1)) return 0;
    if(i>0 && j>0 && plateau->getPlateau()[i][j]==player){
      n = confirme(i-1,j-1,dir,player,act);
      break;
    }
    return -1;
  case 1:
    if(plateau->getPlateau()[i][j] == ((player==1)?2:1)) return 0;
    if(i>0 && plateau->getPlateau()[i][j]==player){
      n = confirme(i-1,j,dir,player,act);
      break;
      }
    return -1;
  case 2:
    if(plateau->getPlateau()[i][j] == ((player==1)?2:1)) return 0;
    if(i>0 && j+1<8 && plateau->getPlateau()[i][j]==player){
      n = confirme(i-1,j+1,dir,player,act);
      break;
    }
    return -1;
  case 3:
    if(plateau->getPlateau()[i][j] == ((player==1)?2:1)) return 0;
    if(j+1<8 && plateau->getPlateau()[i][j]==player){
      n = confirme(i,j+1,dir,player,act);
      break;
    }
    return -1;
  case 4:
    if(plateau->getPlateau()[i][j] == ((player==1)?2:1)) return 0;
    if(i+1<8 && j+1<8 && plateau->getPlateau()[i][j]==player){
      n = confirme(i+1,j+1,dir,player,act);
      break;
    }
    return -1;
  case 5:
    if (plateau->getPlateau()[i][j] == ((player==1)?2:1)) return 0;
    if(i+1<8 && plateau->getPlateau()[i][j]==player){
      n = confirme(i+1,j,dir,player,act);
      break;
    }
    return -1;
  case 6:
    if(plateau->getPlateau()[i][j] == ((player==1)?2:1)) return 0;
    if(i+1<8 && j>0 && plateau->getPlateau()[i][j]==player){
      n = confirme(i+1,j-1,dir,player,act);
      break;
    }
    return -1;
  case 7:
    if(plateau->getPlateau()[i][j] == ((player==1)?2:1)) return 0;
    if(j>0 && plateau->getPlateau()[i][j]==player){
      n = confirme(i,j-1,dir,player,act);
      break;
    }
    return -1;
  default:
    return -1;
  }
  if(n != -1){
    if(act)
      plateau->getPlateau()[i][j] = (player==1)?2:1;
  return n+1;
  }
  return -1;
}


bool Othello::est_remplie(){

  for(int i=0; i<plateau->getNbLignes(); i++){
    for(int j=0 ;j<plateau->getNbCols(); j++){
      if(plateau->getPlateau()[i][j] == 0 )
	return false;
    }
  }
  return true;
}

int Othello::vainqueur(){

  int score_player_1 = 0;
  int score_player_2 = 0;
  if(!est_remplie())
    return -1;
  for(int i=0; i<plateau->getNbLignes(); i++){
    for(int j=0 ;j<plateau->getNbCols(); j++){
      if(plateau->getPlateau()[i][j] == 1)
	score_player_1++;
      else
	score_player_2++;
    }
  }
  if(score_player_1 > score_player_2 )
    return 1;
  else if(score_player_2 > score_player_1)
    return 2;
  else if(score_player_2 == score_player_1)
    return 0;
  else
    return -1;
}

int Othello::nbr_case_vide(){

  int nbr = 0;
   for(int i=0; i<plateau->getNbLignes(); i++){
     for(int j=0 ;j<plateau->getNbCols(); j++){
      if(plateau->getPlateau()[i][j] == 0 )
	nbr+=1;
     }
   }

   return nbr;
   
}
/*
void Othello::ajouteJoueur(Joueur *j){
  joueurs.push_back(j);
}
*/
