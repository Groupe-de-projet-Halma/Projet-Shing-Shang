#include <joueur.h>

Joueur construct_Joueur(int numero)
{
  Joueur joueur;
  joueur.numero = numero;

  return joueur;
}

void Joueur_creerPion(Joueur * joueur)
{
  int num_case_pion = 0;
  int abscisseMIN;
	int abscisseMAX;
	int ordonneeMIN;
	int ordonneeMax;
	int valeurPionMAX;
	int valeurPion;

  if (joueur->numero == 1)
  {
    printf("Joueur %d:\n",joueur->numero);
    abscisseMIN = 1;
  	abscisseMAX = 4;
  	ordonneeMIN = 0;
  	ordonneeMax = 3;
  	valeurPionMAX = 3;
  	valeurPion;

  	for(int y = ordonneeMIN; y < ordonneeMax; y++)
  	{
  		valeurPion = valeurPionMAX;
  		for(int x = abscisseMIN; x < abscisseMAX; x++)
  		{
        joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, valeurPion, x, y);
  			//printf("%d[%d;%d] ",valeurPion,x,y);
        printf("%d[%d;%d] ",joueur->tab_p_pion[num_case_pion].typePion,joueur->tab_p_pion[num_case_pion].x,joueur->tab_p_pion[num_case_pion].y);
  			valeurPion--;
        num_case_pion++;
  		}
  		printf("\n");
  		abscisseMAX--;
  		valeurPionMAX--;
  	}

    abscisseMIN = 6;
  	abscisseMAX = 9;
  	ordonneeMIN = 0;
    ordonneeMax = 3;
    valeurPionMAX = 1;

    for(int y = ordonneeMIN; y < ordonneeMax; y++)
    {
      valeurPion = 1;
      for(int x = abscisseMIN; x < abscisseMAX; x++)
      {
        joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, valeurPion, x, y);
        //printf("%d[%d;%d] ",valeurPion,x,y);
        printf("%d[%d;%d] ",joueur->tab_p_pion[num_case_pion].typePion,joueur->tab_p_pion[num_case_pion].x,joueur->tab_p_pion[num_case_pion].y);
        valeurPion++;
        num_case_pion++;
      }
      printf("\n");
      abscisseMIN++;
    }
    printf("\n");
  }

  else if (joueur->numero == 2)
  {
    printf("Joueur %d:\n",joueur->numero);
    abscisseMIN = 1;
    abscisseMAX = 2;
    ordonneeMIN = 7;
    ordonneeMax = 10;
    valeurPionMAX = 1;

    for(int y = ordonneeMIN; y < ordonneeMax; y++)
    {
      valeurPion = valeurPionMAX;
      for(int x = abscisseMIN; x < abscisseMAX; x++)
      {
        joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, valeurPion, x, y);
        //printf("%d[%d;%d] ",valeurPion,x,y);
        printf("%d[%d;%d] ",joueur->tab_p_pion[num_case_pion].typePion,joueur->tab_p_pion[num_case_pion].x,joueur->tab_p_pion[num_case_pion].y);
        valeurPion--;
        num_case_pion++;
      }
      printf("\n");
      valeurPionMAX++;
      abscisseMAX++;
    }

	  abscisseMIN = 8;
    abscisseMAX = 9;
    ordonneeMIN = 7;
    ordonneeMax = 10;
    valeurPionMAX = 1;

    for(int y = ordonneeMIN; y < ordonneeMax; y++)
    {
      valeurPion = 1;
      for(int x = abscisseMIN; x < abscisseMAX; x++)
      {
        joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, valeurPion, x, y);
        //printf("%d[%d;%d] ",valeurPion,x,y);
        printf("%d[%d;%d] ",joueur->tab_p_pion[num_case_pion].typePion,joueur->tab_p_pion[num_case_pion].x,joueur->tab_p_pion[num_case_pion].y);
        valeurPion++;
        num_case_pion++;
      }
      printf("\n");
      valeurPionMAX++;
      abscisseMIN--;
    }
    printf("\n");
  }
}
