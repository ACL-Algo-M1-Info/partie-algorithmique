//
// Created by remik on 06/12/2025.
//

#ifndef ALGORITHMIE_UTILS_H
#define ALGORITHMIE_UTILS_H

// INCLUSIONS

#include "../types/instance/instance.h"
#include "types/ordonnancementMachine/ordonnancementMachine.h"

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
 * Supprime un entier
 *
 * @param i l'entier que l'on veut supprimer
 */
void deleteInt(void* i);

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
 * Affiche une liste de double
 * @param n la taille de l'array
 * @param array le tableau de doubles à afficher
 */
void afficheArrayDouble(int n, const double array[n]);

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

/**
 * Applique le tri fusion sur les qi d'une instance donnée
 *
 * @param i le début du tableau
 * @param j la taille du tableau - 1
 * @param instance l'instance où on veut appliquer le tri
 * @param tq tableau pour stocker provisoirement les qi
 * @param tp tableau pour stocker provisoirement les pi
 */
void triFusionDecroissant(int i, int j, Instance* instance, double *tq, double *tp);

/**
 * Applique le tri fusion sur les qi d'une instance donnée
 *
 * @param i le début du tableau
 * @param j la taille du tableau - 1
 * @param instance l'instance où on veut appliquer le tri
 * @param tq tableau pour stocker provisoirement les qi
 * @param tp tableau pour stocker provisoirement les pi
 */
void triFusionCroissant(int i, int j, Instance* instance, double *tq, double *tp);

/**
 * Applique l'ordre de Jackson sur les qi d'une instance
 *
 * @param i l'instance où l'on veut appliquer l'ordre
 */
void triJacksonQ(Instance* i);

/**
 * Rassemble les taches des differents ordonnancements dans une même instance
 * triée par date de début au plus tôt croissante
 * @param instance Instance de départ
 * @param instanceOut Instance pour le problème de robot (sortie)
 * @param ordonnancement Ordonnancement donné par le problème de placement sur m
 * machines (Lmax)
 */
void triDateDebutCroissante(Instance* instance, Instance* instanceOut, OrdonnancementMachine** ordonnancement);

#endif  // ALGORITHMIE_UTILS_H
