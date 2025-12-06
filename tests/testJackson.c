//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <stdio.h>

#include "../src/utils/utils.h"

int main()
{
    /// TEST
    {
        int n = 5;
        int m = 3;

        double p[] = {5, 3, 1, 5, 9};
        double q[] = {1, 2, 3, 4, 5};

        Instance* i = newInstance(n, m, p, q);

        afficheInstance(i);

        printf("\n");
        printf("\n");

        triJacksonQ(i);

        afficheInstance(i);
    }

    return 0;
}