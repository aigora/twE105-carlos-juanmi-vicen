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

void temasrand(int aleatorio[NUMT1])
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

void abrirficherospreguntas(void)
{
	int i, j;
	FILE *pf, *pb1, *pb2, *pb3; 
	pf = fopen("Ficheros/Nombres/Nombres.txt", "r");
	pb1 = fopen("Ficheros/Nombres/PreguntasBloque1", "r");
	pb2 = fopen("Ficheros/Nombres/PreguntasBloque2", "r");
	pb3 = fopen("Ficheros/Nombres/PreguntasBloque3", "r");
	
}









