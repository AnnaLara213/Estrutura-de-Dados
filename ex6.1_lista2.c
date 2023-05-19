#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void valor(int x); // Declara��o da fun��o �valor�
void referencia(int *x); // Declara��o da fun��o �referencia�

int main() {
	setlocale(LC_ALL, "Portuguese");
    
    int num = 5; // Inicializa��o da vari�vel �num�
    
    printf("Valor original: %d\n", num);
    
    valor(num); // Chama a fun��o por valor
    printf("Ap�s passagem por valor: %d\n", num);
    
    referencia(&num); // Chama a fun��o por refer�ncia
    printf("Valor ap�s passagem por refer�ncia: %d\n", num);
    
    return 0;
}

void valor(int x) {
    x = 10; // Modifica a c�pia local de 'x'
    printf("Dentro da fun��o (passagem por valor): %d\n", x);
}

void referencia(int *x) {
    *x = 10; // Modifica o valor apontado por 'x'
    printf("Dentro da fun��o (passagem por refer�ncia): %d\n", *x);
}
