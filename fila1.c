#include "helper.h"
//functioneaza citirea + 
int main ()
{
    int **tabla;
    int n;
    int linie = 0, coloana = 0, diag = 0, diag_s = 0;

    alocare_si_initializare(&tabla);
    input(tabla, &linie, &coloana, &diag, &diag_s);
    castigator(tabla, &linie, &coloana, &diag, &diag_s);
    for (int i = 0; i < 3; i++) {
        free(tabla[i]);
    }
    free(tabla);
    return 0;

}