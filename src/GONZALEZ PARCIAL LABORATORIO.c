#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	eTrabajo miTrabajo[T];
	eServicio listaServicio[S]; //= {{1,"Limpieza",250},{2,"Parche",300},{3,"Centrado",400},{4,"Cadena",350}};

	int idAux;
	char marcaAux[90];
	int rodadoAux;
	int idServicioAux;
	int indexAux;
	char continuar='n';
	int flagAlta=0;
	int dia;
	int mes;
	int anio;

	InicializarTrabajos (miTrabajo,T);
	HardcodearServicio(listaServicio);



	do
		{
		continuar='n';
			switch(Menu())
			{
			case 1:

				if ( PedirDatos(miTrabajo,T,&idAux,marcaAux,&rodadoAux, &idServicioAux, &indexAux, listaServicio, &dia, &mes, &anio)==0 && LeerDatos (miTrabajo,T,idAux,marcaAux,rodadoAux,idServicioAux,indexAux,dia,mes,anio) == 0)
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
					ModificarTrabajo(miTrabajo,T,listaServicio,4);
				}
				break;
			case 4:
				ordenarTrabajos(miTrabajo,T);
				ListadoTrabajos(miTrabajo,T,listaServicio,4);
				break;

			case 5:
				MostrarListaServicios(listaServicio,S);
				break;
			case 6:
				TotalEnPesos(miTrabajo,T,listaServicio,S);
				break;
			case 9:
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
					BajaTrabajo(miTrabajo,T,listaServicio,S);
				}

			}
		}while(continuar!='s');





	return EXIT_SUCCESS;
}
