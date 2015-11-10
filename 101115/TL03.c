#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (int narg, char *argv[]) {
	int vetor[5000];
	int count;
	double tBubble, tInsertion, tSelection;
	time_t inicio,fim;
	
	printf("Processando o Selection Sort\n");
	inicio = clock();
	for(count = 0 ; count < 1000; count++)
		PopularVetor(vetor, 5000);
		SelectionSort(vetor, 5000);
	fim = clock();
	tSelection = (double)(fim - inicio)/CLOCKS_PER_SEC;
	printf("O Selection Sort levou %f segundos\n", tSelection);
	
	printf("Processando o Bubble Sort\n");
	inicio = clock();
	for(count = 0 ; count < 1000; count++) {
		PopularVetor(vetor, 5000);
		BubbleSort(vetor, 5000);
	}
	fim = clock();
	tBubble = (double)(fim - inicio)/CLOCKS_PER_SEC;
	printf("O Bubble Sort levou %f segundos\n", tBubble);
	
	printf("Processando o Insertion Sort\n");
	inicio = clock();
	for(count = 0 ; count < 1000; count++)
		PopularVetor(vetor, 5000);
		InsertionSort(vetor, 5000);
	fim = clock();
	tInsertion = (double)(fim - inicio)/CLOCKS_PER_SEC;
	printf("O Insertion Sort levou %f segundos\n", tInsertion);
	
	if(tBubble < tInsertion && tBubble < tSelection)
		printf("O Bubble Sort foi melhor\n");
	else if(tInsertion < tBubble && tInsertion < tSelection)
		printf("O Insertion Sort foi melhor\n");
	else
		printf("O Selection Sort foi melhor\n");
		
	return EXIT_SUCCESS;
}

int PopularVetor(int vetor[], int tamanho) { 
	int i;
	srand(time(NULL));
	
	for(i=0 ; i < tamanho ; i++) {
    	vetor[i] = (rand() % 5001);
    }
}

int BubbleSort (int vetor[], int tamanho) {
	int aux, i, j;
	
	for(i=tamanho-1; i >= 1; i--) {  
		for(j=0; j < i ; j++) {  
			if(vetor[j]>vetor[j+1]) {
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}

int InsertionSort(int vetor[], int tamanho) {
	int i, j, numero;
   
	for (i = 1; i < tamanho; i++){
		numero = vetor[i];
		j = i - 1;
		while ((j>=0) && (numero < vetor[j])) {
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = numero;
	}
}

int SelectionSort(int vetor[], int tamanho) { 
	int i, j, min, aux;
	   
	for (i = 0; i < (tamanho-1); i++) {
		min = i;
		for (j = (i+1); j < tamanho; j++) {
			if(vetor[j] < vetor[min]) 
				min = j;
		}
		if (i != min) {
			aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
		}
	}
}
