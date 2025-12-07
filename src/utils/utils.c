//
// Created by remik on 06/12/2025.
//

// INCLUSIONS

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

// FONCTIONS

int imax(int a, int b)
{
    return a > b ? a : b;
}

int dblcmp(double a, double b)
{
    return fabs(a - b) < DOUBLE_EGALITE_EPSILON;
}

void deleteInt(void* i)
{
    assert(i);
    free(i);
}

void* cloneInt(const void* source)
{
    assert(source);
    const int* src = source;

    int* res = (int*)malloc(sizeof(int));
    *res = *src;

    return res;
}

void afficheInt(const void* i)
{
    assert(i);
    const int* k = i;

    printf("%d", *k);
}

int intsEgaux(const void* a, const void* b)
{
    assert(a && b);

    const int *i = a;
    const int *j = b;

    return *i == *j;
}

void afficheArray(int n, const void* array[n], void (*afficheur)(const void*))
{
    assert(n >= 0 && array && afficheur);
    printf("[");

    for (int i = 0; i < n; i++)
    {
        (*afficheur)(array[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

int arraysEgales(int n, const void* a[n], const void* b[n], int (*comp)(const void*, const void*))
{
    assert(n >= 0 && a && b && comp);

    for (int i = 0; i < n; i++)
        if ((*comp)(a[i], b[i]) == 0)
            return 0;

    return 1;
}

void afficheArrayInt(int n, const int array[n])
{
    assert(n >= 0 && array);
    printf("[");

    for (int i = 0; i < n; i ++)
    {
        printf("%d", array[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

int arraysIntEgales(int n, const int a[n], const int b[n])
{
    assert(n >= 0 && a && b);

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;

    return 1;
}

int maxArrayInt(int n, const int a[n])
{
    assert(n > 0 && a);

    int res = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > res)
            res = a[i];

    return res;
}

void afficheArrayDouble(int n, const double array[n])
{
    assert(n >= 0 && array);
    printf("[");

    for (int i = 0; i < n; i ++)
    {
        printf("%.2lf", array[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

int arraysDoubleEgales(int n, const double a[n], const double b[n])
{
    assert(n >= 0 && a && b);

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;

    return 1;
}

double maxArrayDouble(int n, const double a[n])
{
    assert(n > 0 && a);

    double res = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > res)
            res = a[i];

    return res;
}

Instance* genererInstanceAleatoire()
{
    // Génération aléatoire.
    int randN = rand() % MAX_N_ALEA_GEN;
    int randM = rand() % MAX_M_ALEA_GEN;

    // Tableaux aléatoires des p(i) et q(i)
    double randP[randN];
    double randQ[randN];

    // Assignation des valeurs aléatoires p(i) et q(i)
    for (int i = 0; i < randN; i++)
    {
        // Pour p(i)
        randP[i] = 1 + rand() % (MAX_P_ALEA_GEN - 1);

        // Pour q(i)
        randQ[i] = 1 + rand() % (MAX_Q_ALEA_GEN - 1);
    }

    return newInstance(randN, randM, randP, randQ);
}

Instance** genererInstancesAleatoires(int nbInstances)
{
    assert(nbInstances >= 0);

    // Génération du tableau stockant des pointeurs vers des instances.
    Instance** res = malloc(nbInstances * sizeof(Instance*));

    // Génération de chaque instance aléatoire.
    for (int i = 0; i < nbInstances; i++)
        res[i] = genererInstanceAleatoire();

    return res;
}

void triFusionDecroissant(int i, int j, Instance* instance, double *tq, double *tp)
{
    if(j <= i) return;

    // Milieu du tableau
    int m = (i + j) / 2;

    // Tri de la moitié gauche
    triFusionDecroissant(i, m, instance, tq, tp);
    // Tri de la moitié droite
    triFusionDecroissant(m + 1, j, instance, tq, tp);

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
            tq[c] = instance->q[pd];
            tp[c] = instance->p[pd];
            pd++;
        }
        else if (pd == j + 1)
        {
            tq[c] = instance->q[pg];
            tp[c] = instance->p[pg];
            pg++;
        }
        else if (instance->q[pg] > instance->q[pd])
        {
            tq[c] = instance->q[pg];
            tp[c] = instance->p[pg];
            pg++;
        }
        else
        {
            tq[c] = instance->q[pd];
            tp[c] = instance->p[pd];
            pd++;
        }
    }

    // Copie des éléments dans tab
    for(c = i; c <= j; c++)
    {
        instance->q[c] = tq[c];
        instance->p[c] = tp[c];
    }
}

void triJacksonQ(Instance* i)
{
    assert(i);

    double tq[i->n];
    double tp[i->n];
    triFusionDecroissant(0, i->n-1, i, tq, tp);
}

double rasteriserInferieur(double k, double facteur)
{
    // La formule est floor(k / facteur) * facteur pour la rastérisation
    return floor(k / facteur) * facteur;
}
