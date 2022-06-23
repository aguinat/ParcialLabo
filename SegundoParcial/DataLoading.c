#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdio.h>
#include <string.h>

#define FIRSTCLASS 1
#define ENCONOMY 2
#define EXECUTIVE 3
#define REIN 3
#define MAX_PRICE 10000
#define ATERRIZADO 1
#define HORARIO 2
#define ENVUELO 3
#define DEMORADO 4

int getPalabra(char palabra[], char mensaje[], char mensajeErrorFinal[]){
	int palabraCorrecta;
	int lenPalabra = 50;
	palabraCorrecta = 0;
	char auxPalabra[lenPalabra];

	if(palabra != NULL){
		if (GetLetters(mensaje, "ERROR.\n", auxPalabra, lenPalabra, REIN)== 1){
			strcpy(palabra,auxPalabra);
			palabraCorrecta = 1;
		}else{
			printf("%s\n", mensajeErrorFinal);
		}

	}

	return palabraCorrecta;
}

int getCodigoVuelo(char codigo[], int lenCodigo){
	int codigoCorrecto;
	codigoCorrecto = 0;
	char auxCodigo[6];

	if(codigo != NULL && lenCodigo > 0){
		if(GetStringAlfaNum("\nIngrese su codigo de vuelo: ", "ERROR. Codigo invalido\n", auxCodigo, lenCodigo, REIN)!=0){
			strcpy(codigo, auxCodigo);
			codigoCorrecto = 1;
		}else{
			printf("ERROR, Codigo ingresado invalido, no se guardo el valor.\n");
		}
	}
	return codigoCorrecto;
}

int getPassegerType(int* typePassenger){
	int tipoCorrecto;
	tipoCorrecto = 0;
	int numero;

	if(typePassenger!= NULL){
		if(GetNumberWithRange("Ingrese el tipo de pasajero (1 - FirstClass, 2 - Economy, 3 - Executive): ", "ERROR. Tipo invalido\n ", REIN, 1, 3, &numero)== 1){
			*typePassenger = numero;
			tipoCorrecto = 1;
		}else{
			printf("ERROR, el tipo de pasajero ingresado es invalido, no se guardo el valor.\n");
		}
	}

	return tipoCorrecto;
}

int getPrice(float* price){
	int precioValido;
	precioValido = 0;
	float auxPrecio;

	if(price != NULL){
		if(GetFloatNumberWithRange("Ingrese el precio: ","ERROR. Precio invalido.\n", REIN, 0, MAX_PRICE, &auxPrecio) == 1){
			*price = auxPrecio;
			precioValido = 1;
		}
	}else{
		printf("ERROR, el precio del pasaje es invalido, no se guardo el valor.\n");
	}
	return precioValido;
}

int getStatusFlight(int* statusFlight){
	int tipoCorrecto;
	tipoCorrecto = 0;
	int numero;

	if(statusFlight!= NULL){
		if(GetNumberWithRange("Ingrese el estado de vuelo (1 - ATERRIZADO, 2 - HORARIO, 3 - EN VUELO, 4 - DEMORADO): ", "ERROR. Tipo invalido\n", REIN, 1, 4, &numero)== 1){
			*statusFlight = numero;
			tipoCorrecto = 1;
		}else{
			printf("ERROR, el estado del vuelo es invalido, no se guardo el valor.\n");
		}
	}

	return tipoCorrecto;
}

int getStr_StatusFlight(char statusStr[], int statusNum){
	int estadoValido;

	estadoValido = 0;

	if(statusStr != NULL && statusNum>0){
		switch(statusNum){
		case 1:
			strcpy(statusStr,"Aterrizado");
			estadoValido = 1;
			break;
		case 2:
			strcpy(statusStr,"En Horario");
			estadoValido = 1;
			break;
		case 3:
			strcpy(statusStr, "En Vuelo");
			estadoValido = 1;
			break;
		case 4:
			strcpy(statusStr, "Demorado");
			estadoValido = 1;
			break;
		}
	}

	return estadoValido;
}

int getNum_StatusFlight(char statusStr[], int* statusNum){
	int estadoValido;
	char estado_Uno[] = "ATERRIZADO";
	char estado_Dos[] = "EN HORARIO";
	char estado_Tres[] = "EN VUELO";
	char estado_Cuatro[] = "DEMORADO";
	estadoValido = 0;

	if(statusStr != NULL && statusNum	!= NULL){
		StringUpper(statusStr);
		if(strcmp(statusStr, estado_Uno)== 0){
			*statusNum = 1;
			estadoValido = 1;
		}
		if(strcmp(statusStr, estado_Dos)== 0){
			*statusNum = 2;
			estadoValido = 1;
		}
		if(strcmp(statusStr, estado_Tres)== 0){
			*statusNum = 3;
			estadoValido = 1;
		}
		if (strcmp(statusStr, estado_Cuatro) == 0) {
			*statusNum = 4;
			estadoValido = 1;
		}
	}

	return estadoValido;
}

int getNum_PassegerType(char passegerTypeStr[], int* passegerTypeNum){
	int estadoValido;
	char tipo_Uno[] = "FIRSTCLASS";
	char tipo_Dos[] = "ECONOMYCLASS";
	char tipo_Tres[] = "EXECUTIVECLASS";

	estadoValido = 0;

	if (passegerTypeStr != NULL && passegerTypeNum != NULL) {
		StringUpper(passegerTypeStr);
		if (strcmp(passegerTypeStr, tipo_Uno) == 0) {
			*passegerTypeNum = 1;
			estadoValido = 1;
		}
		if (strcmp(passegerTypeStr, tipo_Dos) == 0) {
			*passegerTypeNum = 2;
			estadoValido = 1;
		}
		if (strcmp(passegerTypeStr, tipo_Tres) == 0) {
			*passegerTypeNum = 3;
			estadoValido = 1;
		}
	}

	return estadoValido;
}

int getStr_PassegerType(char passegerTypeStr[], int passegerTypeNum){
	int tipoValido;

	tipoValido = 0;

	if (passegerTypeStr != NULL && passegerTypeNum > 0) {
		switch (passegerTypeNum) {
		case 1:
			strcpy(passegerTypeStr, "FirstClass");
			tipoValido = 1;
			break;
		case 2:
			strcpy(passegerTypeStr, "EconomyClass");
			tipoValido = 1;
			break;
		case 3:
			strcpy(passegerTypeStr, "ExecutiveClass");
			tipoValido = 1;
			break;
		}
	}

	return tipoValido;
}
