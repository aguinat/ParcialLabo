#ifndef LIBRARIECOSTUMERS_H_
#define LIBRARIECOSTUMERS_H_

typedef struct
{
	char localidad[100];
}eLocalidad;

typedef struct
{
	int idCliente; // PK
	char empresa[100];
	int cuit;
	char direccion[100];
	char localidad[100];
	int isEmpty;

}eCliente;

typedef struct
{
	int id;
	float acumulador;
	int contador;
	float promedio;

}eAuxliar;

int CargarDatos(eCliente lista[], int tam, int reintentos, int* idGenerado);
eCliente IngresarUnDato(int* validacion, int reintentos);
void InicializarDatos(eCliente lista[], int tam);
int ModificarDatosCliente (eCliente lista[], int tam, int reintentos);
int BorrarCliente(eCliente lista[], int tam, int reintentos);
void MostrarDatosCargados(eCliente lista[], int tam);
void MostrarDatos(eCliente datos);
int BuscarCliente (eCliente lista[], int tam, int idCliente);
int BuscarLocalidad (eCliente lista[], int tam, char localidad[]);
int BuscarPrimerEspacioLibre (eCliente lista[], int tam);

#endif /* LIBRARIECOSTUMERS_H_ */
