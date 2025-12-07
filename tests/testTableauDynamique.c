//
// Created by MEGACHEESEKEBAB on 06/12/2025.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "../src/types/tableauDynamique/tableauDynamique.h"
#include "../src/utils/utils.h"

void afficheEntier(const void* i)
{
    if (i == NULL)
    {
        printf("NULL");
    }
    else
    {
        int a = *(int*)i;
        printf("%d", a);
    }
}

void* cloneEntier(const void* i)
{
    int* entierAcloner = (int*)i;
    int* clone = malloc(sizeof(int));
    *clone = *entierAcloner;
    return clone;
}

void lancerTest(const char* nomFonction, void (*testFonction)())
{
    printf("Lancement tests sur %s \n", nomFonction);
    testFonction();
    printf("Les tests de %s se sont bien deroules ! \n\n", nomFonction);
}

void testCreationTableauDynamique()
{
    int* i1 = malloc(sizeof(int));
    *i1 = 7;
    TableauDynamique* tab = newTableauDynamique();
    assert(tab->tailleEffectif == 0 && tab->taille == 1);
    tab->T[0] = i1;
    incrementeTailleEffectifTableauDynamique(tab);
    assert(tab->tailleEffectif == 1);
    assert(getElementTableauDynamique(tab,0)==i1);
    free(i1);
}

void testGetteursSetteursTableauDynamique()
{
    int* i1 = malloc(sizeof(int));
    *i1 = 7;
    int* i2 = malloc(sizeof(int));
    *i2 = 4;

    TableauDynamique* tab = newTableauDynamique();

    setElementTableauDynamique(tab, 0, i1);
    incrementeTailleEffectifTableauDynamique(tab);
    assert(getElementTableauDynamique(tab,0) == i1);
    assert(tableauDynamiqueEstPlein(tab));
    assert(getTailleEffectifTableauDynamique(tab) == 1);
    assert(getTailleTableauDynamique(tab)==1);

    setTailleTableauDynamique(tab, 2);
    setElementTableauDynamique(tab, 1, i2);
    incrementeTailleEffectifTableauDynamique(tab);
    assert(getElementTableauDynamique(tab,1)==i2);
    assert(tableauDynamiqueEstPlein(tab));
    assert(getTailleEffectifTableauDynamique(tab)==2);
    assert(getTailleTableauDynamique(tab)==2);

    setTailleTableauDynamique(tab, 100);
    assert(tableauDynamiqueEstPresqueVide(tab));

    free(i1);
    free(i2);
}

void testInsertTableauDynamique()
{
    int* i1 = malloc(sizeof(int));
    *i1 = 7;
    int* i2 = malloc(sizeof(int));
    *i2 = 4;

    TableauDynamique* tab = newTableauDynamique();

    insereElementTableauDynamique(tab, i1);
    assert(getTailleEffectifTableauDynamique(tab)==1);
    assert(getElementTableauDynamique(tab,0)==i1);
    assert(getTailleTableauDynamique(tab)==1);
    // afficheTableauDynamique(tab, afficheEntier);

    insereElementTableauDynamique(tab, i2);
    assert(getTailleEffectifTableauDynamique(tab)==2);
    assert(getElementTableauDynamique(tab,1)==i2);
    assert(getTailleTableauDynamique(tab)==2);
    // afficheTableauDynamique(tab, afficheEntier);

    free(i1);
    free(i2);
    // deleteTableauDynamique(tab,NULL);
}


void testcloneTableauDynamique()
{
    int* i1 = malloc(sizeof(int));
    *i1 = 7;
    int* i2 = malloc(sizeof(int));
    *i2 = 4;

    int* i3 = malloc(sizeof(int));
    *i3 = -99;
    TableauDynamique* tab = newTableauDynamique();
    insereElementTableauDynamique(tab, i1);
    insereElementTableauDynamique(tab, i2);

    TableauDynamique* clone = cloneTableauDynamique(tab, cloneInt);
    assert(getElementTableauDynamique(clone,0)!=i1);
    assert(getElementTableauDynamique(clone,1)!=i2);
    setElementTableauDynamique(tab, 0, i3);
    assert(getElementTableauDynamique(clone,0)!=i3);
    assert(getElementTableauDynamique(clone,1)!=i2);

    assert(getElementTableauDynamique(tab,0)==i3);
    assert(getElementTableauDynamique(tab,1)==i2);
    // afficheTableauDynamique(clone, afficheEntier);
    // afficheTableauDynamique(tab,afficheEntier);
}

int main()
{
    lancerTest("testCreationTableauDynamique", testCreationTableauDynamique);
    lancerTest("testGetteursSetteursTableauDynamique",
               testGetteursSetteursTableauDynamique);
    lancerTest("testInsertTableauDynamique", testInsertTableauDynamique);
    lancerTest("testcloneTableauDynamique", testcloneTableauDynamique);
    return 0;
}
