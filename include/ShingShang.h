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
  int joueurActuel;
  Pion * p_pionSelectionner;
}ShingShang;

ShingShang construct_ShingShang();
int run();
void ShingShang_nouvellePartie(ShingShang * shingShang);
ShingShang ShingShang_chargerPartie();
void ShingShang_sauvegarderPartie(ShingShang partie);

#endif
