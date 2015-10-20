#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {

	int dia, mes, ano,
		diaAtl, mesAtl, anoAtl,
		count, totalDias = 0;
	int meses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	printf("Entre o dia que você nasceu:\n");
	scanf("%d", &dia);
	printf("Entre o mes que você nasceu:\n");
	scanf("%d", &mes);
	printf("Entre o ano que você nasceu:\n");
	scanf("%d", &ano);
	
	printf("Entre o dia atual:\n");
	scanf("%d", &diaAtl);
	printf("Entre o mes atual:\n");
	scanf("%d", &mesAtl);
	printf("Entre o ano atual:\n");
	scanf("%d", &anoAtl);
	
	if(anoAtl < ano) {
		printf("Data inválida \n");
		return EXIT_FAILURE;
	}
	
	if(anoAtl == ano && mesAtl < mes) {
		printf("Data inválida \n");
		return EXIT_FAILURE;
	}
	
	if(anoAtl == ano && mesAtl == mes && diaAtl < dia) {
		printf("Data inválida \n");
		return EXIT_FAILURE;
	}
	
	if(mes > 12 || mesAtl > 12) {
		printf("Data inválida \n");
		return EXIT_FAILURE;
	}
	
	if(dia > meses[mes] || diaAtl > meses[mesAtl]) {
		printf("Data inválida \n");
		return EXIT_FAILURE;
	}
	
	if(mesAtl == mes && anoAtl == ano)
		totalDias = diaAtl - dia;
	else
		totalDias = (meses[mes] - dia) + (diaAtl);
   	
   	if(anoAtl == ano) {
   		for(count=mes + 1 ; count <= mesAtl - 1 ; count++) {
   			totalDias = totalDias + meses[count];
   		}
   	}
   	else {
   		for(count=mes + 1 ; count <= 12 ; count++) {
   			totalDias = totalDias + meses[count];
   		}
   		for(count=1; count <= mesAtl - 1; count++) {
   			totalDias = totalDias + meses[count];
   		}
   	}
   	
   	for(count=ano + 1 ; count <= anoAtl - 1 ; count++) {
		if ( ( count % 4 == 0 && count % 100 != 0 ) || count % 400 == 0 )
    		totalDias = totalDias + 366;
    	else
    		totalDias = totalDias + 365;
   	}
   	
   	printf("Você já viveu %d dias \n\n", totalDias + 1); //Contando o dia do nascimento como dia vivido
	
	return EXIT_SUCCESS;
}
