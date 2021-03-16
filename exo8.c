#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[])  {
    char *userInput = NULL;

    if (argc < 2) {
        char *buffer = NULL;
        printf("Veuillez entrer un parametre : ");
        scanf("%ms", &buffer);
        userInput = buffer;
    } else {
        userInput = argv[1];
    }

    bool isPalindrome = true;

    int userInputLength = (int) strlen(userInput);

    for (int i = 0; i < userInputLength;) {
        for (int j = userInputLength - 1; j >= 0; j--) {
            if (userInput[i] != userInput[j]) {
                isPalindrome = false;
                goto loopsEnd;
            }
            i++;
        }
    }
    loopsEnd:

    if (isPalindrome) printf("%s est un palindrome. \n", userInput);
    else printf("%s n'est pas un palindrome. \n", userInput);

    return 0;
}
