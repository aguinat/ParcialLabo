#include "LibrarieCostumers.h"
#include "LibrarieOrders.h"
#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdlib.h>
#include <string.h>


int CargarPedido(ePedido lista[], int tam, int reintentos, eCliente listaCli[], int tamListaCli, int* idGenerado, eLocalidad localidades[], int tamLocalidades) {
	int espacioLibre;
	int continuar;
	int validacion;
	int idPedido;

	do{
		idPedido = *idGenerado;
		espacioLibre = BuscarEspacioLibre(lista, tam);
		if(lista[espacioLibre].isEmpty == 1 && espacioLibre != -1){
			lista[espacioLibre] = CrearPedido(&validacion, reintentos, listaCli, tamListaCli, localidades, tamLocalidades);
			if(validacion ==1){
				lista[espacioLibre].idPedido = idPedido++;
				*idGenerado = lista[espacioLibre].idPedido;
				lista[espacioLibre].isEmpty = 0;
			}
		}else{
			if(espacioLibre == -1){
				puts("No hay mas espacios libres");
				break;
			}
		}
	ConfirmarContinuar("¿Desea ingresar otro producto? ", "\nError", &continuar, reintentos);
	}while(continuar==1);

	return validacion;
}

int CompletarPedido(ePedido lista[], int tam, int reintentos) {
	int i;
	int continuar;
	int validacionPedido;
	int idPedido;

	for (i = 0; i < tam; i++) {
		do{
			MostrarPedidosPendientes(lista, tam);
			validacionPedido = PedirNumeroEntero("\nIngrese el Id del Pedido: ","\nError", reintentos, &idPedido);
			if(lista[i].idPedido == idPedido && (stricmp(lista[i].estado, "Pendiente") == 0)){
				validacionPedido = PedirNumeroFloat("\nIngrese los kilos de HDPE:", "\nError", reintentos, &lista[i].residuosHDPE);
				validacionPedido = PedirNumeroFloat("\nIngrese los kilos de LDPE:", "\nError", reintentos, &lista[i].residuosLDPE);
				validacionPedido = PedirNumeroFloat("\nIngrese los kilos de PP:", "\nError", reintentos, &lista[i].residuosPP);
				if(validacionPedido !=1){
					strcpy(lista[i].estado, "Completo");
				}
			}else{
				puts("El pedido no existe");
				validacionPedido = 0;
			}
		ConfirmarContinuar("¿Desea ingresar otro producto? ", "\nError", &continuar, reintentos);
		}while(continuar==0);
		break;
	}

	return validacionPedido;
}


ePedido CrearPedido(int* validacion, int reintentos, eCliente lista[], int tamClienteLista, eLocalidad localidades[], int tamLocalidades) {
	ePedido producto;
	int validacionPedido;
	validacionPedido = 1;
	int idCliente;
	int clienteExiste;

		do{
			MostrarDatosCargados(lista, tamClienteLista, localidades, tamLocalidades);
			validacionPedido = PedirNumeroEntero("\nIngrese el Id del cliente: ","\nError", reintentos, &idCliente);
			if (validacionPedido == 1){
				clienteExiste = BuscarCliente(lista, tamClienteLista, idCliente);
				if(clienteExiste == 1){
					producto.cliente = idCliente;
				}else{
					puts("El cliente no existe");
					validacionPedido = 0;
				}
			}
		}while(validacionPedido !=1 && reintentos !=0);

		do{
			validacionPedido = PedirNumeroFloat("\nIngrese el monto total de kilos a recolectar","\nError", reintentos, &producto.residuosTotales);
		}while(validacionPedido != 1);

		strcpy(producto.estado, "Pendiente");

	*validacion = validacionPedido;

	return producto;
}

void InicializarListaProducto(ePedido lista[], int tam){

    for(int i = 0;i < tam; i++){
        lista[i].isEmpty = 1;
    }
}

void MostrarPedidosPendientes(ePedido lista[], int tam) {
	int i;
	int flagDatosVacios;

	flagDatosVacios = 0;
	printf("\tIdPedido \t Cliente \t Estado \t ResiduosTotales\n");

	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == 0 && (stricmp(lista[i].estado, "Pendiente") == 0)) {
			MostrarPedido(lista[i]);
		} else {
			if (flagDatosVacios == 0) {
				//puts("No se encontraron pedidos pendientes.\n");
				flagDatosVacios = 1;
			}

		}
	}

}

void MostrarPedido(ePedido datos) {
	printf("%10d %16d %12s %12.2f\n", datos.idPedido, datos.cliente, datos.estado, datos.residuosTotales);
}

int BuscarEspacioLibre (ePedido lista[], int tam){
  int i;
  int index;

  index = -1;
  for (i = 0; i < tam; i++){
	  if (lista[i].isEmpty == 1){
		  index = i;
	  break;
	  }
  }
  return index;
}

/*
void OrdenarListaProductosPorId(ePedido lista[], int tam)
{
	ePedido auxiliarProducto;
	for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if(lista[i].idProducto<lista[j].idProducto)
			{
				auxiliarProducto = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliarProducto;
			}
		}
	}
}


int BorrarProductoGuardado(ePedido lista[], int tam, int reintentos){
	int i;
	int auxiliarProductoGuardado = 0;
	int productoSeleccionado;
	MostrarDatosCargados(lista, tam);

	PedirNumeroEntero("Ingrese el producto que quiere borrar", "Error", reintentos, &productoSeleccionado);

	for(i=0; i<tam; i++)
	{
	    if(lista[i].isEmpty==1 && lista[i].idProducto==productoSeleccionado)
	    {
	        lista[i].isEmpty=0;
	        auxiliarProductoGuardado=1;
	        break;
	    }
	}
	return auxiliarProductoGuardado;
}


float BuscarPrecioMasAlto (ePedido lista[], int tam)
{

  int flagMax = 0;
  float auxiliarPrecioMax;

  auxiliarPrecioMax = 0;

  for (int i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == 1)
	{
	  if (flagMax == 0 || lista[i].precio > auxiliarPrecioMax)
	    {
	      auxiliarPrecioMax = lista[i].precio;
	      flagMax = 1;
	    }
	}
    }
  return auxiliarPrecioMax;
}
*/
