#include "helper.h"

void alocare_si_initializare(int ***tabla)
{
    int i;
    *tabla = (int**)calloc(3, sizeof(int*));
    for(i = 0; i<3; i++)
    {
        (*tabla)[i] =(int*) calloc(3, sizeof(int));
    }    
}

void citire(int **tabla, int *linie, int *coloana, int n)//Functia ce citeste pozitia unde jucatorul isi pune "Punctul"
{
    int contor = 0, x, y;
        while (contor == 0) {
        printf("Introdu coordonatele (x, y) intre 1 si 3: ");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
            if (tabla[x - 1][y - 1] == 0) {
                contor = 1;
            } else {
                printf("Pozitia este ocupata. Mai introdu o data.\n");
            }
        } else {
            printf("Coordonate invalide. Te rog sa introduci coordonate intre 1 si 3.\n");
        }
    }
            if(n % 2 == 0)
                tabla[x-1][y-1] = 1;
                    else tabla[x-1][y-1] = 2;
        (*linie) = verif_linie(tabla, x);
        (*coloana) = verif_coloana(tabla, y);
}

int verif_coloana(int **tabla, int y)
{
    int i, j;
    for( i = 0; i < 3; i++)
        for(j = i + 1; j < 3; j++)
        if((tabla[i][y - 1] != tabla[j ][y - 1]) || (tabla[i][y - 1] == 0))  
                return 0;              
                else return 1;    
}

int verif_linie(int **tabla, int x)
{
    int j, i;
    for(j = 0; j < 3; j++)
        for(i = j + 1; i <3; i++)

        if((tabla[x - 1][j] != tabla[x - 1][i]) || (tabla[x - 1][j] == 0))
                return 0;    
                else return 1;
            
}

int verif_diag_p(int **tabla)
{
    int i = 0;
    
    while (i < 2) { // 0, 1
        for (int j = i + 1; j < 3; j++) { // j (1, 2) / (2)
            if (tabla[i][i] != tabla[j][j] || tabla[i][i] == 0)
                return 0;
        }

        i++;
    }

    return 1;
}

int verif_diag_s(int **tabla)
{
    int i, j, diag_s = 1;

    for(i = 0; i < 3; i++)
        for( int j = i + 1; j < 3; j++)
            if(tabla[i][2 - i] == tabla[j][2 - j] || (tabla[i][2 - i] != 0))
            {
                diag_s=0;
                break;
            }
        
    return diag_s;
}

void input(int **tabla, int *linie, int *coloana, int *diag, int *diag_s)
{
    int n, contor, x, y;
    for (n = 0; n < 9; n++) {
        contor = 0;
            if (n % 2 == 0) 
                {
                    printf("Primul jucator: ");
                    citire(tabla, linie, coloana, n);
                } 
            else 
                {
                    printf("Al doilea jucator: ");
                    citire(tabla, linie, coloana, n);
                }
        *diag = verif_diag_p(tabla);
        *diag_s = verif_diag_s(tabla);
        if (*linie == 1 || *coloana == 1 || *diag == 1 || *diag_s == 1) {
            break;
        }

        *linie = *coloana = *diag = *diag_s = 0; // Reset variables
    }
}

void castigator(int **tabla,int *linie, int *coloana,int *diag, int *diag_s)
{
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            {
                *linie = verif_linie(tabla, i);
                *coloana = verif_coloana(tabla, j);
                *diag = verif_diag_p(tabla);
                *diag_s = verif_diag_s(tabla);
                if((*linie==1 || *coloana==1 || *diag==1|| *diag_s==1) && (tabla[i][j] == 1))
                    {
                        printf("jucatorul 1 a castigat.\n");
                        break;
                    }
                    else if((*linie==1 || *coloana==1 || *diag==1 || *diag_s==1 ) && (tabla[i][j] == 1))
                        {
                            printf("jucatorul 2 a castigat.\n");
                            break;
                        }
            }   
}