#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibrarieCostumers.h"
#include "LibrarieOrders.h"
#include "LibrarieInt.h"
#include "LibrarieLocalidad.h"
#include "LibrarieReports.h"


#define TAM 5
#define REIN 5
#define LOCALIDADES 10


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int opcionCorrecta;

	eLocalidad Localidades[TAM] = {{1,"Caba",0},{2,"Lanus",0},{3,"Lomas de Zamora",0},{4,"Monte Grande",0},{4,"Moreno",0}};

	//eCliente Cliente[TAM];
	eCliente Cliente[TAM]={{1,"NuevaEmp",1234567891,"unLugar 40",1 ,0},{2,"OtraEmpresa",147852369,"OtroLugar 200",1 ,0},{3,"Apple",17823456,"Lima 820",2,0}};

	//ePedido Pedido [TAM];
	ePedido Pedido [TAM] ={{1,3,"Completado",12.2, 6.3, 7.2, 7.2,0},{2,1,"Completado",20.65,  6.3, 7.2, 3.5,0},{3,1,"Pendiente", 50.2, 6.3, 7.2, 20.5,0},{1,2,"Pendiente",12.2, 6.3, 7.2, 15.5,0},
			{1,3,"Pendiente",12.2, 6.3, 7.2, 26.5,0}};

	int idCliente;
	int idPedido;

	//idCliente = 0;
	//idPedido = 0;

	//InicializarDatos(Cliente, TAM);
	//InicializarListaProducto(Pedido, TAM);

	do {
			printf("1. Alta de cliente\n");
			printf("2. Modificar datos de cliente\n");
			printf("3. Baja de cliente\n");
			printf("4. Crear pedido de recolección\n");
			printf("5. Procesar residuos\n");
			printf("6. Mostrar Clientes\n");
			printf("7. Mostrar Pedidos pendientes\n");
			printf("8. Mostrar Pedidos procesados\n");
			printf("9. Buscar Pedidos por localidad\n");
			printf("10. Calcular promedio polipropileno por cliente\n");
			printf("11. Cliente con mas pedidos pendientes\n");
			printf("12. Cliente con mas pedidos completados\n");
			printf("13. Cliente con mas pedidos\n");
			printf("14. Salir\n");
			opcionCorrecta = PedirNumeroEntero("Elija una opcion: ", "Error", REIN, &opcion);
			if (opcionCorrecta == 1) {
				switch (opcion) {
				case 1:
					CargarDatos(Cliente, TAM, REIN, &idCliente, Localidades, TAM);
					break;
				case 2:
					ModificarDatosCliente(Cliente, TAM, REIN, Localidades, TAM );
					break;
				case 3:
					BorrarCliente(Cliente, TAM, REIN, Localidades, TAM);
					break;
				case 4:
					CargarPedido(Pedido, TAM, REIN, Cliente, TAM, &idPedido, Localidades, TAM);
					break;
				case 5:
					CompletarPedido(Pedido, TAM, REIN);
					break;
				case 6:
					MostrarPedidosCliente(Pedido, TAM, Cliente, TAM);
					break;
				case 7:
					MostrarPedidosPorEstado(Pedido, TAM, Cliente, TAM);
					break;
				case 8:
					MostrarPedidosProcesados(Pedido, TAM, Cliente, TAM);
					break;
				case 9:
					MostrarPedidosPorLocalidad(Pedido, TAM, Cliente, TAM, Localidades, TAM);
					break;
				case 10:
					CalcularPromedioPolipropileno(Pedido, TAM, Cliente, TAM);
					break;
				case 11:
					CalcularClienteConMasPedidosP(Pedido, TAM, Cliente, TAM);
					break;
				case 12:
					CalcularClienteConMasPedidosC(Pedido, TAM, Cliente, TAM);
					break;
				case 13:
					CalcularClienteConMasPedidos(Pedido, TAM, Cliente, TAM);
					break;

				}
			}else{
				opcion = 14;
				printf("\nEl programa finalizo debido a que no se ingreso ninguna opcion valida\n");
			}

		} while (opcion != 10);

	return EXIT_SUCCESS;
}
