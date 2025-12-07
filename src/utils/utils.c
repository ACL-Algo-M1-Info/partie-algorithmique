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

void deleteInt(void* i)
{
    free(i);
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

void afficheArrayDouble(int n, const double array[n])
{
    printf("[");

    for (int i = 0; i < n; i ++)
    {
        printf("%.2lf", array[i]);

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
    double randP[randN];
    double randQ[randN];

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

void triFusionCroissant(int i, int j, Instance* instance, double *tq, double *tp)
{
    if(j <= i) return;

    // Milieu du tableau
    int m = (i + j) / 2;

    // Tri de la moitié gauche
    triFusionCroissant(i, m, instance, tq, tp);
    // Tri de la moitié droite
    triFusionCroissant(m + 1, j, instance, tq, tp);

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
        else if (instance->q[pg] < instance->q[pd])
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
    double tq[i->n];
    double tp[i->n];
    triFusionDecroissant(0, i->n-1, i, tq, tp);
}

void triDateDebutCroissante(Instance* instance, Instance* instanceOut, OrdonnancementMachine** ordonnancement)
{
    int indice = 0;
    for (int i = 0; i < instance->m; i++)
    {
        OrdonnancementMachine* ordo = ordonnancement[i];
        int size = ordo->tabId->tailleEffectif;
        double cmax = 0;
        for (int j = 0; j < size; j++)
        {
            int* index = getElementTableauDynamique(ordo->tabId, j);
            cmax += instance->p[*index - 1];

            instanceOut->p[indice] = instance->q[*index - 1];
            instanceOut->q[indice] = cmax;
            indice++;
        }
    }

    //instanceOut est désormais initialisé avec pi qui représente le temps de livraison pour un robot et qi qui représente la date de début au plus tôt de la tâche i
    afficheInstance(instanceOut);

    double tq[instanceOut->n];
    double tp[instanceOut->n];
    triFusionCroissant(0, instanceOut->n-1, instanceOut, tq, tp);
}



