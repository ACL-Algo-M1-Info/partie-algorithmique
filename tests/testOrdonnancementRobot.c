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

    double p[] = {5, 3, 1, 5, 9};
    double q[] = {1, 2, 3, 4, 5};

    //Init instance
    Instance* i = newInstance(n, m, p, q);

    //Init ordonancement
    OrdonnancementMachine* o = newOrdonnancementMachine();
    OrdonnancementMachine* o2 = newOrdonnancementMachine();
    OrdonnancementMachine* o3 = newOrdonnancementMachine();

    ajouterTache(o, 1, 5);
    ajouterTache(o2, 2, 3);
    ajouterTache(o3, 3, 1);
    ajouterTache(o, 4, 5);
    ajouterTache(o2, 5, 9);

    OrdonnancementMachine* tabOrd[] = {o, o2, o3};

    //Algo
    double res = ordonnancementRobot(i, tabOrd, 0.2);
    printf("\nResultat  : %lf \n", res);
}