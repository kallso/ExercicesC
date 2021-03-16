#include <stdio.h>

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

    if (donneePhisio1.age <= 16 && donneePhisio1.coeffPoids > 27.3
        || donneePhisio1.age > 16 && donneePhisio1.age <= 48 && donneePhisio1.coeffPoids > 23
        || donneePhisio1.age > 48 && donneePhisio1.coeffPoids > 21.5)
    {
        printf("Votre C = %.1f et, pour votre age de %hi ans, votre taille de %.2f et votre poids de %.1f, vous êtes en surpoids. \n",
               donneePhisio1.coeffPoids, donneePhisio1.age, donneePhisio1.taille, donneePhisio1.poids);
    } else {
        printf("Votre C = %.1f et, pour votre age de %hi ans, votre taille de %.2f et votre poids de %.1f, vous avez un poids normal. \n",
               donneePhisio1.coeffPoids, donneePhisio1.age, donneePhisio1.taille, donneePhisio1.poids);
    }
}
