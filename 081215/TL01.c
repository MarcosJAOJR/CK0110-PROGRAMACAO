#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *porExtenso(int numero) {

	char
	*teens[10] = {"","onze","doze","treze","quatorze","quinze","dezesseis","dezessete","dezoito","dezenove"},
	*unidades[10] = {"","um","dois","três","quatro","cinco","seis","sete","oito","nove"},
	*dezenas[10] = {"","dez","vinte","trinta","quarenta","cinquenta","sesenta","setenta","oitenta","noventa"},
	*centenas[10] = {"","cento","duzentos","trezentos","quatrocentos","quinhentos","seiscentos","setecentos","oitocentos","novecentos"};
	char *buffer, *retorno;

	buffer = malloc(1024*sizeof(char));

	if (numero >= 100 && numero < 1000) {
		if (numero == 100) {
			strcat(buffer, "cem");
		} else {
			strcat(buffer, centenas[(int)numero/100]);
			numero = numero - ((int)numero/100)*100;
			if (numero > 0) {
				strcat(buffer, " e ");
			}
		}
	}

	if (numero >= 10 && numero < 100) {
		if(numero > 10 && numero < 20 )
			strcat(buffer, teens[numero - (int)numero/10*10]);
		else {
			strcat(buffer, dezenas[(int)numero/10]);
			numero = numero - ((int)numero/10)*10;
			if (numero > 0) {
				strcat(buffer, " e ");
			}
		}
	}

	if (numero >= 1 && numero < 10)
		strcat(buffer, unidades[numero]);

	retorno = malloc(strlen(buffer)*sizeof(char));
	retorno = buffer;

	return retorno;
}

int main (int narg, char *argv[]) {

	FILE *arq;
	char buffer[5], *numextenso[1000], *extenso;
	int numero = 0, count = 0, i;

	if(argv[1] != NULL) {
		printf("Lendo arquivo...\n");

		arq = fopen(argv[1],"r");

		if(arq == NULL) {
			printf("Erro lendo o arquivo.\n");
			return EXIT_FAILURE;
		}

		while(!feof(arq)) {
			if(fgets(buffer,5,arq)) {
				buffer[strlen(buffer) - 1] = '\0';
				numextenso[count++] = porExtenso(atoi(buffer));
			}
		}

		for (i = 0; i < count; i++) {
			printf("%s\n", numextenso[i]);
		}

		fclose(arq);
		return EXIT_SUCCESS;
	}

	printf("Digite um numero entre 1 e 999: ");
	scanf("%d",&numero);
	if ( numero<1 || numero>999 )
	{
		printf("Número inválido!\n");
		return 0;
	}
	extenso = porExtenso(numero);
	printf("Numero %d: %s\n",numero,extenso);

	return EXIT_SUCCESS;
}
