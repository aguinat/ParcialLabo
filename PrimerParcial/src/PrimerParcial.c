/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : Nathaly Aguila Chavez

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Censistas.h"
#include "Zonas.h"
#include "ControlCensistas.h"
#include "LibrarieInt.h"

#define LEN 10
#define REIN 3
#define LENZONAS 14
#define LENLOCALIDAD 5

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int validacion;
	int idCensista;
	int idZona;
	int opcionSubMenu;
	int censistasCargados;
	int cargaForzadaCensistas;
	int zonaCargada;
	int cargaForzadaZonas;

	eCensistas censistas[LEN];// = {{1,"Andre", "Luizaga", 20,03,2020, 30, "iriarte", 1944,1,0}, {2,"Sabrina", "Soto", 04,05,1993, 29, "avbrown", 633,1,0},
			//{3,"Mariano", "Cañete", 20,03,2020, 30, "California", 2050,3,0}};
	eZonas zonas[LENZONAS];// = {{1,1,"Iriarte", "Herrera", "Montes De Oca", "California",1,0,0,0,1,0}, {2,2,"Montes de oca", "Azara", "California", "Rocha",2,0,0,0,1,0},
			//{3,0,"Suarez", "Vieytes", "Rocha", "Azara",1,0,0,0,1,0}};

	idCensista = 0;
	idZona = 0;
	InitStructCensistas(censistas, LEN);
	InitStructZonas(zonas, LENZONAS);

	eLocalidades localidades[LENLOCALIDAD]={{1,"Avellaneda"},{2,"Barracas"},{3,"La Boca"}, {4,"Lanus"}, {5,"Palermo"}};

	do {
		validacion = GetNumberWithRange("***********************\n"
								"BIENVENIDO\n"
								"1.Cargar censistas\n"
								"2.Modificar censista\n"
								"3.Dar de baja censista\n"
								"4.Cargar zona\n"
								"5.Asignar zona a censar\n"
								"6.Cargar datos\n"
								"7.Mostrar censistas\n"
								"8.Mostrar zonas\n"
								"9.Salir\n"
								"***********************\n"
								"Ingrese una opcion: ",

								"\n***********************\n"
								"BIENVENIDO\n\n"
								"1.Cargar censistas\n"
								"2.Modificar censista\n"
								"3.Dar de baja censista\n"
								"4.Cargar zona\n"
								"5.Asignar zona a censar\n"
								"6.Cargar datos\n"
								"7.Mostrar censistas\n"
								"8.Mostrar zonas\n"
								"9.Salir\n"
								"***********************\n"
								"\nOpcion invalida, vuelva a intentarlo: ", REIN, 1, 9, &opcion);
								printf("\n");
					if (validacion == 1) {
						switch (opcion) {
						case 1:
							GetNumberWithRange("1. Opcion Carga Manual\n2. Opcion Carga Forzada\nElija la forma de carga: ", "\nOpcion invalida, vuelva a intentarlo: ", REIN, 1, 2, &opcionSubMenu);
							switch(opcionSubMenu){
							case 1:
								censistasCargados = CargarCensistas(censistas, LEN, &idCensista, REIN);
								break;
							case 2: cargaForzadaCensistas = CargaForzadaCensistas(censistas, LEN, &idCensista);
							}
							break;
						case 2:
							if(censistasCargados == 1 || cargaForzadaCensistas == 1){
								ModificarDatosCensista(censistas, LEN, REIN);
							}else{
								printf("NO CUENTA CON DATOS DISPONIBLES PARA OPERAR.\n\n");
							}
							break;
						case 3:
							if(censistasCargados == 1 || cargaForzadaCensistas == 1){
								DarDeBajaCensista(censistas, LEN, REIN, zonas , LEN);
							}else{
								printf("NO CUENTA CON DATOS DISPONIBLES PARA OPERAR.\n\n");
							}
							break;
						case 4:
							GetNumberWithRange("1. Opcion Carga Manual\n2. Opcion Carga Forzada\nElija la forma de carga: ", "\nOpcion invalida, vuelva a intentarlo: ", REIN, 1, 2, &opcionSubMenu);
							switch(opcionSubMenu){
							case 1:
								zonaCargada = CargarZonas(zonas, LENZONAS, &idZona, REIN, localidades, LENLOCALIDAD);
								break;
							case 2:
								cargaForzadaZonas = CargaForzadaZonas(zonas, LENZONAS, &idZona);
								break;
							}
							break;
						case 5:
							if((zonaCargada == 1 || cargaForzadaZonas == 1) && (censistasCargados == 1 || cargaForzadaCensistas == 1)){
								AsignarCensistaAzona(censistas, LEN, zonas, LENZONAS, REIN, localidades, LENLOCALIDAD);
							}else{
								printf("NO CUENTA CON DATOS DISPONIBLES PARA OPERAR.\n\n");
							}
							break;
						case 6:
							if(zonaCargada == 1 || cargaForzadaZonas == 1){
								CompletarDatosZona(zonas, LENZONAS, censistas, LEN, localidades, LENLOCALIDAD, REIN);
							}else{
								printf("NO CUENTA CON DATOS DISPONIBLES PARA OPERAR.\n\n");
							}
							break;
						case 7:
							if(censistasCargados == 1 || cargaForzadaCensistas == 1){
								MostrasCensistas(censistas, LEN);
							}else{
								printf("NO CUENTA CON DATOS DISPONIBLES PARA OPERAR.\n\n");
							}
							break;
						case 8:
							if(zonaCargada == 1 || cargaForzadaZonas == 1){
								MostrasZonas(zonas, LENZONAS, censistas, LEN, localidades, LENLOCALIDAD);
							}else{
								printf("NO CUENTA CON DATOS DISPONIBLES PARA OPERAR.\n\n");
							}
							break;
						}
					}else{
						opcion = 9;
						printf("\nEl programa finalizo debido a que no se ingreso ninguna opcion valida\n");
					}

				} while (opcion != 9);

	return EXIT_SUCCESS;
}
