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
    OrdonnancementMachine* ordonnancement = malloc(sizeof(struct _OrdonnancementMachine));
    assert(ordonnancement);

    ordonnancement->cmax = 0;
    ordonnancement->tabId = newTableauDynamique();

    return ordonnancement;
}

void deleteOrdonnancementMachine(void* ordonnancement)
{
    assert(ordonnancement);
    OrdonnancementMachine *o = ordonnancement;

    // Ici, tous les ints sont préalloués pour que l'ajout se fasse bien. On vient les free.
    deleteTableauDynamique(o->tabId, deleteInt);
    free(ordonnancement);
}

void* cloneOrdonnancementMachine(const void* source)
{
    assert(source);
    const OrdonnancementMachine* src = source;

    OrdonnancementMachine* ordonnancement = newOrdonnancementMachine();

    ordonnancement->cmax = src->cmax;

    // La dyntable contient des int*, donc on clone selon cloneInt.
    ordonnancement->tabId = cloneTableauDynamique(src->tabId, cloneInt);

    return ordonnancement;
}

void afficheOrdonnancementMachine(const void* ordonnancement)
{
    assert(ordonnancement);
    const OrdonnancementMachine* o = ordonnancement;

    printf("\nOrdonnancement [cmax = %.2lf, tabId = ", o->cmax);

    afficheTableauDynamique(o->tabId, (void (*)(const void*))afficheInt,"id ");

    printf("]");
}

int ordonnancementsMachinesEgaux(const void* a, const void* b)
{
    assert(a && b);

    const OrdonnancementMachine* i = a;
    const OrdonnancementMachine* j = b;

    // Cmax différents (avec marge d'erreur de 10e-6)
    if (!dblcmp(i->cmax, j->cmax))
        return 0;

    // Pas les mêmes éléments
    if (getTailleEffectifTableauDynamique(i->tabId) != getTailleEffectifTableauDynamique(j->tabId))
        return 0;

    // Comparaison des entiers contenus dans le tableau
    return tableauxDynamiquesEgaux(i->tabId, j->tabId, intsEgaux);
}

void ajouterTache(OrdonnancementMachine* ordonnancement, int i, double pi)
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
