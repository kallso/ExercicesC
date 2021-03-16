#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])  {
    double result = 0;

    for (int i = 1; i < argc; ++i) {
        result += atof(argv[i]);
    }

    if (result != 0) result /= argc - 1;

    printf("La moyenne est : %f \n", result);
}
