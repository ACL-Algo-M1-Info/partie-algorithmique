//
// Created by remik on 06/12/2025.
//

// INCLUSIONS

#include <stdio.h>
#include <stdlib.h>

#include "../src/algos/algo.h"
#include "../src/utils/utils.h"

// DEFINES

/** Nombre de fois que le test doit se lancer. */
#define OCCURRENCES 10

/** Nombre de tâches. */
#define N 5

/** Nombre de machines. */
#define M 3

/** Valeur epsilon désirée. */
#define EPSILON .2

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
 * Test de l'algo avec modification de l'instance selon la programmation
 * dynamique.
 * @param instance Instance à modifier, sur laquelle tester l'algo.
 * @return L'état final trouvé.
 */
void* testAlgoFPTAS(Instance* instance);

/**
 * Applique l'algo robot.
 * @param instance Instance de base.
 * @param optimal Résultat de la PD.
 * @return Résultat du problème des robots.
 */
double testAlgoRobot(Instance* instance, Etat* optimal);

// MAIN

int main(int argc, char* argv[])
{
    // Instances.
    Instance** instances = genererInstancesAleatoires(OCCURRENCES);
    Instance* instancesModifiees[OCCURRENCES];

    // Variables de résultats.
    Etat* optimalPur[OCCURRENCES];
    Etat* optimalPD[OCCURRENCES];
    Etat* optimalFPTAS[OCCURRENCES];
    double optimalCmax[OCCURRENCES];

    // Moyennes des temps.
    double tempsAlgo, tempsAlgoSimplifie, tempsAlgoFPTAS;

    // Clône des instances
    for (int i = 0; i < OCCURRENCES; i++)
        instancesModifiees[i] = cloneInstance(instances[i]);

    // On applique chaque algo.
    for (int i = 0; i < OCCURRENCES; i++)
    {
        // On lance l'algo 1.
        tempsAlgo += benchmarkSurInstance(instances[i], testAlgo, (void**)&optimalPur[i]);

        // On lance l'algo 2.
        tempsAlgoSimplifie += benchmarkSurInstance(instances[i], testAlgoSimplifie, (void**)&optimalPD[i]);

        // On lance l'algo 2 avec modification de l'instance.
        tempsAlgoFPTAS += benchmarkSurInstance(instancesModifiees[i], testAlgoFPTAS, (void**)&optimalFPTAS[i]);

        // On applique l'algo robot sur le résultat de l'instance modifiée.
        optimalCmax[i] = testAlgoRobot(instances[i], optimalFPTAS[i]);
    }

    // Calcul des moyennes.
    tempsAlgo /= OCCURRENCES;
    tempsAlgoSimplifie /= OCCURRENCES;
    tempsAlgoFPTAS /= OCCURRENCES;

    // Affichage des résultats moyens.

    // Frees.

    for (int i = 0; i < OCCURRENCES; i++)
    {
        // Free de chaque instance.
        deleteInstance(instances[i]);
        deleteInstance(instancesModifiees[i]);

        // Free des états
        deleteEtat(optimalPur[i]);
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

void* testAlgoSimplify(Instance* instance)
{
    return algoProgrammationDynamiqueSimplifie(instance);
}

void* testAlgoFPTAS(Instance* instance)
{
    modifierInstanceFPTAS(instance, EPSILON);

    return algoProgrammationDynamiqueSimplifie(instance);
}

double testAlgoRobot(Instance* instance, Etat* optimal)
{
    return ordonnancementRobot(instance, optimal->ordonnancements, EPSILON);
}
