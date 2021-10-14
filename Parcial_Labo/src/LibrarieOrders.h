#ifndef LIBRARIEORDERS_H_
#define LIBRARIEORDERS_H_

typedef struct
{
	int idPedido; //PK
	int	cliente; //FK
	char estado[50];
	float residuosTotales;
	float residuosHDPE;
	float residuosLDPE;
	float residuosPP;
	int isEmpty;

}ePedido;

int CargarPedido(ePedido lista[], int tam, int reintentos, eCliente listaCli[], int tamListaCli, int* idGenerado);
int CompletarPedido(ePedido lista[], int tam, int reintentos);
ePedido CrearPedido(int* validacion, int reintentos, eCliente lista[], int tamClienteLista);
void InicializarListaProducto(ePedido lista[], int tam);
void MostrarPedidosPendientes(ePedido lista[], int tam);
void MostrarPedido(ePedido datos);
int BuscarEspacioLibre (ePedido lista[], int tam);


//void OrdenarListaProductosPorId(ePedido lista[], int tam);
//int BorrarProductoGuardado(ePedido lista[], int tam, int reintentos);
//float BuscarPrecioMasAlto (ePedido lista[], int tam);

#endif /* LIBRARIECOSTUMERS_H_ */
