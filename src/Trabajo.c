#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Trabajo.h"

#include "utn.h"

int idAutoincremental=0;

int Asignarid()

{
	return idAutoincremental+=1;
}


int InicializarTrabajos (eTrabajo lista[],int tam)
{
	int i;
	int error=-1;

	if (lista != NULL && tam > 0)

	{
		for (i=0;i<tam;i++)
		{
			lista[i].isEmpty=VACIO;
		}
		error=0;
	}


	return error;
}
int BuscarLibre (eTrabajo lista[],int tam)
{

	int i;
	int index=-1;

		if (lista != NULL && tam > 0)

		{
			for (i=0;i<tam;i++)
			{
				if(lista[i].isEmpty==VACIO)
				{
					index=i;
					break;
				}
			}

		}


		return index;

}

int BuscarTrabajoPorID(eTrabajo lista[], int tam,int id)
{
	int indice=-1;
	int i;
	if (lista != NULL && tam > 0)

	{
		for (i=0;i<tam;i++)
		{
			if (lista[i].id==id)
			{
				indice=i;
				break;
			}
		}

	}
	return indice;
}

int ordenarTrabajos(eTrabajo lista[], int tam)
{
    eTrabajo auxTrabajo;
    int retorno = -1;

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam ; j++)
        {
            if(lista[i].fecha.anio==lista[j].fecha.anio)
            {
                if(strcmp(lista[i].marcaBicicleta,lista[j].marcaBicicleta)>0)
                {

                    auxTrabajo = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxTrabajo;
                    retorno = 0;
                }
            }
            else
            {
                if(lista[i].fecha.anio>lista[j].fecha.anio)
                {
                    auxTrabajo = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxTrabajo;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}




