#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {

	int N, resultado=1, a=1, aOld=1, cont = 1;
	
	printf("Entre um número inteiro positivo:\n");
	scanf("%d", &N);
	
	while(N > resultado){
		printf("Fibonacci %d: %d\n", cont, resultado);
		aOld = a;
		a = resultado;
		resultado = a + aOld;
		
		cont++;
	}
	
	return EXIT_SUCCESS;
}
