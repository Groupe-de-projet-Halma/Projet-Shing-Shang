#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU 10

#include <stdio.h>
#include <stdlib.h>

#include <case_plateau.h>
#include <pion.h>
#include <joueur.h>

typedef struct
{
  CasePlateau t_casesPlateau[TAILLE_PLATEAU][TAILLE_PLATEAU]; // Case du plateau
}Plateau;

Plateau construct_Plateau();  // Constructeur du plateau
void Plateau_placerPionJoueur(Plateau * plateau,Pion * tab_p_pion[]); // Place les pions d'un joueur sur le plateau
void Plateau_afficher(Plateau plateau); // Affiche le plateau de jeu

void Plateau_rechercheDeplacement(Plateau plateau, Joueur * joueur, Pion pionSelectionner);
#endif
