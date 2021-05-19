#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include"Servicio.h"
#include "Trabajo.h"
#include "utn.h"

int Menu ();
int PedirDatos (eTrabajo lista[], int tam, int* id, char marcaBici[], int* rodadoBici, int* idServicio,int* index, eServicio listaS[],int* dia, int* mes, int* anio);
int LeerDatos (eTrabajo lista[], int tam, int id, char marcaBici[],int rodadoBici, int idServicio, int index, int dia, int mes, int anio);
void MostrarTrabajo (eTrabajo Lista, eServicio listaS[], int tamS);
int ListadoTrabajos (eTrabajo Lista[],int tam, eServicio listaS[], int tamS);
int ModificarTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS);
int MenuModificaciones ();
int BajaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS);
int TotalEnPesos (eTrabajo listaT[], int tam, eServicio listaS[], int tamS);
int SubMenuBajas ();
#endif /* FUNCIONES_H_ */



