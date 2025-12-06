//
// Created by remik on 06/12/2025.
//

#ifndef ALGORITHMIE_UTILS_H
#define ALGORITHMIE_UTILS_H

// INCLUSIONS

#include "../types/instance/instance.h"

// DEFINES

/** Borne pour le N maximal. */
#define MAX_N_ALEA_GEN 50

/** Borne pour le m maximal. */
#define MAX_M_ALEA_GEN 45

/** Borne pour le p(i) maximal. */
#define MAX_P_ALEA_GEN 10

/** Borne pour le q(i) maximal. */
#define MAX_Q_ALEA_GEN 10

// FONCTIONS

/**
 * Calcul du maximum entre deux int.
 * @param a Valeur A.
 * @param b Valeur B.
 * @return Le maximum entre A et B.
 */
int imax(int a, int b);

/**
 * Clone un int par adresse. Nécessaire pour le clone de tableau dynamique.
 * @param source Entier à cloner.
 * @return Entier cloné.
 */
int* cloneInt(const int* source);

/**
 * Affiche un int par adresse.
 * @param i Entier à afficher.
 */
void afficheInt(const int* i);

/**
 * Affiche une liste.
 * @param n Taille de l'array
 * @param array Liste à afficher.
 * @param afficheur Méthode d'affichage de chaque élément.
 */
void afficheArray(int n, const void* array[n], void (*afficheur)(const void*));

/**
 * Affiche une liste d'entiers.
 * @param n Taille de l'array
 * @param array Array d'entiers à afficher
 */
void afficheArrayInt(int n, const int array[n]);

/**
 * Génère une instance aléatoirement.
 * @return Instance générée aléatoirement.
 */
Instance* genererInstanceAleatoire();

/**
 * Génère un tableau d"instances aléatoires.
 * @param nbInstances Nombre d'instances aléatoires à tester.
 * @return Le tableau d'instances aléatoires.
 */
Instance** genererInstancesAleatoires(int nbInstances);

int comparaisonEntierDecroissant(int a, int b);


void triFusionDecroissant(int i, int j, int* tab, int* tmp);


void triJacksonQ(Instance* i);

#endif  // ALGORITHMIE_UTILS_H
