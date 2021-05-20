#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"


int Menu ()
{
	int opcion;



	printf("------------MENU------------ \n");
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. LISTADO DE TRABAJOS\n");
	printf("5. LISTADO DE SERVICIOS\n");
	printf("6. TOTAL EN PESOS POR SERVICIOS PRESTADOS\n");
	printf("7. INFORMES\n");
	printf("0. SALIDA\n");

	utn_getInt(&opcion,"\n",3,9,0,9);
	return opcion;
}

int PedirDatos (eTrabajo lista[], int tam, int* id, int* idServicio,int* idBici,int* index,int* dia, int* mes, int* anio,eServicio listaS[],int tamS,eBicicleta listaB[],int tamB)

{

	int retorno=-1;

	if (lista != NULL && tam >0 )

		{

			*index=BuscarLibre(lista,tam);

				{
					if (*index==-1)
					{
						printf("No se encontro un lugar vacio. La lista de trabajos esta llena \n");
					}
					else
					{



						*id=Asignarid();
						MostrarListaServicios(listaS,S);
						utn_getInt(idServicio,"Por favor ingresar un ID de SERVICIO \n",9,4,20000,30000);
						ListadoBicicletas(listaB,tamB);
						utn_getInt(idBici,"Por favor ingresar un ID de BICI \n",9,4,1,5);

						utn_getInt(dia,"Fechas:\nPor favor ingresar DIA (1-31)\n",4,4,1,31);
						utn_getInt(mes,"Por favor ingresar MES (1-12)\n",4,4,1,12);
						utn_getInt(anio,"Por favor ingresar AÑO (1921-2021)\n",6,4,1921,2021);
						retorno=0;

					}
				}

		}

	return retorno;
}

int LeerDatos (eTrabajo lista[], int tam, int id,int idBici,int idServicio, int index, int dia, int mes, int anio)

{
	int error=-1;

	if (lista != NULL && tam >0)

	{

		lista[index].id=id;
		lista[index].idBici=idBici;
		lista[index].idServicio=idServicio;
		lista[index].isEmpty=OCUPADO;
		lista[index].fecha.dia=dia;
		lista[index].fecha.mes=mes;
		lista[index].fecha.anio=anio;

		error=0;


	}
	return error;
}

void MostrarTrabajo (eTrabajo Lista, eServicio listaS[], int tamS,eBicicleta listaB[],int tamB)
{
	char nombre[41];
	eBicicleta aux;
	aux=BuscarBicicletaPorId(listaB,tamB,Lista.idBici);
	DescripcionDelServicio(listaS,tamS,Lista.idServicio,nombre);

	printf("ID: %d 	SERVICIO: %s	MARCA: %s	RODADO: %d	FECHA: %d/%d/%d\n",Lista.id,nombre,aux.marca,aux.rodado,Lista.fecha.dia,Lista.fecha.mes,Lista.fecha.anio);


}


int ListadoTrabajos (eTrabajo Lista[],int tam, eServicio listaS[], int tamS,eBicicleta listaB[],int tamB)
{
	int i;
	int retorno=0;
	for (i=0;i<tam;i++)
	{
		if (Lista[i].isEmpty==OCUPADO)
		{
				MostrarTrabajo(Lista[i],listaS,tamS,listaB,tamB);
		}
	}
	return retorno;
}

int ModificarTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS,eBicicleta listaB[],int tamB)
{
	int retorno=-1;
	int id;
	int indiceT;
	eBicicleta aux;
	char salida;
	if (lista != NULL && tam >0)
	{
		ListadoTrabajos(lista,tam,listaS,tamS,listaB,tamB);
		utn_getInt(&id,"\nPor favor ingresar el ID del Trabajo a modificar\n",7,4,1,1000);
		indiceT=BuscarTrabajoPorID(lista,tam,id);

		if (indiceT==-1)
		{
			printf("El id no le corresponde a ningun trabajo \n");
		}
		else
		{
			printf("El id le corresponde al empleado: \n");
			MostrarTrabajo(lista[indiceT],listaS,tamS,listaB,tamB);
			do
			{

				switch(MenuModificaciones())
				{

				case 1:
					aux=BuscarBicicletaPorId(listaB,tamB,lista[indiceT].idBici);
					printf("La bicicleta es: \n");
					MostrarBicicleta(aux);
					printf("\n");
					ListadoBicicletas(listaB,tamB);
					utn_getInt(&lista[indiceT].idBici,"Por favor ingresar nueva BICICLETA",9,4,1,5);
					break;
				case 2:
					printf("El SERVICIO es %d \n",lista[indiceT].idServicio);
					MostrarListaServicios(listaS,tamS);
					utn_getInt(&lista[indiceT].idServicio,"Por favor ingresar nuevo SERVICIO",9,4,20000,30000);
					break;
				case 3:
					printf("Esta seguro que desea volver al menu principal? presione 's' para salir\n");
					fflush(stdin);
					scanf("%c",&salida);
					break;

				default:
					printf("Por favor ingresar una opcion valida");

					break;
				}
			}while(salida!='s');
			retorno=0;
		}
	}
	return retorno;
}



int MenuModificaciones ()
{
	int opcion;



	printf("Que desea modificar?\n");
	printf("1. BICI\n");
	printf("2. SERVICIO\n");
	printf("3. SALIR\n");


	scanf("%d",&opcion);

	return opcion;
}

int BajaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS,eBicicleta listaB[],int tamB)
{
	int retorno=-1;
	int indiceT;
	char confirmacion;
	int id;
	if (lista != NULL && tam > 0)
	{
		ListadoTrabajos(lista,tam,listaS,tamS,listaB,tamB);
		utn_getInt(&id,"Por favor ingresar el ID del trabajo a dar BAJA",7,4,1,1000);
		indiceT=BuscarTrabajoPorID(lista,tam,id);

		if (indiceT<0)
		{
			printf("El id no le corresponde a ningun trabajo \n\n");
		}
		else
		{

			MostrarTrabajo(lista[indiceT],listaS,tamS,listaB,tamB);


			printf("Esta seguro que desea realizar la BAJA? s/n \n:");
			scanf("%c",&confirmacion);

			if (confirmacion != 's' && confirmacion != 'n')
			{
				printf("Por favor ingresar la letra s para confirmar la baja O la letra n para no realizar la baja \n");
				scanf("%c",&confirmacion);
			}
			else
			{
				if (confirmacion=='s')
				{
					lista[indiceT].isEmpty=VACIO;
					retorno=0;
					printf("El trabajo se dio de baja con exito \n");
				}
				else
				{
					printf("El trabajo NO se dio de baja \n");
				}
			}
		}



	}
	return retorno;
}

int TotalEnPesos (eTrabajo listaT[], int tam, eServicio listaS[], int tamS)
{
	int retorno=-1;
	int i;
	int j;
	float acumuladorPesos=0;


	for(i=0;i<tam;i++)
	{

		for(j=0;j<tamS;j++)

		{

			if (listaT[i].isEmpty==OCUPADO)
			{
				if (listaT[i].idServicio==listaS[j].id)
				{


					acumuladorPesos+=listaS[j].precio;

					retorno=0;


				}
			}
		}

	}

	printf("\nEl total por Los servicios prestados es: %f \n",acumuladorPesos);

	return retorno;
}


void Ordenamiento (eTrabajo listaT[], int tam,eBicicleta listaB[], int tamB)

{
    eTrabajo pivot;
    int i;
    int j;
    char descripuno[41];
    char descripdos[42];

    for (i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if (listaT[i].isEmpty==OCUPADO && listaT[j].isEmpty ==OCUPADO)
            {
                if (listaT[i].fecha.anio > listaT[j].fecha.anio)
                {
                    pivot = listaT[i];
                    listaT[i] = listaT[j];
                    listaT[j] = pivot;
                }
                else
                {
                    if (listaT[i].fecha.anio == listaT[j].fecha.anio)
                    {
                        DescripcionDeLaBicicleta(listaB,tamB,listaT[i].idBici,descripuno);
                        DescripcionDeLaBicicleta(listaB,tamB,listaT[j].idBici,descripdos);
                        if (stricmp(descripuno,descripdos)>0)
                        {

                        	pivot = listaT[i];
                            listaT[i] = listaT[j];
                            listaT[j] = pivot;
                        }
                    }
                }
            }
        }
    }
}
