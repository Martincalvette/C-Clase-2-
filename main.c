#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int numero[10];
    int numero;
    int numeroMin;
    int numeroMax;
    float i;
    int promedio;
    int acumNumero;

    i=0;


    for(i=0;i<10;i++)
    {
    printf("ingrese el numero:", i+1);
    scanf("%d",&numero);
       if (i==0)
       {
            numeroMax=numero;
            numeroMin=numero;
       }
       else if(numero<numeroMin)
       {
           numeroMin=numero;
       }

       else if(numero>numeroMax)
       {
            numeroMax=numero;
       }

        acumNumero=acumNumero+numero;

    }

        printf("esg", acumNumero);
        //printf("numero maximo %d\nnumero minimo %d\nel promedio es", numeroMax, numeroMin,promedio);



    return 0;
}

