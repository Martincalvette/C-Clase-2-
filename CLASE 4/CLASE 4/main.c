#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int edad;
    if(utn_getEntero(&edad,3,"ingrese la edad:","La edad ingresada es erronea\n",199,0) == 0)
    {
        printf("La edad es: %d",edad);
    }


    return 0;
}






