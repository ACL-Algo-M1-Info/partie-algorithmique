//
// Created by remik on 06/12/2025.
//

// INCLUSIONS

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

// FONCTIONS

int* cloneInt(const int* source)
{
    int* res = (int*)malloc(sizeof(int));
    *res = *source;

    return res;
}

void afficherInt(int* i)
{
    printf("%d", *i);
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
