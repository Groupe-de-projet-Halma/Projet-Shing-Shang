#include <ShingShang.h>

int run()
{
  // Juste un petit test pas de panique
  Plateau plateau = construct_Plateau();
  Plateau_afficher(plateau);
  Joueur joueur1 = construct_Joueur(1,"Toto");
  Joueur_creerPion(&joueur1);

  return 0;
}
