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

ListDeplacement construct_ListDeplacement()
{
  ListDeplacement listDeplacement;
  listDeplacement.p_Deplacement = calloc(sizeof(Deplacement),0);
  listDeplacement.tailleListe = 0;
  return listDeplacement;
}

void ListDeplacement_ajouterDeplacement(ListDeplacement * listDeplacement, Deplacement deplacement)
{
  listDeplacement->tailleListe ++;
  listDeplacement->p_Deplacement = realloc(listDeplacement->p_Deplacement,sizeof(Deplacement) * listDeplacement->tailleListe);
  listDeplacement->p_Deplacement[listDeplacement->tailleListe - 1] = deplacement;
}

Deplacement ListDeplacement_getIndexDeplacement(ListDeplacement listDeplacement, int i)
{
  return listDeplacement.p_Deplacement[i];
}
