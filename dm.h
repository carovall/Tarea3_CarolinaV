#ifndef DM_H_
#define DM_H_


typedef struct Sistema{
  int n; // numero de particulas
  double **r; // posicion de particulas
} sys;

sys * system_alloc(int);
void system_free(sys *);
void crear_red_fcc(sys *, double, int);
void guardar_datos(sys *, int, int, FILE *);

#endif // DM_H_
