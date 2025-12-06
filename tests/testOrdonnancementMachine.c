//
// Created by remik on 06/12/2025.
//

#include <stdio.h>

#include "../src/types/ordonnancementMachine/ordonnancementMachine.h"

// Test d'un ordonnancement.
int main(int argc, char *argv[])
{
    OrdonnancementMachine* o = newOrdonnancementMachine();

    printf("Ordonnancement vide: ");
    afficheOrdonnancementMachine(o);
    printf("\n");

    ajouterTache(o, 1, 3);

    printf("Ordonnancement avec la tâche 1 et cmax = 3: ");
    afficheOrdonnancementMachine(o);
    printf("\n");

    OrdonnancementMachine* o2 = cloneOrdonnancementMachine(o);

    printf("Clone: ");
    afficheOrdonnancementMachine(o2);
    printf("\n");

    ajouterTache(o, 2, 5);

    printf("Ajout tâche 2 et cmax = 8 à l'original");
    afficheOrdonnancementMachine(o);
    printf("\n");

    printf("vs clone: ");
    afficheOrdonnancementMachine(o2);
    printf("\n");

    deleteOrdonnancementMachine(o);
    deleteOrdonnancementMachine(o2);

    return 0;
}
