#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <stdio.h>
#include <stdlib.h>

#include <pion.h>
#include <case_plateau.h>

typedef struct
{
  CasePlateau * caseDestination;
  int estUnSaut;
  Pion * pionEliminer;
  int tourSupplementaire;
}Deplacement;

typedef struct
{
  Deplacement * p_Deplacement;
  int tailleListe;
}ListDeplacement;

Deplacement construct_Deplacement(CasePlateau * caseDestination,int estUnSaut,Pion * pionEliminer,int tourSupplementaire);
void Deplacement_affichage(Deplacement deplacement);

ListDeplacement construct_ListDeplacement();
void ListDeplacement_ajouterDeplacement(ListDeplacement * listDeplacement, Deplacement deplacement);
Deplacement ListDeplacement_getIndexDeplacement(ListDeplacement listDeplacement, int i);

#endif
