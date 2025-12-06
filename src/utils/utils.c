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

int comparaisonEntierDecroissant(int a, int b)
{
    if (a > b) return -1;

    return 1;
}

void triFusionDecroissant(int i, int j, int* tab, int* tmp)
{
    if(j <= i) return;

    // Milieu du tableau
    int m = (i + j) / 2;

    // Tri de la moitié gauche
    triFusionDecroissant(i, m, tab, tmp);
    // Tri de la moitié droite
    triFusionDecroissant(m + 1, j, tab, tmp);

    // Pointeur du sous tableau gauche
    int pg = i;
    // Pointeur du sous tableau droite
    int pd = m + 1;

    // Compteur
    int c;

    // Remplissage de i à j pour le tableau fusionné
    for(c = i; c <= j; c++)
    {
        if(pg == m + 1)
        {
            tmp[c] = tab[pd];
            pd++;
        }
        else if (pd == j + 1)
        {
            tmp[c] = tab[pg];
            pg++;
        }
        else if (tab[pg] > tab[pd])
        { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            //tmp[c] = tab[pg];
            pg++;
        }
        else
        {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }

    // Copie des éléments dans tab
    for(c = i; c <= j; c++)
    {
        tab[c] = tmp[c];
    }
}

void triJacksonQ(Instance* i)
{
    int tmp[i->n];
    triFusionDecroissant(0, i->n-1, i->q,tmp);
}



