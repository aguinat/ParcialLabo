#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include "LibrarieString.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int GetIntNumber(char mensaje[], char mensajeError[],int reintentos, int* numeroEntero) {
	char numeroIngresado[4000];
	int validacion;

	validacion = 0;
	if(mensaje!= NULL && mensajeError!= NULL && reintentos>0){
		do {
			printf("%s", mensaje);
			fflush(stdin);
			if (getString(numeroIngresado, sizeof(numeroIngresado)) == 1 && ValidarNumEntero(numeroIngresado) == 1) {
				*numeroEntero = atoi(numeroIngresado);
				validacion = 1;
				break;
			}else{
				printf("%s", mensajeError);
				fflush(stdin);
			}
		} while (reintentos > 0);
	}

	return validacion;
}

int GetFloatNumber(char mensaje[], char mensajeError[],int reintentos, float* numeroFloat) {
	char numeroIngresado[4000];
	int validacion;

	validacion = 0;

	if(mensaje!= NULL && mensajeError!= NULL && reintentos>0 && numeroFloat!=NULL){
		do {
			printf("%s", mensaje);
			fflush(stdin);
			if (getString(numeroIngresado, sizeof(numeroIngresado)) == 1 && ValidarNumeroFloat(numeroIngresado)== 1) {
				*numeroFloat = atof(numeroIngresado);
				validacion = 1;
				break;
			}else{
				printf("%s", mensajeError);
				fflush(stdin);
			}
		} while (reintentos > 0);
	}

	return validacion;
}

int CalcularPromedio(float numDividendo, float numDivisor, float* resultado){
	float promedio;
	int operacionRealizada;

	operacionRealizada = 1;
	if(numDivisor==0){
		operacionRealizada = 0;
	}else{
		promedio = numDividendo / numDivisor;
	}

	*resultado = promedio;

	return operacionRealizada;
}


int GetNumberWithRange(char mensaje[],char mensajeError[], int reintentos , int min, int max, int* numeroIngresado) {
	int validacion;
	int numero;

	validacion = 0;
	do {
		if(GetIntNumber(mensaje, mensajeError, reintentos, &numero) == 1){
			*numeroIngresado = numero;
		}
		if (ValidarRango(numero, min, max) == 1){
			validacion = 1;
			break;
		}else{
			printf("%s", mensajeError);
			reintentos--;
		}
	} while (ValidarRango(numero, min, max) == 0 && reintentos > 0 );

	return validacion;
}

int GetFloatNumberWithRange(char mensaje[],char mensajeError[], int reintentos , int min, int max, float* numeroIngresado) {
	int validacion;
	float numero;

	validacion = 0;
	do {
		if(GetFloatNumber(mensaje, mensajeError, reintentos, &numero) == 1){
			*numeroIngresado = numero;
		}
		if (ValidarRango(numero, min, max) == 1){
			validacion = 1;
			break;
		}else{
			printf("%s", mensajeError);
			reintentos--;
		}
	} while (ValidarRango(numero, min, max) == 0 && reintentos > 0 );

	return validacion;
}


int FactorialDeUnNumero(int numeroIngresado) {
	int resultado;

	if (numeroIngresado == 0) {
		resultado = 1;
	} else {
		if(numeroIngresado>0){
		resultado = numeroIngresado * FactorialDeUnNumero(numeroIngresado - 1);
		}else{
			resultado = -1;
		}
	}

	return resultado;
}

void Swap(int numero1, int numero2, int *refNumero1, int *refNumero2) {
	int aux;
	aux = numero1;
	*refNumero1 = numero2;
	*refNumero2 = aux;
}

