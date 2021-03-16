#include <stdio.h>

int main() {
    char *question = "Quelle est la plus belle ville de France ?";
    char *reponses[] = {"Vannes", "Oyonnax", "Soyaux Angouleme", "Toulouse"};

    printf("%s \n", question);

    for (int i = 0; i < 4; ++i) {
        printf("%d : %s\n", i + 1, reponses[i]);
    }

    int choix;
    printf("Le numero de votre reponse : ");
    scanf("%d", &choix);

    if (reponses[choix - 1] == reponses[3]) {
        printf("Evidemment ... Bravo !");
    } else {
        printf("Enfin ... mauvaise reponse.");
    }

}
