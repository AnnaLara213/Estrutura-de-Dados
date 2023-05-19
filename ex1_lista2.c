#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int le_valida_num(){
	setlocale(LC_ALL, "Portuguese");
	
	int numero;
	
	do{
		printf("Informe um número entre 1 e 99: ");
		scanf("%d", &numero);
		
		if(numero < 1 || numero > 99){
			printf("Número inválido\n");
		}
	} while (numero < 1 || numero > 99);
	
	return numero;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	const int MIN_NUM = 10;
	const int MAX_NUM = 20;	
	int num[MAX_NUM];
	char menu = 'S';
    int i, tam, j, k, aux;
    
    
    for (i = 0; i < MAX_NUM; i++) {
    	num[i] = le_valida_num();
    	
    	if (i == (MIN_NUM - 1)) {
        	printf("Deseja continuar? [S|N]\n");
        	scanf(" %c", &menu);
        	menu = toupper(menu); 
        }
        
		if (menu == 'N'){
        	break;
		}
	}
    
    tam = i;
    for (j = 0; j < tam; j++) {
    	for (k = 0; k < tam-j-1; k++) {
        	if (num[k] > num[k+1]) {
            	aux = num[k];
            	num[k] = num[k+1];
            	num[k+1] = aux;
	        }
	    }
	}
    
	printf("Números em ordem crescente: ");
	for (j = 0; j < tam; j++) {
    	printf("%d ", num[j]);
	}
    
	return 0;
}
