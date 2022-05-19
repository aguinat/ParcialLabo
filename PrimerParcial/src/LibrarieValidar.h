#ifndef LIBRARIEVALIDAR_H_
#define LIBRARIEVALIDAR_H_

/// \fn int ValidarIngresoEntero(int*)
/// \brief Valida que el numero ingresado sea un numero y no una letra, etc
/// \param refNumeroEntero La direccion en memoria de la variable donde se va a guardar el numero ingresado
/// \return Informa 1 en caso de que pudo guardar el valor y 0 en caso de no poder por no ser un numero
int ValidarNumEntero(char strNumbers[]);

/// \fn int ValidarNumeroFloat(char[])
/// \brief Valida que el numero ingresado sea un numero y no una letra, etc
/// \param strNumbers
/// \return
int ValidarNumeroFloat(char strNumbers[]);

/// \fn int ValidarLetras(char[])
/// \brief
/// \param strLetras
/// \return Informa 1 en caso de que la cadena son solo letras o 0 por error.
int ValidarLetras(char strLetras[]);


int ValidarLetrasYNum(char strAlfaNum[]);

/// \fn int ValidarRango(int, int, int)
/// \brief Valida el rango en el que debe encontrarse un numero determinado
/// \param numero El numero ue debe ser validado
/// \param min El valor minimo del rango
/// \param max El valor maximo del rango
/// \return Devuelve 1 si esta en el rango, y 0 en caso de que este fuera de rango
int ValidarRango(int numero, int min, int max);

/// \fn int ValidarSigno(int)
/// \brief Valida si el numero ingresado es positivo o negativo
/// \param numero El numero que va a ser validado
/// \return Devuelve 1 si positivo, y 0 en caso de ser negativo
int ValidarSigno(int numero);

/// \fn int ValidarEsPar(int)
/// \brief Valida si el entero ingresado es par o impar
/// \param numero El numero que se va a validar su paridad
/// \return Devuelve 1 en caso de ser par y 0 en caso de ser impar
int ValidarEsPar(int numero);

/// \fn char ConfirmarContinuar(char[])
/// \brief Realiza una pregunta y retorna la letra, como respuesta (unicamente s o n)
/// \param mensaje El pregunta que va a mostrar ( con respuesta S o N)
/// \return La letra ingresada como confirmacion.
void ConfirmarContinuar(char mensaje[], char mensajeError[], int* continuar, int reintentos);

#endif /* LIBRARIEVALIDAR_H_ */
