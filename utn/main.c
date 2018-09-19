#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define   CANTIDAD_EMPLEADOS 5
#define CARGA_INVALIDA -1


int main()
{
    Persona personas;
    utn_altaPersona(&personas,3,14,1,100);
    printf("%s   %d    %f.2 ",personas.nombre,personas.edad,personas.altura);
    return 0;
}
