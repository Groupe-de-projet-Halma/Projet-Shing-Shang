#include <menu.h>

//fonction procésseur pour changer la couleur du texte en console
//source: https://openclassrooms.com/courses/des-couleurs-dans-la-console-linux
#define couleur(param) printf("\033[%sm", param)



void afficher_menu(){
  clear_console();
  couleur("31");//titre (couleur : rouge)
  printf("   _____ _    _ _____ _   _  _____    _____ _    _          _   _  _____ \n");
  printf("  / ____| |  | |_   _| \\ | |/ ____|  / ____| |  | |   /\\   | \\ | |/ ____|\n");
  printf(" | (___ | |__| | | | |  \\| | |  __  | (___ | |__| |  /  \\  |  \\| | |  __ \n");
  printf("  \\___ \\|  __  | | | | . ` | | |_ |  \\___ \\|  __  | / /\\ \\ | . ` | | |_ |\n");
  printf("  ____) | |  | |_| |_| |\\  | |__| |  ____) | |  | |/ ____ \\| |\\  | |__| |\n");
  printf(" |_____/|_|  |_|_____|_| \\_|\\_____| |_____/|_|  |_/_/    \\_\\_| \\_|\\_____|\n");


  printf("\n\n");

  couleur("37");//couleur : argent
  printf(" 1 - Nouvelle partie\n");
  printf(" 2 - Charger une partie\n");
  printf(" 3 - Règles\n");
  printf(" 4 - Crédits\n");
  printf(" 5 - Quitter\n");
  printf("\n");
}

void menu(){

  afficher_menu();
  int choix ;
  do {  // Choix sécurisé
    printf("Que choisissez vous ? ");
    scanf("%d", &choix);
	  if((choix < 1) || (choix > 5))
	    printf("Erreur, veuillez rééssayer.\n");
  } while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5);

  if(choix == 1){
    nouvellePartie();
  }
  if(choix == 2){
    //chargerPartie();
  }
  if(choix == 3){
    regles1();
  }
  if(choix == 4){
    credits();
  }
  if(choix == 5){
    clear_console();
  }
}


void nouvellePartie()
{
  run();
}




void regles1() // Affiche les règles du jeu
{
  int choix;
  clear_console();
  couleur("31");
  printf("\n====== Règles ======\n\n");
  couleur("37");
  printf("Le Shing Shang est un jeu de stratégie qui se joue sur un damier de 84 cellules avec 2 ∗ 12 pièces (Bushis).\n\n");
  printf("Préparation :\n");
  printf("Chaque joueur possède une armée de 12 Bushis en une couleur (bleu ou rouge).\nCette armée est composée de 3 groupes de Bushis : 2 Dragons, 4 Lions et 6 Singes. \n\n");

  printf("Taper 1 pour revenir au menu.\nTaper 3 pour aller à la page suivante.\n\nVotre choix : "); //permet de revenir au menu
  do {
    scanf("%d",&choix);
  if((choix != 1) && (choix != 3))
	  printf("Erreur, veuillez rééssayer : ");

  } while((choix != 1) && (choix != 3));
  if(choix == 1){
    menu();
  }
  if(choix == 3){
    regles2();
  }
}

void regles2() // Affiche les règles du jeu
{
  int choix;
  clear_console();
  couleur("31");//texte rouge
  printf("\n====== Déroulement du jeu ======\n\n");
  couleur("37");//texte blanc/gris
  printf("Les joueurs jouent à tour de rôle. \n");
  printf("Lors de son tour de jeu, un joueur doit déplacer l’un de ses Bushis de deux façons :\n");
  printf("  - Glisser vers une case suivante vide horizontalement, verticalement ou en diagonal, aussi bien en avant qu’en arrière.\n");
  printf("  - Sauter par dessus d’un Bushi si celui-ci est de la même grandeur ou plus petit que le sauteur.\n");
  printf("Pour pouvoir sauter, le Bushi doit se trouver sur une case contiguë à une case occupée par un Bushi rouge ou noire,\n");
  printf("il peut sauter la pièce, verticalement, horizontalement ou en diagonale, à condition que la case suivante soit vide.\n");
  printf("On peut enchaîner plusieurs sauts au cours d’un même tour. Cet enchaînement de sauts s’appel un Shing Shang.\n\n");


  printf("Taper 1 pour revenir au menu.\nTaper 2 pour revenir à la page précédente\nTaper 3 pour aller à la page suivante.\n\nVotre choix : "); //permet de revenir au menu
  do {
    scanf("%d",&choix);
  if((choix < 1) || (choix > 3))
    printf("Erreur, veuillez rééssayer : ");

  } while((choix != 1) && (choix != 2) && (choix != 3));
  if(choix == 1){
    menu();
  }
  if(choix == 2){
    regles1();
  }
  if(choix == 3){
    regles3();
  }
}

void regles3() // Affiche les règles du jeu
{
  int choix;
  clear_console();
  couleur("31");//texte rouge
  printf("\n====== Déplacement des Bushis ======\n\n");
  couleur("37");//texte blanc/gris
  printf("- Les SINGES peuvent :\n");
  printf("se déplacer d’une ou deux cases dans n’importe quelle direction, horizontalement, verticalement ou en diagonal mais sans changer de direction au cours du tour.\n\n");
  printf("- Les LIONS peuvent :\n");
  printf("se déplacer d’une case dans n’importe quelle direction, horizontalement, verticalement ou en diagonal.\n\n");
  printf("- Les DRAGONS ne peuvent se déplacer qu’en sautant.\n\n");

  printf("Bon jeu\n\n");


  printf("Taper 1 pour revenir au menu.\nTaper 2 pour revenir à la page précédente\n\nVotre choix : "); //permet de revenir au menu
  do {
    scanf("%d",&choix);
  if((choix != 1) && (choix != 2))
    printf("Erreur, veuillez rééssayer : ");

  } while((choix != 1) && (choix != 2));
  if(choix == 1){
    menu();
  }
  if(choix == 2){
    regles2();
  }
}


void credits(){
  int choix;
  clear_console();
  couleur("31");
  printf("\n====== Crédits ======\n\n");
  couleur("37");
  printf("Jeu réalisé par Alexis HESLOUIN et Tancelin MAZZOTTI\n");
  printf("Etudiants en DUT Informatique de l'université de Caen Normandie\n\n");
  printf("Taper 1 pour revenir au menu : ");
  do {
    scanf("%d",&choix);
    if(choix != 1)
	  printf("Erreur, veuillez rééssayer : ");

  } while(choix != 1);
  if(choix == 1){
    menu();
  }
}
