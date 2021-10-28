#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdlib.h>
#include <string.h>

int PedirNumeroEntero(char mensaje[], char mensajeError[],int reintentos, int* numeroEntero) {
	char numeroIngresado[4000];
	int validacion;

	do {
		printf("%s ", mensaje);
		fflush(stdin);
		scanf("%[^\n]", numeroIngresado);
		validacion = ValidarNumeroEntero(numeroIngresado);
		if (validacion != 1) {
			printf("%s ", mensajeError);
			fflush(stdin);
			reintentos--;
		}else{
			*numeroEntero = atoi(numeroIngresado);
			reintentos = 0;
		}
	} while (reintentos > 0);

	return validacion;
}

int PedirNumeroFloat(char mensaje[], char mensajeError[],int reintentos, float* numeroFloat) {
	char numeroIngresado[4000];
	int validacion;

	do {
		printf("%s ", mensaje);
		fflush(stdin);
		scanf("%[^\n]", numeroIngresado);
		validacion = ValidarNumeroFloat(numeroIngresado);
		if (validacion != 1) {
			printf("%s ", mensajeError);
			fflush(stdin);
			reintentos--;
		}else{
			*numeroFloat = atof(numeroIngresado);
			reintentos = 0;
		}
	} while (reintentos > 0);

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


int PedirNumConRango(char mensaje[],char mensajeError[], int reintentos , int min, int max) {
	int numeroIngresado;

	do {
		PedirNumeroEntero(mensaje, mensajeError, reintentos, &numeroIngresado);
	} while (ValidarRango(numeroIngresado, min, max) == 0);

	return numeroIngresado;
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

