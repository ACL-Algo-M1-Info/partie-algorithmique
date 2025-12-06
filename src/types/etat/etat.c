//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <stdlib.h>

#include "etat.h"
#include "../../utils/utils.h"

// FONCTIONS

Etat* newEtat(int m)
{
    Etat* e = malloc(sizeof(struct _Etat));

    e->m = m;
    e->lmax = 0;
    e->ordonnancements = malloc(m*sizeof(OrdonnancementMachine*));

    for (int i = 0; i < m; i++)
    {
        e->ordonnancements[i] = newOrdonnancementMachine();
    }

    return e;
}

Etat* cloneEtat(Etat* source)
{
    Etat* e = malloc(sizeof(struct _Etat));

    e->m = source->m;
    e->lmax = source->lmax;
    e->ordonnancements = malloc(source->m*sizeof(OrdonnancementMachine*));

    for (int i = 0; i < source->m; i++)
    {
        // Clone de l'ordonnancement i
        e->ordonnancements[i] = cloneOrdonnancementMachine(source->ordonnancements[i]);
    }

    return e;
}

void ajouterTacheSurMachine(Etat* etat, int k, int i, int pi, int qi)
{
    // On ajoute d'abord la tâche sur la machine pour avoir le nouveau cmax
    ajouterTache(etat->ordonnancements[k], i, pi);
    // Recalcul du lmax selon l'ajout fait précedemment
    etat->lmax = imax(etat->ordonnancements[k]->cmax + qi, etat->lmax);
}

void ajouterTacheSurMachineParInstance(Etat* etat, int k, int i, Instance instance)
{
    ajouterTacheSurMachine(etat, k, i, instance.p[i], instance.q[i]);
}