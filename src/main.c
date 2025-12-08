//
// Created by remik on 06/12/2025.
//

// INCLUSIONS

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algos/algo.h"
#include "utils/utils.h"

// DEFINES

/** Nombre de fois que le test doit se lancer. */
#define OCCURRENCES 100

/** Nombre de tâches. */
#define N 8

/** Nombre de machines. */
#define M 5

/** Valeur epsilon désirée. */
#define EPSILON .2

/** Détermine si l'algo de base doit être utilisé. */
#define UTILISER_ALGO_BASE 0

// DECLARATIONS

/**
 * Test de l'algo de base sans simplification.
 * @param instance Instance sur laquelle tester l'algo.
 * @return L'état final trouvé.
 */
void* testAlgo(Instance* instance);

/**
 * Test de l'algo simplifié.
 * @param instance Instance sur laquelle tester l'algo.
 * @return L'état final trouvé.
 */
void* testAlgoSimplifie(Instance* instance);

/**
 * Test de l'algo simplifié avec prémodification de l'instance.
 * @param instance Instance sur laquelle rastériser et tester l'algo.
 * @return L'état final trouvé.
 */
void* testAlgoFPTAS(Instance* instance);

/**
 * Applique l'algo robot.
 * @param instance Instance de base.
 * @param optimal Résultat de la PD.
 * @return Résultat du problème des robots.
 */
int testAlgoRobot(Instance* instance, Etat* optimal);

// MAIN

int main(int argc, char* argv[])
{
    srand(time(NULL));


    Instance** instances = genererInstancesAleatoires(OCCURRENCES, N, M);;
    Instance* instancesModifiees[OCCURRENCES];

    // Variables de résultats.
    Etat* optimalPur[OCCURRENCES];
    Etat* optimalPD[OCCURRENCES];
    Etat* optimalFPTAS[OCCURRENCES];
    int optimalCmax[OCCURRENCES];

    // Moyennes des temps.
    double tempsAlgoTotal, tempsAlgoSimplifieTotal, tempsAlgoFPTASTotal;
    double tempsAlgo, tempsAlgoSimplifie, tempsAlgoFPTAS;

    // Ecarts potentiels.
    double lmaxAlgoTotal, lmaxAlgo;
    double ecartLmaxAlgoSimplifieTotal, ecartLmaxAlgoFPTASTotal;
    double ecartLmaxAlgoSimplifie, ecartLmaxAlgoFPTAS;

    tempsAlgoTotal = tempsAlgoSimplifieTotal = tempsAlgoFPTASTotal = 0;
    lmaxAlgoTotal = ecartLmaxAlgoSimplifieTotal = ecartLmaxAlgoFPTASTotal = 0;

    // Clône des instances pour les modifier.
    for (int i = 0; i < OCCURRENCES; i++)
    {
        instancesModifiees[i] = cloneInstance(instances[i]);
        modifierInstanceFPTAS(instancesModifiees[i], EPSILON);
    }

    printf("DEBUT DU BENCHMARKING AVEC N = %d ET M = %d ===\n\n", N, M);

#if OCCURRENCES > 250
    printf("Le nombre d'occurrence etant trop grand, l'affichage ne se fera pas pour gagner du temps...\n\n");
#endif

    // On applique chaque algo.
    for (int i = 0; i < OCCURRENCES; i++)
    {
        tempsAlgo = tempsAlgoSimplifie = tempsAlgoFPTAS = 0;
        lmaxAlgo = ecartLmaxAlgoSimplifie = ecartLmaxAlgoFPTAS = 0;

        // On lance l'algo 1.
#if UTILISER_ALGO_BASE == 1
        tempsAlgo = benchmarkSurInstance(instances[i], testAlgo, (void**)&optimalPur[i]);

        lmaxAlgo = (double)optimalPur[i]->lmax;
#endif

        // On lance l'algo 2.
        tempsAlgoSimplifie = benchmarkSurInstance(instances[i], testAlgoSimplifie, (void**)&optimalPD[i]);

#if UTILISER_ALGO_BASE == 1
        // Cet écart devrait être 0.
        ecartLmaxAlgoSimplifie = fabs(lmaxAlgo - (double)optimalPD[i]->lmax);

#else
        // Cet algo est considéré comme exact si l'algo exact sans filtre n'est pas lancé, donc aucun écart.
        lmaxAlgo = (double)optimalPD[i]->lmax;
        ecartLmaxAlgoSimplifie = 0;
#endif

        // On lance l'algo 2 avec modification de l'instance.
        tempsAlgoFPTAS = benchmarkSurInstance(instancesModifiees[i], testAlgoFPTAS, (void**)&optimalFPTAS[i]);

        // Calcul écart entre le Lmax de l'algo exact et celui de l'algo d'approx
        ecartLmaxAlgoFPTAS = fabs(lmaxAlgo - (double)optimalFPTAS[i]->lmax);

        // On applique l'algo robot sur le résultat de l'instance modifiée.
        optimalCmax[i] = testAlgoRobot(instances[i], optimalFPTAS[i]);


        // Messages.
#if OCCURRENCES <= 250
        printf("ITERATION %d =====\n\n", i);

        printf("Instance: ");
        afficheInstance(instances[i]);

        printf("\n\nInstance modifiee: ");
        afficheInstance(instancesModifiees[i]);
        printf("\n\n");

#if UTILISER_ALGO_BASE == 1
        printf("Algo de base occurrence %d...\n", i);
        printf(">>> Solution: %d (%lf secondes)\n\n", optimalPur[i]->lmax, tempsAlgo);
#endif

        printf("Algo simplifie occurrence %d...\n", i);
        printf(">>> Solution: %d (%lf secondes)\n\n", optimalPD[i]->lmax, tempsAlgoSimplifie);

        printf("Algo avec modification de l'instance occurrence %d...\n", i);
        printf(">>> Solution: %d (%lf secondes)\n\n", optimalFPTAS[i]->lmax, tempsAlgoFPTAS);

        printf("Algo des robots occurrence %d...\n", i);
        printf(">>> Solution: %d\n\n", optimalCmax[i]);
#endif

        tempsAlgoTotal += tempsAlgo;
        tempsAlgoSimplifieTotal += tempsAlgoSimplifie;
        tempsAlgoFPTASTotal += tempsAlgoFPTAS;

        lmaxAlgoTotal += lmaxAlgo;
        ecartLmaxAlgoSimplifieTotal += ecartLmaxAlgoSimplifie;
        ecartLmaxAlgoFPTASTotal += ecartLmaxAlgoFPTAS;
    }

    // Calcul des moyennes.
    tempsAlgoTotal /= (double)OCCURRENCES;
    tempsAlgoSimplifieTotal /= (double)OCCURRENCES;
    tempsAlgoFPTASTotal /= (double)OCCURRENCES;

    lmaxAlgoTotal /= (double)OCCURRENCES;
    ecartLmaxAlgoSimplifieTotal /= (double)OCCURRENCES;
    ecartLmaxAlgoFPTASTotal /= (double)OCCURRENCES;

    // Affichage des résultats moyens.

    printf("RESULTATS ===\n\n");

#if UTILISER_ALGO_BASE == 1
    printf("- Algo sans suppression des etats : %lf secondes\n", tempsAlgo);
#endif

    printf("- Algo avec suppression des etats : %lf secondes pour un ecart du Lmax moyen de %lf par rapport a l'algo 1\n", tempsAlgoSimplifieTotal, ecartLmaxAlgoSimplifieTotal);
    printf("- Algo avec suppression des etats et modification de l'instance : %lf secondes pour un ecart du Lmax moyen de %lf par rapport a l'algo 1\n", tempsAlgoFPTASTotal, ecartLmaxAlgoFPTASTotal);

    // Frees.
    for (int i = 0; i < OCCURRENCES; i++)
    {
        // Free de chaque instance.
        deleteInstance(instances[i]);
        deleteInstance(instancesModifiees[i]);

        // Free des états
#if UTILISER_ALGO_BASE == 1
        deleteEtat(optimalPur[i]);
#endif

        deleteEtat(optimalPD[i]);
        deleteEtat(optimalFPTAS[i]);
    }

    // Free tableau.
    free(instances);

    return 0;
}

// FONCTIONS

void* testAlgo(Instance* instance)
{
    return algoProgrammationDynamique(instance);
}

void* testAlgoSimplifie(Instance* instance)
{
    return algoProgrammationDynamiqueSimplifie(instance);
}

void* testAlgoFPTAS(Instance* instance)
{
    return algoProgrammationDynamiqueSimplifie(instance);
}

int testAlgoRobot(Instance* instance, Etat* optimal)
{
    return ordonnancementRobot(instance, optimal->ordonnancements, EPSILON);
}
