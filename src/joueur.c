#include <joueur.h>

Joueur construct_Joueur(int numero, char * nom)
{
  Joueur joueur;
  joueur.numero = numero;
  joueur.nom = nom;

  return joueur;
}
