//
// Created by remik on 06/12/2025.
//

// INCLUSIONS

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

// FONCTIONS

int imax(int a, int b)
{
    return a > b ? a : b;
}

int dblcmp(double a, double b)
{
    return fabs(a - b) < DOUBLE_EGALITE_EPSILON;
}

void deleteInt(void* i)
{
    assert(i);
    free(i);
}

void* cloneInt(const void* source)
{
    assert(source);
    const int* src = source;

    int* res = (int*)malloc(sizeof(int));
    *res = *src;

    return res;
}

void afficheInt(const void* i)
{
    assert(i);
    const int* k = i;

    printf("%d", *k);
}

int intsEgaux(const void* a, const void* b)
{
    assert(a && b);

    const int* i = a;
    const int* j = b;

    return *i == *j;
}

void afficheArray(int n, const void* array[n], void (*afficheur)(const void*))
{
    assert(n >= 0 && array && afficheur);
    printf("[");

    for (int i = 0; i < n; i++)
    {
        (*afficheur)(array[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

int arraysEgales(int n, const void* a[n], const void* b[n],
                 int (*comp)(const void*, const void*))
{
    assert(n >= 0 && a && b && comp);

    for (int i = 0; i < n; i++)
        if ((*comp)(a[i], b[i]) == 0)
            return 0;

    return 1;
}

void afficheArrayInt(int n, const int array[n])
{
    assert(n >= 0 && array);
    printf("[");

    for (int i = 0; i < n; i++)
    {
        printf("%d", array[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

int arraysIntEgales(int n, const int a[n], const int b[n])
{
    assert(n >= 0 && a && b);

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;

    return 1;
}

int maxArrayInt(int n, const int a[n])
{
    assert(n > 0 && a);

    int res = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > res)
            res = a[i];

    return res;
}

void afficheArrayDouble(int n, const double array[n])
{
    assert(n >= 0 && array);
    printf("[");

    for (int i = 0; i < n; i++)
    {
        printf("%.2lf", array[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

int arraysDoubleEgales(int n, const double a[n], const double b[n])
{
    assert(n >= 0 && a && b);

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;

    return 1;
}

double maxArrayDouble(int n, const double a[n])
{
    assert(n > 0 && a);

    double res = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > res)
            res = a[i];

    return res;
}

Instance* genererInstanceAleatoire()
{
    // Génération aléatoire.
    int randN = rand() % MAX_N_ALEA_GEN;
    int randM = rand() % MAX_M_ALEA_GEN;

    // Tableaux aléatoires des p(i) et q(i)
    double randP[randN];
    double randQ[randN];

    // Assignation des valeurs aléatoires p(i) et q(i)
    for (int i = 0; i < randN; i++)
    {
        // Pour p(i)
        randP[i] = 1 + rand() % (MAX_P_ALEA_GEN - 1);

        // Pour q(i)
        randQ[i] = 1 + rand() % (MAX_Q_ALEA_GEN - 1);
    }

    return newInstance(randN, randM, randP, randQ);
}

Instance** genererInstancesAleatoires(int nbInstances)
{
    assert(nbInstances >= 0);

    // Génération du tableau stockant des pointeurs vers des instances.
    Instance** res = malloc(nbInstances * sizeof(Instance*));

    // Génération de chaque instance aléatoire.
    for (int i = 0; i < nbInstances; i++)
        res[i] = genererInstanceAleatoire();

    return res;
}

void triFusionDecroissant(int i, int j, Instance* instance, double* tq,
                          double* tp)
{
    if (j <= i) return;

    // Milieu du tableau
    int m = (i + j) / 2;

    // Tri de la moitié gauche
    triFusionDecroissant(i, m, instance, tq, tp);
    // Tri de la moitié droite
    triFusionDecroissant(m + 1, j, instance, tq, tp);

    // Pointeur du sous tableau gauche
    int pg = i;
    // Pointeur du sous tableau droite
    int pd = m + 1;

    // Compteur
    int c;

    // Remplissage de i à j pour le tableau fusionné
    for (c = i; c <= j; c++)
    {
        if (pg == m + 1)
        {
            tq[c] = instance->q[pd];
            tp[c] = instance->p[pd];
            pd++;
        }
        else if (pd == j + 1)
        {
            tq[c] = instance->q[pg];
            tp[c] = instance->p[pg];
            pg++;
        }
        else if (instance->q[pg] > instance->q[pd])
        {
            tq[c] = instance->q[pg];
            tp[c] = instance->p[pg];
            pg++;
        }
        else
        {
            tq[c] = instance->q[pd];
            tp[c] = instance->p[pd];
            pd++;
        }
    }

    // Copie des éléments dans tab
    for (c = i; c <= j; c++)
    {
        instance->q[c] = tq[c];
        instance->p[c] = tp[c];
    }
}

void triFusionCroissant(int i, int j, Instance* instance, double* tq,
                        double* tp)
{
    if (j <= i) return;

    // Milieu du tableau
    int m = (i + j) / 2;

    // Tri de la moitié gauche
    triFusionCroissant(i, m, instance, tq, tp);
    // Tri de la moitié droite
    triFusionCroissant(m + 1, j, instance, tq, tp);

    // Pointeur du sous tableau gauche
    int pg = i;
    // Pointeur du sous tableau droite
    int pd = m + 1;

    // Compteur
    int c;

    // Remplissage de i à j pour le tableau fusionné
    for (c = i; c <= j; c++)
    {
        if (pg == m + 1)
        {
            tq[c] = instance->q[pd];
            tp[c] = instance->p[pd];
            pd++;
        }
        else if (pd == j + 1)
        {
            tq[c] = instance->q[pg];
            tp[c] = instance->p[pg];
            pg++;
        }
        else if (instance->q[pg] < instance->q[pd])
        {
            tq[c] = instance->q[pg];
            tp[c] = instance->p[pg];
            pg++;
        }
        else
        {
            tq[c] = instance->q[pd];
            tp[c] = instance->p[pd];
            pd++;
        }
    }

    // Copie des éléments dans tab
    for (c = i; c <= j; c++)
    {
        instance->q[c] = tq[c];
        instance->p[c] = tp[c];
    }
}

void triJacksonQ(Instance* i)
{
    assert(i);

    double tq[i->n];
    double tp[i->n];
    triFusionDecroissant(0, i->n - 1, i, tq, tp);
}

void triDateDebutCroissante(Instance* instance, Instance* instanceOut,
                            OrdonnancementMachine** ordonnancement)
{
    int indice = 0;
    for (int i = 0; i < instance->m; i++)
    {
        OrdonnancementMachine* ordo = ordonnancement[i];
        int size = ordo->tabId->tailleEffectif;
        double cmax = 0;
        for (int j = 0; j < size; j++)
        {
            int* index = getElementTableauDynamique(ordo->tabId, j);
            cmax += instance->p[*index - 1];

            instanceOut->p[indice] = instance->q[*index - 1];
            instanceOut->q[indice] = cmax;
            indice++;
        }
    }

    //instanceOut est désormais initialisé avec pi qui représente le temps de livraison pour un robot et qi qui représente la date de début au plus tôt de la tâche i
    afficheInstance(instanceOut);

    double tq[instanceOut->n];
    double tp[instanceOut->n];
    triFusionCroissant(0, instanceOut->n - 1, instanceOut, tq, tp);
}

double rasteriserInferieur(double k, double facteur)
{
    // La formule est floor(k / facteur) * facteur pour la rastérisation
    return floor(k / facteur) * facteur;
}

Etat* minDeLensemble(const TableauDynamique* E)
{
    Etat* e = getElementTableauDynamique(E, 0);
    Etat* min = e;

    for (int i = 1; i < getTailleEffectifTableauDynamique(E); i++)
    {
        Etat* ei = getElementTableauDynamique(E, i);
        if (min->lmax > ei->lmax)
        {
            min = ei;
        }
    }
    return min;
}

int ordoEstPlusGrandQue(const void* a, const void* b)
{
    OrdonnancementMachine* o1 = *(OrdonnancementMachine**)a;
    OrdonnancementMachine* o2 = *(OrdonnancementMachine**)b;

    if (o1->cmax < o2->cmax) return -1;
    if (o1->cmax > o2->cmax) return 1;
    return 0;
}

void trierMachineDeEtat(Etat* e)
{
    qsort(e->ordonnancements, e->m, sizeof(OrdonnancementMachine*),
          ordoEstPlusGrandQue);
}

/**
 * Sous hypothèse que les ordos sont déjà triés !!!!!!!
 * @param a
 * @param b
 * @return vrai si a domine b
 */
int estDomine(const Etat* a, const Etat* b)
{
    if (a->lmax > b->lmax)
    {
        return 0; // a domine pas b
    }
    //Pour chacune des machines de a et b, comme elles sont triées, si l'une a un cmax plus grand qu'une des machine de a c'est terminé, on sait que b domine
    for (int k = 0; k < a->m; k++)
    {
        if (a->ordonnancements[k]->cmax > b->ordonnancements[k]->cmax)
        {
            return 0;
        }
    }
    //si a domine b
    return 1;
}

void supprimerDoublon(TableauDynamique* E)
{
    int nbEtat = getTailleEffectifTableauDynamique(E);
    if (nbEtat == 0) return;

    for (int i = 0; i < nbEtat; i++)
    {
        Etat* e = getElementTableauDynamique(E, i);
        trierMachineDeEtat(e);
    }

    int* aSupprimer = calloc(nbEtat, sizeof(int));
    //Pour un etat donné
    for (int i = 0; i < nbEtat; i++)
    {
        if (aSupprimer[i])
        {
            continue;
        }

        Etat* ei = getElementTableauDynamique(E, i);
        //Pour chaque autre état dans l'ensemble, on le compare aux autres
        for (int j = 0; j < nbEtat; j++)
        {
            if (i == j || aSupprimer[j])
            {
                continue;
            }

            Etat* ej = getElementTableauDynamique(E, j);

            if (estDomine(ei, ej))
            {
                if (estDomine(ej, ei))
                {
                    //C'est pour éviter de supprimer les deux états.. car quand on va boucler ex [0,14] 20 pense dominé [14,0] 20 et réciproquement..
                    //donc je supprime uniquement celui avec le plus grand index (j >i)
                    if (j > i)
                    {
                        aSupprimer[j] = 1;
                    }
                }
                else
                {
                    aSupprimer[j] = 1;
                }
            }
        }
    }
    for (int i = nbEtat - 1; i >= 0; i--)
    {
        if (aSupprimer[i])
        {
            //Pour le supprimer je le mets à la dernière case pour le faire dépop avec la méthode TAD
            unsigned int dernierIndice =
                getTailleEffectifTableauDynamique(E) - 1;
            if (i != dernierIndice)
            {
                swapElementTableauDynamique(E, i, dernierIndice);
            }

            Etat* e = retireElementTableauDynamique(E);
            deleteEtat(e);
        }
    }

    free(aSupprimer);
}

double benchmarkSurInstance(Instance* instance, void* (*traitement)(Instance*), void** out)
{
    assert(instance && traitement);

    volatile clock_t start, end;

    start = clock();
    *out = (*traitement)(instance);
    end = clock();

    return (double)((end - start) / (double)CLOCKS_PER_SEC);
}
