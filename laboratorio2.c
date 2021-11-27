/*
--------------------------------------------------------------------------------
                  IE-0117 Programación Bajo Plataformas Abiertas
              Autor: Samuel Berrocal Soto. samuel.berrocal@ucr.ac.cr
                      Desarrollado en Ubuntu 20.04 LTS
--------------------------------------------------------------------------------
    Este programa permite generar permutaciones de un string cualquiera
    ingresado por como argumento al ejectuar el programa.

    Se utiliza un enfoque de retroceso para llevar a cabo las permutaciones.
    El programa se encarga de fijar un carácter del string mediante un
    intercambio inicial, para luego intercambiar los otros carácteres.
    Luego de esto, se deshace el intercambio inicial y se itera nuevamente.

    Las iteraciones se llevan a cabo (n-1) veces, donde 'n' es el tamaño inicial
    del string ingresado como argumento.
--------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

/*
  Esta función intercambia los carácteres dentro del string ingresado como argumento.
  » indiceInicio indica el valor de la primera posición del arreglo del string.
  » [i] será una posición que se irá recorriendo en el proceso de iteración.
*/
void intercambio(char string[], int indiceInicio, int i) {

  char variable_temporal;

  variable_temporal = string[indiceInicio];
  string[indiceInicio] = string[i];
  string[i] = variable_temporal;
}

/*
  Esta función se encarga de realizar las permutaciones.
  » Si se llega al punto que ambos índices coinciden, imprimirá la permutación.
  » De otra forma, lleva a cabo el proceso descrito, donde los indicadores
    'i' e 'indiceInicio' irán aumentando hasta recorrer todo el string con
    todas las combinaciones posibles.
*/
void encontrarPermutaciones(char string[], int indiceInicio, int indiceFinal) {

  if (indiceInicio == indiceFinal) {
    printf("%s\n", string);
  }

  else {
    // Se crea un contador que atravesará todo el arreglo del string.
    for (int i = indiceInicio; i <= indiceFinal; i++) {

      // Intercambio inicial para fijar una carácter.
      intercambio(string, indiceInicio, i);

      // Realiza las permitaciones con los carácteres no fijados.
      encontrarPermutaciones(string, indiceInicio+1, indiceFinal);

      // Revierte el intercambio inicial.
      intercambio(string, indiceInicio, i);
    }
  }
}

/*
  Programa principal que invoca las funciones requeridas para realizar las
  permutaciones.
  » Se resguarda el programa de recibir más o menos argumentos de los necesarios.
  » Determina los valores iniciales que tendrá indiceInicio e indiceFinal.
*/
int main(int argc, char const *argv[]) {

  // Loop para atrapar los errores en el ingreso de argumentos del programa.
  while (1) {
    if (argc > 2) {
      printf("Error: No se admite más de un argumento para el programa.\n");
      return 1;
    }
    else if (argc < 2) {
      printf(
        "Error: Se requiere ingresar al menos 1 argumento (string) para ejecutar el programa.\n");
      return 1;
    }
    else {
      break;
    }
  }

  /*  Determino el tamaño que tendrá el arreglo de string, para evitar
      stack buffer overflow (stack smashing).
  */
  char string[sizeof(argv[1])];

  // Copio los contenidos del argumento a mi variable string.
  strcpy(string, argv[1]);

  // Calculo la longitud del string.
  int longitud = strlen(string);

  printf("\nLas permutaciones para '%3s' se muestran a continuación:\n", string);
  printf("----\n");
  encontrarPermutaciones(string, 0, longitud-1);
  printf("----\n");

  return 0;
}
