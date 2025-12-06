//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <stdio.h>
#include <time.h>

#include "../src/utils/utils.h"

int main()
{
    // PREMIER TEST
    {
        int n = 10;
        int t[n];

        for (int i = n - 1; i >= 0; i--)
        {
            t[i] = i;
        }
        printf("Tableau de base : \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", t[i]);
        }


        int tmp[n];
        triFusion(0, n-1, t, tmp);
        printf("\nTableau de tri fusion : \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", t[i]);
        }
    }

    // DEUXIEME TEST
    {
        int n = 6;
        int t[n];
        t[0] = 8;
        t[1] = 19;
        t[2] = 1;
        t[3] = 34;
        t[4] = 1;
        t[5] = 2;

        printf("\nTableau de base : \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", t[i]);
        }

        int tmp[n];
        triFusion(0, n-1, t, tmp);
        printf("\nTableau de tri fusion : \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", t[i]);
        }
    }

    return 0;
}