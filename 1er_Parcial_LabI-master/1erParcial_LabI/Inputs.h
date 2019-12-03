#include <stdio.h>
#include <stdlib.h>

/** \brief Toma un entero positivo.
 *
 * \param recibe como parametro un mensaje para aclarar el uso del dato ingresado.
 * \return retorna el numero positivo ingresado en caso de ser correcto.
 *         retorna -1 si el dato ingresado es invalido.
 */
int getIntPos(char*);




/** \brief Valida que el numero ingresado sea entero y positivo.
 *
 * \param Recibe el numero a validar como un string.
 * \return Retorna -1 si el numero ingresado no es valido, ya sea porque es un caracter alpha o poruqe no es positivo.
 *         Retorna 1 si el numero ingresado es valido.
 */
int validar_numero_positivo(char numero[]);




/** \brief Toma un entero.
 *
 * \param Recibe un string con mensaje.
 * \return Retorna el numero si es valido.
 *         Retorna NULL si el numero ingresado no es valido.
 */
int getInt(char*);



/** \brief Valida que el dato ingresado sea caracter y entero, tanto positivo como negativo.
 *
 * \param Recibe string con mensaje.
 * \return Retorna 1 si el dato ingresado es valido.
 *         Retorna NULL si el dato ingresado es invalido.
 */
int validar_numero_entero(char numero[]);



/** \brief Toma un numero que este entre los parametros ingresados.
 *
 * \param Recibe string con mensaje.
 * \param Recibe entero que determina parametro menor.
 * \param Recibe entero que determina parametro mayor.
 * \return Retorna el numero si es valido.
 *         Retorna -1 si el dato ingresado no es un numero.
           Retorna 0 si el dato no respeta los parametros especificados.
 */
int getDesdeHasta(char*,int,int);



/** \brief Valida que el valor ingresado sea un flotante.
 *
 * \param Recibe string con mensaje.
 * \return Retorna el flotante en caso de ser valido.
 *         Retorna -1 en caso de que el flotante sea invalido.
 */
float getFloat(char* mensaje);



/** \brief Valida que el numero ingresado sea un flotante.
 *
 * \param Recibe el numero como un string.
 * \return Retorna -1 si no puede validar que sea flotante.
 *         Retorna 1 si puede validar que sea un flotante.
 */
int validar_flotante(char numero[]);



/** \brief Valida caracter por caracter que el numero pasado como string pueda corresponder a un flotante.
 *
 * \param El numero como string.
 * \return Retorna -1 si no puede validar que el string corresponda a un flotante.
 *         Retorna 1 si puede validar que el strgin corresponda a un flotante.
 */
int isDigitOrPoint(char*);



/** \brief Recibe un caracter.
 *
 * \param Recibe un string con mensaje.
 * \return Retorna el caracter en caso de ser valido.
 *         Retorna NULL en caso de no ser un caracter valido
 */
char getChar(char*);



/** \brief Valida que el caracter recibido sea un alpha
 *
 * \param El caracter a analizar.
 * \return Retorna 1 si es un caracter valido.
 * \return Retorna -1 si es no es un caracter valido.
 */
int validar_char(char);



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int validar_string(char*);


int menu(char[]);
void corregirString(char*);

void pedirCadena(char[], char[]);
int getString(char[]);
