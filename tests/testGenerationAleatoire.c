//
// Created by remik on 07/12/2025.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/utils/utils.h"
#include "../src/types/instance/instance.h"

// Test d'un etat.
int main(int argc, char *argv[])
{
    int n = 50;
    Instance **tab = genererInstancesAleatoires(n);

    for (int i = 0; i < n; i++)
    {
        Instance *a = tab[i];

        printf("%d: ", i);
        afficheInstance(a);
        printf("\n\n");

        assert(a->n <= MAX_N_ALEA_GEN && a->m <= MAX_M_ALEA_GEN);

        for (int k = 0; k < a->n; k++)
            assert(a->p[k] <= MAX_P_ALEA_GEN && a->q[k] <= MAX_Q_ALEA_GEN);
    }

    for (int i = 0; i < n; i++)
        deleteInstance(tab[i]);

    free(tab);
    return 0;
}
