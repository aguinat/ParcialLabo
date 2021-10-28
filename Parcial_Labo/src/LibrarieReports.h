#ifndef LIBRARIEREPORTS_H_
#define LIBRARIEREPORTS_H_

#include "LibrarieCostumers.h"
#include "LibrarieOrders.h"
#include "LibrarieLocalidad.h"

void MostrarCantidadPedidosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades);
void MostrarPedidosPorEstado(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, char estado[]);
void MostrarPedidosPorLocalidad(ePedido pedido[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidad);
int ContarPedidosPorEstado(int idCliente, int tamPedidos, ePedido pedido[], int* numPedidos, char estado[]);
void CalcularPromedioPolipropileno(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes);
void CalcularPedidosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, char estado[]);
int DarClienteDeBaja(eCliente lista[], int tam, int reintentos, eLocalidad localidades[], int tamLocalidades, ePedido pedidos[], int tamPedidos);

//int PedidosPorEstado(int idCliente, int tamPedidos, ePedido pedidos[], char estado[]);
#endif /* LIBRARIEREPORTS_H_ */
