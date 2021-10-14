#ifndef LIBRARIEREPORTS_H_
#define LIBRARIEREPORTS_H_

#include "LibrarieCostumers.h"
#include "LibrarieOrders.h"


void MostrarPedidosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes);
void MostrarPedidosPorEstado(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes);
void MostrarPedidosProcesados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes);
void MostrarPedidosPorLocalidad(ePedido pedido[], int tamPedidos, eCliente clientes[], int tamClientes) ;
int BuscarPedidosPendientes(eCliente cliente, int tamPedidos, ePedido pedido[]);
int BuscarPedidosCompletados(eCliente cliente[], int tamClientes, ePedido pedido);
void CalcularPromedioPolipropileno(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes);

#endif /* LIBRARIEREPORTS_H_ */
