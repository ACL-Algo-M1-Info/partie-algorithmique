//
// Created by maxen on 06/12/2025.
//

#ifndef INSTANCE_H
#define INSTANCE_H

// STRUCTURES

/**
 * Structure qui représente une instance avec ses tâches
 */
typedef struct _Instance
{
    /** Nombre de tâches */
    int n;
    /** Nombre de machines */
    int m;
    /** Durée opératoire des tâches */
    int* p;
    /** Durée de latence des tâches */
    int* q;
} Instance;

// FONCTIONS

/**
 * Créer une nouvelle instance
 *
 * @param n le nombre de tâches
 * @param m le nombre de mâchines
 * @param p la durée opératoire des tâches
 * @param q la durée de latence des tâches
 * @return une instance du problème
 */
Instance* newInstance(int n, int m, int* p, int* q);

/**
 * Clone une instance
 *
 * @param source  l'instance à cloner
 * @return l'instance clonée
 */
Instance* cloneInstance(Instance* source);


#endif //INSTANCE_H
