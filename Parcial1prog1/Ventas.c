#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "Clientes.h"
#include "Ventas.h"
#define CABA 0
#define ZONASUR 1
#define ZONAOESTE 2


static int generarId(void);
static int proximoId(void);


int init_isEmptyVentas(Ventas* pVentas, int limite)
{
    int i;
    int retorno=-1;
    if(pVentas!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pVentas[i].isEmpty = 1;
            retorno=0;
        }
    }

    return retorno;
}
int alta_Ventas(Ventas* pVentas,int limite,
                      Clientes* pCLientes,int limite_Clientes)
{
    int retorno=-1;
    int auxiliarCantidadAfiches;
    char auxiliarNombreArchivo[50];
    int auxiliarZona;
    int indiceVentas;
    int idCliente;

        if ((Venta_buscarIndiceVacio(pVentas,limite,&indiceVentas)==0))
        {
            if(pVentas!=NULL && limite>0)
            {
                listar_Clientes(pCLientes,limite_Clientes);
                if(utn_getEntero(&idCliente,5,"\nIngrese ID de Cliente: \n","\nError, no es un ID valido.\n",0,999)==0)
                {
                    buscarClientesPorId(pCLientes, limite_Clientes,idCliente,&indiceVentas);
                    if(utn_getEntero(&auxiliarCantidadAfiches,5,"\nIngrese cantidad de afiches: \n","\nError, no es un numero valido.\n",0,999)==0)
                    {
                        if(utn_getLetras(auxiliarNombreArchivo,50,2,"\nIngrese nombre del archivo: \n","\nError, no es un nombre.")==0)
                        {
                            if(utn_getEntero(&auxiliarZona,5,"\nIngrese ZONA: CABA 0 ZONA SUR 1 ZONA OESTE 2: \n","\nError, no es un numero valido.\n",CABA,ZONAOESTE)==0)
                            {
                                pVentas[indiceVentas].idCliente=idCliente;
                                pVentas[indiceVentas].cantidad=auxiliarCantidadAfiches;
                                strncpy(pVentas[indiceVentas].nombre, auxiliarNombreArchivo,50);
                                pVentas[indiceVentas].zona = auxiliarZona;
                                pVentas[indiceVentas].isEmpty = 0;
                                pVentas[indiceVentas].id = generarId();
                                pVentas[indiceVentas].estado = 1;
                                retorno=0;
                            }
                        }
                    }
                }
            }
        }
    return retorno;
}
int Venta_buscarIndiceVacio(Ventas* pVentas, int limite, int* indice)
{
    int retorno =-1;
    int i;
    if(pVentas !=NULL && limite>0)
    {
        for(i=0; i<limite;i++)
        {
            if(pVentas[i].isEmpty == 1)
            {
                *indice=i;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
void listar_VentasPorId(Ventas* pVentas, int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        if(pVentas[i].isEmpty==1)
        {
            printf("Nombre: %s\n",pVentas[i].nombre);
            printf("Cantidad: %d\n",pVentas[i].cantidad);
            printf("Zona: %d\n",pVentas[i].zona);
            printf("idCLiente: %d \n",pVentas[i].idCliente);
        }
    }
}

int Ventas_getEspacioVacio(Ventas* pVentas, int limite)
{
    int i;
    int index;

    for(i=0; i<limite; i++)
    {
        if(pVentas[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }

    return index;
}



static int generarId(void)

{
    static int id = 0;
    id++;
    return id;
}

int buscarPorID(Ventas* pVentas, int limite, int id)
{
    int i;
    int retorno=-1;

    for (i=0;i<limite;i++)
    {
        if(pVentas[i].isEmpty==0 && pVentas[i].id==id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
static int proximoId(void)
{


    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
int listar_ventas(Ventas* pVentas,int limite){
    int i;
    int retorno=-1;
    if(pVentas!=NULL&&limite>0){
        for(i=0;i<limite;i++){
            if(pVentas[i].isEmpty==0){
                retorno=0;
                printf("\nId: %d",pVentas[i].id);
                printf("\tId Cli: %d",pVentas[i].idCliente);
                printf("\tCant/Afi: %d",pVentas[i].cantidad);
                printf("\tArchivo: %s",pVentas[i].nombre);
                switch (pVentas[i].zona){
                    case 1:
                        printf("\tZona: CABA");
                        break;
                    case 2:
                        printf("\tZona: ZONA SUR");
                        break;
                    case 3:
                        printf("\tZona: ZONA OESTE");
                    break;
                }


            }
        }
    }
    return retorno;
}


int modificarVentas(Ventas* pVentas,int id,int limite,int cantidad,int zona)
{
    int i;
    int retorno=-1;
    if(pVentas!=NULL && limite>0 && (zona<4&&zona>0)&& cantidad>0)
        {
        for (i=0;i<limite;i++)
        {
            if(pVentas[i].id==id)
            {
                pVentas[i].cantidad=cantidad;
                pVentas[i].zona=zona;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int buscarIdVentas(Ventas* pVentas,int limite,int id){
    int i;
    int retorno=-1;
    if(pVentas!=NULL&&limite>0){
        for(i=0;i<limite;i++){
            if(pVentas[i].id==id && !pVentas[i].isEmpty){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int cobrarVenta(Ventas* pVentas,int limite ,Clientes* pClientes,int limiteCli,int id,int* indice){
    int i,j;
    int retorno=-1;
    if(pVentas!=NULL&&limite>0&& pClientes!= NULL && limiteCli>0){
        for(i=0;i<limite;i++){
            if(pVentas[i].id==id){
                for(j=0;j<limiteCli;j++){
                    if(pVentas[i].idCliente==pClientes[i].id&& !pVentas[i].isEmpty){
                        printf("\nId: %d",pClientes[i].id);
                        printf("\tNombre: %s",pClientes[i].nombre);
                        printf("\tApellido: %s",pClientes[i].apellido);
                        printf("\tCuit: %s",pClientes[i].cuit);
                        retorno=0;
                        *indice=i;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}
int cobrarId(Ventas* pVentas,int limite,int idCliente)
{
    int i;
    int retorno=0;
    for(i=0;i<limite;i++){
        if(pVentas[i].idCliente==idCliente&& pVentas[i].estado== 1 && !pVentas[i].isEmpty){
            retorno++;
        }
    }
    return retorno;
}
