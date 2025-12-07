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


double minDeLensemble(const TableauDynamique* E)
{
    Etat* e = getElementTableauDynamique(E, 0);
    double min = e->lmax;

    for (int i = 1; i < getTailleEffectifTableauDynamique(E); i++)
    {
        Etat* ei = getElementTableauDynamique(E, i);
        if (min > ei->lmax)
        {
            min = ei->lmax;
        }
    }
    return min;
}

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
    afficheTableauDynamique(E,afficheEtat);
    return minDeLensemble(E);
}

/* Exo 3 */

void modifierInstanceFPTAS(Instance* instance, double e)
{
    // On applique la formule de rastérisation selon delta.
    // Delta vaut (e*qmax)/(N+1).

    double qmax = obtenirQmax(instance);
    double delta = (e * qmax) / (instance->n + 1);

    // Application à chaque p(i) et q(i) de la rastérisation inférieure sur delta.
    for (int i = 0; i < instance->n; i++)
    {
        instance->p[i] = rasteriserInferieur(instance->p[i], delta);
        instance->q[i] = rasteriserInferieur(instance->q[i], delta);
    }
}

/* Exo 4 */

// TODO corps algo exo 4
