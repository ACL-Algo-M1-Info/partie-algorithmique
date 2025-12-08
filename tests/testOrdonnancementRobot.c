//
// Created by lucas on 07/12/2025.
//

#include <stdio.h>

#include "algos/algo.h"
#include "types/ordonnancementMachine/ordonnancementMachine.h"
int main(int argc, char *argv[])
{
    //Initialisation des données
    int n = 5;
    int m = 3;

    int p[] = {5, 3, 1, 5, 9};
    int q[] = {1, 2, 3, 4, 5};

    //Init instance
    Instance* i = newInstance(n, m, p, q);

    //Init ordonancement
    OrdonnancementMachine* o = newOrdonnancementMachine();
    OrdonnancementMachine* o2 = newOrdonnancementMachine();
    OrdonnancementMachine* o3 = newOrdonnancementMachine();

    ajouterTache(o, 0, 5);
    ajouterTache(o2, 1, 3);
    ajouterTache(o3, 2, 1);
    ajouterTache(o, 3, 5);
    ajouterTache(o2, 4, 9);

    OrdonnancementMachine* tabOrd[] = {o, o2, o3};

    //Algo
    int res = ordonnancementRobot(i, tabOrd, 0.2);
    printf("\nResultat  : %d \n", res);
}
