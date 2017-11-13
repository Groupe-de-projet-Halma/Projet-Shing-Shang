#include <plateau.h>

Plateau construct_Plateau()
{
  Plateau plateau;
  for (int y = 0; y < TAILLE_PLATEAU_Y; y++)
  {
    for (int x = 0; x < TAILLE_PLATEAU_X; x++)
    {
      plateau.t_casesPlateau[x][y] = construct_CasePlateau(x,y);
    }
  }
  plateau.t_casesPlateauSupp[0] = construct_CasePlateau(-1,4);
  plateau.t_casesPlateauSupp[1] = construct_CasePlateau(-1,5);
  plateau.t_casesPlateauSupp[2] = construct_CasePlateau(TAILLE_PLATEAU_X,4);
  plateau.t_casesPlateauSupp[3] = construct_CasePlateau(TAILLE_PLATEAU_X,5);

  return plateau;
}

void Plateau_afficher(Plateau plateau)
{
  for (int y = 0; y < TAILLE_PLATEAU_Y; y++)
  {
    // Decalage ligne normal
    if (y != 4 && y != 5)
      printf("  ");

    // Affichage case Supp
    else if (y == 4)
    {
      if (plateau.t_casesPlateauSupp[0].p_pionCase == NULL)
        printf("0 ");
      else
        printf("%d ",plateau.t_casesPlateauSupp[0].p_pionCase->typePion);
    }
    else if (y == 5)
    {
      if (plateau.t_casesPlateauSupp[1].p_pionCase == NULL)
        printf("0 ");
      else
        printf("%d ",plateau.t_casesPlateauSupp[1].p_pionCase->typePion);
    }

    // Affichage case normal
    for (int x = 0; x < TAILLE_PLATEAU_X; x++)
    {
      if (plateau.t_casesPlateau[x][y].p_pionCase == NULL)
        printf("0 ");
      else
        printf("%d ", plateau.t_casesPlateau[x][y].p_pionCase->typePion);
    }

    // Affichage case Supp
    if (y == 4)
    {
      if (plateau.t_casesPlateauSupp[2].p_pionCase == NULL)
        printf("0 ");
      else
        printf("%d ",plateau.t_casesPlateauSupp[2].p_pionCase->typePion);
    }
    else if (y == 5)
    {
      if (plateau.t_casesPlateauSupp[3].p_pionCase == NULL)
        printf("0 ");
      else
        printf("%d ",plateau.t_casesPlateauSupp[3].p_pionCase->typePion);
    }
    printf("\n");
  }
}
