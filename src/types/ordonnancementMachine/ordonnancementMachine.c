//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "ordonnancementMachine.h"
#include "../../utils/utils.h"

// FONCTIONS

OrdonnancementMachine* newOrdonnancementMachine()
{
    OrdonnancementMachine* ordonnancement = (OrdonnancementMachine*)malloc(sizeof(struct _OrdonnancementMachine));
    assert(ordonnancement);

    ordonnancement->cmax = 0;
    ordonnancement->tabId = newTableauDynamique();

    return ordonnancement;
}

void deleteOrdonnancementMachine(OrdonnancementMachine* ordonnancement)
{
    assert(ordonnancement);

    // Ici, tous les ints sont préalloués pour que l'ajout se fasse bien. On vient les free.
    deleteTableauDynamique(ordonnancement->tabId, deleteInt);
    free(ordonnancement);
}

OrdonnancementMachine* cloneOrdonnancementMachine(const OrdonnancementMachine* source)
{
    assert(source);

    OrdonnancementMachine* ordonnancement = newOrdonnancementMachine();

    ordonnancement->cmax = source->cmax;

    // La dyntable contient des int*, donc on clone selon cloneInt.
    ordonnancement->tabId = cloneTableauDynamique(source->tabId, (void* (*)(void*))cloneInt);

    return ordonnancement;
}

void afficheOrdonnancementMachine(const OrdonnancementMachine* ordonnancement)
{
    assert(ordonnancement);

    printf("Ordonnancement[cmax = %d, tabId = ", ordonnancement->cmax);

    afficheTableauDynamique(ordonnancement->tabId, (void (*)(const void*))afficheInt);

    printf("]");
}

void ajouterTache(OrdonnancementMachine* ordonnancement, int i, int pi)
{
    assert(ordonnancement && i >= 0 && pi >= 0);

    // Persistance de l'int. La variable pi actuelle est en stack alloc, il faut qu'elle persiste.
    int* iPtr = cloneInt(&i);

    // Appending dans le tableau.
    insereElementTableauDynamique(ordonnancement->tabId, iPtr);

    // Ajout du P(i) au Cmax.
    ordonnancement->cmax += pi;
}

void ajouterTacheParInstance(OrdonnancementMachine* ordonnancement, int i, Instance* instance)
{
    assert(ordonnancement && instance && i > 0);

    ajouterTache(ordonnancement, i, instance->p[i]);
}
