#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int le_valida_num() {
    int num;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("Informe um número ímpar que não seja múltiplo de 3: ");
        scanf("%d", &num);
        if (num < 1 || num > 99 || num % 3 == 0) {
            printf("Número inválido. Tente novamente.\n");
        }
    } while (num < 1 || num > 99 || num % 3 == 0);
    return num;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    const int MIN_NUM = 10;
    const int MAX_NUM = 20;
    int numeros[MAX_NUM], n = 0;

    printf("Informe %d a %d números inteiros (ou digite 0 para sair):\n", MIN_NUM, MAX_NUM);

   
    int i;
    for (i = 0; i < MAX_NUM; i++) {
        numeros[i] = le_valida_num();
        if (numeros[i] == 0)
            break; 
        if (i == (MIN_NUM - 1)) {
            printf("Você já informou o mínimo de 10 números. Deseja continuar? (s/n)\n");
            char op;
            scanf(" %c", &op);
            if (op == 'n' || op == 'N')
                break;
        }
    }

    n = i; 

   
    for (int i = 1; i < n; i++) {
        int chave = numeros[i];
        int j = i - 1;
        while (j >= 0 && numeros[j] < chave) {
            numeros[j + 1] = numeros[j];
            j--;
        }
        numeros[j + 1] = chave;
    }

    printf("Números ordenados de forma decrescente: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}

