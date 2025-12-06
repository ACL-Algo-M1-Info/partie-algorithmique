//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include "ordonnancementMachine.h"

#include <assert.h>
#include <stdlib.h>

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

void deleteOrdonnancementMachine(const OrdonnancementMachine* ordonnancement)
{
    assert(ordonnancement);

    // Ici, tous les ints sont préalloués pour que l'ajout se fasse bien. On vient les free.
    for (int i = 0; i < getTailleEffectifTableauDynamique(ordonnancement->tabId); i++)
        free( getElementTableauDynamique(ordonnancement->tabId, i) );

    // Free des structures.
    free(ordonnancement->tabId);
    free(ordonnancement);
}

OrdonnancementMachine* cloneOrdonnancementMachine(const OrdonnancementMachine* source)
{
    assert(source);

    OrdonnancementMachine* ordonnancement = newOrdonnancementMachine();

    ordonnancement->cmax = ordonnancement->cmax;

    // La dyntable contient des int*, donc on clone selon cloneInt.
    ordonnancement->tabId = cloneTableauDynamique(source->tabId, (void* (*)(void*))cloneInt);

    return ordonnancement;
}

void ajouterTache(OrdonnancementMachine* ordonnancement, int i, int pi)
{
    assert(ordonnancement && i >= 0 && pi >= 0);

    // Persistance de l'int. La variable pi actuelle est en stack alloc, il faut qu'elle persiste.
    int* iPtr = (int*)malloc(sizeof(int));
    *iPtr = i;

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
