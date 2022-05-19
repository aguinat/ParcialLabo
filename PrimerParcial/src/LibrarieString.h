#ifndef LIBRARIESTRING_H_
#define LIBRARIESTRING_H_


/// \fn int GetString(char[], int)
/// \brief Recupera y guarda en una variable de tipo array el input recibido por teclado, validando que el largo no supere al largo del array
/// \param vectorCadena la variable donde se guardara lo recibido por teclado
/// \param el largo de la cadena
/// \return 0 en caso de no poder guardar correctamente el input o 1 en caso de que se guarde con exito.
int getString(char vectorCadena[], int tamCadena);

/// \fn int GetLetters(char[], char[], char[], int, int)
/// \brief
/// \param mensaje
/// \param mensajeError
/// \param vectorCadena
/// \param tamCadena
/// \param reintentos
/// \return
int GetLetters(char mensaje[], char mensajeError[], char vectorCadena[], int tamCadena, int reintentos);

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
