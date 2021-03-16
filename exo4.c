#include <stdio.h>

typedef struct {
    char *question;
    char *reponses[4];
    short bonneReponse;
} questionnaireElement;

int main() {

    questionnaireElement question1 = {
            "Quelle est la specialité du village d'Asté ?",
            {"La bannane", "L'echalotte", "Le parapente", "La tourte"},
            4,
    };
    questionnaireElement question2 = {
            "Quelle est la plus belle ville de France ?",
            {"Asté", "Toulouse", "Nice", "Tarbes"},
            2,
    };
    questionnaireElement question3 = {
            "Chocolatine ou pain au chocolat ?",
            {"Chocolatine", "Pain au chocolat", "petit pain", "brioche avec du chocolat dedans"},
            1,
    };
    questionnaireElement question4 = {
            "Le meilleur sport ?",
            {"Le rugby", "Le basket", "Le parapente", "Le curling"},
            1,
    };

    questionnaireElement questionnaire[] = { question1, question2, question3, question4 };

    int index = 0, total = 0;
    size_t tailleQuestionnaire =  sizeof(questionnaire) / sizeof(questionnaireElement);

    do {
        questionnaireElement element = questionnaire[index];
        char **reponses = questionnaire[index].reponses;

        printf("%s\n", element.question);

        for (int i = 0; i < tailleQuestionnaire; ++i) {
            printf("%d : %s\n", i + 1, reponses[i]);
        }

        short choix;
        printf("Le numero de votre reponse : ");
        scanf("%hd", &choix);

        printf("\n");

        if (reponses[choix - 1] == reponses[element.bonneReponse - 1]) {
            printf("Bonne reponse ! BRAVO !!!");
            total++;
        } else {
            printf("Mauvaise reponse");
        }
        printf("\n\n");

        index++;
    } while (index < tailleQuestionnaire);

    printf("Nombre de bonnes reponses : %d \n", total);
    printf("Nombre de mauvaises reponses : %zu \n", tailleQuestionnaire - total);
}

