#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Censistas.h"

#define CADENA 100
#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3
#define FINALIZADO 1
#define PENDIENTE 2

int InitStructCensistas(eCensistas list[], int len){
	int validacion;

	validacion = 0;

	if(list != NULL && len>0){
		for(int i = 0;i < len; i++)
		    {
		    	list[i].isEmpty = 1;
		        list[i].idCensista = 0;
		    }
		validacion = 1;
	}


    return validacion;

}

void MostrarUnCensista(eCensistas list){

	switch(list.estadoCensista){
		case 1:
			printf("%-5d %-15s %-20s %-d/%d/%-25d %-15d %-8s%-17d %-20s\n", list.idCensista, list.nombre, list.apellido,
			list.fechaDeNacimiento.dia,list.fechaDeNacimiento.mes,list.fechaDeNacimiento.anio , list.edad, list.direccionPersonal.calle,list.direccionPersonal.altura, "ACTIVO");
			break;
		case 2:
			printf("%-5d %-15s %-20s %-d/%d/%-25d %-15d %-8s%-17d %-20s\n", list.idCensista, list.nombre, list.apellido,
			list.fechaDeNacimiento.dia,list.fechaDeNacimiento.mes,list.fechaDeNacimiento.anio , list.edad, list.direccionPersonal.calle,list.direccionPersonal.altura,"INACTIVO");
			break;
		case 3:
			printf("%-5d %-15s %-20s %-d/%d/%-25d %-15d %-8s%-17d %-20s\n", list.idCensista, list.nombre, list.apellido,
			list.fechaDeNacimiento.dia,list.fechaDeNacimiento.mes,list.fechaDeNacimiento.anio , list.edad, list.direccionPersonal.calle,list.direccionPersonal.altura,"LIBERADO");
			break;
	}

}

int MostrasCensistas(eCensistas list[], int len){
	int i;
	int flagDatosVacios;
	int validacion;
	validacion = 0;

	if(list!=NULL && len> 0){
		flagDatosVacios = 1;
			printf("\nDatos de los censistas:\n\n%-5s %-15s %-20s %-30s %-15s %-25s %-25s\n", "ID", "Nombre", "Apellido", "Fecha de Nacimiento", "Edad", "Domicilio", "Estado");
			for (i = 0; i < len; i++) {
				if (list[i].isEmpty == 0 && list[i].idCensista !=0) {
					MostrarUnCensista(list[i]);
					flagDatosVacios = 0;
					validacion = 1;
				}
			}
			if (flagDatosVacios == 1) {
				puts("No se encontraron datos.\n");
			}
	}

	return validacion;

}

int BuscarIndiceLibre(eCensistas list[], int len){
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

int CargarUnCensista(eCensistas list[], int reintentos, int index){
	int cargaCompleta;
	int datoIncorrecto;
	int confirma;
	eCensistas auxCensista;

	cargaCompleta = 0;
	datoIncorrecto = 0;

	if(list != NULL){
		do{
				if (GetLetters("\nIngrese el nombre del Censista: ","\nError. Nombre Invalido.", auxCensista.nombre, sizeof(auxCensista.nombre),reintentos) == 0) {
					datoIncorrecto = 1;
					break;
				}
				if (GetLetters("Ingrese el apellido del Censista: ","\nError. Apellido Invalido.", auxCensista.apellido, sizeof(auxCensista.apellido), reintentos) == 0) {
					datoIncorrecto = 1;
					break;
				}

				printf("Ingrese su fecha de nacimiento: ");
				if (GetNumberWithRange("\nDia: ", "\nError. Dia Invalido.", reintentos, 1, 31, &auxCensista.fechaDeNacimiento.dia) == 0) {
					datoIncorrecto = 1;
					break;
				}
				if (GetNumberWithRange("Mes: ", "\nError. Mes Invalido.", reintentos, 1, 12, &auxCensista.fechaDeNacimiento.mes) == 0) {
					datoIncorrecto = 1;
					break;
				}
				if (GetNumberWithRange("Anio: ", "\nError. Anio Invalido.", reintentos, 1980, 2002, &auxCensista.fechaDeNacimiento.anio) == 0) {
					datoIncorrecto = 1;
					break;
				}
				if (GetNumberWithRange("Ingrese su edad: ", "\nError. Anio Invalido.", reintentos, 18, 60, &auxCensista.edad) == 0) {
					datoIncorrecto = 1;
					break;
				}
				printf("Ingrese su domicilio: ");
				if (GetLetters("\nIngrese el nombre de la calle: ","\nError. Calle Invalida.", auxCensista.direccionPersonal.calle, sizeof(auxCensista.direccionPersonal.calle),reintentos) == 0) {
					datoIncorrecto = 1;
					break;
				}
				if (GetNumberWithRange("Ingrese la altura: ", "\nError. Altura Invalida.", reintentos, 100, 15000, &auxCensista.direccionPersonal.altura) == 0) {
					datoIncorrecto = 1;
					break;
				}

			if(datoIncorrecto != 1){
				auxCensista.idCensista = 0;
				auxCensista.estadoCensista = 3;
				printf("\nEl id del censista de cargara luego de confirmar los datos.\nDatos del censista:\n\n%-5s %-15s %-20s %-30s %-15s %-25s %-20s\n", "ID", "Nombre", "Apellido", "Fecha de Nacimiento", "Edad", "Domicilio", "Estado");
				MostrarUnCensista(auxCensista);
				ConfirmarContinuar("Confirme la carga del Censista (SI/NO): ", "Ingrese una respuesta valida", &confirma, reintentos);

				if(confirma==1){
					strcpy(list[index].nombre, auxCensista.nombre);
					strcpy(list[index].apellido, auxCensista.apellido);
					list[index].fechaDeNacimiento.dia = auxCensista.fechaDeNacimiento.dia;
					list[index].fechaDeNacimiento.mes = auxCensista.fechaDeNacimiento.mes;
					list[index].fechaDeNacimiento.anio = auxCensista.fechaDeNacimiento.anio;
					list[index].edad = auxCensista.edad;
					strcpy(list[index].direccionPersonal.calle, auxCensista.direccionPersonal.calle);
					list[index].direccionPersonal.altura = auxCensista.direccionPersonal.altura;
					list[index].estadoCensista = 3;
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

int CargarCensistas(eCensistas list[], int len, int* id, int reintentos){
	int idAux;
	int index;
	int cargaCorrecta;

	cargaCorrecta = 0;
	index = BuscarIndiceLibre(list, len);
	if(index!=-1){
		cargaCorrecta = CargarUnCensista(list, reintentos, index);
		if(cargaCorrecta == 1){
			idAux = *id;
			list[index].idCensista = idAux+1;
			*id = list[index].idCensista;
			list[index].isEmpty = 0;
			printf("CENSISTA CARGADO\n\n");
			}

	}else{
		printf("\nERROR.No queda lugar para cargar mas censistas\n");
	}

	return cargaCorrecta;
}

int BuscarCensistaPorID(eCensistas list[], int len, int id, int* index){
	int i;
	int clienteExiste;

	clienteExiste = 0;

	for(i=0; i<len; i++)	{
		if(list[i].isEmpty == 0 && list[i].idCensista== id){
			clienteExiste = 1;
			*index = i;
			break;
		}
	}
	return clienteExiste;
}

int ModificarDatosCensista(eCensistas list[], int len, int reintentos){
  int index;
  int idCensista;
  int opcion;
  int opcionCorrecta;
  int continuar;
  int datosCambiados;
  int idExiste;
  int validacionCorrecta;

  datosCambiados = 0;

  if(list!=NULL && len>0){
	  MostrasCensistas(list, len);
	  validacionCorrecta = GetIntNumber("Ingrese el ID del pasajero a modificar: ","\nError. ID invalido.", reintentos, &idCensista);
	  if(validacionCorrecta == 1){
		  idExiste = BuscarCensistaPorID(list, len, idCensista, &index);
	  	  if (idExiste == 1){
	  		do{
	  			opcionCorrecta = GetNumberWithRange("\n1: Nombre"
	  			  				  "\n2: Apellido"
	  			  				  "\n3: Fecha de nacimiento"
	  			  				  "\n4: Edad"
	  			  				  "\n5: Direccion Personal"
	  							  "\n6: Salir"
	  							  "\nIngrese lo que desea modificar: ", "\n\nOpcion invalida\n", reintentos,1,6, &opcion);
	  			if(opcionCorrecta == 1){
	  				switch(opcion){
	  					  		 case 1:
	  					  			 if(GetLetters("\nIngrese el nombre del censista: ", "\nError. Nombre invalido.", list[index].nombre, sizeof(list[index].nombre), reintentos) == 0){
	  					  				printf("Error.No se pudo guardar correctamente el nombre del pasajero.\n");
	  					  			 }
	  					  			 break;
	  					  		 case 2:
	  					  			 if(GetLetters("\nIngrese el apellido del censista: ", "\nError. Apellido invalido.", list[index].apellido, sizeof(list[index].apellido), reintentos)==0){
	  					  				 printf("Error.No se pudo guardar correctamente el apellido del censista.\n");
	  					  			 }
	  					  			 break;
	  					  		 case 3:
	  					  			do{
		  					  			opcionCorrecta = GetNumberWithRange("\n1: Dia\n2: Mes\n3: Anio\n4: Salir\nIngrese que dato desea modificar de la fecha de nacimiento: ", "\n\nOpcion invalida", reintentos, 1, 4, &opcion);
	  					  				if(opcionCorrecta == 1){
	  					  					switch(opcion){
	  					  					case 1:
	  					  						GetNumberWithRange("\nIngrese el Dia: ","\nError. Dia invalido.",reintentos, 1, 31,&list[index].fechaDeNacimiento.dia);
	  					  						break;
	  					  					case 2:
	  					  						GetNumberWithRange("\nIngrese el Mes: ","\nError. Mes invalido.",reintentos, 1, 12,&list[index].fechaDeNacimiento.mes);
	  					  						break;
	  					  					case 3:
	  					  						GetNumberWithRange("\nIngrese el Anio: ","\nError. Anio invalido.",reintentos, 1, 12,&list[index].fechaDeNacimiento.anio);
	  					  						break;
	  					  					}
	  					  					ConfirmarContinuar("¿Quiere seguir modifcando la fecha? (SI/NO): ", "\nRespuesta Invalida.", &continuar, reintentos);
	  					  					if(continuar == 0){
	  					  						opcion = 4;
	  					  						printf("Fecha actualizada.\n");
	  					  					}
	  					  				}else{
	  					  					opcion = 4;
	  					  					printf("\nOpcion invalida. Se regresa al menu principal.\n");
	  					  				}
	  					  			}while(opcion != 4);
	  					  			break;
	  					  		 case 4:
	  					  			 GetNumberWithRange("Ingrese la edad del pasajero: ", "\nError. Edad ingresada invalida.", reintentos, 18, 60, &list[index].edad);
	  					  			 break;
	  					  		 case 5:
	  					  			do{
		  					  			opcionCorrecta = GetNumberWithRange("\n1: Calle\n2: Altura\n3: Salir\nIngrese que dato desea modificar.", "\n\nOpcion invalida", reintentos, 1, 3, &opcion);
	  					  				if(opcionCorrecta == 1){
	  					  					switch(opcion){
	  					  		 	 	 	case 1:
	  					  		 	 	 		GetLetters("\nIngrese la calle: ", "\nError. Calle Invalida.", list[index].direccionPersonal.calle, sizeof(list[index].direccionPersonal.calle), reintentos);
	  					  		 	 	 		break;
	  					  		 	 	 	case 2:
	  					  		 	 	 		GetNumberWithRange("Ingrese la altura: ", "\nError. Altura Invalida.", reintentos, 100, 15000, &list[index].direccionPersonal.altura);
	  					  		 	 	 		break;
	  					  					}
	  					  					ConfirmarContinuar("¿Quiere seguir modifcando la direccion? (SI/NO): ", "\nRespuesta Invalida.", &continuar, reintentos);
	  					  					if(continuar == 0){
	  					  						opcion = 3;
	  					  						printf("Direccion actualizada.\n");
	  					  					}
	  					  				}else{
	  					  					opcion = 3;
	  					  					printf("\nOpcion invalida. Se regresa al menu principal.\n");
	  					  				}
	  					  			}while(opcion!=3);
	  					  			break;
	  					  		 }
	  			}else{
	  				opcion = 6;
	  			}
	  		ConfirmarContinuar("¿Desea modificar otro dato? ", "\nError. Vuelva a intentarlo", &continuar, reintentos);

	  		if(continuar==0){
	  	  	  datosCambiados = 1;
	  	  	  opcion = 6;
	  		}

	  		}while(opcion != 6 );
	  	  }else{
	  		printf("\nEl Id ingresado no se encuentra en la base.\n");
	  	  }
		 }
	  }
  return datosCambiados;
 }

int CargaForzadaCensistas(eCensistas list[], int len, int* id){
	int i;
	int idAux;
	int cantidadCensistas;
	int cargaExitosa;
	cargaExitosa = 0;
	cantidadCensistas = 3;
	idAux = *id;
	int contadorCargaForzada;

	contadorCargaForzada = 0;

	if (len > cantidadCensistas && list != NULL){
		for (i = 0; i<len; i++){
			if(list[i].isEmpty == 1 && contadorCargaForzada<cantidadCensistas){
				idAux++;
				list[i].idCensista = idAux;
				strcpy(list[i].nombre, "Pepe");
				strcpy(list[i].apellido, "Gonzales");
				list[i].fechaDeNacimiento.dia = 7;
				list[i].fechaDeNacimiento.mes = 10;
				list[i].fechaDeNacimiento.anio = 1998;
				list[i].edad = 24;
				strcpy(list[i].direccionPersonal.calle, "Calle Fict");
				list[i].direccionPersonal.altura = 123;
				list[i].estadoCensista = 3;
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

