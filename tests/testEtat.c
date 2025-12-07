//
// Created by remik on 06/12/2025.
//

#include <assert.h>
#include <stdio.h>

#include "../src/types/etat/etat.h"

// Test d'un etat.
int main(int argc, char *argv[])
{
    Etat* e = newEtat(2);

    printf("Etat vide sur 2 machines:\n");
    afficheEtat(e);
    printf("\n\n");

    ajouterTacheSurMachine(e, 0, 1, 5, 2);

    printf("On doit avoir la tache 1 sur la premiere machine, qui a un cmax de 5 et le lmax est 7:\n");
    afficheEtat(e);
    printf("\n\n");

    Etat *e2 = cloneEtat(e);

    printf("Clone:\n");
    afficheEtat(e2);
    printf("\n\n");
    assert(etatsEgaux(e, e2));

    ajouterTacheSurMachine(e, 1, 2, 4, 7);

    printf("On doit avoir la tache 2 sur la deuxieme machine, qui a un cmax de 4 et le lmax est 11:\n");
    afficheEtat(e);
    printf("\n");
    printf("vs clone:\n");
    afficheEtat(e2);
    printf("\n\n");
    assert(!etatsEgaux(e, e2));

    deleteEtat(e);
    deleteEtat(e2);

    return 0;
}
