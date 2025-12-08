//
// Created by lucas on 07/12/2025.
//

// INCLUSIONS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "etatRobot.h"
#include "../../utils/utils.h"

// FONCTIONS

EtatRobot* newEtatRobot(int m)
{
    EtatRobot* e = malloc(sizeof(struct _EtatRobot));
    assert(e);

    e->m = m;
    e->cmax = 0;
    e->ordonnancements = malloc(m*sizeof(OrdonnancementMachine*));
    assert(e->ordonnancements);

    for (int i = 0; i < m; i++)
    {
        e->ordonnancements[i] = newOrdonnancementMachine();
    }

    return e;
}

void deleteEtatRobot(void* etat)
{
    assert(etat);
    EtatRobot* e = etat;

    // On free tout le contenu au préalable.
    for (int i = 0; i < e->m; i++)
        deleteOrdonnancementMachine(e->ordonnancements[i]);

    free(e->ordonnancements);
    free(etat);
}

void* cloneEtatRobot(void* source)
{
    assert(source);
    EtatRobot* src = source;

    EtatRobot* e = malloc(sizeof(struct _EtatRobot));
    assert(e);

    e->m = src->m;
    e->cmax = src->cmax;
    e->ordonnancements = malloc(src->m*sizeof(OrdonnancementMachine*));
    assert(e->ordonnancements);

    for (int i = 0; i < src->m; i++)
    {
        // Clone de l'ordonnancement i
        e->ordonnancements[i] = cloneOrdonnancementMachine(src->ordonnancements[i]);
    }

    return e;
}

void afficheEtatRobot(void* etat)
{
    assert(etat);
    EtatRobot* e = etat;

    printf("EtatRobot[Cmax = %d, m = %d, ordonnancements = ", e->cmax, e->m);
    afficheArray(e->m, (const void**)e->ordonnancements, afficheOrdonnancementMachine);
    printf("]");
}

void ajouterTacheSurRobot(EtatRobot* etat, int k, int i, int pi, int qi)
{
    assert(etat);
    assert(k >= 0 && i >= 0 && pi >= 0 && qi >= 0);

    // On ajoute d'abord la tâche sur la machine pour avoir le nouveau cmax
    ajouterTache(etat->ordonnancements[k], i, pi + imax(qi - etat->ordonnancements[k]->cmax, 0));
    // Recalcul du lmax selon l'ajout fait précedemment
    etat->cmax = etat->ordonnancements[k]->cmax;
}

void ajouterTacheSurRobotParInstance(EtatRobot* etat, int k, int i, Instance* instance)
{
    assert(etat && instance);
    assert(k >= 0 && i >= 0);

    ajouterTacheSurRobot(etat, k, i, instance->p[i], instance->q[i]);
}
