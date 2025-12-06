//
// Created by remik on 06/12/2025.
//

#include <stdio.h>

#include "../src/types/instance/instance.h"

// Test d'une instance.
int main(int argc, char *argv[])
{
    int n = 5;
    int m = 3;

    double p[] = {5, 3, 1, 5, 9};
    double q[] = {5, 4, 3, 2, 1};

    Instance* i = newInstance(n, m, p, q);

    printf("Instance:\n");
    afficheInstance(i);
    printf("\n\n");

    Instance *i2 = cloneInstance(i);

    printf("Clone:\n");
    afficheInstance(i2);
    printf("\n\n");

    deleteInstance(i);
    deleteInstance(i2);

    return 0;
}
