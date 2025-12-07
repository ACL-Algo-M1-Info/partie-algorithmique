//
// Created by MEGACHEESEKEBAB on 06/12/2025.
//

// INCLUSIONS

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "tableauDynamique.h"

// FONCTIONS

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

void deleteTableauDynamique(TableauDynamique* tab,
                            void (*deleteElement)(void*))
{
    assert(tab && tab->T);

    if (deleteElement)
    {
        for (int i = 0; i < tab->tailleEffectif; i++)
        {
            deleteElement(getElementTableauDynamique(tab, i));
        }
    }

    free(tab->T);
    free(tab);
}

void afficheTableauDynamique(const TableauDynamique* tab,
                             void (*afficheElement)(const void*),
                             const char* nomStructure)
{
    assert(tab);

    printf("%s[taille = %d, taille_effectif = %d, T = [", nomStructure,
           getTailleTableauDynamique(tab),
           getTailleEffectifTableauDynamique(tab));

    for (int i = 0; i < getTailleEffectifTableauDynamique(tab); i++)
    {
        afficheElement(getElementTableauDynamique(tab, i));

        if (i < getTailleEffectifTableauDynamique(tab) - 1)
        {
            printf(", ");
        }
    }
    printf("]]");
}

int tableauxDynamiquesEgaux(const TableauDynamique* a,
                            const TableauDynamique* b,
                            int (*comp)(const void*, const void*))
{
    assert(a && b && comp);

    // Tailles inégales
    if (getTailleEffectifTableauDynamique(a) !=
        getTailleEffectifTableauDynamique(b))
        return 0;

    // Egalité par elm
    for (int i = 0; i < getTailleEffectifTableauDynamique(a); i++)
        if ((*comp)(getElementTableauDynamique(a, i),
                    getElementTableauDynamique(b, i)) == 0)
            return 0;

    return 1;
}


/**
 * Double la taille du tableau T
 * @param tab
 */
static void dedoubleTaille(TableauDynamique* tab)
{
    assert(tab);
    tab->T = realloc(tab->T, tab->taille * 2 * sizeof(void*));
    assert(tab->T);
    tab->taille *= 2;
}

static void diviseTaille(TableauDynamique* tab)
{
    assert(tab);
    tab->T = realloc(tab->T, (tab->taille / 2) * sizeof(void*));
    assert(tab->T);
    tab->taille /= 2;
}

void insereElementTableauDynamique(TableauDynamique* tab, void* element)
{
    assert(tab && tab->T);
    if (tableauDynamiqueEstPlein(tab))
    {
        dedoubleTaille(tab);
    }
    setElementTableauDynamique(tab, getTailleEffectifTableauDynamique(tab),
                               element);
    incrementeTailleEffectifTableauDynamique(tab);
}

void* retireElementTableauDynamique(TableauDynamique* tab)
{
    assert(tab);
    assert(tab->T);
    void* element = getElementTableauDynamique(
        tab, getTailleEffectifTableauDynamique(tab) - 1);
    setElementTableauDynamique(tab, getTailleEffectifTableauDynamique(tab) - 1,
                               NULL);
    decrementeTailleEffectifTableauDynamique(tab);
    if (tableauDynamiqueEstPresqueVide(tab))
    {
        diviseTaille(tab);
    }
    return element;
}

void swapElementTableauDynamique(TableauDynamique* tab, unsigned int pos1,
                                 unsigned int pos2)
{
    assert(tab);
    assert(
        pos1 < getTailleEffectifTableauDynamique(tab) && pos2 <
        getTailleEffectifTableauDynamique(tab));

    void* aux = getElementTableauDynamique(tab, pos1);
    setElementTableauDynamique(tab, pos1,
                               getElementTableauDynamique(tab, pos2));
    setElementTableauDynamique(tab, pos2, aux);
}

TableauDynamique* cloneTableauDynamique(const TableauDynamique* tab,
                                        void*(*cloneurElement)(const void*))
{
    assert(tab && tab->T);

    TableauDynamique* cloneTab = newTableauDynamique();

    if (cloneurElement)
    {
        for (int i = 0; i < getTailleEffectifTableauDynamique(tab); i++)
        {
            insereElementTableauDynamique(cloneTab, cloneurElement(tab->T[i]));
        }
    }

    return cloneTab;
}