//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void deleteEtat(void* etat)
{
    assert(etat);
    Etat* e = etat;

    // On free tout le contenu au préalable.
    for (int i = 0; i < e->m; i++)
        deleteOrdonnancementMachine(e->ordonnancements[i]);

    free(e->ordonnancements);
    free(etat);
}

void* cloneEtat(const void* source)
{
    assert(source);
    const Etat* src = source;

    Etat* e = malloc(sizeof(struct _Etat));
    assert(e);

    e->m = src->m;
    e->lmax = src->lmax;
    e->ordonnancements = malloc(src->m*sizeof(OrdonnancementMachine*));
    assert(e->ordonnancements);

    for (int i = 0; i < src->m; i++)
    {
        // Clone de l'ordonnancement i
        e->ordonnancements[i] = cloneOrdonnancementMachine(src->ordonnancements[i]);
    }

    return e;
}

void afficheEtat(const void* etat)
{
    assert(etat);
    const Etat* e = etat;

    printf("Etat[Lmax = %.2lf, m = %d, ordonnancements = ", e->lmax, e->m);
    afficheArray(e->m, (const void**)e->ordonnancements, (void (*)(const void*))afficheOrdonnancementMachine);
    printf("]");
}

int etatsEgaux(const void* a, const void* b)
{
    assert(a && b);

    const Etat* i = a;
    const Etat* j = b;

    // Egalité des lmax
    if (dblcmp(i->lmax, j->lmax) == 0)
        return 0;

    // Egalité des m
    if (i->m != j->m)
        return 0;

    // Egalité des tableaux d'ordonnancement.
    return arraysEgales(i->m, (const void**)i->ordonnancements, (const void**)j->ordonnancements, ordonnancementsMachinesEgaux);
}

void ajouterTacheSurMachine(Etat* etat, int k, int i, double pi, double qi)
{
    assert(etat);
    assert(k >= 0 && i >= 0 && pi >= 0 && qi >= 0);

    // On ajoute d'abord la tâche sur la machine pour avoir le nouveau cmax
    ajouterTache(etat->ordonnancements[k], i, pi);
    // Recalcul du lmax selon l'ajout fait précedemment
    etat->lmax = fmax(etat->ordonnancements[k]->cmax + qi, etat->lmax);
}

void ajouterTacheSurMachineParInstance(Etat* etat, int k, int i, Instance* instance)
{
    assert(etat && instance);
    assert(k >= 0 && i >= 0);

    ajouterTacheSurMachine(etat, k, i, instance->p[i], instance->q[i]);
}
