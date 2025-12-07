//
// Created by maxen on 06/12/2025.
//

#ifndef ETAT_H
#define ETAT_H

// INCLUSIONS

#include "../instance/instance.h"
#include "../ordonnancementMachine/ordonnancementMachine.h"

// STRUCTURES

/**
 * Structure représentant les états
 */
typedef struct _Etat
{
    /** Durée opératoire + durée de latence max de l'état */
    double lmax;
    /** Nombre de machines */
    int m;
    /** Tableau d'ordonnancements de machines */
    OrdonnancementMachine** ordonnancements;
} Etat;

// FONCTIONS

/**
 * Créer un nouvel état avec m machines
 *
 * @param m le nombre de machines
 * @return un nouvel état
 */
Etat* newEtat(int m);

/**
 * Supprime un état.
 *
 * @param etat Etat à supprimer.
 */
void deleteEtat(void* etat);

/**
 * Créer un nouvel état selon un état existant
 *
 * @param source  l'état depuis lequel on clone
 * @return un nouvel état
 */
void* cloneEtat(const void* source);

/**
 * Affiche un état.
 *
 * @param etat Etat à afficher.
 */
void afficheEtat(const void* etat);

/**
 * Compare des états.
 * @param a Etat a.
 * @param b Etat b.
 * @return 1 si égaux, 0 sinon.
 */
int etatsEgaux(const void* a, const void* b);

/**
 *
 * @param etat l'état où se situe la machine où on ajoute la tâche
 * @param k la machine sur laquelle on ajoute la tâche
 * @param i l'id de la tâche que l'on ajoute
 * @param pi la durée opératoire de la tâche i
 * @param qi la durée de latence de la tâche i
 */
void ajouterTacheSurMachine(Etat* etat, int k, int i, double pi, double qi);

/**
 *
 * @param etat l'état où se situe la machine où on ajoute la tâche
 * @param k la machine sur laquelle on ajoute la tâche
 * @param i l'id de la tâche que l'on ajoute
 * @param instance l'instance qui possède la tâche i
 */
void ajouterTacheSurMachineParInstance(Etat* etat, int k, int i, Instance* instance);

#endif //ETAT_H
