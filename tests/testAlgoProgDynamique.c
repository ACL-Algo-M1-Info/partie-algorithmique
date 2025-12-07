//
// Created by MEGACHEESEKEBAB on 07/12/2025.
//


#include <iso646.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include "types/etat/etat.h"
#include "types/instance/instance.h"
#include "types/ordonnancementMachine/ordonnancementMachine.h"
#include "utils/utils.h"
#include "../src/algos/algo.h"

void afficheEtatUltime(const void *etat)
{
    Etat * e = (Etat*)etat;
    printf("Etat[Lmax = %.2lf, m = %d, ordonnancements = ", e->lmax, e->m);
    afficheArray(e->m, (const void**)e->ordonnancements, afficheOrdonnancementMachine);
    printf("]\n");
}
void testTout()
{

    int m = 2;
    int n = 3;
    double p[] = {3,7,4};
    double q[] = {5,9,11};
    Instance * instance = newInstance(n,m,p,q);
    OrdonnancementMachine * ordo = newOrdonnancementMachine();

    // Etat * etat = newEtat(m);
    // TableauDynamique* E = newTableauDynamique();
    // insereElementTableauDynamique(E,etat);
    // afficheTableauDynamique(E,afficheEtat);

    // double minimiserLmax = algoProgrammationDynamique(instance);
    // printf("\nlmax minimal de l'instance : %lf",minimiserLmax);

    double minimiserLmaxSimplifie = algoProgrammationDynamiqueSimplifie(instance);
    printf("\nlmax minimal de l'instance : %lf",minimiserLmaxSimplifie);
}
int main()
{
    testTout();
    return 0;
}
