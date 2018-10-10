#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int generarId(void);

static int proximoId(void);



int init_isEmpty(Clientes* pCLientes, int limite)
{
    int i;
    int retorno=-1;
    if(pCLientes!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pCLientes[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

void altaClientes(Clientes* pCLientes)
{
    int index;



    index=getEspacioVacio(pCLientes,LIMITE_C);


    pCLientes[index].id = generarId();
    utn_getLetrasYNumeros(pCLientes[index].nombre,51,"Ingrese el nombre del empleado:");
    utn_getLetrasYNumeros(pCLientes[index].apellido,51,"Ingrese el apellido del emepleado: ");
    utn_getLetrasYNumeros(pCLientes[index].cuit,12,"Ingrese el cuit");
    listar_Clientes(pCLientes,LIMITE_C);

}
int getEspacioVacio(Clientes* pCLientes, int limite)
{
    int i;
    int index;

    for(i=0; i<limite; i++)
    {
        if(pCLientes[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }

    return index;
}

int modificarClientes(Clientes* pCLientes,int limite,int id)
{
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];
    int retorno=-1;
    if(pCLientes!=NULL&&limite>0)
    {
        for (i=0; i<limite; i++)
        {
            if(pCLientes[i].id==id&& pCLientes[i].isEmpty==1)
            {
                retorno=0;
                if(!utn_getLetras(auxNombre,50,3,"\nIngrese el nombre: ","\nIngrese un nombre valido")&&
                    !utn_getLetras(auxApellido,50,3,"\nIngrese el apellido: ","\nIngrese un apellido valido")&&
                    !utn_getLetrasYNumeros(auxCuit,12,"\nIngrese el cuit a reemplazar:"))
                {


                    strcpy(pCLientes[i].apellido,auxApellido);
                    strcpy(pCLientes[i].nombre,auxNombre);
                    strcpy(pCLientes[i].cuit,auxCuit);
                    break;
                }
            }
        }
    }
    return retorno;
}

int clientes_buscarPorID(Clientes* pCLientes, int limite, int id)
{
    int i;
    int retorno=-1;

    for (i=0; i<limite; i++)
    {
        if(pCLientes[i].isEmpty==0 && pCLientes[i].id==id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

static int generarId(void)

{
    static int id = 0;
    id++;
    return id;
}

void listar_Clientes(Clientes* pCLientes, int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        if(pCLientes[i].isEmpty==1)
        {
            printf("ID: %d\n",pCLientes[i].id);
            printf("Nombre: %s\n",pCLientes[i].nombre);
            printf("Apellido: %s\n",pCLientes[i].apellido);
            printf("Cuit: %s \n",pCLientes[i].cuit);
        }
    }
}

int Cliente_buscarIndiceVacio(Clientes* pCLientes, int limite, int* indice)
{
    int retorno =-1;
    int i;
    if(pCLientes !=NULL && limite>0)
    {
        for(i=0; i<limite;i++)
        {
            if(pCLientes[i].isEmpty == 1)
            {
                *indice=i;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int buscarEmpleadoPorId(Clientes* pCLientes, int limite, int id)
{
    int i;
    int retorno=-1;

    for (i=0; i<limite; i++)
    {
        if(pCLientes[i].isEmpty==0 && pCLientes[i].id==id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int bajaDeCliente(Clientes* pCLientes,int limite,int id)
{
    int i;
    int retorno=-1;
    for(i=0; i<limite; i++)
    {
        if(pCLientes[i].isEmpty==0&& pCLientes[i].id==id)
        {
            pCLientes[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int buscarClientesPorId(Clientes* pCliente, int limite,int id, int* indiceID)//problema punto 2 subsanado recibiendo a ID como puntero
{
    int retorno=-1;
    int i;

    if(pCliente!=NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            if(pCliente[i].id == id && pCliente[i].isEmpty==0)
            {
                *indiceID=i;
                retorno = 0;//originalmente era retorno=i
                break;
            }
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
void menu()
{
    printf("\nIngrese 1 para dar de alta un cliente:\nIngrese 2 para modificar datos ");
    printf("de un empleado:\nIngrese 3 para dar de baja un empleado:\n");
    printf("Ingrese 4 para agregar una venta :\nIngrese 0 para salir del programa:\n");
    printf("Ingrese 5 para modificar una venta :\nIngrese 6 para cobrar una venta :\n");
    printf("Ingrese 7 para ver las ventas por cobrar :\nIngrese 0 para salir del programa :\n");
}

void Cliente_alta_forzada(Clientes* pClientes,int limite, char* nombre,int cuit, char* apellido)
{
    int index;
    if(Cliente_buscarIndiceVacio(pClientes,limite,&index)==0)
    {
        if(index>=0)
        {
            strncpy(pClientes[index].cuit, cuit,12);

            strncpy(pClientes[index].nombre,nombre,50);
            strncpy(pClientes[index].apellido,apellido,50);

            pClientes[index].isEmpty=0;
            pClientes[index].id = generarId();
        }

    }
    }

/*int totalYPromedioSueldos(Clientes* pCLientes,int limite)
{
    int retorno = -1;
    int i;
    float resultado=0;
    float promedio=0;
    float cantidadSupProm=0;
    float contadorSueldos=0;


    if(pCLientes != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCLientes[i].isEmpty==0)
            {
                resultado = resultado+pCLientes[i].cuit;
                contadorSueldos++;
                promedio = resultado/contadorSueldos;

                if(pCLientes[i].sueldo > promedio)
                {
                    cantidadSupProm++;
                }
            }
        }
        retorno = 0;
        printf("\n-El total de los salarios es: %.2f \n2-El promedio de los salarios es: %.2f \n3-La cantidad que superan el salario promedio son: %.2f"
               ,resultado,promedio,cantidadSupProm);
    }
    return retorno;
}*/
/*int OrdenarApellidoYSector(Clientes* pCLientes, int limite)
{

   int i;
   int retorno = -1;
   Empleados auxiliar;
   int j;


   if(pCLientes != NULL && limite > 0)
   {
       for(i=0;i<limite -1;i++)
       {
           for(j=i+1;j<limite;j++)
           {
               if(strcmp(pCLientes[j].apellido,pCLientes[i].apellido)<0)
               {
                   auxiliar = pCLientes[i];
                   pCLientes[i]=pCLientes[j];
                   pCLientes[j]=auxiliar;
               }
               else if(strcmp(pCLientes[j].apellido,pCLientes[i].apellido)==0 &&pCLientes[j].sector<pCLientes[i].sector)
               {
                   auxiliar=pCLientes[i];
                   pCLientes[i]=pCLientes[j];
                   pCLientes[j]=auxiliar;
               }
           }
       }
       retorno=0;
   }
   return retorno;
}
*/
