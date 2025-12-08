//
// Created by remik on 07/12/2025.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../src/algos/algo.h"
#include "../src/types/instance/instance.h"
#include "utils/utils.h"

// DEFINES

#define MAX_N_ALEA_GEN 20
#define MAX_M_ALEA_GEN 15
#define EPSILON 1.35

// Test d'un.
int main(int argc, char *argv[])
{
    srand(time(NULL));

    int n = 5;
    int m = 3;

    int p[] = {5, 3, 1, 5, 9};
    int q[] = {5, 4, 3, 2, 1};

    Instance* i = newInstance(n, m, p, q);
    // Instance* i = genererInstanceAleatoire(MAX_N_ALEA_GEN, MAX_M_ALEA_GEN);
    Instance* original = cloneInstance(i);

    // On applique l'algo
    modifierInstanceFPTAS(i, EPSILON);

    // On vérifie la rastérisation
    printf("Instance originale:\n");
    afficheInstance(original);
    printf("\nInstance modifiee:\n");
    afficheInstance(i);

    // N égal, M égal
    assert(i->n == original->n && i->m == original->m);

    for (int k = 0; k < i->n; k++)
        // Les p(i) et q(i) de l'instance modifiée i sont <= aux originaux
        assert(i->q[k] <= original->q[k] && i->p[k] <= original->p[k]);

    return 0;
}
