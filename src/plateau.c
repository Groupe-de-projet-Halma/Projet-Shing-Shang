#include <plateau.h>
#include <joueur.h>

#define couleur(param) printf("\033[%sm", param)

Plateau construct_Plateau()
{
  clear_console();
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
        else {
          if(plateau.t_casesPlateau[x][y].p_pionCase->numeroJoueur == 1){
            couleur("36");
            if(plateau.t_casesPlateau[x][y].p_pionCase->typePion == 3)
              printf(" D ");
            else if(plateau.t_casesPlateau[x][y].p_pionCase->typePion == 2)
              printf(" L ");
            else if(plateau.t_casesPlateau[x][y].p_pionCase->typePion == 1)
              printf(" S ");
         }else if(plateau.t_casesPlateau[x][y].p_pionCase->numeroJoueur == 2){
            couleur("31");
            if(plateau.t_casesPlateau[x][y].p_pionCase->typePion == 3)
              printf(" D ");
            else if(plateau.t_casesPlateau[x][y].p_pionCase->typePion == 2)
              printf(" L ");
            else if(plateau.t_casesPlateau[x][y].p_pionCase->typePion == 1)
              printf(" S ");
          }
          couleur("0");
        }
      }else if (plateau.t_casesPlateau[x][y].typeDeCase == PORTE_J1){
        couleur("32");
        printf(" X ");
        couleur("0");
      }else if (plateau.t_casesPlateau[x][y].typeDeCase == PORTE_J2){
        couleur("33");
        printf(" X ");
        couleur("0");
      }
    }
    printf("\n");
  }
}



void Plateau_creerPion(Plateau * plateau, Joueur * joueur)
{
  int num_case_pion = 0;
  int abscisseMIN;
	int abscisseMAX;
	int ordonneeMIN;
	int ordonneeMax;
	int valeurPionInitial;
	int valeurPion;

  if (joueur->numero == 1)
  {
    abscisseMIN = 1;
  	abscisseMAX = 4;
  	ordonneeMIN = 0;
  	ordonneeMax = 3;
  	valeurPionInitial = DRAGON;

  	for(int y = ordonneeMIN; y < ordonneeMax; y++)
  	{
  		valeurPion = valeurPionInitial;
  		for(int x = abscisseMIN; x < abscisseMAX; x++)
  		{
        joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, valeurPion, x, y);
        plateau->t_casesPlateau[x][y].p_pionCase = &joueur->tab_p_pion[num_case_pion];
  			valeurPion--;
        num_case_pion++;
  		}
  		abscisseMAX--;
  		valeurPionInitial--;
  	}

    abscisseMIN = 6;
  	abscisseMAX = 9;
  	ordonneeMIN = 0;
    ordonneeMax = 3;
    valeurPionInitial = SINGE;

    for(int y = ordonneeMIN; y < ordonneeMax; y++)
    {
      valeurPion = SINGE;
      for(int x = abscisseMIN; x < abscisseMAX; x++)
      {
        joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, valeurPion, x, y);
        plateau->t_casesPlateau[x][y].p_pionCase = &joueur->tab_p_pion[num_case_pion];
        valeurPion++;
        num_case_pion++;
      }
      abscisseMIN++;
    }
  }

  else if (joueur->numero == 2)
  {
    abscisseMIN = 1;
    abscisseMAX = 2;
    ordonneeMIN = 7;
    ordonneeMax = 10;
    valeurPionInitial = SINGE;

    for(int y = ordonneeMIN; y < ordonneeMax; y++)
    {
      valeurPion = valeurPionInitial;
      for(int x = abscisseMIN; x < abscisseMAX; x++)
      {
        joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, valeurPion, x, y);
        plateau->t_casesPlateau[x][y].p_pionCase = &joueur->tab_p_pion[num_case_pion];
        valeurPion--;
        num_case_pion++;
      }
      valeurPionInitial++;
      abscisseMAX++;
    }

	  abscisseMIN = 8;
    abscisseMAX = 9;
    ordonneeMIN = 7;
    ordonneeMax = 10;
    valeurPionInitial = SINGE;

    for(int y = ordonneeMIN; y < ordonneeMax; y++)
    {
      valeurPion = SINGE;
      for(int x = abscisseMIN; x < abscisseMAX; x++)
      {
        joueur->tab_p_pion[num_case_pion] = construct_Pion(joueur->numero, valeurPion, x, y);
        plateau->t_casesPlateau[x][y].p_pionCase = &joueur->tab_p_pion[num_case_pion];
        valeurPion++;
        num_case_pion++;
      }
      valeurPionInitial++;
      abscisseMIN--;
    }
  }
}

int Plateau_testRegleDeplacementSimple(Plateau plateau,TypePion typePion, int coordXCible, int coordYCible)
{
  // Teste si la cases est hors plateau
  int valide = 1;
  if(coordXCible < 0 || coordYCible < 0) {valide = 0;}
  if(coordXCible >= TAILLE_PLATEAU || coordYCible >= TAILLE_PLATEAU) {valide = 0;}

  if (valide == 1)
  {
    // Test si la case est BLOQUE
    if(plateau.t_casesPlateau[coordXCible][coordYCible].typeDeCase == BLOQUE) {valide = 0;}
    // Test si il y a deja un pion sur la case
    if(plateau.t_casesPlateau[coordXCible][coordYCible].p_pionCase != NULL) {valide = 0;}
  }

  return valide;
}

int Plateau_testRegleDeplacementDouble(Plateau plateau,TypePion typePion, int coordXCaseObstacle, int coordYCaseObstacle, int coordXCible, int coordYCible)
{
  // Teste si les cases sont hors plateau
  int valide = 1;
  if(coordXCaseObstacle < 0  || coordYCaseObstacle < 0) {valide = 0;}
  if(coordXCible < 0 || coordYCible < 0) {valide = 0;}

  if(coordXCaseObstacle >= TAILLE_PLATEAU || coordYCaseObstacle >= TAILLE_PLATEAU) {valide = 0;}
  if(coordXCible >= TAILLE_PLATEAU || coordYCible >= TAILLE_PLATEAU) {valide = 0;}

  if(valide == 1)
  {
    // Test si les cases sont BLOQUE
    if(plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].typeDeCase == BLOQUE) {valide = 0;}
    if(plateau.t_casesPlateau[coordXCible][coordYCible].typeDeCase == BLOQUE) {valide = 0;}

    // Test si il y a deja un pion sur les cases
    if(plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase != NULL) {valide = 0;}
    if(plateau.t_casesPlateau[coordXCible][coordYCible].p_pionCase != NULL) {valide = 0;}
  }

  return valide;
}

int Plateau_testRegleSaut(Plateau plateau,TypePion typePion, int coordXCaseObstacle, int coordYCaseObstacle, int coordXCible, int coordYCible)
{
  // Teste si les cases sont hors plateau
  int valide = 1;
  if(coordXCaseObstacle < 0  || coordYCaseObstacle < 0) {valide = 0;}
  if(coordXCible < 0 || coordYCible < 0) {valide = 0;}

  if(coordXCaseObstacle >= TAILLE_PLATEAU || coordYCaseObstacle >= TAILLE_PLATEAU) {valide = 0;}
  if(coordXCible >= TAILLE_PLATEAU || coordYCible >= TAILLE_PLATEAU) {valide = 0;}

  if(valide == 1)
  {
    // Test si les cases sont BLOQUE
    if(plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].typeDeCase == BLOQUE) {valide = 0;}
    if(plateau.t_casesPlateau[coordXCible][coordYCible].typeDeCase == BLOQUE) {valide = 0;}

    // Test si il y a deja un pion sur les cases
    if(plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase == NULL) {valide = 0;}
    if(plateau.t_casesPlateau[coordXCible][coordYCible].p_pionCase != NULL) {valide = 0;}
  }

  // Test si le pion sauter est plus grand que le pion qui saute
  if (valide == 1)
  {
    if(plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase->typePion > typePion) {valide = 0;}
  }

  return valide;
}

void Plateau_rechercheDeplacement(Plateau plateau, Pion pionSelectionner,ListDeplacement * listDeplacement)
{
  int coordXCaseObstacle;
  int coordYCaseObstacle;

  int coordXCible;
  int coordYCible;

  // Recherche destination en sautant
  for (int y = -1; y <= 1; y++)
  {
    for (int x = -1; x <= 1; x++)
    {
      if (x != 0 || y!= 0)
      {
        // Calcul des coordonne de l'obstacle
        coordXCaseObstacle = pionSelectionner.x + x;
        coordYCaseObstacle = pionSelectionner.y + y;

        // Calcul des coordonne de la case cible
        if (x == 0)
          coordXCible = pionSelectionner.x;
        else if (x < 0)
          coordXCible = pionSelectionner.x + x - 1;
        else if (x > 0)
          coordXCible = pionSelectionner.x + x + 1;

        if (y == 0)
          coordYCible = pionSelectionner.y;
        else if (y < 0)
          coordYCible = pionSelectionner.y + y - 1;
        else if (y > 0)
          coordYCible = pionSelectionner.y + y + 1;

        // Test les regles de saut
        if(Plateau_testRegleSaut(plateau,pionSelectionner.typePion,
            coordXCaseObstacle,coordYCaseObstacle,
            coordXCible, coordYCible))
        {
          // On cree un deplacement vers la case cible
          Deplacement deplacement = construct_Deplacement(&plateau.t_casesPlateau[coordXCible][coordYCible],1,NULL,1);

          // Si on saute par dessus un pion adverse
          if (plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase->numeroJoueur != pionSelectionner.numeroJoueur )
          {
            deplacement.pionEliminer = plateau.t_casesPlateau[coordXCaseObstacle][coordYCaseObstacle].p_pionCase;
          }

          // On ajoute le deplacement à la liste des deplacement possible
          ListDeplacement_ajouterDeplacement(listDeplacement,deplacement);
        }

        // Test les regles deplacement double SINGE
        if(pionSelectionner.typePion == SINGE &&
          Plateau_testRegleDeplacementDouble(plateau,pionSelectionner.typePion,
            coordXCaseObstacle,coordYCaseObstacle,
            coordXCible, coordYCible))
        {
          // On cree un deplacement vers la case cible
          Deplacement deplacement = construct_Deplacement(&plateau.t_casesPlateau[coordXCible][coordYCible],0,NULL,0);

          // On ajoute le deplacement à la liste des deplacement possible
          ListDeplacement_ajouterDeplacement(listDeplacement,deplacement);
        }

        // Test les regles deplacement simple si different de DRAGON
        coordXCible = coordXCaseObstacle;
        coordYCible = coordYCaseObstacle;
        if((pionSelectionner.typePion != DRAGON && pionSelectionner.typePion != AUCUN) &&
          Plateau_testRegleDeplacementSimple(plateau,pionSelectionner.typePion,
            coordXCible, coordYCible))
        {
          // On cree un deplacement vers la case cible
          Deplacement deplacement = construct_Deplacement(&plateau.t_casesPlateau[coordXCible][coordYCible],0,NULL,0);

          // On ajoute le deplacement à la liste des deplacement possible
          ListDeplacement_ajouterDeplacement(listDeplacement,deplacement);
        }
      }
    }
  }
  // Affichage deplacement possible
  /*for (int i = 0; i < listDeplacement->tailleListe; i++) {
    Deplacement_affichage(ListDeplacement_getIndexDeplacement(*listDeplacement,i));
  }*/
}

void Plateau_deplacerPion(Plateau * plateau, Pion * pion, Deplacement deplacement, Joueur * joueurAdverse)
{
  int x_initial = pion->x;
  int y_initial = pion->y;
  int x_deplacement = deplacement.caseDestination->x;
  int y_deplacement = deplacement.caseDestination->y;

  plateau->t_casesPlateau[x_initial][y_initial].p_pionCase = NULL;
  pion->x = x_deplacement;
  pion->y = y_deplacement;
  plateau->t_casesPlateau[x_deplacement][y_deplacement].p_pionCase = pion;

  if(deplacement.pionEliminer != NULL)
  {
    int x_eliminer = deplacement.pionEliminer->x;
    int y_eliminer = deplacement.pionEliminer->y;
    if (deplacement.pionEliminer->typePion == DRAGON)
    {
      joueurAdverse->nbrDragon--;
    }
    plateau->t_casesPlateau[x_eliminer][y_eliminer].p_pionCase = NULL;
  }
}

/*test si le joueur a encore des dragons*/
int test_dragon(Joueur * joueur)
{
  int wyrm = 0;
    for (int i = 0; i < 13; i++)
    {
      if (joueur->tab_p_pion[i].typePion == DRAGON)
      {
        wyrm += 1;
      }
    }
  return wyrm;
}

/*Conditions de victoire*/
int victoire(Joueur * joueur, Plateau * plateau ){
  int vainqueur = 0;
  if(test_dragon( joueur) == 0){
    //le joueur adverse gagne
  }else{
    if(joueur->numero == 1){
      if(plateau->t_casesPlateau[4][TAILLE_PLATEAU-2].p_pionCase->typePion == DRAGON && plateau->t_casesPlateau[4][TAILLE_PLATEAU-2].p_pionCase->numeroJoueur == joueur -> numero){
        vainqueur = 1;
      }
      if(plateau->t_casesPlateau[5][TAILLE_PLATEAU-2].p_pionCase->typePion == DRAGON && plateau->t_casesPlateau[5][TAILLE_PLATEAU-2].p_pionCase->numeroJoueur == joueur -> numero){
        vainqueur = 1;
      }

    }else {
      if(plateau->t_casesPlateau[4][1].p_pionCase->typePion == DRAGON && plateau->t_casesPlateau[4][1].p_pionCase->numeroJoueur == joueur -> numero) {
        vainqueur = 2;
      }
      if(plateau->t_casesPlateau[5][1].p_pionCase->typePion == DRAGON && plateau->t_casesPlateau[5][1].p_pionCase->numeroJoueur == joueur -> numero){
        vainqueur = 2;
      }
    }
  }
  return vainqueur;
}
