#include "LibrarieCostumers.h"
#include "LibrarieString.h"
#include "LibrarieValidar.h"
#include "LibrarieInt.h"
#include <stdlib.h>
#include <string.h>


int CargarDatos(eCliente lista[], int tam, int reintentos, int* idGenerado) {
	int espacioLibre;
	char continuar[1];
	int validacion;
	int idNuevo;

	do{
		idNuevo = *idGenerado;
		espacioLibre = BuscarPrimerEspacioLibre(lista, tam);
		if(lista[espacioLibre].isEmpty == 1 && espacioLibre != -1){
			lista[espacioLibre] = IngresarUnDato(&validacion, reintentos);
			if(validacion == 1){
				lista[espacioLibre].idCliente = idNuevo++;
				*idGenerado = lista[espacioLibre].idCliente;
				lista[espacioLibre].isEmpty = 0;
			}
		}else{
			if(espacioLibre == -1){
				puts("No hay mas espacios libres");
				break;
			}
		}
	ConfirmarContinuar("¿Desea ingresar otro cliente? ", continuar);
	}while(continuar[0] == 'S');

	return validacion;
}

eCliente IngresarUnDato(int* validacion, int reintentos) {
	eCliente cliente;
	int validacionProd;
	validacionProd = 1;

	do{
		validacionProd = GetStringAlfaNum("Ingrese el nombre de la empresa: ","\nError", cliente.empresa, sizeof(cliente.empresa), reintentos);
	}while(validacionProd !=1);

	do{
		validacionProd = PedirNumeroEntero("\nIngrese el CUIT: ","\nError", reintentos, &cliente.cuit);
	}while(validacionProd !=1);

	do{
		validacionProd = GetStringAlfaNum("\nIngrese la direccion: ", "\nError", cliente.direccion, sizeof(cliente.direccion), reintentos);
	}while(validacionProd !=1);

	do{
		validacionProd = GetString("\nIngrese la localidad: ", "\nError", cliente.entidadlocalidad[0].localidad, sizeof(cliente.entidadlocalidad[0].localidad), reintentos);
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

void MostrarDatosCargados(eCliente lista[], int tam) {
	int i;
	int flagDatosVacios;

	flagDatosVacios = 1;
	printf("\n IdCliente \t Empresa \t Cuit \t Direccion \t Localidad\n");
	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == 0) {
			MostrarDatos(lista[i]);
		} else {
			if (flagDatosVacios == 0) {
				puts("No se encontraron datos.\n");
				flagDatosVacios = 1;
			}

		}
	}
}


void MostrarDatos(eCliente datos) {
	printf("%10d %16s %12d %10s %12s\n\n", datos.idCliente, datos.empresa, datos.cuit, datos.direccion, datos.entidadlocalidad.localidad);
}


int ModificarDatosCliente (eCliente lista[], int tam, int reintentos){
  int i;
  int cliente;
  int datosCambiados;
  datosCambiados = 0;
  int validacionCorrecta;

  validacionCorrecta = PedirNumeroEntero("Ingrese el cliente por ID a modificar","\nError",reintentos,&cliente);
  if(validacionCorrecta == 1){
	  for (i = 0; i < tam; i++){
		  if (lista[i].isEmpty == 0 && lista[i].idCliente == cliente){
			  validacionCorrecta = GetStringAlfaNum("\nIngrese la direccion: ", "\nError", lista[i].direccion, sizeof(lista[i].direccion), reintentos);
			  if(validacionCorrecta == 1){
				  validacionCorrecta = GetString("\nIngrese la localidad: ", "\nError", lista[i].entidadlocalidad.localidad, sizeof(lista[i].entidadlocalidad.localidad), reintentos);
				  if(validacionCorrecta == 1){
					  datosCambiados = 1;
					  break;
				  }
			  }
		  }
	  }
  }

  return datosCambiados;
}

int BorrarCliente(eCliente lista[], int tam, int reintentos){
	int i;
	int auxiliarDatosCliente = 0;
	int cliente;
	MostrarDatosCargados(lista, tam);

	PedirNumeroEntero("Ingrese el id del cliente a eliminar", "\Error", reintentos, &cliente);

	for(i=0; i<tam; i++)	{
	    if(lista[i].isEmpty==0 && lista[i].idCliente== cliente)	{
	        lista[i].isEmpty=1;
	        auxiliarDatosCliente=1;
	        break;
	    }
	}
	return auxiliarDatosCliente;
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

int BuscarLocalidad (eCliente lista[], int tam, char localidad[]){
	int i;
	int localidadExiste;

	localidadExiste = 0;

	for(i=0; i<tam; i++) {
		if(stricmp(lista[i].direccion, localidad)==0){
			localidadExiste = 1;
		}
	}

	return localidadExiste;
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


/*void OrdenarListaclientesPorId(eCliente lista[], int tam)
{
	eCliente auxiliarcliente;
	for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if(lista[i].idcliente<lista[j].idcliente)
			{
				auxiliarcliente = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliarcliente;
			}
		}
	}
}

int BorrarclienteGuardado(eCliente lista[], int tam, int reintentos){
	int i;
	int auxiliarclienteGuardado = 0;
	int clienteSeleccionado;
	MostrarDatosCargados(lista, tam);

	PedirNumeroEntero("Ingrese el cliente que quiere borrar", "Error", reintentos, &clienteSeleccionado);

	for(i=0; i<tam; i++)
	{
	    if(lista[i].isEmpty==1 && lista[i].idcliente==clienteSeleccionado)
	    {
	        lista[i].isEmpty=0;
	        auxiliarclienteGuardado=1;
	        break;
	    }
	}
	return auxiliarclienteGuardado;
}


float BuscarPrecioMasAlto (eCliente lista[], int tam)
{

  int flagMax = 0;
  float auxiliarPrecioMax;

  auxiliarPrecioMax = 0;

  for (int i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == 0)
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
