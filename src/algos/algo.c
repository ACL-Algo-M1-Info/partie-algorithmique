//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS
#include <assert.h>
#include <stdlib.h>
#include "algo.h"
#include "types/etat/etat.h"
#include "utils/utils.h"

// FONCTIONS

/* Exo 2 */


double algoProgrammationDynamique(Instance* instance)
{
    triJacksonQ(instance);
    int nbMachine = instance->m;
    int nbTache = instance->n;

    Etat* etat = newEtat(nbMachine);
    TableauDynamique* E = newTableauDynamique();
    insereElementTableauDynamique(E, etat);

    //Pour chaque tâche
    for (int j = 0; j < nbTache; j++)
    {
        TableauDynamique* Ej = newTableauDynamique();

        //Pour chaque etat dans E
        for (int e = 0; e < getTailleEffectifTableauDynamique(E); e++)
        {
            Etat* ei = getElementTableauDynamique(E, e);
            //Pour chaque machine
            for (int k = 0; k < nbMachine; k++)
            {
                Etat* etatEvolue = cloneEtat(ei);
                ajouterTacheSurMachine(etatEvolue, k, j, instance->p[j],
                                       instance->q[j]);
                insereElementTableauDynamique(Ej, etatEvolue);
            }
        }
        deleteTableauDynamique(E, deleteEtat);
        E = cloneTableauDynamique(Ej, cloneEtat);
    }
    afficheTableauDynamique(E, afficheEtat, "Ensemble\n");
    return minDeLensemble(E);
}

double algoProgrammationDynamiqueSimplifie(Instance* instance)
{
    triJacksonQ(instance);
    int nbMachine = instance->m;
    int nbTache = instance->n;

    Etat* etat = newEtat(nbMachine);
    TableauDynamique* E = newTableauDynamique();
    insereElementTableauDynamique(E, etat);

    //Pour chaque tâche
    for (int j = 0; j < nbTache; j++)
    {
        TableauDynamique* Ej = newTableauDynamique();

        //Pour chaque etat dans E
        for (int e = 0; e < getTailleEffectifTableauDynamique(E); e++)
        {
            Etat* ei = getElementTableauDynamique(E, e);
            //Pour chaque machine
            for (int k = 0; k < nbMachine; k++)
            {
                Etat* etatEvolue = cloneEtat(ei);
                ajouterTacheSurMachine(etatEvolue, k, j, instance->p[j],
                                       instance->q[j]);
                insereElementTableauDynamique(Ej, etatEvolue);
            }
        }
        deleteTableauDynamique(E, deleteEtat);
        supprimerDoublon(Ej);
        E = cloneTableauDynamique(Ej, cloneEtat);
    }
    afficheTableauDynamique(E, afficheEtat, "Ensemble\n");
    return minDeLensemble(E);
}

/* Exo 3 */

void modifierInstanceFPTAS(Instance* instance)
{
    // TODO corps algo exo 3
}

/* Exo 4 */

// TODO corps algo exo 4