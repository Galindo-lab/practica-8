
//kraya@uabc.edu.mx

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complejo_t {
    float real;
    float complex;
} complejo_t;

float equation( float, float, float, float );
void display_complejo( complejo_t );
void setcomplex_t( complejo_t *a , float real, float img );
void raices_fg(float a, float b, float c, complejo_t *raiz1, complejo_t *raiz2);



int main()
{
    float a,b,c;
    complejo_t raiz_1, raiz_2;

    scanf("%f %f %f",&a,&b,&c);

    raices_fg(a,b,c,&raiz_1,&raiz_2);

    return 0;
}

void setcomplex_t( complejo_t *a, float real, float img)
{
    a->real = real;
    a->complex = img;
}

void display_complejo(complejo_t a)
{
    printf("(x - (%.2f + %.2fi))\n",a.real,a.complex);
}

float equation(float a, float b, float c, float x)
{
    return a*x*x + b*x + c;
}

void raices_fg(float a, float b, float c, complejo_t *raiz1, complejo_t *raiz2)
{
    complejo_t
        numerador = {0};
    float
        denominador = 2*a;
    complejo_t
        raiz_1 ={0},
        raiz_2 = {0};

    if( (b*b) >= (4*a*c) )      /* determinar si es complejo */
    {
        numerador.real = sqrt(b*b - 4*a*c);
        setcomplex_t(&raiz_1, (-b) + numerador.real, 0);
        setcomplex_t(&raiz_2, (-b) - numerador.real, 0);
    }
    else
    {
        numerador.complex = sqrt(fabs( b*b - 4*a*c ));
        setcomplex_t(&raiz_1, (-b), numerador.complex);
        setcomplex_t(&raiz_2, (-b), -numerador.complex);
    }

    denominador = 2*a;          /* dividir en la formula general */

    raiz_1.real /= denominador;
    raiz_1.complex /= denominador;
    raiz_2.real /= denominador;
    raiz_2.complex /= denominador;

    printf("Raices: \n");       /* imprimir los resultados */
    display_complejo(raiz_1);
    display_complejo(raiz_2);

    *raiz1 = raiz_1;
    *raiz2 = raiz_2;
}
