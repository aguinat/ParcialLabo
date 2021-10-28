#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibrarieReports.h"


void MostrarCantidadPedidosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades){
	int i;
	int existenPedidos;
	int pedidosCliente;
	int contadorClientesConPedidos;

	contadorClientesConPedidos = 0;

	printf("\n IdCliente \t Empresa \t  Cuit \t\tDireccion \t Localidad \t PedidosPendientes\n");
	for (i = 0; i < tamClientes; i++) {
		pedidosCliente = 0;
		existenPedidos = ContarPedidosPorEstado(clientes[i].idCliente, tamPedidos, pedidos, &pedidosCliente, "Pendiente");
		if(existenPedidos == 1 && pedidos[i].isEmpty==0){
			MostrarDatos(clientes[i], localidades, tamLocalidades, pedidosCliente);
			contadorClientesConPedidos++;
		}else{
			if(contadorClientesConPedidos == 0){
				puts("No se encontraron clientes con pedidos pendientes");
			}
		}
	}
}

void MostrarPedidosPorEstado(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, char estado[]){
	int i;
	int j;
	int existenPedidos;
	int contadorPedidos;
	int pedidosCliente;

	contadorPedidos = 0;

	if(stricmp(estado,"Pendiente") == 0){
		printf("\n Estado \t Cuit del cliente \t Dirección \t Kilos a Recolectar \n");
	}else{
		if(stricmp(estado,"Completado") == 0){
			printf("\n Estado \t Cuit del cliente \t Dirección \t Residuos HDPE \t Residuos LDPE \t Residuos PP  \n");
		}
	}

	for (i = 0; i < tamPedidos; i++) {
		existenPedidos = ContarPedidosPorEstado(pedidos[i].cliente, tamPedidos, pedidos, &pedidosCliente, estado);
		for (j = 0; j < tamClientes; j++) {
				if (pedidos[i].cliente == clientes[j].idCliente && (stricmp(pedidos[i].estado,estado) == 0) && clientes[i].isEmpty == 0){
					if(stricmp(estado,"Pendiente") == 0){
						printf("%10s %20d %17s %16.2f\n\n", pedidos[i].estado, clientes[j].cuit, clientes[j].direccion, pedidos[i].residuosTotales);
					}else{
						if(stricmp(estado,"Completado") == 0){
							printf("%10s %16d %20s %16.2f %15.2f %15.2f\n\n", pedidos[i].estado, clientes[i].cuit, clientes[i].direccion, pedidos[i].residuosHDPE,pedidos[i].residuosLDPE, pedidos[i].residuosPP);
						}
					}
					contadorPedidos++;
				}else{
					if(contadorPedidos == 0 && existenPedidos==0){
						printf("No se encontraron clientes con pedidos en estado %s",estado);
					}
				}
		}
	}
}


void MostrarPedidosPorLocalidad(ePedido pedido[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidad) {
	int i;
	int idLocalidadEncontrado;
	int contadorPedidos;
	int reintentos;
	int validacionString;
	int localidadExiste;
	char localidad[200];

	idLocalidadEncontrado = 0;
	reintentos = 5;
	contadorPedidos = 0;

	validacionString = GetString("Ingrese una localidad a mostrar: ", "\nError", localidad, sizeof(localidad), reintentos);
	if(validacionString == 1){
		localidadExiste = BuscarLocalidad(localidades, tamLocalidad, localidad, &idLocalidadEncontrado);
		if(localidadExiste == 1 && idLocalidadEncontrado != 0){
			for( i = 0; i< tamClientes ; i++){
				if(clientes[i].idLocalidad == idLocalidadEncontrado){
					ContarPedidosPorEstado(clientes[i].idCliente, tamPedidos, pedido, &contadorPedidos,"Pendiente");
					}
				}
			}
		}

	if(contadorPedidos>0 ){
		printf("\nPedidos pendientes: %d\n\n", contadorPedidos);
	}else{
		if(localidadExiste == 1){
			puts("\nNo se encontrados pedidos pendientes para la localidad ingresada\n");
		}else{
			puts("\nLa localidad ingresada no existe\n");
		}
	}
}

int ContarPedidosPorEstado(int idCliente, int tamPedidos, ePedido pedido[], int* numPedidos, char estado[]) {
	int j;
	int validacion;
	int contadorPedidos;

	validacion = 0;
	contadorPedidos = *numPedidos;

	for (j = 0; j < tamPedidos; j++) {
		if (idCliente == pedido[j].cliente && (stricmp(pedido[j].estado, estado) == 0)) {
			contadorPedidos = contadorPedidos+1;
			*numPedidos = contadorPedidos;
			validacion = 1;
		}
	}
	return validacion;
}


void CalcularPromedioPolipropileno(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes){
	int i ;
	int j ;
	eAuxliar acumulador[tamClientes];

	for(i=0; i<tamClientes;i++){
		acumulador[i].id = clientes[i].idCliente;
		acumulador[i].acumulador = 0;
		acumulador[i].contador = 0;
		acumulador[i].promedio = 0;
	}

	for (i=0; i<tamClientes; i++){
		for (j =0; j<tamPedidos; j++){
			if(acumulador[i].id == pedidos[j].cliente){
				acumulador[i].acumulador = acumulador[i].acumulador + pedidos[j].residuosPP;
				acumulador[i].contador++;
			}
		}
	}

	printf("\n IdCliente \t PromedioPolipropileno\n");
	for(i=0; i<tamClientes; i++){
		acumulador[i].promedio = acumulador[i].acumulador/acumulador[i].contador;
		if(acumulador[i].id!=0){
			printf("%5d %20.2f\n\n", acumulador[i].id, acumulador[i].promedio);
		}
	}

}

void CalcularPedidosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, char estado[]){
	int i ;
	int j ;
	int pedidosMax;
	int idMax;
	eAuxliar acumulador[tamClientes];

	pedidosMax = 0;


	for(i=0; i<tamClientes;i++){
		acumulador[i].id = clientes[i].idCliente;
		acumulador[i].contador = 0;
	}

	for (i=0; i<tamClientes; i++){
		for (j =0; j<tamPedidos; j++){
			if(acumulador[i].id == pedidos[j].cliente && pedidos[j].isEmpty == 0 && stricmp(pedidos[j].estado,estado) == 0){
				if(stricmp(estado,"Pendiente") == 0){
					acumulador[i].contador++;
				}else{
					if(stricmp(estado,"Completado") == 0){
						acumulador[i].contador++;
					}
				}

			}else{
				if(stricmp(estado,"") == 0){
					acumulador[i].contador++;
				}
			}
		}
	}

	for(i=0; i<tamClientes; i++){
		if(acumulador[i].contador>pedidosMax){
			pedidosMax = acumulador[i].contador;
			idMax = acumulador[i].id;
		}
	}
	printf("\nEl id del cliente con mas pedidos %s es: %d\n\n",estado, idMax);

}

int DarClienteDeBaja(eCliente lista[], int tam, int reintentos, eLocalidad localidades[], int tamLocalidades, ePedido pedidos[], int tamPedidos){
	int i;
	int auxiliarDatosCliente = 0;
	int cliente;
	int validacionCorrecta;
	int pedidosPendientes;

	pedidosPendientes = 0;

	printf("\n IdCliente \t Empresa \t   Cuit \t   Direccion \t	 Localidad\n");
	MostrarDatosCargados(lista, tam, localidades, tamLocalidades,0);

	validacionCorrecta = PedirNumeroEntero("Ingrese el id del cliente a eliminar", "\Error", reintentos, &cliente);

	if(validacionCorrecta == 1){
		for(i=0; i<tam; i++)	{
			if(lista[i].isEmpty==0 && lista[i].idCliente== cliente)	{
				ContarPedidosPorEstado(lista[i].idCliente, tamPedidos, pedidos, &pedidosPendientes, "Pendiente");
				if(pedidosPendientes == 0){
					lista[i].isEmpty=1;
					auxiliarDatosCliente=1;
					for(int j = 0; j<tamPedidos; j++){
						if(lista[i].idCliente == pedidos[j].cliente){
							pedidos[j].isEmpty = 1;
						}
					}
					puts("\nEl cliente fue dado de baja con exito.\n");
					break;
				}else{
					puts("\nEl cliente cuenta con pedidos pendientes y no se puede dar de baja.\n");
				}
			}
		}
	}
	return auxiliarDatosCliente;
}



/*int PedidosPorEstado(int idCliente, int tamPedidos, ePedido pedidos[], char estado[]) {
	int j;
	int existenPedidos;

	existenPedidos = 0;

	for (j = 0; j < tamPedidos; j++) {
		if (pedidos[j].cliente == idCliente && (stricmp(pedidos[j].estado,estado) == 0)) {
			existenPedidos++;
		}
	}
	return existenPedidos;
}*/

