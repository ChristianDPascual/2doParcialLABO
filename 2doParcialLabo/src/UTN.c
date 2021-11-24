#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#define TRUE 0
#define FALSE -1

int validarPalabra(char nombre[])
{
	int validacion=TRUE;
	int largo;
	int i;
	int control;

	largo=strlen(nombre);
	for(i=0;i<largo;i++)
	{
		control=isalpha(nombre[i]);
		if(control==0)
		{
			validacion=FALSE;
			break;
		}
	}

	return validacion;
}

int validarNumeroEntero(char numero[])
{
	int i;
	int largo;
	int control;
	int validacion=TRUE;

	largo=strlen(numero);

	for(i=0;i<largo;i++)
	{
	   control=isdigit(numero[i]);
	   if(control==0)
	   {
		   validacion=FALSE;
		   break;
	   }
	}

	return validacion;
}
int validarNumeroFlotante(char numero[])
{
	    int validacion=TRUE;
		int i;
		int comas=0;
		int valor=0;
		int control;

		for(i=0;i<strlen(numero);i++)
		{
		   control=isdigit(numero[i]);
		   if(control==0 && valor==0)
		   {
			   valor=-1;
			   if(numero[i]=='.' && i>1 && comas==0)
			   {
				valor=0;
				comas++;
			   }
			   else
			   {
				   validacion=FALSE;
				   break;
			   }

		   }
		}

	return validacion;
}



int DarRespuesta()
{
	int validacion;
	int i;
	char respuesta[3];
	char letra;

	printf("Desea continuar(si/no)\n");
	fflush(stdin);
	scanf("%[^\n]",respuesta);

	while(validarPalabra(respuesta)==FALSE)
	{
		printf("Error, desea continuar(si/no)\n");
			fflush(stdin);
			scanf("%[^\n]",respuesta);
	}

	for(i=0;i<3;i++)
	{
			letra=tolower(respuesta[i]);
			respuesta[i]=letra;
	}

	if(strcmp(respuesta,"si")==TRUE)
	{
		validacion=TRUE;
	}
	else
	{
		validacion=FALSE;
	}

	return validacion;
}

