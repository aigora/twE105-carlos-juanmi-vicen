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

void vectorrand8(int aleatorio[NUMT1])
{
	int i, j;	
	srand (time(NULL));
	aleatorio[0]=rand()%8;
	for( i=1 ; i<NUMT1 ; i++)
	{
	aleatorio[i]=rand()%8;
	for( j=i-1 ; j>=0 ; j--)
	{
	while(aleatorio[i]==aleatorio[j])
	{
	aleatorio[i]=rand()%8;
	j=i-1;
	}
	}
	}
}

void vectorrand2(int aleatorio[NUMP])
{
	int i, j;	
	srand (time(NULL));
	aleatorio[0]=rand()%2;
	for( i=1 ; i<NUMP ; i++)
	{
	aleatorio[i]=rand()%2;
	for( j=i-1 ; j>=0 ; j--)
	{
	while(aleatorio[i]==aleatorio[j])
	{
	aleatorio[i]=rand()%2;
	j=i-1;
	}
	}
	}
}

void vectorrand4(int aleatorio[NUMR1])
{
	int i, j;	
	srand (time(NULL));
	aleatorio[0]=rand()%4;
	for( i=1 ; i<NUMR1 ; i++)
	{
	aleatorio[i]=rand()%4;
	for( j=i-1 ; j>=0 ; j--)
	{
	while(aleatorio[i]==aleatorio[j])
	{
	aleatorio[i]=rand()%4;
	j=i-1;
	}
	}
	}
}


int repDin(int *papuestaA,int *papuestaB,int *papuestaC,int *papuestaD,float *pdinero)
{
	if(*papuestaA+*papuestaB+*papuestaC+*papuestaD<*pdinero)
	{
		escribeTexto("Debes repartir todo el dinero");
		return 0;
	}
	else if(*papuestaA+*papuestaB+*papuestaC+*papuestaD>*pdinero)
	{
		escribeTexto("No puedes repartir más dinero del que tienes");
		return 0;
	}
	else
	return 1;
	
}





