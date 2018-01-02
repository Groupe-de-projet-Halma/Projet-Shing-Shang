#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU 10

#include <stdio.h>
#include <stdlib.h>

#include <case_plateau.h>
#include <pion.h>
#include <joueur.h>
#include <deplacement.h>
#include <utilitaire.h>

typedef struct
{
  CasePlateau t_casesPlateau[TAILLE_PLATEAU][TAILLE_PLATEAU]; // Case du plateau
}Plateau;

Plateau construct_Plateau();  // Constructeur du plateau
void Plateau_afficher(Plateau plateau); // Affiche le plateau de jeu

void Plateau_creerPion(Plateau * plateau, Joueur * joueur);

int Plateau_testRegleDeplacementSimple(Plateau plateau,TypePion typePion, int coordXCible, int coordYCible);
int Plateau_testRegleDeplacementDouble(Plateau plateau,TypePion typePion, int coordXCaseObstacle, int coordYCaseObstacle, int coordXCible, int coordYCible);
int Plateau_testRegleSaut(Plateau plateau,TypePion typePion, int coordXCaseObstacle, int coordYCaseObstacle, int coordXCible, int coordYCible);

void Plateau_rechercheDeplacement(Plateau plateau, Pion pionSelectionner);
#endif
