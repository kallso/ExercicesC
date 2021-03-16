#include <stdio.h>
#include <string.h>

int main() {
    int year = 0;
    char *choice = NULL;

    do {
        printf("Année : ");
        scanf("%d", &year);

        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            printf("Cette année est bissextile.");
        } else {
            printf("Cette année n'est pas bissextile.");
        }
        printf("\n");

        do {
            printf("Voulez-vous recommencer(o/n) ? ");
            scanf("%ms", &choice);
        } while (*choice != 'o' && *choice != 'O' && *choice != 'n' && *choice != 'N');

    } while (*choice != 'n' && *choice != 'N');

    return 0;
}
