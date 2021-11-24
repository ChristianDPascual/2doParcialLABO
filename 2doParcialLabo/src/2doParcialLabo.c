#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "controller.h"
#include "UTN.h"
#define FALSE -1
#define TRUE 0


int main()
{
	setbuf(stdout,NULL);
	srand(time(NULL));
    int opciones;
	int control;
	int verificar;
	char cOpciones[2];
	char nombreArchivo[30];

	LinkedList* listadoPeliculas = ll_newLinkedList();

	if(listadoPeliculas->pFirstNode==NULL)
	{
	  do
	  {

		printf("\nElija la opcion\n");
		printf("1\tCargar archivo:\n");
		printf("2\tImprimir lista\n");
		printf("3\tAsignar tiempo\n");
		printf("4\tFiltrar por tipo\n");
		printf("5\tMostrar duraciones\n");
		printf("6\tGuardar peliculas\n");
		printf("7\tSalir\n");
		fflush(stdin);
		scanf("%[^\n]",cOpciones);
		opciones=atoi(cOpciones);

		while((verificar=validarNumeroEntero(cOpciones))==FALSE || (opciones>7 || opciones<1))
		{
			printf("Error, Elija una opcion valida (1-7)\n");
			fflush(stdin);
			scanf("%[^\n]",cOpciones);
			opciones=atoi(cOpciones);
		}
		  control=ll_len(listadoPeliculas);
		  switch(opciones)
		  {
		  case 1:
			  printf("Ingrese el nombre del archivo para cargar:\n");
			  fflush(stdin);
			  scanf("%[^\n]",nombreArchivo);
			  if(cargarArchivo(/*"movies.csv"*/nombreArchivo,listadoPeliculas)==TRUE)
			  {
                 printf("Se cargo exitosamente\n");
			  }
			  else
			  {
				  printf("No se pudo cargar el archivo\n");
			  }
			  break;
		  case 2:
			  if(control>0)
			  {
			    if((cListadoPeliculas(listadoPeliculas))==FALSE)
			    {
				    printf("Ocurrio un error\n");
			    }
			  }
		       else
			  {
				    printf("Error, no hay peliculas cargadas\n");
			  }
			  break;
		  case 3:
			  if(control>0)
			  {
				 listadoPeliculas=ll_map(listadoPeliculas,mapDuracion);
			  }
			  else
			  {
				  printf("Error, no hay peliculas cargadas\n");
			  }

		      break;
		  case 4:

			  break;
		  case 5:
		   break;
		  case 6:
			  if(control>0)
			  {
				  if(guardarArchivo(nombreArchivo,listadoPeliculas)==TRUE)
				  {
					  printf("se guardo exitosamente el archivo\n");
				  }
				  else
				  {
					  printf("no se pudo guardar el archivo\n");
				  }
			  }
			  else
			  {
				  printf("Error, no hay peliculas cargadas\n");
	    	  }

			  break;
		  case 7:
			  printf("Programa Finalizado\n");
			  break;
		  }
	   }while(opciones!=7);
	}
	else
	{
		printf("ERROR, no se inicializo el programa\n");
	}

		return 0;
}
