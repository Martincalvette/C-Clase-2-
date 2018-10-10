#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE_V 2

int inf_impClientesAcobrar(Clientes* pClientes,int limiteCli,Ventas* pVentas,int limiteVent)
{
       int retorno=-1;
    int i;
    int cantidadACobrar;
    if(pClientes!=NULL && limiteCli>0 && pVentas!=NULL && limiteVent>0){
        for(i=0;i<limiteCli;i++){
            if(!pClientes[i].isEmpty){
                printf("\nId: %d",pClientes[i].id);
                printf("\tNombre: %s",pClientes[i].nombre);
                printf("\tApellido: %s",pClientes[i].apellido);
                printf("\tCuit: %s",pClientes[i].cuit);
                cantidadACobrar=cobrarId(pVentas,LIMITE_V,pClientes[i].id);
                printf("\tCan/A cobrar: %d",cantidadACobrar);
                retorno=0;
            }
        }
    }
    return retorno;
}
int inf_ordenarCliById(Clientes* pClientes,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Clientes auxClientes;
    if(pClientes!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && pClientes[i].id< pClientes[i+1].id)||(flag && pClientes[i].id> pClientes[i+1].id)){
                        auxClientes=pClientes[i];
                        pClientes[i]=pClientes[i+1];
                        pClientes[i+1]=auxClientes;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_ordenarAfiById(Ventas* pVentas,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Ventas auxVentas;
    if(pVentas!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && pVentas[i].id< pVentas[i+1].id)||(flag && pVentas[i].id> pVentas[i+1].id)){
                        auxVentas=pVentas[i];
                        pVentas[i]=pVentas[i+1];
                        pVentas[i+1]=auxVentas;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_ordenarCliByCuit(Clientes* pClientes,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Clientes auxClientes;
    if(pClientes!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && strcmp(pClientes[i].cuit, pClientes[i+1].cuit)<0 )||(flag && strcmp(pClientes[i].cuit, pClientes[i+1].cuit)>0)){
                        auxClientes=pClientes[i];
                        pClientes[i]=pClientes[i+1];
                        pClientes[i+1]=auxClientes;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_ordenarCliByNombre(Clientes* pClientes,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Clientes auxClientes;
    if(pClientes!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && strcmp(pClientes[i].nombre, pClientes[i+1].nombre)<0 )||(flag && strcmp(pClientes[i].nombre, pClientes[i+1].nombre)>0)){
                        auxClientes=pClientes[i];
                        pClientes[i]=pClientes[i+1];
                        pClientes[i+1]=auxClientes;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
int inf_ordenarCliByApellido(Clientes* pClientes,int limite,int flag){
    int i;
    int retorno=-1;
    int flagOrden;
    Clientes auxClientes;
    if(pClientes!=NULL && limite>0){
        retorno=0;
        do{
            flagOrden=0;
            for (i=0;i<(limite-1);i++){
                if((!flag && strcmp(pClientes[i].apellido, pClientes[i+1].apellido)<0 )||(flag && strcmp(pClientes[i].apellido, pClientes[i+1].apellido)>0)){
                        auxClientes=pClientes[i];
                        pClientes[i]=pClientes[i+1];
                        pClientes[i+1]=auxClientes;
                        flagOrden=1;
                }

            }
        }while(flagOrden);
    }
    return retorno;
}
/*int inf_impCliByMayorOrMenorCanAfiches(Ventas* pVentas,int limiteAfi,Clientes* pClientes,int limiteCli,int flag,char* msj){
    int i;
    int auxId;
    int mayorMenor;
    int auxMayorMenor;
    int retorno=-1;
    if(pClientes!=NULL && limiteCli>0 && pVentas!=NULL && limiteAfi>0){
        for(i=0;i<limiteCli;i++){
            auxMayorMenor=afi_cantidadDeAfichesByIdCliente(pVentas,limiteAfi,pVentas[i].idCliente);
            if(!i){
                mayorMenor=auxMayorMenor;
                auxId=i;
            }else if((!flag && mayorMenor<auxMayorMenor)||(flag && mayorMenor>auxMayorMenor)){
                mayorMenor=auxMayorMenor;
                auxId=i;
            }
        }
        printf("Con la cantidad de: %d",mayorMenor);
        printf("%s",msj);
        cli_impById(pClientes,limiteCli,auxId);

    }
    return retorno;
}*/
