#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "Peliculas.h"
#define FALSE -1
#define TRUE 0


int cargarArchivo(char* Archivo,LinkedList* pListado)
{
	int retorno=FALSE;
    FILE* pFile=NULL;

    if(pListado!=NULL)
    {
        pFile=fopen(Archivo,"r");
        if(pFile!=NULL)
        {
           printf("lele\n");
           if(parser_FromText(pFile, pListado)==TRUE)
           {
        	   retorno=TRUE;
           }
        }
    }
    fclose(pFile);
    return retorno;

}



int cListadoPeliculas(LinkedList* pListado)
{
    int retorno=FALSE;
    int tamanio=0;
    int i;
    Node* aux=NULL;

    if(pListado!=NULL)
    {
        tamanio=ll_len(pListado);
        if(tamanio>=1)
        {
             retorno=TRUE;
             aux=pListado->pFirstNode;
             if(aux!=NULL)
             {
            	 listarPeliculas(aux->pElement);
                 for(i=0;i<tamanio-1;i++)
                 {
                	 aux=aux->pNextNode;
                	 listarPeliculas(aux->pElement);
                 }
             }
        }
        else
        {
          	printf("No hay peliculas cargadas\n");
        }
    }
    return retorno;
}

int guardarArchivo(char* Archivo,LinkedList* pListado)
{
    FILE* pFile=NULL;
    int retorno=FALSE;
    int tamanio;
    int i;
    ePelicula* aux=NULL;

    if(pListado!=NULL)
    {
        tamanio=ll_len(pListado);

        pFile=fopen(Archivo,"w");

        if(pFile!=NULL && tamanio>0 && fprintf(pFile, "id_peli,titulo,genero,duracion\n")!=FALSE)
        {
            for(i=0;i<tamanio;i++)
            {
                aux=(ePelicula*)ll_get(pListado,i);
                if(aux == NULL || fprintf(pFile,"%d,%s,%s,%d\n",aux->id_peli, aux->titulo, aux->genero, aux->duracion)==-1)
                {
                    break;
                }
            }
        }

        if(i>0 && i==tamanio)
        {
            retorno= TRUE;
        }
        fclose(pFile);
    }
    return retorno;
}
