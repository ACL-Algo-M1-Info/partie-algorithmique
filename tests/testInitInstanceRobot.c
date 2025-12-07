//
// Created by lucas on 07/12/2025.
//

#include <stdio.h>

#include "types/instance/instance.h"
#include "utils/utils.h"

int main()
{
    /// TEST
    {
        int n = 5;
        int m = 3;

        double p[] = {5, 3, 1, 5, 9};
        double q[] = {1, 2, 3, 4, 5};

        //Init instance
        Instance* i = newInstance(n, m, p, q);
        Instance* i2 = cloneInstance(i);
        afficheInstance(i);

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


        printf("\n");
        printf("\n");

        triDateDebutCroissante(i, i2, tabOrd);

        printf("Affiche instance départ : \n");
        afficheInstance(i);

        printf("Affiche instance finale : \n");
        afficheInstance(i2);
    }

    return 0;
}