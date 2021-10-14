#include <string.h>
#include "LibrarieInt.h"

int ValidarNumero(char strNumbers[]) {
	int i;
	int validacion;

	validacion = 1;

	for(i=0; i<strlen(strNumbers); i++){
			if(strNumbers[i]<'0' || strNumbers[i]>'9'){
				validacion = 0;
				break;
			}
	}

	return validacion;
}

int ValidarNumeroFloat(char strNumbers[]) {
	int i;
	int validacion;

	validacion = 1;

	for(i=0; i<strlen(strNumbers); i++){
			if((strNumbers[i]<'0' || strNumbers[i]>'9') &&(strNumbers[i] != '.' )){
				validacion = 0;
				break;
			}
	}

	return validacion;
}

int ValidarLetras(char strLetras[]) {
	int i;
	int validacion;

	validacion = 1;

	for(i=0; i<strlen(strLetras); i++){
			if((strLetras[i] != ' ') && (strLetras[i]<'a' || strLetras[i]>'z') && (strLetras[i]<'A' || strLetras[i]>'Z')){
				validacion = 0;
				break;
			}
	}

	return validacion;
}

int ValidarLetrasYNum(char strAlfaNum[]) {
	int i;
	int validacion;

	validacion = 1;

	for(i=0; i<strlen(strAlfaNum); i++){
			if((strAlfaNum[i] != ' ') && (strAlfaNum[i]<'a' || strAlfaNum[i]>'z') && (strAlfaNum[i]<'A' || strAlfaNum[i]>'Z')&& (strAlfaNum[i]<'0' || strAlfaNum[i]>'9')){
				validacion = 0;
				break;
			}
	}

	return validacion;
}




int ValidarRango(int numero, int min, int max) {
	int respuesta;

	respuesta = 0;
	if (numero > min && numero < max) {
		respuesta = 1;
	}

	return respuesta;
}


int ValidarSigno(int numero) {
	int respuesta;
	if (numero > 0) {
		respuesta = 1;
	} else {
		if (numero < 0) {
			respuesta = 0;
		}
	}

	return respuesta;
}


int ValidarEsPar(int numero) {
	int respuesta;

	if (numero % 2 == 0) {
		respuesta = 1;
	} else {
		respuesta = 0;
	}

	return respuesta;
}


void ConfirmarContinuar(char mensaje[], char continuar[]) {
	char respuesta[1];

	do {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%s", &respuesta);

		strupr(respuesta);
	} while (respuesta[0] != 'S' && respuesta[0] != 'N');

	strncpy(continuar, respuesta, 1);
}
