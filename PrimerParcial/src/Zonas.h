#ifndef ZONAS_H_
#define ZONAS_H_

typedef struct
{
	int idLocalidad;
	char localidad[51];

}eLocalidades;

typedef struct
{
	int idZona; // PK
	int idCensista; // FK
	char calle_1[51];
	char calle_2[51];
	char calle_3[51];
	char calle_4[51];
	int idLocalidad;
	int censadosInSitu;
	int censadosVirtual;
	int ausentes;
	int estado; // ---> Finalizado/Pendiente
	int isEmpty;

}eZonas;

int InitStructZonas(eZonas list[], int len);
void MostrarLocalidades(eLocalidades list[], int len, int mostrarUna, int index);
void MostrarUnaZona(eZonas list, eLocalidades listLocalidades[], int lenLocalidades, char NombreCensista[], char ApellidoCensista[]);
int BuscarIndiceLibreZona(eZonas list[], int len);
int CargarUnaZona(eZonas list[], int reintentos, int index, eLocalidades listLocalidades[], int lenLocalidades);
int CargarZonas(eZonas list[], int len, int* id, int reintentos,eLocalidades listLocalidades[], int lenLocalidades);
int BuscarZonaPorID(eZonas list[], int len, int id, int* index);
int CargaForzadaZonas(eZonas list[], int len, int* id);
int ContarTotalDeCensadosPorTipo(eZonas listZonas[], int lenZonas, int tipo);
int TotalCensadosPorZonaYCensista(eZonas listZonas[], int lenZonas, int idCensista);
void ObtenerLocalidadConMasAusentes(eZonas listZonas[], int lenZonas, eLocalidades listLocalidades[], int lenLocalidades);

#endif /* ZONAS_H_ */
