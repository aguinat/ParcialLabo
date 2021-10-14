#include "LibrarieString.h"
#include "LibrarieValidar.h"

int GetString(char mensaje[], char mensajeError[], char vectorCadena[], int tamCadena, int reintentos) {
	int validacion;
	char auxCadena[1000];

	do {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxCadena);
		validacion = ValidarLetras(auxCadena);
		if (validacion != 1 || strlen(auxCadena)== 0 ) {
			printf("%s\n ", mensajeError);
			fflush(stdin);
			reintentos--;
		} else {
			strncpy(vectorCadena, auxCadena, tamCadena);
			break;
		}
	} while (reintentos > 0);

	return validacion;
}

int GetStringAlfaNum(char mensaje[], char mensajeError[], char vectorCadena[], int tamCadena, int reintentos) {
	int validacion;
	char auxCadena[1000];

	do {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxCadena);
		validacion = ValidarLetrasYNum(auxCadena);
		if (validacion != 1 || strlen(auxCadena)== 0 ) {
			printf("%s\n ", mensajeError);
			fflush(stdin);
			reintentos--;
		} else {
			strncpy(vectorCadena, auxCadena, tamCadena);
			reintentos = 0;
		}
	} while (reintentos > 0);

	return validacion;
}

void StringUpperCamelCase(char vectorCadena[]) {
	int i;

	strlwr(vectorCadena);
	vectorCadena[0] = toupper(vectorCadena[0]);

	for (i = 0; i < strlen(vectorCadena); i++) {
		if (vectorCadena[i] == ' ') {
			vectorCadena[i + 1] = toupper(vectorCadena[i + 1]);
		}
	}

}

void ConcatStrings(char cadenaDestino[], char candenaConcatenar[],
		int tamCadenaDestino) {

	if (strlen(cadenaDestino) == 0) {
		strncpy(cadenaDestino, candenaConcatenar, tamCadenaDestino);
	} else {
		strncat(cadenaDestino, " ", tamCadenaDestino);
		strncat(cadenaDestino, candenaConcatenar, tamCadenaDestino);
	}

}

