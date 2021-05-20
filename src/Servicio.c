#include "Servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


int MostrarListaServicios(eServicio servicios[], int tam)
{
    int retorno=-1;
    int i;

    if(servicios!=NULL && tam>0)
    {
        printf("----------SERVICIOS----------\n");

        for(i=0;i<tam;i++)
        {
            MostrarServicio(servicios[i]);
            retorno=0;
        }
    }

    return retorno;
}

void MostrarServicio (eServicio servicio)
{



    printf( "ID del servicio: %d\n"
            "Descripcion: %s\n"
            "Precio: %.2f\n", servicio.id
                            , servicio.descripcion
                            , servicio.precio);


 }


int DescripcionDelServicio(eServicio lista[], int tam, int id, char descripcion[])
{
	int retorno;
	int i;

	if(lista!=NULL && tam>0 && descripcion!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].id==id)
			{
				strcpy(descripcion,lista[i].descripcion);
				retorno=0;
			}
		}
	}

	return retorno;
}

void HardcodearServicio(eServicio lista[])
{
    int i;
    eServicio aux[4]=
    {
    		{20000,"Limpieza",250},
			{20001,"Parche",300},
			{20002,"Centrado",400},
			{20003,"Cadena",350},


    };
    for(i=0;i<4;i++)
    	lista[i]=aux[i];
}
