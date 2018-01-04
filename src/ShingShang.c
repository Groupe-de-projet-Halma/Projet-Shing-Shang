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

  printf("\n%s VS %s\n\n",shingShang->joueur1.nom,shingShang->joueur2.nom );
}

Pion * ShingShang_selectionnerPion(ShingShang shingShang)
{
  int x;
  int y;
  int selection_valide = 0;
  Pion * pionSelectionner = NULL;
  printf("*** Choix du pion ***\n");

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

void message_victoire(ShingShang * shingShang, int vainqueur){
  clear_console();
  int choix;
  printf("Résultat de la partie : \n");
  if(vainqueur == 0)
    printf("    Aucun gagnant\n\n");
  if(vainqueur == 1)
    printf("    Victoire de %s\n\n", shingShang->joueur1.nom);
  if(vainqueur == 2)
    printf("    Victoire de %s\n\n", shingShang->joueur2.nom);

  do { //test pour retourner au menu
    scanf("%d",&choix);
  if(choix != 1)
    printf("Erreur, veuillez rééssayer : ");
  } while(choix != 1);
  if(choix == 1){
    menu();
  }
}

Deplacement * ShingShang_selectionnerDeplacement(ListDeplacement listDeplacement)
{
  int x;
  int y;
  Deplacement * deplacementSelectionner = NULL;
  printf("*** Choix de la destination ***\n");

  printf("Entrez la coordonnee X: ");
  scanf("%d", &x);

  printf("Entrez la coordonnee Y: ");
  scanf("%d", &y);

  for (int  i = 0; i < listDeplacement.tailleListe; i++)
  {
    if (listDeplacement.p_Deplacement[i].caseDestination->x == x && listDeplacement.p_Deplacement[i].caseDestination->y == y)
    {
      deplacementSelectionner = &listDeplacement.p_Deplacement[i];
    }
  }
  return deplacementSelectionner;
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

  Pion * pion = NULL;
  Deplacement * deplacement = NULL;
  ListDeplacement listDeplacement = construct_ListDeplacement();

  pion = ShingShang_selectionnerPion(shingShang);

  Plateau_rechercheDeplacement(shingShang.plateau,*pion,&listDeplacement);
  /*printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
  for (int i = 0; i < listDeplacement.tailleListe; i++) {
    Deplacement_affichage(ListDeplacement_getIndexDeplacement(listDeplacement,i));
  }*/
  Plateau_afficher(shingShang.plateau);
  deplacement = ShingShang_selectionnerDeplacement(listDeplacement);
  if (deplacement != NULL)
  {
    //Deplacement_affichage(*deplacement);
    if (shingShang.joueurActuel == 1)
      Plateau_deplacerPion(&shingShang.plateau,pion,*deplacement,&shingShang.joueur2);
    else
      Plateau_deplacerPion(&shingShang.plateau,pion,*deplacement,&shingShang.joueur2);

    Plateau_afficher(shingShang.plateau);
  }

  return 0;
}
