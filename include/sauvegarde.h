#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#define TAILLE_PLATEAU 10

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;  // Represente le numero de joueur
    char nom[100]; // Represente le nom du joueur
    Pion tab_p_pion[NB_PION]; // Represente les pions du joueur




    int resultat_deplacement; // Indique le type de déplacement effectué
    int **tableau_destination; // Tableau qui stock toute les destinations possible
    int taille_tableau_destination; // Taille du tableau des destinations
}DonneesPartie;

int char_to_int(char chiffre);  // Convertisseur char en int
char int_to_char(int chiffre);	// Convertisseur int en char

int sauvegarde(DonneesPartie * donnes_a_sauvegarder); // Sauvegarde la partie
int charger(DonneesPartie * donnees_a_charger); // Chargement de la derniere sauvegarde

#endif
