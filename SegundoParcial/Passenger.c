#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include "DataLoading.h"
#define MAX_TYPEPASSENGER 3
#define MAX_STATUSFLIGHT 4
#define LENPALABRA 50
#define LEN_CODE 7
#define REIN 3
#define LINEA_ARCHIVO 7
#define MAX_PRICE 50000

int Passenger_setId(Passenger* this,int id){
	int setCorrecto;

	setCorrecto = 0;
	if (this != NULL && id>= 0) {
		this->id = id;
		setCorrecto = 1;
	}
	return setCorrecto;
}
int Passenger_getId(Passenger* this,int* id){
	int getCorrecto;

	getCorrecto = 0;
	if(this!=NULL && id!=NULL){
		*id = this->id;
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setNombre(Passenger* this,char* nombre){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		setCorrecto = 1;
	}

	return setCorrecto;
}
int Passenger_getNombre(Passenger* this,char* nombre){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre,this->nombre);
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setApellido(Passenger* this,char* apellido){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && apellido != NULL){
		strcpy(this->apellido, apellido);
		setCorrecto = 1;
	}

	return setCorrecto;
}
int Passenger_getApellido(Passenger* this,char* apellido){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		setCorrecto = 1;
	}

	return setCorrecto;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && ValidarRango(tipoPasajero, 0, MAX_TYPEPASSENGER) == 1){
		this->tipoPasajero = tipoPasajero;
		setCorrecto = 1;
	}else{
		printf("ERROR. No fue posible guardar el tipo de pasajero.\n");
	}

	return setCorrecto;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setPrecio(Passenger* this, float precio){
	int setCorrecto;

	setCorrecto = 0;
	if( this != NULL && ValidarRangoFloat(precio, 0, MAX_PRICE) == 1){
		this->precio = precio;
		setCorrecto = 1;
	}else{
		printf("ERROR. No fue posible guardar el precio.\n");
	}

	return setCorrecto;
}
int Passenger_getPrecio(Passenger* this,float* precio){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		getCorrecto = 1;
	}

	return getCorrecto;
}
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo){
	int setCorrecto;

	setCorrecto = 0;
	if (this != NULL && ValidarRango(estadoVuelo, 1, MAX_STATUSFLIGHT) == 1) {
		this->estadoVuelo = estadoVuelo;
		setCorrecto = 1;
	} else {
		printf("ERROR. No fue posible guardar el estado del vuelo.\n");
	}

	return setCorrecto;
}
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo){
	int getCorrecto;

	getCorrecto = 0;
	if (this != NULL && estadoVuelo != NULL) {
		*estadoVuelo = this->estadoVuelo;
		getCorrecto = 1;
	}

	return getCorrecto;
}

void Passenger_delete(Passenger* this){
	if(this != NULL){
		free(this);
	}
}

Passenger* Passenger_new(){
	Passenger* auxPassenger = NULL;
	auxPassenger = (Passenger*)malloc(sizeof(Passenger));
		Passenger_setId(auxPassenger, 0);
		Passenger_setApellido(auxPassenger, "");
		Passenger_setNombre(auxPassenger, "");
		Passenger_setCodigoVuelo(auxPassenger, 0);
	return auxPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajero, char* apellidoStr, char* precio, char* codigoVuelo, char* estadoVuelo){
	int statusNumFlight;
	int typePassengerNum;
	Passenger* auxPassenger = NULL;
	auxPassenger = Passenger_new();

	if(auxPassenger !=NULL){
		if(idStr != NULL && nombreStr != NULL && tipoPasajero != NULL && apellidoStr != NULL && precio != NULL && codigoVuelo != NULL && estadoVuelo != NULL){
			getNum_StatusFlight(estadoVuelo, &statusNumFlight);
			getNum_PassegerType(tipoPasajero, &typePassengerNum);

			Passenger_setId(auxPassenger, atoi(idStr));
			Passenger_setNombre(auxPassenger, nombreStr);
			Passenger_setApellido(auxPassenger, apellidoStr);
			Passenger_setCodigoVuelo(auxPassenger, codigoVuelo);
			Passenger_setPrecio(auxPassenger, atof(precio));
			Passenger_setTipoPasajero(auxPassenger, typePassengerNum);
			Passenger_setEstadoVuelo(auxPassenger, statusNumFlight);
		}else{
			Passenger_delete(auxPassenger);
			auxPassenger = NULL;
		}

	}

	return auxPassenger;
}

Passenger* Passenger_getFromUser(int* cargaCorrecta, int* id){
	int cargaCompleta;
	int datoIncorrecto;
	int confirma;
	char auxNombre[LENPALABRA];
	char auxApellido[LENPALABRA];
	char auxCodigo[LEN_CODE];
	char idStr[50];
	float auxPrecio;
	char precioStr[50];
	char tipoPasajeroStr[50];
	char estadoVueloStr[50];
	int auxTipoPasajero;
	int auxEstadoVuelo;
	Passenger* auxPassenger = NULL;
	*id = *id+1;
	cargaCompleta = 0;
	datoIncorrecto = 0;

	if (cargaCorrecta != NULL) {
		do {
			if (getPalabra(auxNombre, "Ingrese su nombre: \n", "ERROR. Nombre invalido.\n") == 0) {
				datoIncorrecto = 1;
			}
			if (getPalabra(auxApellido, "Ingrese su apellido: \n","ERROR. Apellido invalido.\n") == 0) {
				datoIncorrecto = 1;
			}
			if (getCodigoVuelo(auxCodigo, LEN_CODE) == 0) {
				datoIncorrecto = 1;
			}
			if (getPrice(&auxPrecio) == 1) {
				sprintf(precioStr,"%f", auxPrecio);
			}else{
				datoIncorrecto = 1;
			}
			if (getPassegerType(&auxTipoPasajero) == 1) {
				getStr_PassegerType(tipoPasajeroStr, auxTipoPasajero);
			}else{
				datoIncorrecto = 1;
			}
			if (getStatusFlight(&auxEstadoVuelo) == 1) {
				getStr_StatusFlight(estadoVueloStr, auxEstadoVuelo);
			}else{
				datoIncorrecto = 1;
			}
			if (datoIncorrecto != 1) {
				ConfirmarContinuar("Confirme la carga del pasajero (SI/NO): ","Ingrese una respuesta valida", &confirma, REIN);
				if (confirma == 1) {
					sprintf(idStr,"%d", *id);
					auxPassenger = Passenger_newParametros(idStr, auxNombre, tipoPasajeroStr, auxApellido, precioStr, auxCodigo, estadoVueloStr);
					if(auxPassenger != NULL){
						cargaCompleta = 1;
					}
				}
			} else {
				printf("\nUno o mas datos no fueron cargados correctamente.");
				ConfirmarContinuar("\n¿Quiere volver a reingresar los datos?: (SI/NO)", "\nIngrese una respuesta valida. ", &confirma, REIN);
			}
		} while (confirma == 1 && cargaCompleta == 0);
	}

	*cargaCorrecta = cargaCompleta;
	return auxPassenger;
}

void MostrarUnPasajero(Passenger* this){
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int estadoVuelo;
	char estadoVuelo_Str[50];
	int estadoVueloValido;
	int tipoPasajero;
	char tipoPasajero_Str[50];
	int tipoPasajeroValido;

	if(this!=NULL){
		Passenger_getId(this, &id);
		Passenger_getNombre(this, nombre);
		Passenger_getApellido(this, apellido);
		Passenger_getCodigoVuelo(this, codigoVuelo);
		Passenger_getPrecio(this, &precio);
		Passenger_getTipoPasajero(this, &tipoPasajero);
		Passenger_getEstadoVuelo(this, &estadoVuelo);

		if(tipoPasajero>0 && estadoVuelo>0){
			estadoVueloValido = getStr_StatusFlight(estadoVuelo_Str, estadoVuelo);
			tipoPasajeroValido = getStr_PassegerType(tipoPasajero_Str, tipoPasajero);
			if(estadoVueloValido == 1 && tipoPasajeroValido == 1){
				printf("%-5d %-15s %-20s %-20s %-15.2f %-20s %-20s\n", id, nombre, apellido, codigoVuelo, precio, tipoPasajero_Str, estadoVuelo_Str);
			}
		}
	}

}

int ModificarDatosPasajero(Passenger* this){
	int opcionCorrecta;
	int opcion;
	int confirma;
	int datosModifcados;
	char auxNombre[50];
	char auxApellido[50];
	char auxCodigo[50];
	float auxPrecio;
	int auxTipoPasajero;
	int auxEstadoVuelo;
	Passenger* auxPassenger = this;

	datosModifcados =  0;
	do{
		opcionCorrecta = GetNumberWithRange(
				"\n1: Nombre"
				"\n2: Apellido"
				"\n3: Precio"
				"\n4: Tipo pasajero"
				"\n5: Codigo de Vuelo"
				"\n6: Estado de vuelo"
				"\n7: Salir"
				"\nIngrese lo que desea modificar: ", "\n\nOpcion invalida\n",REIN, 1, 7, &opcion);
		if(opcionCorrecta==1){
			switch (opcion) {
			case 1:
				if (getPalabra(auxNombre, "\nIngrese el nombre del pasajero: ","\nERROR. Nombre invalido.\n") == 1) {
					Passenger_setNombre(auxPassenger, auxNombre);
					printf("Pasajero luego de la modificacion:\n");
					printf("\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Codigo Vuelo", "Precio","Tipo Pasajero", "Estado Vuelo");
					MostrarUnPasajero(auxPassenger);
					ConfirmarContinuar("¿Confirma el dato modificado? (SI/NO) ", "\nError. Vuelva a intentarlo", &confirma, REIN);
					if(confirma == 1){
						Passenger_setNombre(this, auxNombre);
						datosModifcados = 1;
					}
				}
				break;
			case 2:
				if (getPalabra(auxApellido, "Ingrese el apellido del pasajero: \n","ERROR. Apellido invalido.\n")== 1) {
					Passenger_setApellido(auxPassenger, auxApellido);
					printf("Pasajero luego de la modificacion:\n\n");
					printf("\n\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Codigo Vuelo", "Precio","Tipo Pasajero", "Estado Vuelo");
					MostrarUnPasajero(auxPassenger);
					ConfirmarContinuar("¿Confirma el dato modificado? (SI/NO) ", "\nError. Vuelva a intentarlo", &confirma, REIN);
					if (confirma == 1) {
						Passenger_setApellido(this, auxApellido);
						datosModifcados = 1;
					}
				}
				break;
			case 3:
				if(getPrice(&auxPrecio) == 1){
					Passenger_setPrecio(auxPassenger, auxPrecio);
					printf("Pasajero luego de la modificacion:\n\n");
					printf("\n\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Codigo Vuelo", "Precio","Tipo Pasajero", "Estado Vuelo");
					MostrarUnPasajero(auxPassenger);
					ConfirmarContinuar("¿Confirma el dato modificado? (SI/NO) ", "\nError. Vuelva a intentarlo", &confirma, REIN);
					if (confirma == 1) {
						Passenger_setPrecio(this, auxPrecio);
						datosModifcados = 1;
					}
				}
				break;
			case 4:
				if(getPassegerType(&auxTipoPasajero) == 1){
					Passenger_setTipoPasajero(auxPassenger, auxTipoPasajero);
					printf("Pasajero luego de la modificacion:\n\n");
					printf("\n\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Codigo Vuelo", "Precio","Tipo Pasajero", "Estado Vuelo");
					MostrarUnPasajero(auxPassenger);
					ConfirmarContinuar("¿Confirma el dato modificado? (SI/NO) ","\nError. Vuelva a intentarlo", &confirma, REIN);
					if (confirma == 1) {
						Passenger_setTipoPasajero(this, auxTipoPasajero);
						datosModifcados = 1;
					}
				}
				break;
			case 5:
				if(getCodigoVuelo(auxCodigo, LEN_CODE) == 1){
					Passenger_setCodigoVuelo(auxPassenger, auxCodigo);
					printf("Pasajero luego de la modificacion:\n\n");
					printf("\n\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Codigo Vuelo", "Precio","Tipo Pasajero", "Estado Vuelo");
					MostrarUnPasajero(auxPassenger);
					ConfirmarContinuar("¿Confirma el dato modificado? (SI/NO) ","\nError. Vuelva a intentarlo", &confirma, REIN);
					if (confirma == 1) {
						Passenger_setCodigoVuelo(this, auxCodigo);
						datosModifcados = 1;
					}
				}
				break;
			case 6:
				if(getStatusFlight(&auxEstadoVuelo) == 1){
					Passenger_setEstadoVuelo(auxPassenger, auxEstadoVuelo);
					printf("Pasajero luego de la modificacion:\n\n");
					printf("\n\nDatos del pasajero:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Codigo Vuelo", "Precio","Tipo Pasajero", "Estado Vuelo");
					MostrarUnPasajero(auxPassenger);
					ConfirmarContinuar("¿Confirma el dato modificado? (SI/NO) ","\nError. Vuelva a intentarlo", &confirma, REIN);
					if (confirma == 1) {
						Passenger_setEstadoVuelo(this, auxEstadoVuelo);
						datosModifcados = 1;
					}
				}
				break;
			}
			ConfirmarContinuar("¿Desea modificar otro dato? (SI/NO) ", "\nError. Vuelva a intentarlo", &confirma, REIN);
			if (confirma==0) {
			}
				printf("\nDATOS MODIFICADOS CORRECTAMENTE.\n\n");
		}else{
			opcion = 7;
		}
	}while(opcion != 7 && confirma == 1) ;

	return datosModifcados;
}

Passenger* GetPassenger_ById(LinkedList* pArrayListPassenger, int id, int* index){
	int largoDeLista;
	int idAux;
	Passenger * auxPassenger = NULL;

	*index = -1;
	largoDeLista = ll_len(pArrayListPassenger);
	if (largoDeLista > 0) {
		for (int i = 0; i < largoDeLista; i++) {
			auxPassenger = ll_get(pArrayListPassenger, i);
			Passenger_getId(auxPassenger, &idAux);
			if (id == idAux) {
				*index = i;
				break;
			}
		}
	}

	return auxPassenger;
}


int Passenger_sortByApellido(Passenger* pasajeroUno, Passenger* pasajeroDos){
	int retorno;
	char auxParamUno[100];
	char auxParamDos[100];
	char auxNombreUno[100];
	char auxNombreDos[100];

	if(pasajeroUno != NULL && pasajeroUno != NULL){
		Passenger_getApellido(pasajeroUno, auxParamUno);
		Passenger_getApellido(pasajeroDos, auxParamDos);
		retorno = strcmp(auxParamUno, auxParamDos);
		if(retorno == 0){
			Passenger_getNombre(pasajeroUno, auxNombreUno);
			Passenger_getNombre(pasajeroDos, auxNombreDos);
			retorno = strcmp(auxNombreUno, auxNombreDos);
		}
	}

	return retorno;
}

int Passenger_sortByPrecio(Passenger* pasajeroUno, Passenger* pasajeroDos){
	int retorno;
	float precio1;
	float precio2;

	retorno = 0;
	if(pasajeroUno != NULL && pasajeroUno != NULL){
		Passenger_getPrecio(pasajeroUno, &precio1);
		Passenger_getPrecio(pasajeroDos, &precio2);
		if(precio1 > precio2){
			retorno = 1;
		}else if(precio2 > precio1){
			retorno = -1;
		}
	}

	return retorno;
}

int Passenger_sortByTipoPasajero(Passenger* pasajeroUno, Passenger* pasajeroDos){
	int retorno;
	int tipoPasajeroUno;
	int tipoPasajeroDos;

	retorno = 0;
	if(pasajeroUno != NULL && pasajeroUno != NULL){
		Passenger_getTipoPasajero(pasajeroUno, &tipoPasajeroUno);
		Passenger_getTipoPasajero(pasajeroDos, &tipoPasajeroDos);
		if (tipoPasajeroUno > tipoPasajeroDos) {
			retorno = 1;
		} else if (tipoPasajeroDos > tipoPasajeroUno) {
			retorno = -1;
		}
	}

	return retorno;
}

int Passenger_sortByEstadoVuelo(Passenger* pasajeroUno, Passenger* pasajeroDos){
	int retorno;
	int estadoVueloUno;
	int estadoVueloDos;

	retorno = 0;
	if(pasajeroUno != NULL && pasajeroUno != NULL) {
		Passenger_getEstadoVuelo(pasajeroUno, &estadoVueloUno);
		Passenger_getEstadoVuelo(pasajeroUno, &estadoVueloDos);
		if (estadoVueloUno > estadoVueloDos) {
			retorno = 1;
		} else if (estadoVueloDos > estadoVueloUno) {
			retorno = -1;
		}
	}

	return retorno;
}
