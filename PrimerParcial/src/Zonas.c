#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Zonas.h"

#define PENDIENTE 1
#define FINALIZADO 2

int InitStructZonas(eZonas list[], int len){
	int validacion;

	validacion = 0;

	if(list != NULL && len>0){
		for(int i = 0;i < len; i++)
		    {
		    	list[i].isEmpty = 1;
		        list[i].idZona = 0;
		    }
		validacion = 1;
	}


    return validacion;

}

void MostrarLocalidades(eLocalidades list[], int len, int mostrarUna, int index){
	int i;

	printf("%-5s %-15s\n", "ID", "Localidad");
	if(mostrarUna == 1){
		printf("%-5d %-15s\n", list[index].idLocalidad, list[index].localidad);
	}else{
		for(i=0; i<len; i++){
			printf("%-5d %-15s\n", list[i].idLocalidad, list[i].localidad);
		}
	}

}

void MostrarUnaZona(eZonas list, eLocalidades listLocalidades[], int lenLocalidades, char NombreCensista[], char ApellidoCensista[]){
	int i;

	switch(list.estado){
	case 1:
		for(i=0; i<lenLocalidades; i++){
			if(listLocalidades[i].idLocalidad == list.idLocalidad){
				printf("%-5d %-15s %-15s %-15s %-15s %-15s %-15s %-8s%-15s\n", list.idZona, list.calle_1, list.calle_2, list.calle_3, list.calle_4, listLocalidades[i].localidad, "PENDIENTE", NombreCensista, ApellidoCensista);
			}
		}
		break;
	case 2:
		for(i=0; i<lenLocalidades; i++){
			if(listLocalidades[i].idLocalidad == list.idLocalidad){
				printf("%-5d %-15s %-15s %-15s %-15s %-15s %-15s %-8s%-15s\n", list.idZona, list.calle_1, list.calle_2, list.calle_3, list.calle_4, listLocalidades[i].localidad, "FINALIZADO", NombreCensista, ApellidoCensista);
			}
		}
		break;
	}

}

int BuscarIndiceLibreZona(eZonas list[], int len){
	int i;
	int index;

	  index = -1;
	  if(list != NULL && len > 0){
		  for (i = 0; i < len; i++){
		  		  if (list[i].isEmpty == 1){
		  			  index = i;
		  		  break;
		  		  }
		  	  }
	  }

	  return index;
}

int CargarUnaZona(eZonas list[], int reintentos, int index, eLocalidades listLocalidades[], int lenLocalidades){
	int cargaCompleta;
	int datoIncorrecto;
	int confirma;
	eZonas auxZona;

	cargaCompleta = 0;
	datoIncorrecto = 0;

	if(list != NULL){
		do{
			printf("Ingrese el nombre de las calles que delimitaran la zona a censar:");
				if (GetLetters("\nIngrese el nombre la primer calle: ","\nError. Calle Invalida.", auxZona.calle_1, sizeof(auxZona.calle_1),reintentos) == 0) {
					datoIncorrecto = 1;
					break;
				}
				if (GetLetters("Ingrese el nombre la segunda calle: ","\nError. Calle Invalida.", auxZona.calle_2, sizeof(auxZona.calle_2), reintentos) == 0) {
					datoIncorrecto = 1;
					break;
				}
				if (GetLetters("Ingrese el nombre la tercer calle: ","\nError. Calle Invalida.", auxZona.calle_3, sizeof(auxZona.calle_3), reintentos) == 0) {
					datoIncorrecto = 1;
					break;
				}
				if (GetLetters("Ingrese el nombre la cuarta calle: ","\nError. Calle Invalida.", auxZona.calle_4, sizeof(auxZona.calle_4), reintentos) == 0) {
					datoIncorrecto = 1;
					break;
				}
				printf("\nLocalidades: \n");
				MostrarLocalidades(listLocalidades, lenLocalidades,2, 0);
				if (GetNumberWithRange("\nSeleccione la localidad que corresponda a la zona: ", "\nError. Localidad Invalida.", reintentos, 1, lenLocalidades, &auxZona.idLocalidad) == 0) {
					datoIncorrecto = 1;
					break;
				}

			if(datoIncorrecto != 1){
				auxZona.idZona = 0;
				auxZona.estado = 1;
				printf("El id de la zona se cargara luego de confirmar los datos.\n\nDatos de la zona:\n\n%-5s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Calle 1", "Calle 2 ", "Calle 3", "Calle 4", "Localidad", "Estado", "Censista");
				MostrarUnaZona(auxZona, listLocalidades, lenLocalidades, "SIN ASIGNAR", "");
				ConfirmarContinuar("Confirme la carga de la zona (SI/NO): ", "Ingrese una respuesta valida", &confirma, reintentos);
				if(confirma==1){
					strcpy(list[index].calle_1, auxZona.calle_1);
					strcpy(list[index].calle_2, auxZona.calle_2);
					strcpy(list[index].calle_3, auxZona.calle_3);
					strcpy(list[index].calle_4, auxZona.calle_4);
					list[index].idLocalidad = auxZona.idLocalidad;
					list[index].estado = 1;
					list[index].idCensista = 0;
					cargaCompleta = 1;
				}
			}else{
				printf("\nUno o mas datos no fueron cargados correctamente.");
				ConfirmarContinuar("\n¿Quiere volver a reingresar los datos?: (SI/NO)", "Ingrese una respuesta valida", &confirma, reintentos);
			}
		}while(confirma == 1 && cargaCompleta == 0);
	}
	return cargaCompleta;
}

int CargarZonas(eZonas list[], int len, int* id, int reintentos,eLocalidades listLocalidades[], int lenLocalidades){
	int idAux;
	int index;
	int cargaCorrecta;

	cargaCorrecta = 0;
	index = BuscarIndiceLibreZona(list, len);
	if(index!=-1){
		cargaCorrecta = CargarUnaZona(list, reintentos, index, listLocalidades, lenLocalidades);
		if(cargaCorrecta == 1){
			idAux = *id;
			list[index].idZona = idAux+1;
			*id = list[index].idZona;
			list[index].isEmpty = 0;
			printf("ZONA CARGADA\n\n");
		}

	}else{
		printf("\nERROR.No queda lugar para cargar mas zonas\n");
	}

	return cargaCorrecta;
}

int BuscarZonaPorID(eZonas list[], int len, int id, int* index){
	int i;
	int clienteExiste;

	clienteExiste = 0;

	for(i=0; i<len; i++)	{
		if(list[i].isEmpty == 0 && list[i].idZona== id){
			clienteExiste = 1;
			*index = i;
			break;
		}
	}
	return clienteExiste;
}

int CargaForzadaZonas(eZonas list[], int len, int* id){
	int i;
	int idAux;
	int cantidadZonas;
	int cargaExitosa;
	cargaExitosa = 0;
	cantidadZonas = 3;
	idAux = *id;
	int contadorCargaForzada;

	contadorCargaForzada = 0;

	if (len > cantidadZonas && list != NULL){
		for (i = 0; i<len; i++){
			if(list[i].isEmpty == 1 && contadorCargaForzada<cantidadZonas){
				idAux++;
				list[i].idZona = idAux;
				strcpy(list[i].calle_1, "Azara");
				strcpy(list[i].calle_2, "California");
				strcpy(list[i].calle_3, "Rocha");
				strcpy(list[i].calle_4, "Patricios");
				list[i].estado = 1;
				list[i].idCensista = 0;
				list[i].idLocalidad = 1;
				list[i].isEmpty = 0;
				cargaExitosa = 1;
				contadorCargaForzada++;
			}
		}
	}

	*id = idAux;
	if(cargaExitosa == 1){
		printf("\nCARGA COMPLETA\n");
	}

	return cargaExitosa;

}

int ContarTotalDeCensadosPorTipo(eZonas listZonas[], int lenZonas, int tipo){
	int i;
	int totalCensadosPorTipo;

	totalCensadosPorTipo = 0;

	for(i = 0; i<lenZonas; i++){
		if(listZonas[i].estado == 2 && listZonas[i].censadosVirtual>0 && tipo == 1){
			totalCensadosPorTipo = listZonas[i].censadosVirtual + totalCensadosPorTipo;
		}
		if(listZonas[i].estado == 2 && listZonas[i].censadosInSitu>0 && tipo == 2){
			totalCensadosPorTipo = listZonas[i].censadosInSitu + totalCensadosPorTipo;
		}
	}

	return totalCensadosPorTipo;
}

void ObtenerLocalidadConMasAusentes(eZonas listZonas[], int lenZonas, eLocalidades listLocalidades[], int lenLocalidades){
	int i;
	int x;
	int contadorLoc1;
	int contadorLoc2;
	int contadorLoc3;
	int contadorLoc4;
	int contadorLoc5;
	int idLocalidadMax;
	int contadorMax;

	contadorLoc1 = 0;
	contadorLoc2 = 0;
	contadorLoc3 = 0;
	contadorLoc4 = 0;
	contadorLoc5 = 0;
	contadorMax = 0;


	for(i = 0; i<lenZonas; i++){
		if(listZonas[i].estado == 2 && listZonas[i].ausentes>0){
			if(listZonas[i].idLocalidad == 1){
				contadorLoc1 = listZonas[i].ausentes+ contadorLoc1;
				if(contadorMax<contadorLoc1){
					contadorMax = contadorLoc1;
					idLocalidadMax = listZonas[i].idLocalidad;
				}
			}
			if(listZonas[i].idLocalidad == 2){
				contadorLoc2 = listZonas[i].ausentes+ contadorLoc2;
				if(contadorMax<contadorLoc2){
					contadorMax = contadorLoc2;
					idLocalidadMax = listZonas[i].idLocalidad;
				}
			}
			if(listZonas[i].idLocalidad == 3){
				contadorLoc3 = listZonas[i].ausentes+ contadorLoc3;
				if(contadorMax<contadorLoc3){
					contadorMax = contadorLoc3;
					idLocalidadMax = listZonas[i].idLocalidad;
				}
			}
			if(listZonas[i].idLocalidad == 4){
				contadorLoc4 = listZonas[i].ausentes+ contadorLoc4;
				if(contadorMax<contadorLoc4){
					contadorMax = contadorLoc4;
					idLocalidadMax = listZonas[i].idLocalidad;
				}
			}
			if(listZonas[i].idLocalidad == 5){
				contadorLoc5 = listZonas[i].ausentes+ contadorLoc5;
				if(contadorMax<contadorLoc5){
					contadorMax = contadorLoc5;
					idLocalidadMax = listZonas[i].idLocalidad;
				}
			}
		}
	}

	for(x = 0; x<lenLocalidades; x++){
		if(listLocalidades[x].idLocalidad == idLocalidadMax){
			printf("La localidad %s, tiene mayor numero de ausentes: %d.",listLocalidades[x].localidad, contadorMax);
		}
	}

}

int TotalCensadosPorZonaYCensista(eZonas listZonas[], int lenZonas, int idCensista){
	int i;
	int totalCensados;

	totalCensados = 0;

	for(i = 0; i<lenZonas; i++){
		if(listZonas[i].idCensista == idCensista && listZonas[i].estado == 2 && (listZonas[i].censadosVirtual > 0 || listZonas[i].censadosInSitu > 0)){
				totalCensados = listZonas[i].censadosVirtual + totalCensados;
				totalCensados = listZonas[i].censadosInSitu + totalCensados;
		}
	}

	return totalCensados;

}




