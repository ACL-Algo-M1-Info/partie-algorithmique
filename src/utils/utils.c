//
// Created by remik on 06/12/2025.
//

// INCLUSIONS

#include <stdio.h>

#include "utils.h"

#include <time.h>

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



