//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <stdlib.h>

#include "ordonnancementMachine.h"

// FONCTIONS

OrdonnancementMachine* newOrdonnancementMachine()
{
    OrdonnancementMachine* ordonnancement = (OrdonnancementMachine*)malloc(sizeof(struct _OrdonnancementMachine));

    ordonnancement->cmax = ordonnancement->taille = 0;
    // TODO initialisation de la dyntable et suppression du champ "taille" dans la ligne du dessus

    return ordonnancement;
}

OrdonnancementMachine* cloneOrdonnancementMachine(OrdonnancementMachine* source)
{
    OrdonnancementMachine* ordonnancement = newOrdonnancementMachine();

    ordonnancement->taille = source->taille; // TODO à convertir en dyntable
    ordonnancement->cmax = ordonnancement->cmax;

    // TODO cloner la dyntable

    return ordonnancement;
}

void ajouterTache(OrdonnancementMachine* ordonnancement, int i, int pi)
{
    // TODO ajout de i dans la dyntable (en append)

    // Ajout du P(i) au Cmax.
    ordonnancement->cmax += pi;
}

void ajouterTacheParInstance(OrdonnancementMachine* ordonnancement, int i, Instance* instance)
{
    ajouterTache(ordonnancement, i, instance->pi[i]);
}
