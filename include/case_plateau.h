#ifndef CASE_PLATEAU_H
#define CASE_PLATEAU_H

#include <stdio.h>
#include <stdlib.h>

#include <pion.h>

typedef struct
{
  int x;  // Coordonnee en abcisse de la case sur le plateau
  int y;  // Coordonnee en ordonnee de la case sur le plateau
  Pion * p_pionCase;  // Pointeur vers le pion sur la case (NULL si aucun)
  int estUneBase; // Indique si la case est une base ou non
}CasePlateau;

CasePlateau construct_CasePlateau(int x, int y); // Constructeur de CasePlateau

#endif
