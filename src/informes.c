
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include"Servicio.h"
#include "Trabajo.h"
#include "informes.h"
#include "Bicicleta.h"
#include "Funciones.h"

void ListadosPorMarca (eTrabajo listaT[],int tamT,eBicicleta listaB[],int tamB,eServicio listaS[],int tamS)

{

    eTrabajo pivot;
    int i;
    int j;
    char primeramarca[41];
    char segundamarca[41];

    for (i=0;i<tamT-1;i++)
    {
        for(j=i+1;j<tamT;j++)
        {
            if (listaT[i].isEmpty==OCUPADO && listaT[j].isEmpty ==OCUPADO)
            {
            	DescripcionDeLaBicicleta(listaB,tamB,listaT[i].idBici,primeramarca);
            	DescripcionDeLaBicicleta(listaB,tamB,listaT[j].idBici,segundamarca);
                if (stricmp(primeramarca,segundamarca)>0)
                {
                    pivot = listaT[i];
                    listaT[i] = listaT[j];
                    listaT[j] = pivot;
                }

            }
        }
    }

    ListadoTrabajos (listaT,tamT,listaS,tamS,listaB,tamB);
}


void ServicioConMasTrabajos(eTrabajo listaT[],int tamT,eServicio listaS[],int tamS)
{
	eServicio aux[tamS];


	int contador[tamS];
    int cantidad=0;
    int id;
    int index;
    char servicio[45];

    for(int i=0; i<tamS ;i++)
    {
    	aux[i].id=listaS[i].id;
    	contador[i]=0;
        index=i;

        	for(int j=0;j<tamT;j++)
        	{
        		if((listaT[j].isEmpty==OCUPADO) && (listaT[j].idServicio==aux[i].id))
        		{
        			contador[index]++;
        		}
        	}
    }

    for(int k=0;k<tamS;k++)
    {
        if(k==0||(cantidad<contador[k]))
        {
            cantidad=contador[k];
            id=aux[k].id;
        }
    }

    DescripcionDelServicio(listaS,tamS,id,servicio);
    printf("\nEl servicio con mas trabajos realizados es: %s\n",servicio);
}

void BicisPorServicio(eTrabajo listaT[],int tamT , eBicicleta listaB[], int tamB)
{

    int i;
    int contador=0;
    int index;
    {
        for(i=0;i<tamT;i++)
        {
            if(listaT[i].isEmpty==OCUPADO)
            {
                index = IndiceDeLaBici(listaB,tamB,listaT[i].idBici);
                if((stricmp(listaB[index].color,"Rojo")==0))
                {
                    contador++;

                }
            }
        }
        printf("La cantidad de bicis rojas para el servicio es: %d\n",contador);
    }

}
