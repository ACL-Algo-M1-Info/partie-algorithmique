//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "etat.h"
#include "../../utils/utils.h"

// FONCTIONS

Etat* newEtat(int m)
{
    Etat* e = malloc(sizeof(struct _Etat));
    assert(e);

    e->m = m;
    e->lmax = 0;
    e->ordonnancements = malloc(m*sizeof(OrdonnancementMachine*));
    assert(e->ordonnancements);

    for (int i = 0; i < m; i++)
    {
        e->ordonnancements[i] = newOrdonnancementMachine();
    }

    return e;
}

void deleteEtat(Etat* etat)
{
    assert(etat);

    // On free tout le contenu au préalable.
    for (int i = 0; i < etat->m; i++)
        deleteOrdonnancementMachine(etat->ordonnancements[i]);

    free(etat->ordonnancements);
    free(etat);
}

Etat* cloneEtat(Etat* source)
{
    assert(source);

    Etat* e = malloc(sizeof(struct _Etat));
    assert(e);

    e->m = source->m;
    e->lmax = source->lmax;
    e->ordonnancements = malloc(source->m*sizeof(OrdonnancementMachine*));
    assert(e->ordonnancements);

    for (int i = 0; i < source->m; i++)
    {
        // Clone de l'ordonnancement i
        e->ordonnancements[i] = cloneOrdonnancementMachine(source->ordonnancements[i]);
    }

    return e;
}

void afficheEtat(Etat *etat)
{
    printf("Etat[Lmax = %d, m = %d, ordonnancements = ", etat->lmax, etat->m);
    afficheArray(etat->m, (const void**)etat->ordonnancements, (void (*)(const void*))afficheOrdonnancementMachine);
    printf("]");
}

void ajouterTacheSurMachine(Etat* etat, int k, int i, int pi, int qi)
{
    assert(etat);
    assert(k >= 0 && i >= 0 && pi >= 0 && qi >= 0);

    // On ajoute d'abord la tâche sur la machine pour avoir le nouveau cmax
    ajouterTache(etat->ordonnancements[k], i, pi);
    // Recalcul du lmax selon l'ajout fait précedemment
    etat->lmax = imax(etat->ordonnancements[k]->cmax + qi, etat->lmax);
}

void ajouterTacheSurMachineParInstance(Etat* etat, int k, int i, Instance* instance)
{
    assert(etat && instance);
    assert(k >= 0 && i >= 0);

    ajouterTacheSurMachine(etat, k, i, instance->p[i], instance->q[i]);
}
