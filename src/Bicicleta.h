/*
 * Bicicleta.h
 *
 *  Created on: 20 may. 2021
 *      Author: jose_
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_

#define B 5
typedef struct
{
	int id;
	char marca[26];
	int rodado;
	char color[30];
}eBicicleta;

void MostrarBicicleta (eBicicleta bici);
int ListadoBicicletas(eBicicleta listaB[], int tamB);
void HardcodearBicicleta(eBicicleta listaB[]);
eBicicleta BuscarBicicletaPorId(eBicicleta listaB[], int tamB, int id);
int DescripcionDeLaBicicleta(eBicicleta lista[], int tam, int id, char descripcion[]);
int IndiceDeLaBici(eBicicleta listaB[], int tamB, int id);
#endif /* BICICLETA_H_ */
