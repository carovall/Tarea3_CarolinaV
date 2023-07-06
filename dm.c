#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dm.h"

sys * system_alloc(int n){
  sys * obj = malloc(sizeof(sys));

  obj->n = n;

  obj->r = malloc(sizeof(double *) * n);

  for (int i=0; i<n; ++i) {
    obj->r[i] = calloc(3, sizeof(double));
  }

  return obj;
}

void system_free(sys *obj){
  for (int i = 0; i<(obj->n); i++) {
    free(obj->r[i]);
  }
  free(obj->r);

  free(obj);
}

void crear_red_fcc(sys *obj, double densidad, int nc) {
  /* Funcion que crea una red cristalina FCC.
   * Se asume una caja que se puede particionar en
   * *nc* celdas en cada dimensión
   */

  int l = 0, m = 0, n = 0, contador = 0;
  
  // Para cubo de lado L:
  // L = a*(nc-1) + 0.5*a
  // Para L= 1[m³] y nc=3; despejando a:
  // a = L/(nc-0.5) = 1/2.5 = 0.4
  double L = 1.0;
  double a = L/(nc-0.5);

  for (l = 0; l < nc; ++l) {
    for (m = 0; m < nc; ++m) {
      for (n = 0; n < nc; ++n) {
        
        obj->r[contador][0] = a * l;
        obj->r[contador][1] = a * m;
        obj->r[contador][2] = a * n;
        ++contador;

        
        obj->r[contador][0] = a * (l + 0.5);
        obj->r[contador][1] = a * (m + 0.5);
        obj->r[contador][2] = a * n;
        ++contador;

        
        obj->r[contador][0] = a * (l + 0.5);
        obj->r[contador][1] = a * m;
        obj->r[contador][2] = a * (n + 0.5);
        ++contador;

        
        obj->r[contador][0] = a * l;
        obj->r[contador][1] = a * (m + 0.5);
        obj->r[contador][2] = a * (n + 0.5);
        ++contador;
      }
    }
  }
}


void guardar_datos(sys *obj, int step, int nc, FILE *archivo){

  fprintf(archivo, "%i\n", 64);
  fprintf(archivo, "Lattice=\"%d 0 0 0 %d 0 0 0 %d\"", 1, 1, 1);
  fprintf(archivo, " Properties=id:I:1:pos:R:3:radius:R:1\n");
  for (int i = 0; i < 64; i++) {
    fprintf(archivo,
            "%i %f %f %f %f\n", i,
            obj->r[i][0],
            obj->r[i][1],
            obj->r[i][2],
            0.125);

  }
}
