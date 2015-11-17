#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char rand_char () {
	char c;
	int n;
	
	n =random()%52;
	
	if (n <= 25)
		n = n + 65;
	else
		n = n + 97 - 26;
		
	c = (char)n;
	
	return c;
}

int PrimeiraEmOrdemAlfabetica (char vetor[40][1000], int primeiraPosicao, int segundaPosicao) {
	int i=0, j=0, estaCompleto = 0;
	
	while(!estaCompleto) {
		estaCompleto = 1;
		if(vetor[j][primeiraPosicao] > vetor[i][segundaPosicao])
			return 1;
		else if (vetor[j][primeiraPosicao] < vetor[i][segundaPosicao])
			return 2;
		else {
			estaCompleto = 0;
			i++;
			j++;
		}
	}
}

int TrocarDePosicao (char vetor[40][1000], int primeiraPosicao, int segundaPosicao) {
	int i;
	char aux[40];
	
	for(i=0 ; i < 40 ; i++) {
		aux[i] = vetor[i][primeiraPosicao];
		vetor[i][primeiraPosicao] = vetor[i][segundaPosicao];
		vetor[i][segundaPosicao] = aux[i];
	}
}

int main (int narg, char *argv[]) {
	char vetor[40][1000];	
	int i, j;
	
	srand(time(NULL));

	//	Popular Vetor
	for(j=0 ; j < 1000 ; j++) {
		for(i=0 ; i < 40 ; i++) {
			vetor[i][j] = rand_char();
		}
	}
	
	for(i=1000-1; i >= 1; i--) {  
		for(j=0; j < i ; j++) {
			if(PrimeiraEmOrdemAlfabetica(vetor,j, (j+1)) == 1) {
				TrocarDePosicao(vetor, j, (j+1));
			}
		}
	}
	
	for(j=0 ; j < 1000 ; j++) {
		printf("%d - ", j+1);
		for(i=0 ; i < 40 ; i++)
			printf("%c", vetor[i][j]);
		printf("\n");
	}
    printf("\n");
	
	return EXIT_SUCCESS;
}
