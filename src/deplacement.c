#include <deplacement.h>

Deplacement construct_Deplacement(CasePlateau * caseDestination,int estUnSaut)
{
  Deplacement deplacement;
  deplacement.caseDestination = caseDestination;
  deplacement.estUnSaut = estUnSaut;
  
  return deplacement;
}
