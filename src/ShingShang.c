#include <ShingShang.h>

ShingShang construct_ShingShang()
{
  ShingShang shingShang;
  shingShang.plateau = construct_Plateau();
  shingShang.joueur1 = construct_Joueur(1);
  shingShang.joueur2 = construct_Joueur(2);
  shingShang.joueurActuel = 1;
  shingShang.p_pionSelectionner = NULL;

  return shingShang;
}

void ShingShang_nouvellePartie(ShingShang * shingShang)
{
  printf("Entrez le nom du joueur 1: ");
  scanf("%s",shingShang->joueur1.nom);
  vider_buffer();
  Plateau_creerPion(&shingShang->plateau, &shingShang->joueur1);

  printf("Entrez le nom du joueur 2: ");
  scanf("%s",shingShang->joueur2.nom);
  vider_buffer();
  Plateau_creerPion(&shingShang->plateau, &shingShang->joueur2);

  printf("%s VS %s\n",shingShang->joueur1.nom,shingShang->joueur2.nom );
}

Pion * ShingShang_selectionnerPion(ShingShang shingShang)
{
  int x;
  int y;
  int selection_valide = 0;
  Pion * pionSelectionner = NULL;

  while (selection_valide == 0)
  {
    // Test si on est dans le plateau
    do
    {
      printf("Entrez la coordonnee X: ");
      scanf("%d", &x);
    } while(x < 0 || x >= 10);
    do
    {
      printf("Entrez la coordonnee Y: ");
      scanf("%d", &y);
    } while(y < 0 || y >= 10);

    // Test si il y a un pion
    if (shingShang.plateau.t_casesPlateau[x][y].p_pionCase != NULL)
    {
      // Test si le pion est dans le bon camp
      if (shingShang.plateau.t_casesPlateau[x][y].p_pionCase->numeroJoueur == shingShang.joueurActuel)
      {
        pionSelectionner = shingShang.plateau.t_casesPlateau[x][y].p_pionCase;
        selection_valide = 1;
      }
      else
        printf("Erreur selection d'un pion adverse en [%d;%d]\n\n",x,y);
    }
    else
      printf("Erreur aucun pion en [%d;%d]\n\n",x,y);
  }
  return pionSelectionner;
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

  Pion * pion;
  pion = ShingShang_selectionnerPion(shingShang);
  printf("Pion selectionne:\n");
  Pion_affichage(*pion);

  ListDeplacement listDeplacement = Plateau_rechercheDeplacement(shingShang.plateau,*pion);

  return 0;
}
