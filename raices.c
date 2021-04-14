
#include <math.h>
#include <stdio.h>

float eps()                    /* Epsilon, numero mas
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

float Scarb(float n)           /* metodo de escarbeu */
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

float ErrorA(float vac, float van) /* error aproximado
                                     * (percentual) */
{
    float ea = fabs( vac - van );
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

float primera_derivada(float x,float (*f) (float)) /* derivada */
{
    float
        h = pow(2,-8);

    float
        fxph = f(x+h),
        fxmh = f(x-h);

    float
        fp1 = (fxph - fxmh) / (2*h);

    return fp1;
}

//float newton(float xi,float f)

float biseccion(float xi, float xu, float (*f) (float)  )
{
    float
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

float newton(float xi,  float (*f) (float)  )
{
    float
        ea = 50,
        es = Scarb(5),
        x1 = 0;

    while(ea > es)
    {
        x1 = xi - f(xi) / primera_derivada(xi,f);
        ea = ErrorA(x1,xi);
        xi = x1;
    }
    return xi;
}

float falsa_pos(float xi, float xu, float (*f) (float) )
{
    float
        xr = 0,
        xrant = 0,
        ea = 50,
        es = Scarb(5);

    if ( ! ((f(xi) * f(xu)) > 0) )
    {
        while(ea > es)
        {
            xrant = xr;
            xr = xu - (f(xu) * (xi - xu)) / (f(xi) - f(xu));
            if( (f(xi) * f(xr)) < 0 )
            {
                xu = xr;
            }
            if( (f(xu) * f(xr)) < 0 )
            {
                xi = xr;
            }
            ea = ErrorA(xr, xrant);
        }
    }

    return xr;
}

float a(float b){
    return (b*b)-5.0;
}

int main() {
    printf("%f \n", falsa_pos(1,3,a) );
    /* printf("%f \n", eps()); */


    /* for(int i = 0;i < 3;i++){ */
    /*     printf("%f", ); */
    /*     /\* for(int j = 0; j < 5; j++){ *\/ */
    /*      /\* printf(" i:%d - %f %f \n", i, a(i), primera_derivada(i,a) ); *\/ */
    /*     /\* } *\/ */
    /* } */

    return 0;
}
