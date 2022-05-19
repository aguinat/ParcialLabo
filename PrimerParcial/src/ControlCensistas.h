#ifndef CONTROLCENSISTAS_H_
#define CONTROLCENSISTAS_H_
#include "Censistas.h"
#include "Zonas.h"

int CambiarEstadoCensista(eCensistas listCensista[], int idCensista, int index, eZonas listZona[],int lenZona);
int DarDeBajaCensista(eCensistas list[], int len, int reintentos, eZonas listZona[], int lenZona);
int MostrasZonas(eZonas listZonas[], int lenZonas, eCensistas listCensistas[], int lenCensistas, eLocalidades listLocalidades[], int lenLocalidades);
int AsignarCensistaAzona(eCensistas listCensista[],int lenCensista, eZonas listZona[], int lenZona, int reintentos, eLocalidades listLocalidades[], int lenLocalidades);
int CompletarDatosZona(eZonas listZonas[], int lenZonas, eCensistas listCensistas[], int lenCensistas, eLocalidades listLocalidades[], int lenLocalidades, int reintentos);

#endif /* CONTROLCENSISTAS_H_ */
