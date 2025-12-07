//
// Created by MEGACHEESEKEBAB on 06/12/2025.
//

#ifndef ALGORITHMIE_TABLEAUDYNAMIQUE_H
#define ALGORITHMIE_TABLEAUDYNAMIQUE_H

// STRUCTURES

/**
 * Structure représentant un tableau dynamique
 */
typedef struct _tableauDynamique
{
    /** Taille du tableau **/
    unsigned int taille;

    /** Nombre d'élément dans le tableau **/
    unsigned int tailleEffectif;

    /** Tableau de pointeurs vers des donnéées de type void **/
    void** T;
} TableauDynamique;

// FONCTIONS

/**
 * Crée un nouveau tableau dynamique.
 * @return un tableau dynamique de taille 1 et de taille effectif 0.
 */
TableauDynamique* newTableauDynamique();

/**
 * Retourne l'élément qui se trouve en pos = position.
 * La position doit être < taille effectif.
 * @param tab
 * @param position
 * @return l'élément du tableau à la pos : position.
 */
void* getElementTableauDynamique(const TableauDynamique* tab,
                                 unsigned int position);

/**
 * Retourne la taille réel du tableau.
 * @param tab
 * @return la taille du tableau tab.
 */
unsigned int getTailleTableauDynamique(const TableauDynamique* tab);

/**
 * Retourne le nombre d'élément que contient le tableau.
 * @param tab
 * @return la taille effectif de tab.
 */
unsigned getTailleEffectifTableauDynamique(const TableauDynamique* tab);

/**
 * Retourne 1 si tab est plein.
 * @param tab
 * @return vrai si tab est rempli.
 */
int tableauDynamiqueEstPlein(const TableauDynamique* tab);

/**
 * Retourne 1 si le tableau tab contient moins que taille/4 éléments.
 * @param tab
 * @return 1 si le tableau tab contient moins que taille/4 éléments.
 */
int tableauDynamiqueEstPresqueVide(const TableauDynamique* tab);

/**
 * Retourne 1 si le tableau ne contient pas d'élément.
 * @param tab
 * @return 1 si le tableau ne contient pas d'élément.
 */
int tableauDynamiqueEstVide(const TableauDynamique* tab);

/**
 * Remplace l'élément de position de tab par newElement
 * @param tab
 * @param position
 * @param nouvelElement
 */
void setElementTableauDynamique(const TableauDynamique* tab,
                                unsigned int position, void* nouvelElement);

/**
 * Remplace l'ancienne taille de tab par nouvelleTaille
 * @param tab
 * @param nouvelleTaille
 */
void setTailleTableauDynamique(TableauDynamique* tab,
                               unsigned int nouvelleTaille);

/**
 * Incrémente le nombre de case utilisée du tableau de 1
 * @param tab
 */
void incrementeTailleEffectifTableauDynamique(TableauDynamique* tab);

/**
 * Décrémente le nombre de case utilisée du tableau de 1
 * @param tab
 */
void decrementeTailleEffectifTableauDynamique(TableauDynamique* tab);

/**
 * Si deleteElement n'est pas null alors il libérera aussi les éléments du tableau T
 * Sinon ce ne sera pas le cas
 * Dans tous les cas, le tableau T et la structure elle même sont libérés
 * @param tab
 */
void deleteTableauDynamique(TableauDynamique* tab,
                            void (*deleteElement)(void*));

/**
 * Retourne le clone de tab
 * clone chaque élément du tableau grâce au pointeur de fonction associé
 *
 * @param tab
 * @return le clone de tab
 */
TableauDynamique* cloneTableauDynamique(const TableauDynamique* tab,
                                        void*(*cloneurElement)(void*));
/**
 * Affiche les éléments du tableau dynamique tab.
 * les données de chaque case du tableau est affichée grâce au pointeur de fonction afficheElement
 * @param tab
 * @param afficheElement
 */
void afficheTableauDynamique(const TableauDynamique* tab,
                             void (*afficheElement)(const void*));

/**
 * Compare deux tableaux dynamiques.
 * @param a Tableau a.
 * @param b Tableau b.
 * @param comp Fonction de comparaison entre les éléments.
 * @return 1 si égaux, 0 sinon.
 */
int tableauxDynamiquesEgaux(const TableauDynamique* a, const TableauDynamique* b, int (*comp)(const void*, const void*));

/**
 * Insère à la première position disponible un nouvel élément.
 * Si le tableau est déjà rempli, la taille du tableau est doublé avant
 * @param tab
 * @param element
 */
void insereElementTableauDynamique(TableauDynamique* tab, void* element);


#endif //ALGORITHMIE_TABLEAUDYNAMIQUE_H