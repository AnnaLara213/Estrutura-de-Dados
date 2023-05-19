#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(int *pt_n1, int *pt_n2); // Declaração da função “troca” para dois ponteiros

int main(){
  int n1, n2; // Declaração das variáveis 
  printf("Valor para n1: ");
  scanf("%d", &n1);

  printf("Valor para n2: ");
  scanf("%d", &n2);

  
  
  printf("Ordem informada: %d e %d\n", n1, n2);
  troca(&n1, &n2); // Chama a função “troca”
  printf("Ordem apos a troca: %d e %d\n", n1, n2);
	// %p -> notação para impressão de ponteiros...

  return 0;
}

void troca(int *pt_n1, int *pt_n2){
  int temp;
  temp = *pt_n1; // Armazenamento temporário 
  *pt_n1 = *pt_n2; 
  *pt_n2 = temp;
}
