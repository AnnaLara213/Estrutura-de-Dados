#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void valor(int x); // Declaração da função “valor”
void referencia(int *x); // Declaração da função “referencia”

int main() {
	setlocale(LC_ALL, "Portuguese");
    
    int num = 5; // Inicialização da variável “num”
    
    printf("Valor original: %d\n", num);
    
    valor(num); // Chama a função por valor
    printf("Após passagem por valor: %d\n", num);
    
    referencia(&num); // Chama a função por referência
    printf("Valor após passagem por referência: %d\n", num);
    
    return 0;
}

void valor(int x) {
    x = 10; // Modifica a cópia local de 'x'
    printf("Dentro da função (passagem por valor): %d\n", x);
}

void referencia(int *x) {
    *x = 10; // Modifica o valor apontado por 'x'
    printf("Dentro da função (passagem por referência): %d\n", *x);
}
