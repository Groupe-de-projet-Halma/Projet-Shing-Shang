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
  //4 5  1 TAILLE_PLATEAU-2

  // Transformation des cases en porte
  plateau.t_casesPlateau[4][1].typeDeCase = PORTE_J1;
  plateau.t_casesPlateau[5][1].typeDeCase = PORTE_J1;
  plateau.t_casesPlateau[4][TAILLE_PLATEAU-2].typeDeCase = PORTE_J2;
  plateau.t_casesPlateau[5][TAILLE_PLATEAU-2].typeDeCase = PORTE_J2;

  return plateau;
}

void Plateau_rechercheDeplacement(Plateau plateau, Joueur * joueur, Pion pionSelectionner)
{


}

void Plateau_afficher(Plateau plateau)
{
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
