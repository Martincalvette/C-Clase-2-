#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Clientes.h"
#include "Ventas.h"
#include "informes.h"
int main()
{
    Clientes sClientes[LIMITE_C];
    Ventas sVentas[LIMITE_V];
    int opcion;
    int indiceM;
    int auxId;
    int auxCantidadAfiches;
    int auxZona;
    int banderaDeDatos= -1;
    int confirmar;

    Cliente_alta_forzada(sClientes,LIMITE_C,"Jamon",23391600759,"Calvoso");
    Cliente_alta_forzada(sClientes,LIMITE_C,"Juan",234859534,"Triaca");
    Cliente_alta_forzada(sClientes,LIMITE_C,"Ricardo",4569875,"Montalvano");
    Cliente_alta_forzada(sClientes,LIMITE_C,"Javier",234859531,"Zarate");
    do
    {
        menu();

        utn_getEntero(&opcion,3,"\nIngrese una opcion:","opcion invalida",0,60);

        switch (opcion)
        {
        case 1:
            init_isEmpty(sClientes,LIMITE_C);
            altaClientes(sClientes);
            listar_Clientes(sClientes,LIMITE_C);
            banderaDeDatos=0;
            break;
        case 2:
            if(-1==banderaDeDatos)
            {
                printf("\nEl sistema no dispone de datos ingresados\n");
            }
            else if (utn_getEntero(&auxId,3,"\nIngrese el id del cliente a modificar :"
                                    ,"\nError. Ingrese un id valido",-1,100)==0)

            {
                modificarClientes(sClientes,LIMITE_C,auxId);
                listar_Clientes(sClientes,LIMITE_C);
            }

            break;
        case 3:
            if(-1==banderaDeDatos)
            {
                printf("\nEl sistema no dispone de datos ingresados\n");
            }
            else if (!utn_getEntero(&auxId,3,"\nIngrese el id del cliente a dar de baja :"
                                    ,"\nError. Ingrese un id valido",-1,100))

            {
                bajaDeCliente(sClientes,LIMITE_C,auxId);
            }

            break;
        case 4:
            alta_Ventas(sVentas,LIMITE_V,sClientes,LIMITE_C);
            break;
        case 5:
            listar_ventas(sVentas,LIMITE_V);
            if(!utn_getEntero(&auxId,3,"\nIngrese el id de venta: ","\n Ingrese un id valido ",-1,999)&&
                    !buscarIdVentas(sVentas,LIMITE_V,auxId)&&
                    !utn_getEntero(&auxCantidadAfiches,3,"\nIngrese la cantidad de afiches :","\n Ingrese un numero valido",0,9999)&&
                    !utn_getEntero(&auxZona,3,"\nIngrese la zona: 1- CABA 2-ZONA SUR 3-ZONA OESTE :","\nIngrese una opcion valida",1,3)){
                        modificarVentas(sVentas,auxId,LIMITE_V,auxCantidadAfiches,auxZona);
                }else{
                        printf("\nError reingrese el dato");
                        getchar();
                }
            break;
        case 6:
            listar_ventas(sVentas,LIMITE_V);
            if(!utn_getEntero(&auxId,3,"\nIngrese el id de venta: ","\nError...Ingrese un id valido ",-1,999) &&
                    !cobrarVenta(sVentas,LIMITE_V,sClientes,LIMITE_C,auxId,&indiceM)&&
                    !utn_getEntero(&confirmar,3,"\nDesea cobrar esta venta? 0-si 1-no","\nIngrese una opcion valida",0,1)&&
                    !confirmar)
            {
                sVentas[indiceM].estado=0;
            }
                break;
        case 7:
            inf_impClientesAcobrar(sClientes,LIMITE_C,sVentas,LIMITE_V);
            break;

        }
    }
    while (opcion!=0);
}


