#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"
#define X 4
int main(void)
{
	setbuf(stdout,NULL);
	eTrabajo miTrabajo[T];
	eServicio listaServicio[S]; //= {{1,"Limpieza",250},{2,"Parche",300},{3,"Centrado",400},{4,"Cadena",350}};
	eBicicleta miBicicleta[B];


	int idAux;
	int idBiciAux;
	int idServicioAux;
	int indexAux;
	char continuar='n';
	int flagAlta=0;
	int dia;
	int mes;
	int anio;

	InicializarTrabajos (miTrabajo,T);
	HardcodearServicio(listaServicio);
	HardcodearBicicleta(miBicicleta);


	do
		{
		continuar='n';
			switch(Menu())
			{
			case 1:
					if (PedirDatos(miTrabajo,T,&idAux,&idServicioAux,&idBiciAux,&indexAux,&dia,&mes,&anio,listaServicio,S,miBicicleta,B)==0
						&&
						LeerDatos (miTrabajo,T,idAux,idBiciAux,idServicioAux,indexAux,dia,mes,anio)==0)
					{
						printf("El alta fue realizada \n");
						flagAlta=1;
					}
					else
					{
						printf("Error. El alta no pudo ser realizada \n");
					}
					break;
			case 2:
				if (flagAlta!=1)
				{
					printf("Error, primero debe realizar un Alta \n");
				}
				else
				{
					ModificarTrabajo(miTrabajo,T,listaServicio,S,miBicicleta,B);
				}
				break;
			case 4:
				Ordenamiento(miTrabajo,T,miBicicleta,B);
				ListadoTrabajos(miTrabajo,T,listaServicio,S,miBicicleta,B);
				break;

			case 5:
				MostrarListaServicios(listaServicio,S);
				break;
			case 6:
				TotalEnPesos(miTrabajo,T,listaServicio,S);
				break;
			case 7:
				if (flagAlta!=1)
				{
					printf("Error, primero debe realizar un Alta \n");
				}
				else
				{
					printf("-------INFORMES--------\n");
					ListadosPorMarca (miTrabajo,T,miBicicleta,B,listaServicio,S);
					printf("\n");
					ServicioConMasTrabajos(miTrabajo,T,listaServicio,S);
					printf("\n");
					BicisPorServicio(miTrabajo,T,miBicicleta,B);
				}
				break;
			case 0:
					printf("Presionar 's' para la salida\n");
					fflush(stdin);
					scanf("%c", &continuar);
					break;
			case 3:
				if (flagAlta!=1)
				{
							printf("Error, primero debe realizar un Alta \n");
				}
				else
				{
					BajaTrabajo(miTrabajo,T,listaServicio,S,miBicicleta,B);
				}

			}
		}while(continuar!='s');





	return EXIT_SUCCESS;
}
