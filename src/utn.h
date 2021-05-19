

#ifndef UTN_H_
#define UTN_H_

/**
 * @fn int utn_getInt(int*, char[], int)
 * @brief Funcion que toma un entero del usuario
 *
 * @param resultado de la funcion (variable donde guardo la misma)
 * @param mensaje a mostrar por consola
 * @param tamaño del entero
 * @return
 */
int utn_getInt(int* resultado, char mensaje[], int tam, int reintentos, int min, int max);
/**
 * @fn int EsUnNumero(char[])
 * @brief
 *
 * @param buffer
 * @return
 */
int EsUnNumero(char buffer[]);
/**
 * @fn int utn_getFloat(float*, char[], int)
 * @brief
 *
 * @param resultado
 * @param mensaje
 * @param tam
 * @return
 */
int utn_getFloat(float* resultado, char mensaje[], int tam, int reintentos, float min, float max);
/**
 * @fn int EsUnFloat(char[])
 * @brief
 *
 * @param buffer
 * @return
 */
int EsUnFloat(char buffer[]);
/**
 * @fn int utn_getNombre(char[], char[], int)
 * @brief
 *
 * @param resultado
 * @param mensaje
 * @param tam
 * @return
 */
int utn_getNombre(char resultado[], char mensaje[], int tam, int reintentos);
/**
 * @fn int EsUnaLetra(char[])
 * @brief
 *
 * @param buffer
 * @return
 */
int EsUnaLetra(char buffer[]);



#endif /* UTN_H_ */
