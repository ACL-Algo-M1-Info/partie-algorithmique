//
// Created by remik on 06/12/2025.
//

#ifndef ALGORITHMIE_UTILS_H
#define ALGORITHMIE_UTILS_H

// INCLUSIONS

#include "../types/instance/instance.h"

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

int comparaisonEntierDecroissant(int a, int b);


void triFusionDecroissant(int i, int j, int* tab, int* tmp);


void triJacksonQ(Instance* i);

#endif  // ALGORITHMIE_UTILS_H
