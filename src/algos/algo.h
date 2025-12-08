//
// Created by maxen on 06/12/2025.
//

#ifndef ALGO_H
#define ALGO_H

// INCLUSIONS

#include "types/etat/etat.h"
#include "../types/instance/instance.h"
#include "types/ordonnancementMachine/ordonnancementMachine.h"

// FONCTIONS

/* Exo 2 */
/**
 * Algo exact
 * Génére toutes les combinaisons de placement possible d'ordonnancement pour une instance de n tâche et m machine
 * Retourne la solution avec le lmax minimal (ne retourne pas l'état qui donne ce lmax minimal)
 * @param instance
 * @return le lmax minimal
 */
Etat* algoProgrammationDynamique(Instance* instance);
/**
 * Algo exact
 * Génére toutes les combinaisons de placement possible d'ordonnancement pour une instance de n tâche et m machine
 * Mais cette fois-ci, retire les états dominés
 * Retourne la solution avec le lmax minimal (ne retourne pas l'état qui donne ce lmax minimal)
 * @param instance
 * @return
 */
Etat* algoProgrammationDynamiqueSimplifie(Instance* instance);
/* Exo 3 */

/**
 * Modifie l'instance passée en paramètres pour appliquer le traitement du
 * FPTAS.
 * @param instance Instance à modifer.
 * @param e Epsilon à fixer.
 */
void modifierInstanceFPTAS(Instance* instance, double e);

/* Exo 4 */

/**
 * Calcule la date de fin optimale de la dernière livraison
 * @param instance Instance du problème
 * @param ordonnancementMachine Tableau d'ordonnancements sur les différentes machines
 * @return La date de fin optimale (Cmax)
 */
int ordonnancementRobot(Instance* instance, OrdonnancementMachine** ordonnancementMachine, double e);

#endif //ALGO_H
