#include <stdio.h>
#define CONSTANTE1 100
const int CONSTANTE2 = 10;

int main( void ) {
    const int CONSTANTE3 = 31;
    int tab1[4]={ 1, 2, 3, 5 };
    int v1 = 7;
    int v2 = 9;
    int tab2[4]={ 11, 13, 17, 19 };

    printf("CONSTANTE1 : %i \n", CONSTANTE1);
    // CONSTANTE1 est definie grace a une macro (#define) qui remplacera toutes les occurences de CONSTANTE1 dans
    // le code par la valeur associée lors de la phase de prepocesseur.
    printf("CONSTANTE2 : %i \n", CONSTANTE2);
    // CONSTANTE2 est une constante global.
    printf("CONSTANTE3 : %i \n", CONSTANTE3);
    // CONSTANTE3 est une constante local.

    // CONSTANTE1 = 0; // impossible : CONSTANTE1 n'est pas une variable, c'est un marqueur pour la macro #define, on
    // ne peut rien lui affecter.

    // CONSTANTE2 = 0; // CONSTANTE2 est une constante, on ne peux pas changer sa valeur.

    // CONSTANTE3 = 0; // CONSTANTE2 est une constante, on ne peux pas changer sa valeur.

    int *pCONSTANTE1, *pCONSTANTE2, *pCONSTANTE3;

    // pCONSTANTE1 = &CONSTANTE1;
    /* CONSTANTE1 sera remplacer par 100 par le preprocesseur.
    Il est donc incorect d'essayer de recuperer l'adresse d'un int (ce n'est pas une variable). */

    //pCONSTANTE2 = &CONSTANTE2;
    /* Cette assignation genere un warning car le compilateur detecte deja qu'un pointeur
     * qui n'est pas const pointe sur une constante, ce qui ouvre la possiblité d'acceder a la constante en ecriture.
     */
    // *pCONSTANTE2 = 2021;
    /* On essaie d'ecrire dans l'emplacement memoire pointé par la constante et notre pointeur.
     * Cette emplacement est en memoire read-only puisque il a etait attribué en premier lieu en tant que constante GLOBAL.
     * Le systeme d'exploitation remarque alors notre maneouvre illégale sur la memoire et nous tue en nous envoyant un
     * Signal: SIGSEGV (Segmentation fault). (punition pour avoir essayé une manoeuvre illegal en memoire). */

    pCONSTANTE3 = &CONSTANTE3;
    /* Cette assignation genere aussi un warning car le compilateur detecte deja qu'un pointeur
     * qui n'est pas const pointe sur une constante, ce qui ouvre la possiblité d'acceder a la constante en ecriture.*/
    *pCONSTANTE3 = 2021;
    /* On essaie d'ecrire dans l'emplacement memoire pointé par la constante et notre pointeur.
     * et ON Y ARRIVE ! Car, étant une variable locale, elle est déclarée sur la stack et est donc modifiable.
     * Le systeme d'exploitation ne remarque rien du tout, tout est normal selon lui. */
    printf("CONSTANTE3 : %i \n", CONSTANTE3); // CONSTANTE3 est maintenant 2021.

    for (int i = 0; i < 11; ++i) {
        printf("tab1[%i] = %p : %i \n", i, &tab1[i], tab1[i]);
    }

    /* On constate deja que le langage C n'a aucune protection par defaut contre les accés en dehors des limites d'un
     * tableau contrairement a Java ou JavaScript par exemple.
     *  On recupere les 4 premieres valeurs sont bien celles du tableau donc pas de soucis.
     *  On recupere ensuite les 4 valeurs tableau tab2 car les elements de tab2 sont consecutifs en memoire avec tab1,
     *  ce qui laisse sugerer que tout les tableaux sont stocker en
     *  memoire de facon consecutive en memoire et pas au meme endroit que les autres types de variables
     *  (non consecutives) car on ne voit ni v1 ni v2.
     *  Les 3 derniers acces remonte des valeurs quelconque qui on l'air d'etre des adresses memoire.
     *  On remarque aussi que tab1[n] est equivalent a  *tab + n car on voit bien que cette syntaxe n'opere en fait
     *  qu'a un decalage depuis l'adresse du premier element du tableau (pointeur tab1).
     */
}
