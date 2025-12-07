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

void deleteInstance(void* instance)
{
    assert(instance);
    Instance* i = instance;

    free(i->p);
    free(i->q);
    free(instance);
}

void* cloneInstance(const void* source)
{
    assert(source);
    const Instance* src = source;

    return newInstance(src->n, src->m, src->p, src->q);
}

void afficheInstance(const void* instance)
{
    assert(instance);
    const Instance* i = instance;

    printf("Instance[n = %d, m = %d, p = ", i->n, i->m);
    afficheArrayDouble(i->n, i->p);
    printf(", q = ");
    afficheArrayDouble(i->n, i->q);
    printf("]");
}

int instancesEgales(const void* a, const void* b)
{
    const Instance* i = a;
    const Instance* j = b;

    // Tailles inégales
    if (i->n != j->n)
        return 0;

    // Machines inégales
    if (i->m != j->m)
        return 0;

    // Tableaux inégaux des p
    if (arrayDoubleEgales(i->n, i->p, j->p) == 0)
        return 0;

    // Tableaux inégaux des q
    if (arrayDoubleEgales(i->n, i->q, j->q) == 0)
        return 0;

    return 1;
}