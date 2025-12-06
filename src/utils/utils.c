//
// Created by remik on 06/12/2025.
//

// INCLUSIONS

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

// FONCTIONS

int imax(int a, int b)
{
    return a > b ? a : b;
}

int* cloneInt(const int* source)
{
    int* res = (int*)malloc(sizeof(int));
    *res = *source;

    return res;
}

void afficheInt(const int* i)
{
    printf("%d", *i);
}

void afficheArray(int n, const void* array[n], void (*afficheur)(const void*))
{
    printf("[");

    for (int i = 0; i < n; i++)
    {
        (*afficheur)(array[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

void afficheArrayInt(int n, const int array[n])
{
    printf("[");

    for (int i = 0; i < n; i ++)
    {
        printf("%d", array[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

Instance* genererInstanceAleatoire()
{
    // Génération aléatoire.
    int randN = rand() % MAX_N_ALEA_GEN;
    int randM = rand() % MAX_M_ALEA_GEN;

    // Tableaux aléatoires des p(i) et q(i)
    int randP[randN];
    int randQ[randN];

    // Assignation des valeurs aléatoires p(i) et q(i)
    for (int i = 0; i < randN; i++)
    {
        // Pour p(i)
        randP[i] = rand() % MAX_P_ALEA_GEN;

        // Pour q(i)
        randQ[i] = rand() % MAX_Q_ALEA_GEN;
    }

    return newInstance(randN, randM, randP, randQ);
}

Instance** genererInstancesAleatoires(int nbInstances)
{
    // Génération du tableau stockant des pointeurs vers des instances.
    Instance** res = malloc(nbInstances * sizeof(Instance*));

    // Génération de chaque instance aléatoire.
    for (int i = 0; i < nbInstances; i++)
        res[i] = genererInstanceAleatoire();

    return res;
}
