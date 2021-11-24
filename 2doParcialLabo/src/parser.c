#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Peliculas.h"
#define T 100
#define FALSE -1
#define TRUE 0

int parser_FromText(FILE* pArchivo, LinkedList* lista)
{
	int retorno=FALSE;
	ePelicula* Peliculas;
	char id[T];
	char titulo[T];
	char genero[T];
	char duracion[T];

	if(pArchivo!=NULL && lista!=NULL)
	{
	  fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,duracion);
	  while(!feof(pArchivo))
	  {
		  fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,duracion);
		  Peliculas=nuevaPelicula();
		  Peliculas=nuevos_Parametros(id,titulo,genero,duracion);
		  ll_add(lista,Peliculas);
	   }
	  retorno=TRUE;
	}

	return retorno;
}
