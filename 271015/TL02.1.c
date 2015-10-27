#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {

	int N, numero = 2, cont=2;
	
	printf("Entre um número inteiro positivo:\n");
	scanf("%d", &N);
	
	while(N > numero){
		while(cont<numero){
			if(numero % cont != 0)
				cont++;
			else{
				cont = 2;
				numero++;
			}
		}
		printf("primo: %d\n", numero);
		cont = 2;
		numero++;
	}
	
	return EXIT_SUCCESS;
}
