//
// Created by maxen on 06/12/2025.
//

#ifndef ALGO_H
#define ALGO_H

// INCLUSIONS

#include "../types/instance/instance.h"
#include "types/ordonnancementMachine/ordonnancementMachine.h"

// FONCTIONS

/* Exo 2 */

// TODO entête algo exo 2

/* Exo 3 */

/**
 * Modifie l'instance passée en paramètres pour appliquer le traitement du
 * FPTAS.
 * @param instance Instance à modifer.
 */
void modifierInstanceFPTAS(Instance* instance);

/* Exo 4 */

/**
 * Calcule la date de fin optimale de la dernière livraison
 * @param instance Instance du problème
 * @param ordonnancementMachine Tableau d'ordonnancements sur les différentes machines
 * @return La date de fin optimale (Cmax)
 */
double ordonnancementRobot(Instance* instance, OrdonnancementMachine** ordonnancementMachine, double e);

#endif //ALGO_H
