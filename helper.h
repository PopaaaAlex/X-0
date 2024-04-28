#ifndef helper
#define helper

#include <stdio.h>
#include <stdlib.h>

void alocare_si_initializare(int ***tabla);
int verificare_liber(int **tabla, int x, int y);
int verif_coloana(int **tabla,int y);
int verif_linie(int **tabla, int x);
int verif_diag_p(int **tabla);
int verif_diag_s(int **tabla);
void citire(int **tabla, int *linie, int *coloana, int );
void input(int **tabla, int *linie, int *coloana, int *diag, int *diag_s);
void castigator(int **tabla, int *linie, int *coloana, int *diag, int *diag_s);

#endif