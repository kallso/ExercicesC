#include <stdio.h>

int main() {
    int values[] = {20, 12, 15};
    double result = 0;

    for (int i = 0; i < 3; ++i) {
        result += values[i];
    }
    result /= 3;

    printf("La moyenne est : %.2f", result);
}
