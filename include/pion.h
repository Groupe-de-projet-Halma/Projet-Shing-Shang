#ifndef PION_H
#define PION_H

#include <stdio.h>
#include <stdlib.h>

typedef enum TypePion TypePion;
enum TypePion
{
    AUCUN, SINGE, LION, DRAGON
};

typedef struct
{
  int numeroJoueur;
  TypePion typePion;  // Represente le type de pion (singe, lion, dragon, aucun)
  int x;
  int y;
}Pion;

Pion construct_Pion(int numeroJoueur,TypePion typePion, int x, int y);

#endif
