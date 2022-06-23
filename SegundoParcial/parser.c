#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "DataLoading.h"
#define LINEA_ARCHIVO 7

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger = NULL;
	char idStr[50];
	char nombre[50];
	char apellido[50];
	char priceStr[50];
	char flyCode[50];
	char typePassenger[50];
	char statusFlight[50];
	int elementosDeLinea;
	int cargaCompleta;

	cargaCompleta = 1;

	if (pFile != NULL) {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombre,apellido,priceStr,flyCode,typePassenger,statusFlight);
		do{
			elementosDeLinea = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombre,apellido,priceStr,flyCode,typePassenger,statusFlight);
			if(elementosDeLinea == LINEA_ARCHIVO){
				auxPassenger = Passenger_newParametros(idStr, nombre,typePassenger, apellido, priceStr, flyCode,statusFlight);
				if (auxPassenger != NULL) {
					ll_add(pArrayListPassenger, auxPassenger);
				} else {
					cargaCompleta = 0;
				}
			}
		}while(feof(pFile)==0);

		fclose(pFile);
		printf("Archivo CSV abierto y cerrado con exito.\n\n");
		if(cargaCompleta == 1){
			printf("Carga Completa.\n\n");
		}

	}else{
		printf("Error al intentar abrir el archivo CSV.\n\n");
	}

	return cargaCompleta;

}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{	int cantidad;
	Passenger* auxPassenger = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL){
		do{
			auxPassenger = Passenger_new();
			if(auxPassenger != NULL){
				cantidad = fread(auxPassenger, sizeof(Passenger), 1, pFile);
				if (cantidad == 1) {
					ll_add(pArrayListPassenger, auxPassenger);
				}
			}
		}while(feof(pFile)==0);
		fclose(pFile);
		printf("Archivo binario abierto y cerrado con exito.\n\n");
	}else{
		printf("Error al intentar abrir el archivo binario.\n\n");
	}


    return 1;
}

int parser_GetMaxId(){
	int idAux;
	char idStr[50];
	int elementosDeLinea;

	idAux = -1;
	FILE *pArchivo = fopen("Ids.csv", "r");
	if (pArchivo != NULL) {
		fscanf(pArchivo, "%[^\n]\n", idStr);
		do {
			elementosDeLinea = fscanf(pArchivo, "%[^\n]\n", idStr);
			if (elementosDeLinea == 1) {
				if (idAux < atoi(idStr)) {
					idAux = atoi(idStr);
				}
			}
		} while (feof(pArchivo) == 0);
	}

	return idAux;
}
