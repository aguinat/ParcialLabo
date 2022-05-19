#ifndef CENSISTAS_H_
#define CENSISTAS_H_

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	char calle[51];
	int altura;

}eDirecciones;

typedef struct
{
	int idCensista; // PK
	char nombre[51];
	char apellido[51];
	eFecha fechaDeNacimiento;
	int edad;
	eDirecciones direccionPersonal;
	int estadoCensista; //---> estado del censista , Activo/Inactivo/Liberado.
	int isEmpty;

}eCensistas;

int InitStructCensistas(eCensistas list[], int len);
void MostrarUnCensista(eCensistas list);
int MostrasCensistas(eCensistas list[], int len);
int BuscarIndiceLibre(eCensistas list[], int len);
int BuscarCensistaPorID(eCensistas list[], int len, int id, int* index);
int CargarUnCensista(eCensistas list[], int reintentos, int index);
int CargarCensistas(eCensistas list[], int len, int* id, int reintentos);
int ModificarDatosCensista(eCensistas list[], int len, int reintentos);
int CargaForzadaCensistas(eCensistas list[], int len, int* id);



#endif /* CENSISTAS_H_ */
