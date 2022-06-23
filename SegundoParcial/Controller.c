#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include "DataLoading.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){
	int retorno;
	retorno = 0;

	if(path!=NULL && pArrayListPassenger !=NULL ){
		FILE *pArchivo = fopen(path, "r");
		retorno = parser_PassengerFromText(pArchivo, pArrayListPassenger);
	}

	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{	int cargaBinario;

	cargaBinario = 0;
	if(path != NULL && pArrayListPassenger!=NULL){
		FILE *pFile = fopen(path, "rb");
		if(pFile!=NULL){
			parser_PassengerFromBinary(pFile, pArrayListPassenger);
			cargaBinario = 1;
		}else{
			printf("Error al intentar abrir el archivo Binario.\n\n");
		}

	}
    return cargaBinario;
}

int controller_GetMaxId(LinkedList* pArrayListPassenger){
	int id;
	int maxId;
	int largoDeLista;
	Passenger *auxPassenger = NULL;
	maxId = 0;

	if(pArrayListPassenger != NULL){
		largoDeLista = ll_len(pArrayListPassenger);
		if (largoDeLista > 0) {
			for (int i = 0; i < largoDeLista; i++) {
				auxPassenger = ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &id);
				if(id>maxId){
					maxId = id;
				}
			}
		}
	}

	return maxId;
}

int controller_saveMaxIdAsText(LinkedList* pArrayListPassenger){
	int maxId;
	int archivoActualizado;

	archivoActualizado = 0;
	if(pArrayListPassenger != NULL){
		maxId = controller_GetMaxId(pArrayListPassenger);
		FILE *pArchivo = fopen("Ids.csv", "w");
		if (pArchivo != NULL) {
			fprintf(pArchivo,"%d\n",maxId);
			fclose(pArchivo);
			archivoActualizado = 1;
		}
	}
	return archivoActualizado;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{	int cargaCorrecta;
	int ultimoIdCargado;
	Passenger *newPassenger = NULL;

	cargaCorrecta = 0;
	if(ll_len(pArrayListPassenger)>0){
		ultimoIdCargado = controller_GetMaxId(pArrayListPassenger);
	}else{
		ultimoIdCargado = parser_GetMaxId();
	}

	if(pArrayListPassenger != NULL && ultimoIdCargado>0){
		newPassenger = Passenger_getFromUser(&cargaCorrecta, &ultimoIdCargado);
		if(newPassenger != NULL){
			ll_add(pArrayListPassenger, newPassenger);
			cargaCorrecta = 1;
			printf("\nCarga completa del nuevo pasajero\n");
		}
	}else{
		printf("ERROR. No se pudo realizar la carga.\n");
	}

	return cargaCorrecta;
}


/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{	int lenListPassenger;
	int registrosMostrados;
	int continuar;
	Passenger *passenger = NULL;
	registrosMostrados = 0;

	if(pArrayListPassenger!= NULL){
		lenListPassenger = ll_len(pArrayListPassenger);
		if(lenListPassenger>0){
			printf("\n\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Codigo Vuelo", "Precio","Tipo Pasajero", "Estado Vuelo");
			for(int i = 0; i< lenListPassenger; i++){
				passenger = ll_get(pArrayListPassenger, i);
				if(passenger!= NULL){
					registrosMostrados++;
					MostrarUnPasajero(passenger);
					if(registrosMostrados==100){
						ConfirmarContinuar("Continuar... ?'SI'/'NO': ", "ERROR. Respuesta invalida", &continuar, 3);
						if(continuar == 1){
							registrosMostrados = 0;
						}else{
							break;
						}
					}
				}

			}
		}

	}

    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{	int pasajeroEliminado;
	int confirma;
	int idPassenger;
	int numeroValido;
	Passenger * auxPassenger = NULL;
	int index;

	pasajeroEliminado = 0;
	if(pArrayListPassenger != NULL){
		controller_ListPassenger(pArrayListPassenger);
		numeroValido = GetIntNumber("\nIndique el id del pasajero que desea eliminar: ", "ERROR. Id invalido.", 3, &idPassenger);
		if (numeroValido == 1){
			auxPassenger = GetPassenger_ById(pArrayListPassenger, idPassenger, &index);
			if(auxPassenger != NULL && index>= 0){
				printf("\nEl pasajero que se va a eliminar es el siguiente: ");
				printf("\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n","ID", "Nombre", "Apellido", "Codigo Vuelo", "Precio","Tipo Pasajero", "Estado Vuelo");
				MostrarUnPasajero(auxPassenger);
				ConfirmarContinuar("\nCONFIRME PARA CONTINUAR.(SI/NO) ", "\nError. Vuelva a intentarlo", &confirma, 3);
				if(confirma == 1){
					free(auxPassenger);
					ll_remove(pArrayListPassenger, index);
					pasajeroEliminado = 1;
				}
			}
		}

	}

    return pasajeroEliminado;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{	int idPassenger;
	int numeroValido;
	Passenger * auxPassenger = NULL;
	int index;
	int pasajeroEditado;

	pasajeroEditado = 0;
	if(pArrayListPassenger!=NULL){
		controller_ListPassenger(pArrayListPassenger);
		numeroValido = GetIntNumber("\nIndique el id del pasajero que desea modificar los datos: ", "ERROR. Id invalido.", 3, &idPassenger);
		if (numeroValido == 1){
			auxPassenger = GetPassenger_ById(pArrayListPassenger, idPassenger, &index);
			if(index >= 0 && auxPassenger != NULL){
				if (ModificarDatosPasajero(auxPassenger) == 1) {
					ll_set(pArrayListPassenger, index, auxPassenger);
					pasajeroEditado = 1;
				}
			}else{
				printf("ERROR. El id indicado no existe.");
			}
		}
	}

    return pasajeroEditado;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{	int retorno;
	int opcion;

	retorno = 0;
	if(pArrayListPassenger!=NULL){
		do{
			GetNumberWithRange("\n1. Ordenar por apellido y nombre.\n"
					"2. Ordenar por estado estado de vuelo.\n"
					"3.  Ordenar por precio de vuelo\n"
					"4. Ordenar por tipo de pasajero\n"
					"5. Salir\n"
					"Ingrese una opcion: ",
					"1. Ordenar por apellido.\n"
					"2. Ordenar por estado estado de vuelo.\n"
					"3. Ordenar por precio de vuelo\n"
					"4. Ordenar por tipo de pasajero\n"
					"5. Salir\n"
					"\nOpcion invalida, vuelva a intentarlo: ", 3, 1, 5, &opcion);
			switch (opcion) {
			case 1:
				GetNumberWithRange("\n1. Ordenar de la 'A' a la 'Z'.\n"
						"2. Ordenar de la 'Z' a la 'A'.\n"
						"3. Salir\n"
						"Ingrese una opcion: ",
						"1. Ordenar de la 'A' a la 'Z'.\n"
						"2. Ordenar de la 'Z' a la 'A'.\n"
						"3. Salir\n"
						"\nOpcion invalida, vuelva a intentarlo: ", 3, 1, 3, &opcion);
				switch(opcion){
				case 1:
					if(ll_sort(pArrayListPassenger, Passenger_sortByApellido, 1)==0){
						printf("\nLista ordenada correctamente por apellido\n");
						retorno = 1;
					}
					break;
				case 2:
					if(ll_sort(pArrayListPassenger, Passenger_sortByApellido, 0)==0){
						printf("\nLista ordenada correctamente por apellido\n");
						retorno = 1;
					}
					break;
				}
				break;
			case 2:
				if(ll_sort(pArrayListPassenger, Passenger_sortByEstadoVuelo, 1)==0){
					printf("\nLista ordenada correctamente por estado de vuelo\n");
					retorno = 1;
				}
				break;
			case 3:
				GetNumberWithRange("\n1. Ordenar de menor a mayor.\n"
						"2. Ordenar de mayor a menor.\n"
						"3. Salir\n"
						"Ingrese una opcion: ",
						"1. Ordenar de menor a mayor.\n"
						"2. Ordenar de mayor a menor.\n"
						"3. Salir\n"
						"\nOpcion invalida, vuelva a intentarlo: ", 3, 1, 3, &opcion);
				switch (opcion){
				case 1:
					if(ll_sort(pArrayListPassenger, Passenger_sortByPrecio, 1)==0){
						printf("\nLista ordenada correctamente por precio\n");
						retorno = 1;
					}
					break;
				case 2:
					if(ll_sort(pArrayListPassenger, Passenger_sortByPrecio, 0)==0){
						printf("\nLista ordenada correctamente por precio\n");
						retorno = 1;
					}
					break;
				}
				break;
			case 4:
				if(ll_sort(pArrayListPassenger, Passenger_sortByTipoPasajero, 1)==0){
					printf("\nLista ordenada correctamente por tipo de pasajero\n");
					retorno = 1;
				}
				break;
			}


		}while(opcion != 5);
	}



    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{	int cargaCorrecta;
	Passenger* auxPassenger = NULL;
	int largoDeLista;
	int i;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char codigoVuelo[50];
	int auxTipoPasajero;
	char strTipoPasajero[50];
	int auxEstadoVuelo;
	char strEstadoVuelo[50];
	char encabezados[] = "id,name,lastname,price,flycode,typePassenger,statusFlight";

	cargaCorrecta = 1;
	largoDeLista = ll_len(pArrayListPassenger);
	if (path != NULL && pArrayListPassenger != NULL && largoDeLista > 0){
		printf("Guardando archivo CSV. \n");

		FILE *pArchivo = fopen(path, "w");

		if(pArchivo != NULL){
			fprintf(pArchivo,"%s\n", encabezados);
			for (i = 0; i < largoDeLista; i++){
				auxPassenger = ll_get(pArrayListPassenger, i);
				if (auxPassenger != NULL) {
					Passenger_getId(auxPassenger, &auxId);
					Passenger_getNombre(auxPassenger, auxNombre);
					Passenger_getApellido(auxPassenger, auxApellido);
					Passenger_getPrecio(auxPassenger,& auxPrecio);
					Passenger_getCodigoVuelo(auxPassenger, codigoVuelo);
					Passenger_getTipoPasajero(auxPassenger, &auxTipoPasajero);
					getStr_PassegerType(strTipoPasajero, auxTipoPasajero);
					Passenger_getEstadoVuelo(auxPassenger, &auxEstadoVuelo);
					getStr_StatusFlight(strEstadoVuelo, auxEstadoVuelo);
					fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,codigoVuelo,strTipoPasajero,strEstadoVuelo);
				} else {
					cargaCorrecta = 0;
				}
			}
			fclose(pArchivo);
			printf("Archivo '%s' guardado correctamente. \n",path);
		}else{
			cargaCorrecta = 0;
		}
	}

    return cargaCorrecta;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{	int cargaCorrecta;
	Passenger* auxPassenger = NULL;
	int largoDeLista;
	int i;

	cargaCorrecta = 1;
	largoDeLista = ll_len(pArrayListPassenger);

	if (path != NULL && pArrayListPassenger != NULL && largoDeLista > 0) {
		printf("Guardando archivo Binario. \n");

		FILE * pBin = fopen(path, "wb");

		if(pBin != NULL){
			for (i = 0; i < largoDeLista; i++){
				auxPassenger = ll_get(pArrayListPassenger, i);
				if(auxPassenger != NULL){
					fwrite(auxPassenger,sizeof(Passenger),1,pBin);
				}else{
					cargaCorrecta = 0;
				}
			}
			fclose(pBin);
			printf("Archivo '%s' guardado correctamente. \n",path);
		}else{
			cargaCorrecta = 0;
		}
	}
    return cargaCorrecta;
}

