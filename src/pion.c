#include <pion.h>

Pion construct_Pion(int numeroJoueur,TypePion typePion, int x, int y)
{
  Pion pion;
  pion.numeroJoueur = numeroJoueur;
  pion.typePion = typePion;
  pion.x = x;
  pion.y = y;
  return pion;
}

void Pion_affichage(Pion pion)
{
  printf("##### PION #####\n");
  printf("Appartient au joueur: %d\n",pion.numeroJoueur );
  printf("Type: %d\n",pion.typePion );
  printf("Coordonnee: [%d;%d]\n",pion.x,pion.y );
  printf("################\n");
}
