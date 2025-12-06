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
    int lmax;
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
void deleteEtat(Etat* etat);

/**
 * Créer un nouvel état selon un état existant
 *
 * @param source  l'état depuis lequel on clone
 * @return un nouvel état
 */
Etat* cloneEtat(Etat* source);

/**
 * Affiche un état.
 *
 * @param etat Etat à afficher.
 */
void afficheEtat(Etat *etat);

/**
 *
 * @param etat l'état où se situe la machine où on ajoute la tâche
 * @param k la machine sur laquelle on ajoute la tâche
 * @param i l'id de la tâche que l'on ajoute
 * @param pi la durée opératoire de la tâche i
 * @param qi la durée de latence de la tâche i
 */
void ajouterTacheSurMachine(Etat* etat, int k, int i, int pi, int qi);

/**
 *
 * @param etat l'état où se situe la machine où on ajoute la tâche
 * @param k la machine sur laquelle on ajoute la tâche
 * @param i l'id de la tâche que l'on ajoute
 * @param instance l'instance qui possède la tâche i
 */
void ajouterTacheSurMachineParInstance(Etat* etat, int k, int i, Instance* instance);

#endif //ETAT_H
