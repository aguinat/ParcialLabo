#ifndef CONTROLCENSISTAS_C_
#define CONTROLCENSISTAS_C_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include "ControlCensistas.h"

#define PENDIENTE 1
#define FINALIZADO 2
#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

int CambiarEstadoCensista(eCensistas listCensista[], int idCensista, int index, eZonas listZona[],int lenZona){
	int i;
	int zonasAsignadas;
	int estadoCambiado;

	estadoCambiado = 0;
	zonasAsignadas = 0;

	if(listCensista != NULL && lenZona > 0 &&  listZona != NULL){
		if(listCensista[index].idCensista == idCensista && listCensista[index].isEmpty == 0){
			for(i=0; i<lenZona; i++){
				if(listZona[i].idCensista == idCensista && listZona[i].estado == 1){
					zonasAsignadas++;
				}
			}
			if(zonasAsignadas == 0){
				listCensista[index].isEmpty = 1;
				listCensista[index].estadoCensista = 3;
				estadoCambiado = 1;
			}
		}
	}
	return estadoCambiado;
}

int DarDeBajaCensista(eCensistas list[], int len, int reintentos, eZonas listZona[], int lenZona){
	int index;
	int idCensista;
	int validacionCorrecta;
	int confirmarBaja;
	if(list != NULL && len > 0 ){
		MostrasCensistas(list, len);
		validacionCorrecta = GetIntNumber("Ingrese el ID del censista que quiere dar de baja: ", "\Error. ID invalido", reintentos, &idCensista);
		if(validacionCorrecta == 1 && BuscarCensistaPorID(list, len, idCensista, &index) == 1){
			printf("\nDatos de los censistas:\n\n%-5s %-15s %-20s %-30s %-15s %-25s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Fecha de Nacimiento", "Edad", "Domicilio", "Estado", "Zona");
			MostrarUnCensista(list[index]);
	  		ConfirmarContinuar("\n¿Confirma la baja del censista?: ", "\nError. Vuelva a intentarlo", &confirmarBaja, reintentos);

			if(confirmarBaja == 1){
				validacionCorrecta = CambiarEstadoCensista(list, idCensista, index, listZona, lenZona);
				if(validacionCorrecta == 0){
					printf("\nEl censista tiene zonas asignadas en estado pendiente y no se puede dar de baja");
				}else{
					printf("\nCensista dado de baja correctamente.\n\n");
				}

			}
		}
	}
	return validacionCorrecta;
}

int MostrasZonas(eZonas listZonas[], int lenZonas, eCensistas listCensistas[], int lenCensistas, eLocalidades listLocalidades[], int lenLocalidades){
	int i;
	int z;
	int flagDatosVacios;
	int validacion;
	validacion = 0;

	if(listZonas!=NULL && lenZonas> 0){
		flagDatosVacios = 1;
		printf("\nDatos de las zonas:\n\n%-5s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Calle 1", "Calle 2 ", "Calle 3", "Calle 4", "Localidad", "Estado", "Censista");
		for (i = 0; i < lenZonas; i++){
			if (listZonas[i].isEmpty == 0 && listZonas[i].idCensista !=0) {
				for(z=0; z<lenCensistas; z++){
					if(listZonas[i].idCensista == listCensistas[z].idCensista){
						MostrarUnaZona(listZonas[i], listLocalidades, lenLocalidades, listCensistas[z].nombre, listCensistas[z].apellido);
					}
				}
				flagDatosVacios = 0;
				validacion = 1;
			}
			if(listZonas[i].idCensista == 0 && listZonas[i].isEmpty == 0){
				flagDatosVacios = 0;
				MostrarUnaZona(listZonas[i], listLocalidades, lenLocalidades, "SIN ASIGNAR", "");
				validacion = 1;
			}
		}
		if (flagDatosVacios == 1) {
			puts("No se encontraron datos.\n");
		}
	}

	return validacion;

}

int AsignarCensistaAzona(eCensistas listCensista[],int lenCensista, eZonas listZona[], int lenZona, int reintentos, eLocalidades listLocalidades[], int lenLocalidades){
	int validacionCorrecta;
	int idZona;
	int i;
	int indexZona;
	int idExiste;
	int continuar;
	int censistasDisponibles;


	do{
		MostrasZonas(listZona, lenZona, listCensista, lenCensista, listLocalidades, lenLocalidades);
		validacionCorrecta = GetIntNumber("Ingrese el ID de la zona que quiere asignar: ","\nError. ID invalido.", reintentos, &idZona);
		idExiste = BuscarZonaPorID(listZona, lenZona, idZona, &indexZona);
		censistasDisponibles = 0;
		if(idExiste == 1){
			if(listZona[indexZona].estado == 1 && listZona[indexZona].idCensista==0){
				for(i = 0; i<lenCensista; i++){
					if(listCensista[i].isEmpty == 0 && listCensista[i].estadoCensista == LIBERADO){
						censistasDisponibles = 1;
						listZona[indexZona].idCensista = listCensista[i].idCensista;
						printf("\nSe asigno un censista a la zona\n");
						ConfirmarContinuar("¿Quiere asignar otra zona?: (SI/NO)\n", "", &continuar, reintentos);
					}
				}
				if(censistasDisponibles == 0){
					printf("\nNo se encontraron censistas disponibles para asignar\n");
				}
			}else{
				if(listZona[indexZona].estado == 2){
					printf("\nLa zona ingresada, ya fue censada\n");
					ConfirmarContinuar("¿Quiere asignar otra zona?: (SI/NO)\n", "", &continuar, reintentos);
				}
				if(listZona[indexZona].estado != 0){
					printf("\nLa zona ya fue asignada\n");
					ConfirmarContinuar("¿Quiere asignar otra zona?: (SI/NO)\n", "", &continuar, reintentos);
				}
			}
		}

	}while(continuar == 1);

	return validacionCorrecta;
}

int CompletarDatosZona(eZonas listZonas[], int lenZonas, eCensistas listCensistas[], int lenCensistas, eLocalidades listLocalidades[], int lenLocalidades, int reintentos){
	int idZona;
	int idValido;
	int indexIdZona;
	int continuar;
	int zonaActualizada;

	do{
		zonaActualizada = 0;
		MostrasZonas(listZonas, lenZonas, listCensistas, lenCensistas, listLocalidades, lenLocalidades);
		idValido = GetIntNumber("\nIndique el ID de la zona que se finalizo: ", "Error. ID Invalido.", reintentos, &idZona);
		if (idValido == 1){
			idValido = BuscarZonaPorID(listZonas, lenZonas, idZona, &indexIdZona);
			if (idValido == 1 && listZonas[indexIdZona].estado == 1 && listZonas[indexIdZona].isEmpty == 0 && listZonas[indexIdZona].idCensista != 0){
				//Actualizacion de zona:
				zonaActualizada = 1;
				if(GetNumberWithRange("\nIngrese la cantidad de censado en la zona: ", "\nError. Numero ingresado invalido.", reintentos, 0, 500, &listZonas[indexIdZona].censadosInSitu) == 0){
					printf("\nLa cantidad de censados en la zona no fue cargada de forma correcta");
					zonaActualizada = 0;
				}
				if(GetNumberWithRange("\nIngrese la cantidad de censados con formulario virtual completo: ", "\nError. Numero ingresado invalido.", reintentos, 0, 500, &listZonas[indexIdZona].censadosVirtual)==0){
					printf("\nLa cantidad de censados de forma virtual no fue cargada correctamente");
					zonaActualizada = 0;
				}
				if(GetNumberWithRange("\nIngrese la cantidad de ausentes: ", "\nError. Numero ingresado invalido.", reintentos, 0, 500, &listZonas[indexIdZona].ausentes)==0){
					printf("\nLa cantidad de ausentes no fue cargada correctamente");
					zonaActualizada = 0;
				}

				if(zonaActualizada == 1){
					listZonas[indexIdZona].estado = 2;
					printf("\nZONA ACTUALIZADA COMO FINALIZADA");
					ConfirmarContinuar("\n¿Desea cargar otra zona? (SI/NO): ", "Error. Respuesta Invalida", &continuar, reintentos);
				}else{
					printf("\nDatos cargados invalidos.\nNO SE PUDO COMPLETAR LA ZONA\n");
					continuar = 0;
				}

			}else{
				if(idValido == 0){
					printf("\nEl id ingresado no corresponde con ninguna zona.\n");
					ConfirmarContinuar("\n¿Desea cargar otra zona? (SI/NO): ", "Error. Respuesta Invalida", &continuar, reintentos);
				}
				if(listZonas[indexIdZona].estado == 2){
					printf("\nEl id ingresado ya fue actualizado y figura como finalizado.\n");
					ConfirmarContinuar("\n¿Desea cargar otra zona? (SI/NO): ", "Error. Respuesta Invalida", &continuar, reintentos);
				}
				if(listZonas[indexIdZona].idCensista == 0){
					printf("\nLa zona seleccionada no fue asiganada a ningun censista.\n");
					ConfirmarContinuar("\n¿Desea cargar otra zona? (SI/NO): ", "Error. Respuesta Invalida", &continuar, reintentos);
				}
			}
		}
	}while(continuar == 1);

	return zonaActualizada;
}

#endif /* CONTROLCENSISTAS_C_ */
