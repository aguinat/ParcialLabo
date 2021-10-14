#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdlib.h>
#include <string.h>
#include "LibrarieReports.h"


void MostrarPedidosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes){
	int i;
	int pedidosCliente;
	int contadorClientesConPedidos;

	contadorClientesConPedidos = 0;

	printf("\n IdCliente \t Empresa \t  Cuit \t\tDireccion \t Localidad \t PedidosPendientes\n");
	for (i = 0; i < tamClientes; i++) {
		pedidosCliente = BuscarPedidosPendientes(clientes[i], tamPedidos, pedidos);
		if(pedidosCliente != 0 && pedidos[i].isEmpty==0){
			printf("%10d %14s %15d %15s %15s %15d\n\n", clientes[i].idCliente, clientes[i].empresa, clientes[i].cuit, clientes[i].direccion, clientes[i].localidad, pedidosCliente);
			contadorClientesConPedidos++;
		}else{
			if(contadorClientesConPedidos == 0){
				puts("No se encontraron clientes con pedidos pendientes");
			}
		}
	}
}

void MostrarPedidosPorEstado(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes){
	int i;
	int pedidosCliente;
	int contadorClientesConPedidos;

	contadorClientesConPedidos = 0;

	printf("\n Estado \t Cuit del cliente \t Dirección \t Kilos a Recolectar \n");
	for (i = 0; i < tamClientes; i++) {
		pedidosCliente = BuscarPedidosPendientes(clientes[i], tamPedidos, pedidos);
		if(pedidosCliente != 0 && clientes[i].isEmpty==0){
			printf("%10s %16d %12s %12.2f\n\n", pedidos[i].estado, clientes[i].cuit, clientes[i].direccion, pedidos[i].residuosTotales);
			contadorClientesConPedidos++;
		}else{
			if(contadorClientesConPedidos == 0){
				puts("No se encontraron clientes con pedidos pendientes");
			}
		}
	}

}

void MostrarPedidosProcesados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes){
	int i;
	int pedidosCliente;
	int contadorClientesConPedidos;

	contadorClientesConPedidos = 0;

	printf("\n Estado \t Cuit del cliente \t Dirección \t Residuos HDPE \t Residuos LDPE \t Residuos PP  \n");
	for (i = 0; i < tamPedidos; i++) {
		pedidosCliente = BuscarPedidosCompletados(clientes, tamClientes, pedidos[i]);
		if(pedidosCliente != 0){
			printf("%10s %16d %20s %16.2f %15.2f %15.2f\n\n", pedidos[i].estado, clientes[i].cuit, clientes[i].direccion, pedidos[i].residuosHDPE,pedidos[i].residuosLDPE, pedidos[i].residuosPP);
			contadorClientesConPedidos++;
		}else{
			if(contadorClientesConPedidos == 0){
				puts("No se encontraron clientes con pedidos completados");
			}
		}
	}

}

void MostrarPedidosPorLocalidad(ePedido pedido[], int tamPedidos, eCliente clientes[], int tamClientes) {
	int i;
	int contadorPedidos;
	int reintentos;
	int validacionString;
	int localidadExiste;
	char localidad[200];

	reintentos = 5;
	contadorPedidos = 0;

	validacionString = GetString("Ingrese una localidad a mostrar: ", "\nError", localidad, sizeof(localidad), reintentos);
	if(validacionString == 1){
		localidadExiste = BuscarLocalidad(clientes, tamClientes, localidad);
		if(localidadExiste == 1){
			for( i = 0; i< tamPedidos ; i++){
				if((stricmp(pedido[i].estado, "Pendiente") == 0)){
					for(int j= 0; j<tamClientes; j++){
						if(clientes[j].idCliente == pedido[i].cliente && stricmp(clientes[j].localidad, localidad)==0){
							contadorPedidos++;
						}
					}
				}
			}
		}

	}

	if(contadorPedidos!=0){
		printf("\nPedidos pendientes: %d\n\n", contadorPedidos);
	}else{
		if(localidadExiste == 1){
			puts("No se encontrados pedidos pendientes para la localidad ingresada");
		}else{
			puts("La localidad ingresada no existe");
		}
	}
}

int BuscarPedidosPendientes(eCliente cliente, int tamPedidos, ePedido pedido[]) {
	int j;
	int existenPedidos;

	existenPedidos = 0;

	for (j = 0; j < tamPedidos; j++) {
		if (cliente.idCliente == pedido[j].cliente && (stricmp(pedido[j].estado, "Pendiente") == 0)) {
			existenPedidos++;
		}
	}
	return existenPedidos;
}

int BuscarPedidosCompletados(eCliente cliente[], int tamClientes, ePedido pedido) {
	int j;
	int existenPedidos;

	existenPedidos = 0;

	for (j = 0; j < tamClientes; j++) {
		if (cliente[j].idCliente == pedido.cliente && (stricmp(pedido.estado,"Completado") == 0)) {
			existenPedidos++;
		}
	}
	return existenPedidos;
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

void CalcularClienteConMasPedidosP(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes){
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
			if(acumulador[i].id == pedidos[j].cliente && (stricmp(pedidos[j].estado,"Pendiente") == 0)){
				acumulador[i].contador++;
			}
		}
	}

	for(i=0; i<tamClientes; i++){
		if(acumulador[i].contador>pedidosMax){
			pedidosMax = acumulador[i].contador;
			idMax = acumulador[i].id;
		}
	}
	printf("El id del cliente con mas pedidos pendientes es: %d\n", idMax);

}

void CalcularClienteConMasPedidosC(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes){
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
			if(acumulador[i].id == pedidos[j].cliente && (stricmp(pedidos[j].estado,"Completado") == 0)){
				acumulador[i].contador++;
			}
		}
	}

	for(i=0; i<tamClientes; i++){
		if(acumulador[i].contador>pedidosMax){
			pedidosMax = acumulador[i].contador;
			idMax = acumulador[i].id;
		}
	}
	printf("El id del cliente con mas pedidos completados es: %d\n", idMax);

}

void CalcularClienteConMasPedidos(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes){
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
			if(acumulador[i].id == pedidos[j].cliente && pedidos[j].isEmpty == 0){
				acumulador[i].contador++;
			}
		}
	}

	for(i=0; i<tamClientes; i++){
		if(acumulador[i].contador>pedidosMax){
			pedidosMax = acumulador[i].contador;
			idMax = acumulador[i].id;
		}
	}
	printf("El id del cliente con mas pedidos completados es: %d\n", idMax);

}


