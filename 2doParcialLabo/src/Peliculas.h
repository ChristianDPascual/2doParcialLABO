#include "LinkedList.h"
#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[100];
    char genero[100];
    int duracion;

}ePelicula;

#endif // PAISES_H_INCLUDED

ePelicula* nuevaPelicula();
ePelicula* nuevos_Parametros(char*,char*,char*, char*);
int getID(ePelicula*,int);
int getDuracion(ePelicula*,int);
int getTitulo(ePelicula*,char*);
int getGenero(ePelicula*,char*);
int setDuracion(ePelicula* pPeli,int duracion);
int mapDuracion(void* Peliculas);

