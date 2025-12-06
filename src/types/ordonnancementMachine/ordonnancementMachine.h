//
// Created by maxen on 06/12/2025.
//

#ifndef ORDONNANCEMENTMACHINE_H
#define ORDONNANCEMENTMACHINE_H

// STRUCTURES

/**
 * Structure représentant un ordonnancement sur une machine donnée.
 */
typedef struct _OrdonnancementMachine
{
    /** Nombre de tâches. */
    int taille;

    /** Tableau ordonné des IDs des tâches placées sur cette machine. */
    int* tabId;

    /** Cmax local à la machine. */
    int cmax;

} OrdonnancementMachine;

// FONCTIONS

/**
 * Créé un nouvel ordonnancement de machine vide.
 * @return L'ordonnancement vide créé.
 */
OrdonnancementMachine* newOrdonnancementMachine();

/**
 * Clone un ordonnancement de machine depuis une source. Le clone est profond,
 * et va réallouer toutes les ressources internes nécessaires.
 * @param source L'ordonnancement duquel puiser les informatons.
 * @return Le clone de l'ordonnancement source.
 */
OrdonnancementMachine* cloneOrdonnancementMachine(OrdonnancementMachine* source);

/**
 * Ajoute une tâche à l'ordonnancement en fin de position.
 * @param i Indice de la tâche à ajouter.
 * @param pi Durée opératoire de la tâche à ajouter.
 */
void ajouterTache(int i, int pi);

#endif //ORDONNANCEMENTMACHINE_H
