#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int getString(char vectorCadena[], int tamCadena){
	int validacion;
	char auxCadena[1000];

	validacion = 0;
	if (vectorCadena!= NULL && tamCadena > 0 ){
		if (fgets(auxCadena, sizeof(auxCadena), stdin) != NULL) {
			if(auxCadena[strnlen(auxCadena, sizeof(auxCadena)) - 1] == '\n'){
				auxCadena[strnlen(auxCadena, sizeof(auxCadena)) - 1] = '\0';
			}
			if (strlen(auxCadena)+1 <= tamCadena) {
				strncpy(vectorCadena, auxCadena, tamCadena);
				validacion = 1;
			}
		}
	}

	return validacion;
}

int GetLetters(char mensaje[], char mensajeError[], char vectorCadena[], int tamCadena, int reintentos) {
	int validacion;

	validacion = 0;
	do {
		printf("%s", mensaje);
		if (mensaje!= NULL && mensajeError!= NULL && vectorCadena !=NULL && tamCadena > 0) {
			if (getString(vectorCadena, tamCadena) == 1 && ValidarLetras(vectorCadena) == 1) {
				validacion = 1;
				break;
			} else {
				printf("%s", mensajeError);
				fflush(stdin);
			}

		}
	} while (reintentos > 0);

	return validacion;
}

int GetStringAlfaNum(char mensaje[], char mensajeError[], char vectorCadena[], int tamCadena, int reintentos) {
	int validacion;
	validacion = 0;

	do {
		printf("%s", mensaje);
		fflush(stdin);
		if (mensaje!= NULL && mensajeError!= NULL && vectorCadena !=NULL && tamCadena > 0) {
			if (getString(vectorCadena, tamCadena) == 1 && ValidarLetrasYNum(vectorCadena) == 1) {
				validacion = 1;
				break;
			} else {
				printf("%s", mensajeError);
				fflush(stdin);
			}
		}
	} while (reintentos > 0);

	return validacion;
}

void StringUpperCamelCase(char vectorCadena[]) {
	int i;

	if(vectorCadena != NULL){
		strlwr(vectorCadena);
		vectorCadena[0] = toupper(vectorCadena[0]);

		for (i = 0; i < strlen(vectorCadena); i++) {
			if (vectorCadena[i] == ' ') {
			vectorCadena[i + 1] = toupper(vectorCadena[i + 1]);
			}
		}
	}

}

void StringUpper(char vectorCadena[]) {
	int i;

	if(vectorCadena != NULL){
		for (i = 0; i < strlen(vectorCadena); i++) {
			vectorCadena[i] = toupper(vectorCadena[i]);
		}
	}

}

void ConcatStrings(char cadenaDestino[], char candenaConcatenar[],int tamCadenaDestino) {

	if(cadenaDestino !=NULL && candenaConcatenar != NULL && tamCadenaDestino > 0 ){
		if (strlen(cadenaDestino) == 0) {
				strncpy(cadenaDestino, candenaConcatenar, tamCadenaDestino);
			} else {
				strncat(cadenaDestino, " ", tamCadenaDestino);
				strncat(cadenaDestino, candenaConcatenar, tamCadenaDestino);
			}
	}
}

