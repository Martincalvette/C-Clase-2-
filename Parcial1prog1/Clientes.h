#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#define LIMITE_C 10
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char cuit[12];
    int isEmpty;
} Clientes;


int init_isEmpty(Clientes* pCLientes, int limite);
/**
    Ventas_getEspacioVacio:Busca un espacio vacio en el array
    @param Puntero a array de clientes
    @param limite del array
    @return 0 is ok, -1 error
*/
int getEspacioVacio(Clientes* pCLientes, int limite);
/**
    listar_Clientes:Muestra una lista con las ventas
    @param :Puntero a array de ventas
    @return void
*/
void listar_Clientes(Clientes* pCLientes, int limite);
/**
    altaClientes:Recorre el array rellenando los datos
    @param Puntero a array de clientes
    @param limite del array
    @return void
*/
void altaClientes(Clientes* pCLientes);
/**
    modificarClientes:Recorre el array modificando los datos
    @param Puntero a array de clientes
    @param limite del array
    @return 0 is ok, -1 error
*/
int modificarClientes(Clientes* pCLientes,int limite,int id);
/**
    bajaDeCliente:Recorre el array dando de baja los clientes
    @param Puntero a array de clientes
    @param limite del array
    @param id del cliente a dar de baja
    @return 0 is ok, -1 error
*/
int bajaDeCliente(Clientes* pCLientes,int limite,int id);
int cliente_altaFOrzada(Clientes* pClientes,int limite,char* nombre,char* apellido,char cuit);
void menu();

#endif // CLIENTES_H_INCLUDED
