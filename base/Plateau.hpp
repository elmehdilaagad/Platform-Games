#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>

using namespace std;

class Plateau{
protected:
    int **grille;
    int nbLignes;
    int nbCols;
public:
    virtual ~Plateau();
    virtual int getNbLignes();
    virtual int getNbCols();
    virtual void setNbLignes(int _nbLignes);
    virtual void setNbCols(int _nbCols);
    virtual void affiche()=0;
    virtual int** getPlateau();
};

#endif
