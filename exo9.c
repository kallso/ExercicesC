#include <stdio.h>
#include <string.h>

int main() {
    long number = 0;
    char *choice = NULL;

    do {
        printf("Entrez votre nombre : ");
        scanf("%ld", &number);

        if (number % 2 == 1) printf("impair");
        else printf("pair");

        printf("\n");

        do {
            printf("Voulez-vous continuer(o/n) ? ");
            scanf("%ms", &choice);
        } while (*choice != 'o' && *choice != 'n');

    } while (*choice != 'n');

    return 0;
}
