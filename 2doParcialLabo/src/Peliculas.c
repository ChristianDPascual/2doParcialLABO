#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Peliculas.h"
#define T 100
#define TRUE 0
#define FALSE -1

ePelicula* nuevaPelicula()
{
	ePelicula* pNuevaPelicula;

	pNuevaPelicula=(ePelicula*)malloc(sizeof(ePelicula));

	return pNuevaPelicula;
}

ePelicula* nuevos_Parametros(char* id,char* titulo,char* genero, char* duracion)
{
	ePelicula* pPelicula;

	pPelicula->id_peli=atoi(id);
	strcpy(pPelicula->titulo,titulo);
	strcpy(pPelicula->genero,genero);
	pPelicula->duracion=atoi(duracion);

    return pPelicula;

}
int getTitulo(ePelicula* pPeli,char* titulo)
{
    int retorno=FALSE;
    if(pPeli!=NULL && titulo!=NULL)
    {
        strcpy(titulo,pPeli->titulo);
        retorno=TRUE;
    }
    return retorno;
}

int getGenero(ePelicula* pPeli,char* genero)
{
    int retorno=FALSE;
    if(pPeli!=NULL && genero!=NULL)
    {
        strcpy(genero,pPeli->genero);
        retorno=TRUE;
    }
    return retorno;
}

int getID(ePelicula* pPeli,int id)
{
	int retorno=FALSE;
    if(pPeli!=NULL)
    {
        id=pPeli->id_peli;
        retorno=TRUE;
    }
    return retorno;
}

int getDuracion(ePelicula* pPeli,int duracion)
{
	int retorno=FALSE;
    if(pPeli!=NULL)
    {
        duracion=pPeli->id_peli;
        retorno=TRUE;
    }
    return retorno;
}

int setDuracion(ePelicula* pPeli,int duracion)
{
	int retorno=FALSE;
    if(pPeli!=NULL)
    {
        pPeli->id_peli=duracion;
        retorno=TRUE;
    }
    return retorno;
}

int listarPeliculas(ePelicula* pPeliculas)
{
    int retorno=FALSE;
    int id;
    char titulo[T];
    char genero[T];
    int duracion;


    if(pPeliculas!=NULL && getID(pPeliculas,id)==TRUE && getTitulo(pPeliculas,titulo)==TRUE && getGenero(pPeliculas,genero)==TRUE && getDuracion(pPeliculas, duracion)==TRUE)
    {
        printf("%d\t\t%s\t\t%s\t\t%d\n",id,titulo,genero,duracion);
        retorno=TRUE;
    }
    return retorno;
}

int mapDuracion(void* Peliculas)
{
    int retorno=FALSE;
    int duracion;
    int max=4;
    int min=1;
    ePelicula* aux;


    if(Peliculas != NULL  )
    {
        aux = (ePelicula*) Peliculas;
        duracion= rand() % (max - min +1) + min;
        if(setDuracion(aux,duracion)==0)
        {
            retorno=TRUE;
        }
    }
    return retorno;
}
