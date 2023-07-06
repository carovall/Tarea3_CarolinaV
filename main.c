#include <stdio.h>
#include <stdlib.h>
#include "dm.h"

int main(int argc, char *argv[]) {

  int nc = 3; //Numero de celdas

  sys *sistema = system_alloc(4*nc*nc*nc);
  FILE *archivo = fopen("archivo.xyz", "w");
  
  crear_red_fcc(sistema, 0.74 , nc);
  
  guardar_datos(sistema, 0, nc, archivo);
  
  system_free(sistema);
  return 0;
}
