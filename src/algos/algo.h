//
// Created by maxen on 06/12/2025.
//

#ifndef ALGO_H
#define ALGO_H

// INCLUSIONS

#include "../types/instance/instance.h"

// FONCTIONS

/* Exo 2 */
/**
 * Algo exact
 * Génére toutes les combinaisons de placement possible d'ordonnancement pour une instance de n tâche et m machine
 * Retourne la solution avec le lmax minimal (ne retourne pas l'état qui donne ce lmax minimal)
 * @param instance
 * @return le lmax minimal
 */
double algoProgrammationDynamique(Instance* instance);
/**
 * Algo exact
 * Génére toutes les combinaisons de placement possible d'ordonnancement pour une instance de n tâche et m machine
 * Mais cette fois-ci, retire les états dominés
 * Retourne la solution avec le lmax minimal (ne retourne pas l'état qui donne ce lmax minimal)
 * @param instance
 * @return
 */
double algoProgrammationDynamiqueSimplifie(Instance* instance);
/* Exo 3 */

/**
 * Modifie l'instance passée en paramètres pour appliquer le traitement du
 * FPTAS.
 * @param instance Instance à modifer.
 */
void modifierInstanceFPTAS(Instance* instance);

/* Exo 4 */

// TODO entête algo exo 4

#endif //ALGO_H
