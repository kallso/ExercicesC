#include <stdio.h>
#include <stdbool.h>

typedef struct {
    float poids;
    float taille;
    short age;
    float coeffPoids;
} donneePhisio;

int main() {

    donneePhisio donneePhisio1;

    printf("Renseigner votre poids en Kg: \n");
    scanf("%f", &donneePhisio1.poids);

    printf("Renseigner votre taille en M: \n");
    scanf("%f", &donneePhisio1.taille);

    printf("Renseigner votre Age :\n");
    scanf("%hd", &donneePhisio1.age);

    donneePhisio1.coeffPoids = donneePhisio1.poids / (donneePhisio1.taille * donneePhisio1.taille);

    bool surpoids = false;

    switch (donneePhisio1.age) {
        case 0 ... 16 :
            if (donneePhisio1.coeffPoids > 27.3) surpoids = true;
            break;
        case 17 ... 48 :
            if (donneePhisio1.coeffPoids > 23) surpoids = true;
            break;
        default :
            if (donneePhisio1.coeffPoids > 21.5) surpoids = true;
    }

    if (surpoids) {
        printf("Votre C = %.1f et, pour votre age de %hi ans, votre taille de %.2f et votre poids de %.1f, vous êtes en surpoids. \n",
               donneePhisio1.coeffPoids, donneePhisio1.age, donneePhisio1.taille, donneePhisio1.poids);
    } else {
        printf("Votre C = %.1f et, pour votre age de %hi ans, votre taille de %.2f et votre poids de %.1f, vous avez un poids normal. \n",
               donneePhisio1.coeffPoids, donneePhisio1.age, donneePhisio1.taille, donneePhisio1.poids);
    }
}
