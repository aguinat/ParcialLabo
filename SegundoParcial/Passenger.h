#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[7];
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajero, char* apellidoStr, char* precio, char* codigoVuelo, char* estadoVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

Passenger* Passenger_getFromUser(int* cargaCorrecta, int* id);
int ModificarDatosPasajero(Passenger* this);
Passenger* GetPassenger_ById(LinkedList* pArrayListPassenger, int id, int* index);
void MostrarUnPasajero(Passenger* this);

int Passenger_sortByApellido(Passenger* pasajeroUno, Passenger* pasajeroDos);
int Passenger_sortByPrecio(Passenger* pasajeroUno, Passenger* pasajeroDos);
int Passenger_sortByTipoPasajero(Passenger* pasajeroUno, Passenger* pasajeroDos);
int Passenger_sortByEstadoVuelo(Passenger* pasajeroUno, Passenger* pasajeroDos);

#endif /* PASSENGER_H_ */
