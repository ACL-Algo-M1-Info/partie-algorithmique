//
// Created by lucas on 07/12/2025.
//

#ifndef ETATROBOT_H
#define ETATROBOT_H

// INCLUSIONS

#include "../instance/instance.h"
#include "../ordonnancementMachine/ordonnancementMachine.h"

// STRUCTURES

/**
 * Structure représentant les états
 */
typedef struct _EtatRobot
{
    /** Durée opératoire max de l'état */
    int cmax;

    /** Nombre de machines */
    int m;

    /** Tableau d'ordonnancements de machines */
    OrdonnancementMachine** ordonnancements;
} EtatRobot;

// FONCTIONS

/**
 * Créer un nouvel état avec m machines
 *
 * @param m le nombre de machines
 * @return un nouvel état
 */
EtatRobot* newEtatRobot(int m);

/**
 * Supprime un état.
 *
 * @param etat Etat à supprimer.
 */
void deleteEtatRobot(void* etat);

/**
 * Créer un nouvel état selon un état existant
 *
 * @param source  l'état depuis lequel on clone
 * @return un nouvel état
 */
void* cloneEtatRobot(void* source);

/**
 * Affiche un état.
 *
 * @param etat Etat à afficher.
 */
void afficheEtatRobot(void* etat);

/**
 *
 * @param etat l'état où se situe la machine où on ajoute la tâche
 * @param k la machine sur laquelle on ajoute la tâche
 * @param i l'id de la tâche que l'on ajoute
 * @param pi la durée opératoire de la tâche i
 * @param qi la date de début au plus tôt de la tâche i
 */
void ajouterTacheSurRobot(EtatRobot* etat, int k, int i, int pi, int qi);

/**
 *
 * @param etat l'état où se situe la machine où on ajoute la tâche
 * @param k la machine sur laquelle on ajoute la tâche
 * @param i l'id de la tâche que l'on ajoute
 * @param instance l'instance qui possède la tâche i
 */
void ajouterTacheSurRobotParInstance(EtatRobot* etat, int k, int i, Instance* instance);

#endif //ETATROBOT_H
