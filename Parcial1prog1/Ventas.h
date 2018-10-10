#ifndef AFICHES_H_INCLUDED
#define AFICHES_H_INCLUDED
#define LIMITE_V 2

typedef struct
{
    char nombre[51];
    int  cantidad;
    int zona;
    int id;
    int idCliente;
    int isEmpty;
    int estado;
} Ventas;
/**
    listar_Ventas:Muestra una lista con las ventas
    @param :Puntero a array de ventas
    @return void
*/

int init_isEmptyVentas(Ventas* pVentas, int limite);
/**
    VentasCargadas:confirma que la carga fue exitosa imprimiendo el id
    @param Puntero a array de ventas
    @param limite del array
    @return 0 is ok, -1 error
*/
void VentasCargadas(Ventas* pVentas, int limite, Clientes* pClientes, int len);
/**
    Ventas_getEspacioVacio:Busca un espacio vacio en el array
    @param Puntero a array de ventas
    @param limite del array
    @param Puntero a array de clientes
    @param limite del array
    @return 0 is ok, -1 error
*/
int Ventas_getEspacioVacio(Ventas* pVentas, int limite);
/**
    utn_getchar:valida una entrada al usuario en formato char
    @param pResultado: puntero donde guardar el char obtenido
    @return 0 is ok, -1 error
*/
int alta_Ventas(Ventas* pVentas,int limite,Clientes* pCLientes,int limite_Clientes);
int Venta_buscarIndiceVacio(Ventas* pVentas, int limite, int* indice);
int modificarVentas(Ventas* pVentas,int id,int limite,int cantidad,int zona);
int buscarPorID(Ventas* pVentas, int limite, int id);
int cobrarId(Ventas* pVentas,int limite,int idCliente);
#endif // AFICHES_H_INCLUDED
