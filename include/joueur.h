#ifndef JOUEUR_H
#define JOUEUR_H
#define NB_PION 12

#include <pion.h>

typedef struct
{
  int numero;  // Represente le numero de joueur
  char nom[100]; // Represente le nom du joueur
  Pion tab_p_pion[NB_PION]; // Represente les pions du joueur
}Joueur;

Joueur construct_Joueur(int numero);
void Joueur_creerPion(Joueur * joueur);

#endif
