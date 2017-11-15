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

Deplacement construct_Deplacement(CasePlateau * caseDestination,int estUnSaut);

#endif
