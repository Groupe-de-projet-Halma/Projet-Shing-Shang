#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU_X 8
#define TAILLE_PLATEAU_Y 10
#define NB_CASE_SUPP 4

#include <stdio.h>
#include <stdlib.h>

#include <case_plateau.h>
#include <pion.h>

typedef struct
{
  CasePlateau t_casesPlateau[TAILLE_PLATEAU_X][TAILLE_PLATEAU_Y]; // Case du plateau
  CasePlateau t_casesPlateauSupp[NB_CASE_SUPP];
}Plateau;

Plateau construct_Plateau();  // Constructeur du plateau
void Plateau_placerPionJoueur(Plateau * plateau,Pion * tab_p_pion[]); // Place les pions d'un joueur sur le plateau
void Plateau_afficher(Plateau plateau); // Affiche le plateau de jeu
#endif
