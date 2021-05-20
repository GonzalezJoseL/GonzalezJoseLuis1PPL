

#ifndef TRABAJO_H_
#define TRABAJO_H_


#define VACIO 0
#define OCUPADO 1

#define T 10


typedef struct
    {
        int dia;
        int mes;
        int anio;
    }eFecha;


    typedef struct
    {
        int id;
        int idBici;
        int idServicio;
        eFecha fecha;
        int isEmpty;
    }eTrabajo;


    int Asignarid();
    int InicializarTrabajos (eTrabajo lista[],int tam);
    int BuscarLibre (eTrabajo lista[],int tam);
    int BuscarTrabajoPorID(eTrabajo lista[], int tam,int id);





#endif /* TRABAJO_H_ */
