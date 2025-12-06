//
// Created by remik on 06/12/2025.
//

#include<assert.h>
#include <stdio.h>

#include "../src/types/ordonnancementMachine/ordonnancementMachine.h"

// Test d'un ordonnancement.
int main(int argc, char *argv[])
{
    OrdonnancementMachine* o = newOrdonnancementMachine();

    printf("Ordonnancement vide:\n");
    afficheOrdonnancementMachine(o);
    printf("\n\n");
    assert(o->cmax == 0 && getTailleEffectifTableauDynamique(o->tabId) == 0);

    ajouterTache(o, 1, 3);

    printf("Ordonnancement avec la tache 1 et cmax = 3:\n");
    afficheOrdonnancementMachine(o);
    printf("\n\n");
    assert(o->cmax == 3 && getTailleEffectifTableauDynamique(o->tabId) == 1);

    OrdonnancementMachine* o2 = cloneOrdonnancementMachine(o);

    printf("Clone:\n");
    afficheOrdonnancementMachine(o2);
    printf("\n\n");
    assert(o2->cmax == 3 && getTailleEffectifTableauDynamique(o2->tabId) == 1);

    ajouterTache(o, 2, 5);

    printf("Ajout tache 2 et cmax = 8 a l'original:\n");
    afficheOrdonnancementMachine(o);
    printf("\n");
    assert(o->cmax == 8 && getTailleEffectifTableauDynamique(o->tabId) == 2);

    printf("vs clone:\n");
    afficheOrdonnancementMachine(o2);
    printf("\n\n");
    assert(o2->cmax == 3 && getTailleEffectifTableauDynamique(o2->tabId) == 1);

    deleteOrdonnancementMachine(o);
    deleteOrdonnancementMachine(o2);

    return 0;
}
