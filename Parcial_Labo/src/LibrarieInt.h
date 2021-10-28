#ifndef LIBRARIEINT_H_
#define LIBRARIEINT_H_

#include <stdio.h>


/// \fn float PedirNumero(char[], char[], int)
/// \brief Pide un numero cualquiera, validando que ingresen unicamente numeros
/// \param Mensaje el mensaje que se mostrara al pedir un numero
/// \param MensajeError el mensaje de error que se mostrara en caso de no ingresar un numero
/// \param Reintentos la cantidad de reintentos para volver a ingresar un numero
/// \return El numero (con decimales) ingresado
int PedirNumeroEntero(char mensaje[], char mensajeError[],int reintentos, int* numeroEntero);

int PedirNumeroFloat(char mensaje[], char mensajeError[],int reintentos, float* numeroFloat);

/// \fn float CalcularPromedio(float, float)
/// \brief
/// \param numDividendo
/// \param numDivisor
/// \return
int CalcularPromedio(float numDividendo, float numDivisor, float* resultado);

/// \fn int FactorialDeUnNumero(int)
/// \brief Realiza el factorial de un numero positivo
/// \param numero El numero que se va a buscar el factorial
/// \return El resultado del factorial o -1 en caso de que sea un numero negativo
int FactorialDeUnNumero(int numero);

/// \fn int PedirNumConRango(char[], int, int)
/// \brief Pide un numero en un rango determinado por el usuario
/// \param mensaje El mensaje que se mostrara al pedir el numero
/// \param desdeElNumero El numero minimo del rango
/// \param hastaElNumero El numero maximo del rango
/// \return El numero ingresado
int PedirNumConRango(char mensaje[],char mensajeError[], int reintentos , int min, int max);


/// \fn void Swap(int, int, int*, int*)
/// \brief Intercambia los valores de dos variables de tipo de int
/// \param numero1 El valor de la variable int 1
/// \param numero2 El valor de la variable int 2
/// \param refNumero1 La direccion en memoria de la variable int 1
/// \param refNumero2 La direccion en memoria de la variable int 2
void Swap(int numero1, int numero2, int* refNumero1, int* refNumero2);


#endif /* LIBRARIEINT_H_ */
