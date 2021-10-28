#ifndef LIBRARIELOCALIDAD_H_
#define LIBRARIELOCALIDAD_H_

typedef struct{

	int idLocalidad;
	char localidad[100];
	int isEmpty;

}eLocalidad;

void MostrarLocalidades(eLocalidad localidades[], int tamLocalidades);
void MostrarUnaLocalidad(eLocalidad localidad);
int BuscarLocalidad (eLocalidad localidades[], int tam, char localidad[], int* idLocalidad);


#endif /* LIBRARIELOCALIDAD_H_ */
