#include <stdlib.h>
#include <string.h>
#include "LibrarieLocalidad.h"

void MostrarLocalidades(eLocalidad localidades[], int tamLocalidades){
	int i;
	int flagDatosVacios;

	flagDatosVacios = 0;
	printf("\n   Id \t\t Localidad \n");
	for (i = 0; i < tamLocalidades; i++) {
		if (localidades[i].isEmpty == 0) {
			MostrarUnaLocalidad(localidades[i]);
		} else {
			if (flagDatosVacios == 0) {
				puts("No se encontraron localidades para mostrar.\n");
				flagDatosVacios = 1;
			}

		}
	}
}


void MostrarUnaLocalidad (eLocalidad localidad){
	printf("%5d %20s \n\n", localidad.idLocalidad, localidad.localidad);
}


int BuscarLocalidad (eLocalidad localidades[], int tam, char localidad[], int* idLocalidad){
	int i;
	int localidadExiste;

	localidadExiste = 0;

	for(i=0; i<tam; i++) {
		if(stricmp(localidades[i].localidad, localidad)==0){
			localidadExiste = 1;
			*idLocalidad = localidades[i].idLocalidad;
		}
	}

	return localidadExiste;
}
