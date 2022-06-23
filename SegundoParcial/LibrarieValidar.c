#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LibrarieInt.h"
#include "LibrarieString.h"
#define TAMRES 3

int ValidarNumEntero(char strNumbers[]) {
	int i;
	int validacion;

	validacion = 1;
		if(strNumbers != NULL){
			for(i=0; i<strlen(strNumbers); i++){
					if(isdigit(strNumbers[i]) == 0 || ((strNumbers[i] == '-' ) && i>0)){
						validacion = 0;
						break;
					}
			}
		}

	return validacion;
}

int ValidarNumeroFloat(char strNumbers[]) {
	int i;
	int contador;
	int validacion;

	contador = 0;
	validacion = 1;

	if(strNumbers != NULL){
		for(i=0; i<strlen(strNumbers); i++){
				if((isdigit(strNumbers[i]) == 0 && strNumbers[i] != '.') || ((strNumbers[i] == '.' ) && i == 0) || ((strNumbers[i] == '-' ) && i>0)){
					validacion = 0;
					break;
				}
				if((strNumbers[i] == '.' )){
				contador++;
					if(contador>1){
						validacion = 0;
					}
				}
			}
	}

	return validacion;
}

int ValidarLetras(char strLetras[]) {
	int i;
	int validacion;

	validacion = 1;

	if(strLetras != NULL){
		for(i=0; i<strlen(strLetras); i++){
					if( (strLetras[i] != ' ') && (isalpha(strLetras[i]) == 0 ) ){
						validacion = 0;
						break;
					}
			}

	}
	return validacion;
}

int ValidarLetrasYNum(char strAlfaNum[]) {
	int i;
	int validacion;

	validacion = 1;

	if(strAlfaNum != NULL){
		for(i=0; i<strlen(strAlfaNum); i++){
					if((strAlfaNum[i] != ' ') && (isalpha(strAlfaNum[i]) == 0 ) && (isdigit(strAlfaNum[i]) == 0)){
						validacion = 0;
						break;
					}
			}
	}

	return validacion;
}



int ValidarRango(int numero, int min, int max) {
	int validacion;
	validacion = 0;

	if ((min <= numero && numero <= max) && (min < max)) {
		validacion = 1;
	}
	return validacion;
}

int ValidarRangoFloat(float numero, int min, int max) {
	int validacion;
	validacion = 0;

	if ((min <= numero && numero <= max) && (min < max)) {
		validacion = 1;
	}
	return validacion;
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


void ConfirmarContinuar(char mensaje[], char mensajeError[], int* continuar, int reintentos){
	int validacion;
	char respuesta[TAMRES];
	char defoultSi[TAMRES] = {"SI"};
	char defoultNo[TAMRES] = {"NO"};

	do {
		validacion = GetLetters(mensaje, mensajeError, respuesta, TAMRES, reintentos);
		if (validacion == 1){
			strupr(respuesta);
		}
	} while (strcmp(respuesta, defoultSi)!= 0 && strcmp(respuesta, defoultNo)!= 0);

	if(strcmp(respuesta, defoultSi)== 0){
		*continuar = 1;
	}else{
		*continuar = 0;
	}
}
