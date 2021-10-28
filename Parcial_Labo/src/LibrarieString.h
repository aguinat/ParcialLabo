#ifndef LIBRARIESTRING_H_
#define LIBRARIESTRING_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/// \fn int GetString(char[], char[], char[], int, int)
/// \brief
/// \param mensaje
/// \param mensajeError
/// \param vectorCadena
/// \param tamCadena
/// \param reintentos
/// \return
int GetString(char mensaje[], char mensajeError[], char vectorCadena[], int tamCadena, int reintentos);

/// \fn int GetStringAlfaNum(char[], char[], char[], int, int)
/// \brief
/// \param mensaje
/// \param mensajeError
/// \param vectorCadena
/// \param tamCadena
/// \param reintentos
/// \return
int GetStringAlfaNum(char mensaje[], char mensajeError[], char vectorCadena[], int tamCadena, int reintentos);

/// \fn void StringUpperCamelCase(char[], int)
/// \brief
/// \param vectorCadena
/// \param tam
void StringUpperCamelCase(char vectorCadena[]);

/// \fn void StringUpperCamelCase(char[], int)
/// \brief
/// \param vectorCadena
/// \param tam
void ConcatStrings(char cadenaDestino[],char candenaConcatenar[], int tamCadenaDestino);

#endif /* LIBRARIESTRING_H_ */
