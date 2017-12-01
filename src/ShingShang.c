#include <ShingShang.h>

ShingShang construct_ShingShang()
{
  ShingShang shingShang;
  shingShang.plateau = construct_Plateau();
  shingShang.joueur1 = construct_Joueur(1);
  shingShang.joueur2 = construct_Joueur(2);
  shingShang.joueurActuel = &shingShang.joueur1;
  shingShang.p_pionSelectionner = NULL;

  return shingShang;
}

void ShingShang_nouvellePartie(ShingShang * shingShang)
{
  printf("Entrez le nom du joueur 1: ");
  scanf("%s",shingShang->joueur1.nom);
  vider_buffer();
  Joueur_creerPion(&shingShang->joueur1);

  printf("Entrez le nom du joueur 2: ");
  scanf("%s",shingShang->joueur2.nom);
  vider_buffer();
  Joueur_creerPion(&shingShang->joueur2);

  //Plateau_placerPionJoueur(&plateau,joueur1);
  //Plateau_placerPionJoueur(&plateau,joueur2);
  
  printf("%s VS %s\n",shingShang->joueur1.nom,shingShang->joueur2.nom );
}

int run()
{
  /* Provisoire */

  // Declaration et initialisation
  ShingShang shingShang = construct_ShingShang();

  /* Appel du menu */

  // Si nouvelle partie
  ShingShang_nouvellePartie(&shingShang);

  Plateau_afficher(shingShang.plateau);

  return 0;
}
