#include "LibrarieCostumers.h"
#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdlib.h>
#include <string.h>

int CargarDatos(eCliente lista[], int tam, int reintentos, int* idGenerado, eLocalidad localidades[], int tamLocalidad){
	int espacioLibre;
	int continuar;
	int validacion;
	int idNuevo;

	do{
		idNuevo = *idGenerado;
		if(idNuevo != 100){
			espacioLibre = BuscarPrimerEspacioLibre(lista, tam);
			if(lista[espacioLibre].isEmpty == 1 && espacioLibre != -1){
				lista[espacioLibre] = IngresarUnDato(&validacion, reintentos);
				if(validacion == 1){
					do{
						MostrarLocalidades(localidades, tamLocalidad);
						lista[espacioLibre].idLocalidad = PedirNumConRango("\nElija la localidad: ", "\nError", reintentos, 0, 4);
						ConfirmarContinuar("¿Confima la localidad ingresada? ", "\nError", &continuar, reintentos);
						printf("%d", continuar);
					}while(continuar==0);

					lista[espacioLibre].idCliente = idNuevo+1;
					*idGenerado = lista[espacioLibre].idCliente;
					lista[espacioLibre].isEmpty = 0;
				}
			}else{
				if(espacioLibre == -1){
					puts("No hay mas espacios libres");
					break;
				}else{
					puts("Datos ingresados incorrectos");
				}
			}
			ConfirmarContinuar("¿Desea ingresar otro cliente? ", "\nError", &continuar, reintentos);
		}else{
			continuar= 0;
			puts("\nLimite de clientes alcanzado\n");
		}
	}while(continuar == 1);

	return validacion;
}


eCliente IngresarUnDato(int* validacion, int reintentos){
	eCliente cliente;
	int validacionProd;
	validacionProd = 1;

	do{
		validacionProd = GetStringAlfaNum("Ingrese el nombre de la empresa: ","\nError", cliente.empresa, sizeof(cliente.empresa), reintentos);
	}while(validacionProd !=1);

	do{
		validacionProd = PedirNumeroEntero("\nIngrese el CUIT: ","\nError en el cuit ingresado", reintentos, &cliente.cuit);
		if(cliente.cuit<20000000000 ){
			validacionProd = -1;
			puts("\nCuit ingresado, no valido, reintente.\n");
		}
	}while(validacionProd !=1);

	do{
		validacionProd = GetStringAlfaNum("\nIngrese la direccion: ", "\nError", cliente.direccion, sizeof(cliente.direccion), reintentos);
	}while(validacionProd !=1);


	if (validacionProd == 1){
		cliente.isEmpty = 0;
	}else{
		cliente.isEmpty = 1;
		puts("\nError en los datos ingresados, uno o mas datos son erroneos");
	}

	*validacion = validacionProd;

	return cliente;
}

void InicializarDatos(eCliente lista[], int tam){

    for(int i = 0;i < tam; i++)
    {
        lista[i].isEmpty = 1;
        lista[i].idCliente = 0;
    }

}

void MostrarDatosCargados(eCliente lista[], int tam, eLocalidad localidades[], int tamLocalidades, int pedidos) {
	int i;
	int flagDatosVacios;

	flagDatosVacios = 1;
	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == 0 && lista[i].idCliente !=0) {
			MostrarDatos(lista[i],localidades,tamLocalidades,pedidos);
			flagDatosVacios = 0;
		}
	}

	if (flagDatosVacios == 1) {
		puts("No se encontraron datos.\n");
	}
}


void MostrarDatos(eCliente datos, eLocalidad localidades[], int tamLocalidades, int pedidos) {
	int i;

	for (i=0; i<tamLocalidades; i++){
		if((localidades[i].idLocalidad == datos.idLocalidad) && pedidos == 0){
			printf("%5d %20s %15d %20s %16s\n\n", datos.idCliente, datos.empresa, datos.cuit, datos.direccion, localidades[i].localidad);
		}else{
			if((localidades[i].idLocalidad == datos.idLocalidad) && pedidos != 0){
				printf("%10d %14s %15d %15s %15s %15d\n\n", datos.idCliente, datos.empresa, datos.cuit, datos.direccion, localidades[i].localidad, pedidos);
			}
		}

	}
}


int ModificarDatosCliente (eCliente lista[], int tam, int reintentos, eLocalidad localidades[], int tamLocalidad){
  int i;
  int cliente;
  int datosCambiados;
  datosCambiados = 0;
  int validacionCorrecta;


  printf("\n IdCliente \t  Empresa \t   Cuit \t     Direccion \t	 Localidad\n");
  MostrarDatosCargados(lista, tam, localidades, tamLocalidad, 0);

  validacionCorrecta = PedirNumeroEntero("Ingrese el cliente por ID a modificar","\nError",reintentos,&cliente);
  if(validacionCorrecta == 1){
	  for (i = 0; i < tam; i++){
		  if (lista[i].isEmpty == 0 && lista[i].idCliente == cliente){
			  validacionCorrecta = GetStringAlfaNum("\nIngrese la direccion: ", "\nError", lista[i].direccion, sizeof(lista[i].direccion), reintentos);
			  if(validacionCorrecta == 1){
				  MostrarLocalidades(localidades, tamLocalidad);
				  lista[i].idLocalidad = PedirNumConRango("\nElija la localidad: ", "\nError", reintentos, 1, 4);
				  datosCambiados = 1;
				  break;
				  }
			  }
		  }
	  }
  return datosCambiados;

}



int BuscarCliente (eCliente lista[], int tam, int idCliente){
	int i;
	int clienteExiste;

	clienteExiste = 0;

	for(i=0; i<tam; i++) {
		if(lista[i].idCliente == idCliente){
			clienteExiste = 1;
		}
	}

	return clienteExiste;
}



int BuscarPrimerEspacioLibre (eCliente lista[], int tam){
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


