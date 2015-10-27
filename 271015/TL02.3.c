#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {

	int numero, resultado=0, potencia=1, parteInt, potResult=1;
	
		
	
	if(narg >= 2){
		numero = atoi(argv[1]);
	}
	else{
		printf("Entre um número inteiro:\n");
		scanf("%d", &numero);
	}
	
	
	while(potencia<=numero) {
   		potencia = potencia*10;
   	}
   	
   	potencia = potencia/10;
	
	while(numero > 0){
		parteInt = (int)(numero/potencia); //Pegando a parte inteira
		
		resultado = resultado + parteInt*potResult;//populando o numero invertido
		potResult = potResult*10;//Atualizando a potencia do numero invertido
		
		numero = numero - potencia*parteInt; //Atualizando o número
		potencia = potencia/10;//Atualizando a potencia
	}
	
	printf("O número invertido é: %d\n", resultado);
	
	return EXIT_SUCCESS;
}
