//
// Created by maxen on 06/12/2025.
//

// INCLUSIONS

#include "algo.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "types/etatRobot/etatRobot.h"
#include "utils/utils.h"

// FONCTIONS

/* Exo 2 */

// TODO corps algo exo 2

/* Exo 3 */

void modifierInstanceFPTAS(Instance* instance)
{
    // TODO corps algo exo 3
}

/* Exo 4 */

double ordonnancementRobot(Instance* instance, OrdonnancementMachine** ordonnancementMachine, double e)
{
    if ( e < 0 )
        return -1;

    //On calcule le nombre de lignes et de colonnes pour FPTAS
    double P = 0;
    double Q = 0;
    for (int i = 0; i < instance->n; i++)
    {
        P += instance->p[i];
        Q += instance->q[i];
    }

    double tailleCarre = (e * (P + Q)) / (2 * instance->n);
    int nbLignesCol = (P + Q) / tailleCarre;
    nbLignesCol = ceil(nbLignesCol);

    printf("\nNbLignes et col : %d \n", nbLignesCol);
    printf("\nTaille carré : %lf \n", tailleCarre);

    //Fin calcule

    //Rassemblement des ordonnancements sur les différentes machines en un seul vecteur trié par date de début au plus tôt croissante
    Instance* newInstance = cloneInstance(instance);

    triDateDebutCroissante(instance, newInstance, ordonnancementMachine);

    //Début de l'algorithme
    //Etat initial
    EtatRobot* e0 = newEtatRobot(2);

    printf("\nAffiche etat : \n");
    afficheEtatRobot(e0);
    printf("\nFin Affiche etat \n");

    TableauDynamique* ensembleEtat = newTableauDynamique();
    insereElementTableauDynamique(ensembleEtat, e0);
    //Fin etat initial


    for (int i = 0; i < newInstance->n; i++)
    {
        unsigned int nbElEnsemblePrecedent = getTailleEffectifTableauDynamique(ensembleEtat);
        for (int j = 0; j < nbElEnsemblePrecedent; j++)
        {
            EtatRobot* etatCourant = getElementTableauDynamique(ensembleEtat, j);
            EtatRobot* nouvelEtat = cloneEtatRobot(etatCourant);
            ajouterTacheSurRobotParInstance(etatCourant, 0, i, newInstance);
            ajouterTacheSurRobotParInstance(nouvelEtat, 1, i, newInstance);
            insereElementTableauDynamique(ensembleEtat, nouvelEtat);
        }

        //Suppression des doublons
        unsigned int nbElEnsemble = getTailleEffectifTableauDynamique(ensembleEtat);
        TableauDynamique* nouveauxEtats = newTableauDynamique();
        TableauDynamique* etatASupp = newTableauDynamique();

        for (int j = 0; j < nbElEnsemble; j++)
        {
            EtatRobot* etatCourant = getElementTableauDynamique(ensembleEtat, j);

            bool isSupp = false;
            int sizeSupp = getTailleEffectifTableauDynamique(etatASupp);
            for (int k = 0; k < sizeSupp; k++)
            {
                if (getElementTableauDynamique(etatASupp, k) == etatCourant)
                {
                    isSupp = true;
                    break;
                }
            }

            if (isSupp)
                continue;

            int cMax1 = etatCourant->ordonnancements[0]->cmax;
            int cMax2 = etatCourant->ordonnancements[1]->cmax;

            for (int k = j + 1; k < nbElEnsemble; k++)
            {
                EtatRobot* etatSuivant = getElementTableauDynamique(ensembleEtat, k);
                int cMax12 = etatSuivant->ordonnancements[0]->cmax;
                int cMax22 = etatSuivant->ordonnancements[1]->cmax;

                if ((cMax1 == cMax12 && cMax2 == cMax22) || (cMax2 == cMax12 && cMax1 == cMax22))
                {
                    insereElementTableauDynamique(etatASupp, etatSuivant);
                }
            }

            insereElementTableauDynamique(nouveauxEtats, etatCourant);
        }
        //Fin suppression des doublons

        //Conserver un seul état par zone

        EtatRobot* tab[nbLignesCol][nbLignesCol];

        for (int j = 0; j < nbLignesCol; j++)
        {
            for (int k = 0; k < nbLignesCol; k++)
            {
                tab[j][k] = NULL;
            }
        }

        unsigned int nbElNouveau = getTailleEffectifTableauDynamique(nouveauxEtats);
        for (int j = 0; j < nbElNouveau; j++)
        {
            EtatRobot* etat = getElementTableauDynamique(nouveauxEtats, j);

            int a = etat->ordonnancements[0]->cmax;
            int b = etat->ordonnancements[1]->cmax;

            int col = imax(0, ceil(a / tailleCarre));
            int ligne = imax(0, ceil(b / tailleCarre));

            EtatRobot* etatCompare = tab[ligne][col];
            if (etatCompare == NULL)
            {
                tab[ligne][col] = etat;
            }
            else
            {
                if (etatCompare->ordonnancements[0]->cmax > etat->ordonnancements[0]->cmax)
                {
                    insereElementTableauDynamique(etatASupp, tab[ligne][col]);
                    tab[ligne][col] = etat;
                }
                else
                {
                    insereElementTableauDynamique(etatASupp, etat);
                }
            }
        }

        TableauDynamique * tabFPTAS = newTableauDynamique();
        for (int j = 0; j < nbLignesCol; j++)
        {
            for (int k = 0; k < nbLignesCol; k++)
            {
                EtatRobot* etatCompare = tab[j][k];
                if (etatCompare != NULL)
                {
                    insereElementTableauDynamique(tabFPTAS, tab[j][k]);
                }
            }
        }

        //Fin un état par zone

        deleteTableauDynamique(etatASupp, deleteEtatRobot);
        deleteTableauDynamique(ensembleEtat, NULL);
        deleteTableauDynamique(nouveauxEtats, NULL);

        ensembleEtat = tabFPTAS;
    }

    unsigned int nbElEnsemble = getTailleEffectifTableauDynamique(ensembleEtat);
    EtatRobot* etatCourant = getElementTableauDynamique(ensembleEtat, 0);
    double res = etatCourant->cMax;

    for (int i = 1; i < nbElEnsemble; i++)
    {
        EtatRobot* etatSuivant = getElementTableauDynamique(ensembleEtat, i);
        res = fmin(res, etatSuivant->cMax);
    }

    deleteTableauDynamique(ensembleEtat, deleteEtatRobot);

    return res;
}