

#ifndef SERVICIO_H_
#define SERVICIO_H_

#define S 4

 typedef struct
   {

	 int id;

	 char descripcion[25];

	 float precio;

   }eServicio;




 int MostrarListaServicios(eServicio servicios[], int tam);
 void MostrarServicio (eServicio servicio);
 int DescripcionDelServicio(eServicio lista[], int tam, int id, char descripcion[]);
 void HardcodearServicio(eServicio lista[]);
#endif /* SERVICIO_H_ */
