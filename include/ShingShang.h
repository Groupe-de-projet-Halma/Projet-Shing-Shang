#ifndef SHINGSHANG_H
#define SHINGSHANG_H

#include <stdio.h>
#include <stdlib.h>

#include <utilitaire.h>
#include <plateau.h>
#include <joueur.h>

typedef struct 
{
  Plateau plateau;
  Joueur joueur1;
  Joueur joueur2;
}ShingShang;

int run();
ShingShang ShingShang_nouvellePartie();
ShingShang ShingShang_chargerPartie();
void ShingShang_sauvegarderPartie(ShingShang partie);

#endif
