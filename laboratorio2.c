// -----------------------------------------------------------------------------
//                IE-0117 Programación Bajo Plataformas Abiertas
//            Autor: Samuel Berrocal Soto. samuel.berrocal@ucr.ac.cr
// -----------------------------------------------------------------------------
// Programa para generar permutaciones de un string.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int i;

  printf("Cantidad de argumentos: %d\n", argc);

  for ( i = 0; i < argc; i++) {
    printf("Posición del argumento: %d, valor: %s\n", i, argv[i]);
  }

  return 0;
}
