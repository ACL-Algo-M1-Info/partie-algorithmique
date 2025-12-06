//
// Created by maxen on 06/12/2025.
//

#ifndef ORDONNANCEMENTMACHINE_H
#define ORDONNANCEMENTMACHINE_H

// INCLUSIONS

#include "../instance/instance.h"
#include "../tableauDynamique//tableauDynamique.h"

// STRUCTURES

/**
 * Structure représentant un ordonnancement sur une machine donnée.
 */
typedef struct _OrdonnancementMachine
{
    /** Tableau ordonné des IDs des tâches placées sur cette machine. */
    TableauDynamique* tabId;

    /** Cmax local à la machine. */
    double cmax;

} OrdonnancementMachine;

// FONCTIONS

/**
 * Créé un nouvel ordonnancement de machine vide.
 * @return L'ordonnancement vide créé.
 */
OrdonnancementMachine* newOrdonnancementMachine();

/**
 * Supprime un ordonnancement machine.
 * @param ordonnancement Ordonnancement à supprimer.
 */
void deleteOrdonnancementMachine(OrdonnancementMachine* ordonnancement);

/**
 * Clone un ordonnancement de machine depuis une source. Le clone est profond,
 * et va réallouer toutes les ressources internes nécessaires.
 * @param source L'ordonnancement duquel puiser les informatons.
 * @return Le clone de l'ordonnancement source.
 */
OrdonnancementMachine* cloneOrdonnancementMachine(const OrdonnancementMachine* source);

/**
 * Affiche un ordonnancement.
 * @param ordonnancement Ordonnancement à afficher.
 */
void afficheOrdonnancementMachine(const OrdonnancementMachine* ordonnancement);

/**
 * Ajoute une tâche à l'ordonnancement en fin de position.
 * @param ordonnancement L'ordonnancement à manipuler.
 * @param i Indice de la tâche à ajouter.
 * @param pi Durée opératoire de la tâche à ajouter.
 */
void ajouterTache(OrdonnancementMachine* ordonnancement, int i, double pi);

/**
 * Ajoute une tâche à l'ordonnancement en fin de position.
 * @param ordonnancement L'ordonnancement à manipuler.
 * @param i Tâche à rajouter dans l'ordonnancement.
 * @param instance Instance depuis laquelle piocher les informations.
 */
void ajouterTacheParInstance(OrdonnancementMachine* ordonnancement, int i, Instance* instance);

#endif //ORDONNANCEMENTMACHINE_H
