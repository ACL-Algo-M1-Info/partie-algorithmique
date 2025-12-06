//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "instance.h"
#include "../../utils/utils.h"

// FONCTIONS

Instance* newInstance(int n, int m, double *p, double *q)
{
    Instance* instance = malloc(sizeof(struct _Instance));
    assert(instance);

    instance->n = n;
    instance->m = m;
    instance->p = malloc(n*sizeof(double));
    instance->q = malloc(n*sizeof(double));
    assert(instance->p && instance->q);

    for (int i = 0; i < n; i++)
    {
        instance->p[i] = p[i];
        instance->q[i] = q[i];
    }

    return instance;
}

void deleteInstance(Instance* instance)
{
    assert(instance);

    free(instance->p);
    free(instance->q);
    free(instance);
}

Instance* cloneInstance(Instance* source)
{
    assert(source);

    return newInstance(source->n, source->m, source->p, source->q);
}

void afficheInstance(const Instance* instance)
{
    assert(instance);

    printf("Instance[n = %d, m = %d, p = ", instance->n, instance->m);
    afficheArrayDouble(instance->n, instance->p);
    printf(", q = ");
    afficheArrayDouble(instance->n, instance->q);
    printf("]");
}
