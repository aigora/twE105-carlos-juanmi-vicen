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
	for( i=1 ; i<NUMT1 ; i++)
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
void abrirficherospreguntas(void)
{
	FILE *pf, *pb1, *pb2, *pb3, *res1; 
	pf = fopen("Ficheros/Nombres/Nombres.txt", "r");
	pb1 = fopen("Ficheros/Preguntas/PreguntasBloque1", "r");
	pb2 = fopen("Ficheros/Preguntas/PreguntasBloque2", "r");
	pb3 = fopen("Ficheros/Preguntas/PreguntasBloque3", "r");
	res1 = fopen("Ficheros/Preguntas/RespuestasBloque1", "r");
}









