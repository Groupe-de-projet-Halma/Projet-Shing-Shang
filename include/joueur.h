#ifndef JOUEUR_H
#define JOUEUR_H
#define NB_PION 12

#include <pion.h>

typedef struct
{
  int numero;  // Represente le numero de joueur
  char * nom;
  Pion * tab_p_pion[NB_PION];
}Joueur;

Joueur construct_Joueur(int numero, char * nom);
void Joueur_creerPion(Joueur * joueur);

#endif
