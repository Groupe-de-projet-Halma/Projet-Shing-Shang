#include <joueur.h>

Joueur construct_Joueur(int numero)
{
  Joueur joueur;
  joueur.numero = numero;
  joueur.nbrDragon = 2;
  return joueur;
}
