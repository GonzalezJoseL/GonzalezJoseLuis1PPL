#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Bicicleta.h"
#include "utn.h"


void HardcodearBicicleta(eBicicleta listaB[])
{
    int i;
    eBicicleta aux[5]=
    {
    		{1,"Razer",2,"Rojo"},
			{2,"Olmo",3,"Azul"},
			{3,"Venzo",4,"Verde"},
			{4,"Top mega",1,"Marron"},
			{5,"Raleigh",3,"Celeste"}


    };
    for(i=0;i<5;i++)
    	listaB[i]=aux[i];
}



int ListadoBicicletas(eBicicleta listaB[], int tamB)
{
    int retorno=-1;
    int i;

    if(listaB!=NULL && tamB>0)
    {
        printf("----------BICICLETAS----------\n");

        for(i=0;i<tamB;i++)
        {
        	MostrarBicicleta(listaB[i]);
            retorno=0;
        }
    }

    return retorno;
}

void MostrarBicicleta (eBicicleta bici)
{



    printf( "ID de la BICI: %d\n"
            "MARCA: %s\n"
            "RODADO: %.d\n"
    		"COLOR: %s\n"	, bici.id
                            , bici.marca
                            , bici.rodado
							, bici.color);


}

eBicicleta BuscarBicicletaPorId(eBicicleta listaB[], int tamB, int id)
{
	eBicicleta auxMascota;
    int i;

    if(listaB!=NULL && tamB>0)
    {
        for(i=0;i<tamB;i++)
        {
            if(listaB[i].id==id)
            {
                auxMascota = listaB[i];
                break;
            }
        }
    }

    return auxMascota;
}

int DescripcionDeLaBicicleta(eBicicleta lista[], int tam, int id, char descripcion[])
{
	int retorno;
	int i;

	if(lista!=NULL && tam>0 && descripcion!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].id==id)
			{
				strcpy(descripcion,lista[i].marca);
				retorno=0;
			}
		}
	}

	return retorno;
}

int IndiceDeLaBici(eBicicleta listaB[], int tamB, int id)
{
	int retorno;
	int i;

	if(listaB!=NULL && tamB>0)
	{
		for(i=0;i<tamB;i++)
		{
			if(listaB[i].id==id)
			{
				retorno=i;
			}
		}
	}

	return retorno;
}
