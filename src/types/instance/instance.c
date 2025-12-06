//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <stdlib.h>

#include "instance.h"

// FONCTIONS

Instance* newInstance(int n, int m, int* pi, int* qi)
{
    Instance* instance = malloc(sizeof(struct _Instance));

    instance->n = n;
    instance->m = m;
    instance->pi = malloc(n*sizeof(int));
    instance->qi = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        instance->pi[i] = pi[i];
        instance->qi[i] = qi[i];
    }

    return instance;
}

Instance* cloneInstance(Instance* source)
{
    return newInstance(source->n, source->m, source->pi, source->qi);
}