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
inline int imax(int a, int b)
{
    return a > b ? a : b;
}

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
void afficherInt(int* i);

Instance* genererInstanceAleatoire();

Instance** genererInstancesAleatoires(int nbInstances);

#endif  // ALGORITHMIE_UTILS_H
