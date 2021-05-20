/*
 * informes.h
 *
 *  Created on: 20 may. 2021
 *      Author: jose_
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Bicicleta.h"
void ListadosPorMarca (eTrabajo listaT[],int tamT,eBicicleta listaB[],int tamB,eServicio listaS[],int tamS);
void ServicioConMasTrabajos(eTrabajo listaT[],int tamT,eServicio listaS[],int tamS);
void BicisPorServicio(eTrabajo listaT[],int tamT,eBicicleta listaB[],int tamB);

#endif /* INFORMES_H_ */
