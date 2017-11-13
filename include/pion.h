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
  int numeroJoueur; // Numero du joueur possedant ce pion
  TypePion typePion;  // Represente le type de pion (singe, lion, dragon, aucun)
  int x;  // Coordonne x du pion
  int y;  // Coordonne y du pion
}Pion;

Pion construct_Pion(int numeroJoueur,TypePion typePion, int x, int y);

#endif
