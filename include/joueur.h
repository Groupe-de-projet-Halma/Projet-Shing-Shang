#ifndef JOUEUR_H
#define JOUEUR_H
#define NB_PION 12

#include <pion.h>

#include <utilitaire.h>


typedef struct
{
  int numero;  // Represente le numero de joueur
  char nom[100]; // Represente le nom du joueur
  Pion tab_p_pion[NB_PION]; // Represente les pions du joueur
  int nbrDragon; // Represente le nombre de dragon restant
}Joueur;


Joueur construct_Joueur(int numero);

#endif
