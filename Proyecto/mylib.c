#include "mylib.h"

void escribeTexto(char vector[]) //funcion letras con retraso
{
	int i=0;
	while(vector[i]!='\0')
	{
		printf("%c", vector[i]);
		i++;
		Sleep(10);
	}	
}

void vectorrand(int x,int aleatorio[x])
{
	int i, j;	
	srand (time(NULL));
	aleatorio[0]=rand()%x;
	for( i=1 ; i<x ; i++)
	{
	aleatorio[i]=rand()%x;
	for( j=i-1 ; j>=0 ; j--)
	{
	while(aleatorio[i]==aleatorio[j])
	{
	aleatorio[i]=rand()%x;
	j=i-1;
	}
	}
	}
}

int ComprobarDinero1(float *papuestaA,float *papuestaB,float *papuestaC,float *papuestaD,float *pdinero, float *pfajos)
{
	char respuesta;
	if((*papuestaA+*papuestaB+*papuestaC+*papuestaD)<*pfajos)
	{
		escribeTexto("Debes repartir todo el dinero");
		return 0;
	}
	else if((*papuestaA+*papuestaB+*papuestaC+*papuestaD)>*pfajos)
	{
		escribeTexto("No puedes repartir mas dinero del que tienes");
		return 0;
	}
	else if((*papuestaA!=0)&&(*papuestaB!=0)&&(*papuestaC!=0)&&(*papuestaD!=0))
	{
		escribeTexto("Te recuerdo que solo puedes repartir el dinero en tres opciones de las cuatro posibles");
		return 0;
	}
	escribeTexto("Seguro que quieres repartir el dinero de esta manera?\n");
	fflush(stdin);
	scanf("%c", &respuesta);
	while ((respuesta!='S')&&(respuesta!='N')) //si no pone ni si ni no
	{
		escribeTexto("\nNo te entiendo. Por favor, escribe 'si' o 'no':\n\n");
		scanf("%c", &respuesta);	
	}
	switch(respuesta) //si pone si
    {
    case 'S':
    	return 1; 
    	break;
    case 'N':
    	return 0;
    	break;
    }
}

int ComprobarDinero2(float *papuestaA,float *papuestaB,float *papuestaC,float *pdinero, float *pfajos)
{
	char respuesta;
	if((*papuestaA+*papuestaB+*papuestaC)<*pfajos)
	{
		escribeTexto("Debes repartir todo el dinero");
		return 0;
	}
	else if((*papuestaA+*papuestaB+*papuestaC)>*pfajos)
	{
		escribeTexto("No puedes repartir mas dinero del que tienes");
		return 0;
	}
	else if((*papuestaA!=0)&&(*papuestaB!=0)&&(*papuestaC!=0))
	{
		escribeTexto("Te recuerdo que solo puedes repartir el dinero en tres opciones de las cuatro posibles");
		return 0;
	}
	escribeTexto("Seguro que quieres repartir el dinero de esta manera?\n");
	fflush(stdin);
	scanf("%c", &respuesta);
	while ((respuesta!='S')&&(respuesta!='N')) //si no pone ni si ni no
	{
		escribeTexto("\nNo te entiendo. Por favor, escribe 'si' o 'no':\n\n");
		scanf("%c", &respuesta);	
	}
	switch(respuesta) //si pone si
    {
    case 'S':
    	return 1; 
    	break;
    case 'N':
    	return 0;
    	break;
    }	
}

int ComprobarDinero3(float *papuestaA,float *papuestaB,float *pdinero, float *pfajos)
{
	char respuesta;
	if((*papuestaA+*papuestaB)<*pfajos)
	{
		escribeTexto("Debes repartir todo el dinero");
		return 0;
	}
	else if((*papuestaA+*papuestaB)>*pfajos)
	{
		escribeTexto("No puedes repartir mas dinero del que tienes");
		return 0;
	}
	else if((*papuestaA!=0)&&(*papuestaB!=0))
	{
		escribeTexto("Te recuerdo que solo puedes repartir el dinero en tres opciones de las cuatro posibles");
		return 0;
	}
	escribeTexto("Seguro que quieres repartir el dinero de esta manera?\n");
	fflush(stdin);
	scanf("%c", &respuesta);
	while ((respuesta!='S')&&(respuesta!='N')) //si no pone ni si ni no
	{
		escribeTexto("\nNo te entiendo. Por favor, escribe 'si' o 'no':\n\n");
		scanf("%c", &respuesta);	
	}
	switch(respuesta) //si pone si
    {
    case 'S':
    	return 1; 
    	break;
    case 'N':
    	return 0;
    	break;
    }
}

void apuesta1(float *papuestaA,float *papuestaB,float *papuestaC,float *papuestaD)
{
	fflush(stdin);
	printf("\nA--> ");
	scanf("%f",papuestaA);
	printf("\nB--> ");
	scanf("%f",papuestaB);
	printf("\nC--> ");
	scanf("%f",papuestaC);
	printf("\nD--> ");
	scanf("%f",papuestaD);
}

void apuesta2(float *papuestaA,float *papuestaB,float *papuestaC)
{
	fflush(stdin);
	printf("\nA--> ");
	scanf("%f",papuestaA);
	printf("\nB--> ");
	scanf("%f",papuestaB);
	printf("\nC--> ");
	scanf("%f",papuestaC);
}

void apuesta3(float *papuestaA,float *papuestaB)
{
	fflush(stdin);
	printf("\nA--> ");
	scanf("%f",papuestaA);
	printf("\nB--> ");
	scanf("%f",papuestaB);
}





