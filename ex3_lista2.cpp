#include <stdio.h>
#include <locale.h>

int le_valida_num() {
	setlocale(LC_ALL, "Portuguese");
    int num;
    
    do {
        printf("Informe um número par que não seja múltiplo de 5 (entre 1 e 99): ");
        scanf("%d", &num);
        if (num < 1 || num > 99 || num % 2 != 0 || num % 5 == 0) {
            printf("Número inválido. Tente novamente.\n");
        }
    } while (num < 1 || num > 99 || num % 2 != 0 || num % 5 == 0);
    return num;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    const int MIN_NUM = 2;
    const int MAX_NUM = 10;
    int numeros[MAX_NUM];
    int quantidade_numeros = 0;

    printf("Informe no mínimo %d e no máximo %d números inteiros.\n", MIN_NUM, MAX_NUM);
    printf("Digite '0' para encerrar a leitura.\n");

    
    int i;
    for (i = 0; i < MAX_NUM; i++) {
        numeros[i] = le_valida_num();
        if (numeros[i] == 0) break; 
        quantidade_numeros++;
        if (quantidade_numeros == MIN_NUM) {
            printf("Você já informou o mínimo de %d números. Deseja continuar? (s/n)\n", MIN_NUM);
            char op;
            scanf(" %c", &op);
            if (op == 'n' || op == 'N') break;
        }
    }

    
    for (i = 0; i < quantidade_numeros - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < quantidade_numeros; j++) {
            if (numeros[j] < numeros[min_idx]) {
                min_idx = j;
            }
        }
        int temp = numeros[min_idx];
        numeros[min_idx] = numeros[i];
        numeros[i] = temp;
    }

    for (i = 0; i < quantidade_numeros - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < quantidade_numeros; j++) {
            if (numeros[j] > numeros[max_idx]) {
                max_idx = j;
            }
        }
        int temp = numeros[max_idx];
        numeros[max_idx] = numeros[i];
        numeros[i] = temp;
    }

   printf("Números ordenados em ordem crescente: ");
    for (i = quantidade_numeros - 1; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
   printf("\n");
   
  
   
    printf("Números ordenados em ordem decrescente: ");
    for (i = 0; i < quantidade_numeros; i++) {
        printf("%d ", numeros[i]);
    }
    

    
}
