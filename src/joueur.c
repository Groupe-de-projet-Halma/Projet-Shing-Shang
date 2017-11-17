#include <joueur.h>

Joueur construct_Joueur(int numero, char * nom)
{
  Joueur joueur;
  joueur.numero = numero;
  joueur.nom = nom;

  return joueur;
}

void Joueur_creerPion(Joueur * joueur)
{
  int num_case_pion = 0;
  int tmp;
  int cpt=4;
  
  for (int y = 0; y < 3; y++)
  {
    for (int x = 1; x < cpt; x++)
    {
      tmp = 4;
      tmp = tmp - x - y;
      joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, tmp, x, y);

      printf("%d",joueur->tab_p_pion[num_case_pion].typePion );
      printf("x=%d y=%d",joueur->tab_p_pion[num_case_pion].x,joueur->tab_p_pion[num_case_pion].y);
      printf("\n");

      num_case_pion++;
    }
    cpt--;
    printf("\n");
  }
}
