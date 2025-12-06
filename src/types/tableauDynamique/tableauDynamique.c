//
// Created by MEGACHEESEKEBAB on 06/12/2025.
//
#include <stdlib.h>
#include <assert.h>

#include "tableauDynamique.h"

TableauDynamique* newTableauDynamique()
{
    TableauDynamique* newTab = calloc(1, sizeof(TableauDynamique));
    assert(newTab);

    newTab->T = calloc(1, sizeof(void*));
    assert(newTab->T);

    newTab->taille = 1;
    return newTab;
}

void* getElementTableauDynamique(const TableauDynamique* tab,
                                 unsigned int position)
{
    assert(tab && tab->T);
    assert(position < tab->tailleEffectif);
    return tab->T[position];
}

unsigned int getTailleTableauDynamique(const TableauDynamique* tab)
{
    assert(tab);
    return tab->taille;
}

unsigned getTailleEffectifTableauDynamique(const TableauDynamique* tab)
{
    assert(tab);
    return tab->tailleEffectif;
}

int tableauDynamiqueEstPlein(const TableauDynamique* tab)
{
    assert(tab);
    return tab->tailleEffectif == tab->taille;
}

int tableauDynamiqueEstPresqueVide(const TableauDynamique* tab)
{
    assert(tab);
    return tab->tailleEffectif < (tab->taille / 4);
}

int tableauDynamiqueEstVide(const TableauDynamique* tab)
{
    assert(tab);
    return tab->tailleEffectif == 0;
}

void setElementTableauDynamique(const TableauDynamique* tab,
                                unsigned int position, void* nouvelElement)
{
    assert(tab && tab->T);
    assert(position < tab->taille);
    tab->T[position] = nouvelElement;
}

void setTailleTableauDynamique(TableauDynamique* tab,
                               unsigned int nouvelleTaille)
{
    assert(tab);
    tab->taille = nouvelleTaille;
}

void incrementeTailleEffectifTableauDynamique(TableauDynamique* tab)
{
    assert(tab);
    assert(!tableauDynamiqueEstPlein(tab));
    tab->tailleEffectif++;
}

void decrementeTailleEffectifTableauDynamique(TableauDynamique* tab)
{
    assert(tab);
    assert(!tableauDynamiqueEstVide(tab));
    tab->tailleEffectif--;
}