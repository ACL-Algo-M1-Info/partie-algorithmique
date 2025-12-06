//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <stdlib.h>

#include "instance.h"

// FONCTIONS

Instance* newInstance(int n, int m, int* p, int* q)
{
    Instance* instance = malloc(sizeof(struct _Instance));

    instance->n = n;
    instance->m = m;
    instance->p = malloc(n*sizeof(int));
    instance->q = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        instance->p[i] = p[i];
        instance->q[i] = q[i];
    }

    return instance;
}

Instance* cloneInstance(Instance* source)
{
    return newInstance(source->n, source->m, source->p, source->q);
}