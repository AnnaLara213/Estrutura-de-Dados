#include <stdio.h>

void trocarValores(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    printf("Valores antes da troca: x = %d, y = %d\n", x, y);

    trocarValores(&x, &y);

    printf("Valores depois da troca: x = %d, y = %d\n", x, y);

    return 0;
}

