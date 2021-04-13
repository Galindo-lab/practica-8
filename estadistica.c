
#include <stdio.h>
#include <stdlib.h>

float suma(float datos[],int n);
float media(float datos[],int n);
float maximo(float datos[],int n);
float minimo(float datos[],int n);
float media(float datos[], int n);
float mediana(float datos[], int n);
float moda(float datos[], int n);

int filter(const void *a, const void *b);
void ordenar( float datos[], int n );

float(*op[])(float[], int) = {
     moda,
     media,
     maximo,
     minimo,
     suma,
     mediana
};

char funciones[][20] = {
    "moda     ",
    "media    ",
    "maximo   ",
    "minimo   ",
    "sumatoria",
    "mediana  "
};

int main() {

    float datos[] = {1,1,1,1,1,1,45,5,23,4,2,2,2,3,1,21};
    int n = sizeof(datos)/sizeof(datos[0]);

    ordenar(datos,n);

    for(int i = 0; i < n ; i++ ){
        printf("%3d - %.2f\n",i,datos[i]);
    }

    printf("===================\n");

    for(int i = 0; i < 6 ; i++){
        printf(" %s : %.2f\n", funciones[i],op[i](datos, n));
    }

    return 0;
}

float suma(float datos[], int n) /* sumatoria */
{
    float s = 0;
    while(n--){ s += datos[n]; }
    return s;
}

float media(float datos[], int n)
{
    float sumatoria = suma(datos, n);
    float media = sumatoria / n;
    return media;
}

void ordenar(float datos[], int n) /* en las pociciones mas bajas
                                    * esatn los valores mas pequeños,
                                    * y en las mas altas los mas altos */
{
    qsort(datos, n, sizeof(float), &filter);
}

int filter(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

float minimo( float datos[], int n )
{
    qsort(datos, n, sizeof(float), &filter);
    return datos[0];
}

float maximo( float datos[], int n  )
{
    qsort(datos, n, sizeof(float), &filter);
    return datos[n-1];
}

float mediana(float datos[], int n)
{
    qsort(datos, n, sizeof(float), &filter);
    return datos[n/2];
}

float moda(float datos[], int n)
{
    float
        a_ctrl = 0,
        a_frec = 0;

    float
        b_ctrl = 0,
        b_frec = 0;

    for(int i = 0;i<n;i++)
    {
        a_frec = 0;             /* recorre todos los elemntos */
        a_ctrl = datos[i];

        for(int j = 0;j<n;j++)  /* suma 1 cada vez que se
                                 * repite */
        {
            if(datos[j] == a_ctrl)
            {
                a_frec++;
            }
        }

        if(a_frec > b_frec)     /* sí la frecuencia es mayor
                                 * se remplaza */
        {
            b_ctrl = a_ctrl;
            b_frec = a_frec;
        }
    }

    return b_ctrl;
}
