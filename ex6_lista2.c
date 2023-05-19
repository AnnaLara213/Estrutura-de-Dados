#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(int *pt_n1, int *pt_n2); // Declara��o da fun��o �troca� para dois ponteiros

int main(){
  int n1, n2; // Declara��o das vari�veis 
  printf("Valor para n1: ");
  scanf("%d", &n1);

  printf("Valor para n2: ");
  scanf("%d", &n2);

  
  
  printf("Ordem informada: %d e %d\n", n1, n2);
  troca(&n1, &n2); // Chama a fun��o �troca�
  printf("Ordem apos a troca: %d e %d\n", n1, n2);
	// %p -> nota��o para impress�o de ponteiros...

  return 0;
}

void troca(int *pt_n1, int *pt_n2){
  int temp;
  temp = *pt_n1; // Armazenamento tempor�rio 
  *pt_n1 = *pt_n2; 
  *pt_n2 = temp;
}
