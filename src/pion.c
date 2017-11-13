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
