#include <deplacement.h>

Deplacement construct_Deplacement(CasePlateau * caseDestination,int estUnSaut,Pion * pionEliminer,int tourSupplementaire)
{
  Deplacement deplacement;
  deplacement.caseDestination = caseDestination;
  deplacement.estUnSaut = estUnSaut;
  deplacement.pionEliminer = pionEliminer;
  deplacement.tourSupplementaire = tourSupplementaire;

  return deplacement;
}

void Deplacement_affichage(Deplacement deplacement)
{
  printf("##### DEPLACEMENT #####\n");
  printf("Case destination: [%d;%d]\n",deplacement.caseDestination->x,deplacement.caseDestination->y);
  printf("Est un saut: %d\n",deplacement.estUnSaut);
  if (deplacement.pionEliminer != NULL)
  {
    printf("Pion à eliminer:\n");
    Pion_affichage(*deplacement.pionEliminer);
  }
  else
    printf("Pion à eliminer: AUCUN\n");

  printf("Tour supplémentaire: %d\n", deplacement.tourSupplementaire);
  printf("#######################\n\n");
}
