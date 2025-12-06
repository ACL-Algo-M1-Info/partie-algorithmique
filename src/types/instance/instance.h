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
    int* pi;
    /** Durée de latence des tâches */
    int* qi;
} Instance;

// FONCTIONS

/**
 * Créer une nouvelle instance
 *
 * @param n le nombre de tâches
 * @param m le nombre de mâchines
 * @param pi la durée opératoire des tâches
 * @param qi la durée de latence des tâches
 * @return une instance du problème
 */
Instance* newInstance(int n, int m, int* pi, int* qi);

/**
 * Clone une instance
 *
 * @param source  l'instance à cloner
 * @return l'instance clonée
 */
Instance* cloneInstance(Instance* source);


#endif //INSTANCE_H
