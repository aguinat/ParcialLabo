#ifndef LIBRARIECOSTUMERS_H_
#define LIBRARIECOSTUMERS_H_
#include "LibrarieLocalidad.h"

typedef struct
{
	int idCliente; // PK
	char empresa[100];
	int cuit;
	char direccion[100];
	int idLocalidad;
	int isEmpty;

}eCliente;

typedef struct
{
	int id;
	float acumulador;
	int contador;
	float promedio;

}eAuxliar;

int CargarDatos(eCliente lista[], int tam, int reintentos, int* idGenerado, eLocalidad localidades[], int tamLocalidad);
eCliente IngresarUnDato(int* validacion, int reintentos);
void InicializarDatos(eCliente lista[], int tam);
int ModificarDatosCliente (eCliente lista[], int tam, int reintentos, eLocalidad localidades[], int tamLocalidad);
void MostrarDatosCargados(eCliente lista[], int tam, eLocalidad localidades[], int tamLocalidades, int pedidos);
void MostrarDatos(eCliente datos, eLocalidad localidades[], int tamLocalidades, int pedidos);
int BuscarCliente (eCliente lista[], int tam, int idCliente);
int BuscarPrimerEspacioLibre (eCliente lista[], int tam);

#endif /* LIBRARIECOSTUMERS_H_ */
