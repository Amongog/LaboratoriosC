/*
--------------------------------------------------------------------------------
                 IE-0117 Programación Bajo Plataformas Abiertas
             Autor: Samuel Berrocal Soto. samuel.berrocal@ucr.ac.cr
--------------------------------------------------------------------------------
  Programa para Máximo Común Divisor (MCD).
  Este programa hace uso del Algoritmo de Euclides para realizar el cálculo
  del MCD.
  El Algoritmo de Euclides funciona iniciando la división entre los primeros
  dos números, encontrando su residuo, e iterando más divisiones en las que
  cada dividendo nuevo será el divisor pasado, y cada divisor nuevo será el
  residuo pasado.
  Cuando el residuo sera cero, significa que el último divisor utilizado es el
  Máximo Común Divisor.
--------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

int main() {

  int valor1, valor2, residuo, mcd;
  char ok[] = "OK";

  printf(
    "Ingrese los números MCD(n1,n2) para los que desea encontrar su MCD.\n");

  while (1) {

    printf("» n1: ");
    scanf("%d", &valor1);
    printf("» n2: ");
    scanf("%d", &valor2);
    printf("Escriba OK para confirmar: ");
    scanf("%2s", ok);   // %2s limita el tamaño del string a 2.

    switch (strcmp(ok, "OK")) {
      case 0:
        break;

      case 32:          // Valor de la diferencia entre "ok" y OK" en ASCIII.
        break;

      default:
        printf("\nError: Ingresó demasiados argumentos.\n\n");
        continue;
    }

    if (valor1 < 0 || valor2 < 0) {
      printf("\nError: Este programa sólo admite valores enteros positivos.\n\n");
    }
    else {
      break;
    }
  }

  do {
    // Evitamos la división entre 0.
    if (valor2 != 0) {
      // Calcula el residuo de la división entre los dos números.
      residuo = valor1 % valor2;

      if (residuo != 0) {
        // Si no hemos encontrado residuo = 0 actualiza los
        // valores de la división.
        valor1 = valor2;
        valor2 = residuo;
      }
      else {
        mcd = valor2;
      }
    }
    else {
      mcd = valor1;
      break;
    }

  } while(residuo != 0);

  printf("--------\n");
  printf("El MCD entre los números asignados es: %d\n", mcd);

  return 0;
}
