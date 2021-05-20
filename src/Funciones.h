#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include"Servicio.h"
#include "Trabajo.h"
#include "utn.h"
#include "informes.h"
#include "Bicicleta.h"

int Menu ();
int PedirDatos (eTrabajo lista[], int tam, int* id, int* idServicio,int* idBici,int* index,int* dia, int* mes, int* anio,eServicio listaS[],int tamS,eBicicleta listaB[],int tamB);
int LeerDatos (eTrabajo lista[], int tam, int id,int idBici,int idServicio, int index, int dia, int mes, int anio);
void MostrarTrabajo (eTrabajo Lista, eServicio listaS[], int tamS,eBicicleta listaB[],int tamB);
int ListadoTrabajos (eTrabajo Lista[],int tam, eServicio listaS[], int tamS,eBicicleta listaB[],int tamB);
int ModificarTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS,eBicicleta listaB[],int tamB);
int MenuModificaciones ();
int BajaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS,eBicicleta listaB[],int tamB);
int TotalEnPesos (eTrabajo listaT[], int tam, eServicio listaS[], int tamS);
int SubMenuBajas ();
void Ordenamiento (eTrabajo listaT[], int tam,eBicicleta listaB[], int tamB);
#endif /* FUNCIONES_H_ */



