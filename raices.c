
#include <math.h>
#include <stdio.h>

double eps()                    /* Epsilon, numero mas
                                 * pequeño que c puede manejar
                                 * que no sea 0*/
{
    float eps = 1;
    while( (1-eps) != 1)
    {
        eps = eps / 2;
    }
    eps *= 2;
    return eps;
}

double Scarb(float n)           /* metodo de escarbeu */
{
    int  n_int = 0;
    if(n <= 0)
    {
        n = 5;
        printf("n debe ser positiva, 5 default\n");
    }

    n_int = (int) (2-n) ;
    return 0.5 * pow(10, n_int );
}

double ErrorA(float vac, float van) /* error aproximado
                                     * (percentual) */
{
    double ea = fabs( vac - van );
    if( vac != 0.0 )
    {
        if( ea < eps() ) /* cualquier valor pequeño
                                           * sirve */
        {
            ea = 0;
        }
        else {
            ea = fabs(ea / vac)*100; /* cnovertirlo a porcentaje */
        }
    }
    return ea;
}

float biseccion(double xi, double xu, double (*f) (double), int n )
{
    double
        xr = 0,                 /* x anterior */
        xrant = 0,              /* almacena xr para compararlo con
                                 * el nuevo valor */
        ea = 50,                /* error aproximado */
        es = Scarb(5);          /* Error esperado (nivel de precicion) */

    int i = 0;

    if( f(xi) * f(xu) > 0 )
    {
        printf("no existe, raiz en el intervalo");
    }
    else
    {
        while( ea > es )        /* miesntras el error aproximado /
                                 * sea menor que el esperado */
        {
            // para revisar los parametros
            //printf( "%d %f %f %f %f %f %f %f \n",
            //i,xi,xu,xr,f(xi),f(xu),f(xr),ea   );

            i++;
            xrant = xr;         /* se almacena para calcular
                                 * el error */

            xr = (xi + xu)/2;   /* punto intermedio */

            if( (f(xi)*f(xr)) < 0 )
            {
                xu = xr;        /* se reemplaza el ultimo valor
                                 * por el valor intermedio */
            }
            if( (f(xu)*f(xr)) < 0 )
            {
                xi = xr;        /* se reempaza el primer valor
                                 * por el valor intermedio */
            }

            ea = ErrorA(xr, xrant);
        }
    }

    return xr;
}




double a(double b){
    return (b*b)-5.0;
}

int main() {
    printf("%f \n", biseccion(1, 3, a, 100) );
    /* printf("%f \n", eps()); */


    /* for(int i = 0;i < 3;i++){ */
    /*     for(int j = 0; j < 5; j++){ */
    /*         printf(" i:%d j:%d - %f \n", i, j, ErrorA(i,j) ); */
    /*     } */
    /* } */

    return 0;
}
