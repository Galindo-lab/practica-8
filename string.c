
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*
 * Ejercicio 4a. Realizar una función que reciba una cadena de
 * caracteres y un apuntador a una estructura que almacene
 * cuantas vocales, consonantes y dígitos contiene la cadena.
 * La función deberá almacenar en los miembros de la estructura
 * los valores del análisis propuesto.
 *
 * Ejercicio 4b. Realizar una función que reciba una cadena de
 * caracteres ingresada por el usuario y elimine los espacios
 * en blanco de la cadena.
 */

char to_lower(char c)           /* hacer minuscula */
{
    return (c >= 'A' && c <= 'Z') ? c + 32 : c ;
}

uint8_t is_numer(char c)        /* es un numero */
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}

uint8_t is_vocal(int c)         /* si es vocal */
{
    switch(to_lower(c))
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
}

uint8_t is_consonant(int c)     /* si no es vocal
                                 * es consonante */
{
    int c_lower = to_lower(c);
    return !is_vocal(c) && c_lower >= 'a' && c_lower <= 'z';
}

void status(char string[], int *voc, int *con, int *dig)
{
    for(int i = 0; string[i] != '\0'; i++)
    {
        if( is_vocal(string[i]) ) {
            printf("%c v \n",string[i]);
            (*voc)++;
        }
        else if ( is_consonant(string[i]) ) {
            printf("%c c \n",string[i]);
            (*con)++;
        }
        else if ( is_numer(string[i]) ) {
            printf("%c n \n",string[i]);
            (*dig)++;
        }
    }
}



void eliminar_espacio(char *string)
{
    while(*string != '\0')
    {

        if(*string == ' ')
        {
            *string = *(string+1);
            string++;
            *string = ' ';
        }
        else {
            string++;
        }
    }

}

//https://stackoverflow.com/questions/5457608/how-to-remove-the-character-at-a-given-index-from-a-string-in-c

void elminar_espacios(char *str) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {


        *dst = *src;
        if (*dst != ' ') dst++;


    }
    *dst = '\0';
}

int main() {

    int voc = 0, con = 0, dig = 0;
    char a[20] = "a b bb 3 3gf sg";

    eliminar_espacio(a);
    status(a,&voc,&con,&dig);

    printf("%s\n", a);
    printf("voc:%d con:%d dig:%d\n",voc,con,dig);


    return 0;
}
