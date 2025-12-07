//
// Created by remik on 07/12/2025.
//

#include <assert.h>
#include <stdio.h>

#include "../src/algos/algo.h"
#include "../src/types/instance/instance.h"
#include "utils/utils.h"

#define EPSILON .2

// Test d'un.
int main(int argc, char *argv[])
{
    Instance* i = genererInstanceAleatoire();
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
