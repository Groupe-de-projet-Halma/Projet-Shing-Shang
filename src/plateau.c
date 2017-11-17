#include <plateau.h>

Plateau construct_Plateau()
{
  Plateau plateau;
  // Creation des cases
  for (int y = 0; y < TAILLE_PLATEAU; y++)
  {
    for (int x = 0; x < TAILLE_PLATEAU; x++)
    {
      plateau.t_casesPlateau[x][y] = construct_CasePlateau(x,y);
    }
  }

  // Bloquages des cases interdites
  for (int i = 0; i < 4; i++)
  {
    plateau.t_casesPlateau[0][i].typeDeCase = BLOQUE;
    plateau.t_casesPlateau[TAILLE_PLATEAU-1][i].typeDeCase = BLOQUE;
    plateau.t_casesPlateau[0][i+6].typeDeCase = BLOQUE;
    plateau.t_casesPlateau[TAILLE_PLATEAU-1][i+6].typeDeCase = BLOQUE;
  }

  // Transformation des cases en porte
  plateau.t_casesPlateau[4][1].typeDeCase = PORTE_J1;
  plateau.t_casesPlateau[5][1].typeDeCase = PORTE_J1;
  plateau.t_casesPlateau[4][TAILLE_PLATEAU-2].typeDeCase = PORTE_J2;
  plateau.t_casesPlateau[5][TAILLE_PLATEAU-2].typeDeCase = PORTE_J2;

  return plateau;
}

int Plateau_testRegleSaut(Plateau plateau,TypePion typePion, int coordXCaseObstacle, int coordYCaseObstacle, int coordXCible, int coordYCible)
{
  // Teste si les cases sont hors plateau
  int valide = 1;
  if(coordXCaseObstacle < 0  && coordYCaseObstacle < 0)
    valide = 0;
  if (coordXCible < 0 && coordYCible < 0)
    valide = 0;

  if(coordXCaseObstacle >= TAILLE_PLATEAU && coordYCaseObstacle >= TAILLE_PLATEAU)
    valide = 0;
  if(coordXCible >= TAILLE_PLATEAU && coordYCible >= TAILLE_PLATEAU)
    valide = 0;

  if(valide == 1)
  {
    // Test si les cases sont BLOQUE
    if(plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].typeDeCase == BLOQUE)
      valide = 0;
    if(plateau.t_casesPlateau[coordXCible][coordYCible].typeDeCase == BLOQUE)
      valide = 0;

    // Test si il y a deja un pion sur les cases
    if(plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase == NULL)
      valide = 0;
    if(plateau.t_casesPlateau[coordXCible][coordYCible].p_pionCase != NULL)
      valide = 0;
  }

  if(valide == 1)
  {
    // Test si le pion sauter est plus grand que le pion qui saute
    if(plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase->typePion > typePion)
      valide = 0;
  }

  return valide;
}

void Plateau_rechercheDeplacement(Plateau plateau, Joueur * joueur, Pion pionSelectionner)
{
  int coordXCaseObstacle;
  int coordYCaseObstacle;

  int coordXCible;
  int coordYCible;

  int nbDeplacement = 0;

  Deplacement * l_deplacement = malloc(sizeof(Deplacement) * nbDeplacement);

  // Recherche destination en sautant
  for (int y = -1; y <= 1; y++)
  {
    for (int x = -1; x <= 1; x++)
    {
      if (x != 0 && y!= 0)
      {
        // Calcul des coordonne de l'obstacle
        coordXCaseObstacle = pionSelectionner.x + x;
        coordYCaseObstacle = pionSelectionner.y + y;

        // Calcul des coordonne de la case cible
        if (x < 0)
          coordXCible = pionSelectionner.x + x - 1;
        else if (x > 0)
          coordXCible = pionSelectionner.x + x + 1;

        if (y < 0)
          coordYCible = pionSelectionner.y + y - 1;
        else if (y > 0)
          coordYCible = pionSelectionner.y + y + 1;

        // Test les regles de saut
        if(Plateau_testRegleSaut(plateau,pionSelectionner.typePion,
                                  coordXCaseObstacle,coordYCaseObstacle,
                                  coordXCible, coordYCible))
        {
          // On cree une un deplacement vers la case cible
          Deplacement deplacement = construct_Deplacement(&plateau.t_casesPlateau[coordXCible][coordYCible],1);

          // Si on saute par dessus un pion adverse
          if (plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase->numeroJoueur != joueur->numero)
          {
            deplacement.pionEliminer = plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase;
          }

          // On ajoute le deplacement à la liste des deplacement possible
          nbDeplacement++;
          l_deplacement = realloc(l_deplacement,sizeof(Deplacement) * nbDeplacement);
          l_deplacement[nbDeplacement-1] = deplacement;
        }
      }
    }
  }
}

void Plateau_afficher(Plateau plateau)
{
  //Test affichage d'un pion
  //Pion monPion = construct_Pion(1,DRAGON, 1, 0);
  //plateau.t_casesPlateau[1][0].p_pionCase = &monPion;

  printf("Y\\X");
  for (int i = 0; i < TAILLE_PLATEAU; i++)
    printf(" %d ",i);

  printf("\n");

  for (int j = 0; j < TAILLE_PLATEAU+1; j++)
    printf(" - ");

  printf("\n");
  for (int y = 0; y < TAILLE_PLATEAU; y++)
  {
    printf(" %d|",y);
    // Affichage case normal
    for (int x = 0; x < TAILLE_PLATEAU; x++)
    {
      if (plateau.t_casesPlateau[x][y].typeDeCase == BLOQUE)
        printf("   ");

      else if (plateau.t_casesPlateau[x][y].typeDeCase == NORMAL)
      {
        if (plateau.t_casesPlateau[x][y].p_pionCase == NULL)
          printf(" 0 ");
        else
          printf(" %d ", plateau.t_casesPlateau[x][y].p_pionCase->typePion);
      }
      else if (plateau.t_casesPlateau[x][y].typeDeCase == PORTE_J1)
        printf(" X ");
      else if (plateau.t_casesPlateau[x][y].typeDeCase == PORTE_J2)
        printf(" X ");

    }
    printf("\n");
  }
}
