#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/**
    utn_getEntero: pide un entero al usuario
    @param pEdad: puntero a la edad
    @param reintentos: cantidad de reintentos
    @return: 0 significa ok, -1 significa error.
*/

int utn_getEntero(int*pEdad,int reintentos,char* msg,char*msgError,int max,int min);


#endif // UTN_H_INCLUDED
