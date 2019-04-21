#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define NUMT1 8     //numero temas de la primera parte
#define NUMT2 6 	//numero temas de la segunda parte
#define NUMT3 2 	//numero temas de la tercera parte

void escribeTexto(char vector[]); //funcion para que las letras vayan con retraso
void temasrand(int aleatorio[NUMT1]); //generador de vector aleatorio
void nombres(char vector[]); //funcion que comprueba si el usuario ya existe

typedef struct {    //2 preguntas en cada tema
char contenido;
} question;

typedef struct {    //8 temas
char titulo[15];
question pregunta[10];
} Ntema; 

int main() //programa principal
{
	srand (time(NULL)); 
	char nombre[50], respuesta, nombrearchivo[50];
	int i, posicion; //posicion se usa en el desorden de los temas
	int aleatorio[NUMT1], loged=0; 
	FILE *pf;
	pf = fopen("Ficheros/Nombres/Nombres.txt", "r");
	Ntema Tordenados[NUMT1];	
	strcpy(Tordenados[0].titulo,"ANIMALES");
	strcpy(Tordenados[1].titulo,"HISTORIA");
	strcpy(Tordenados[2].titulo,"DEPORTE");
	strcpy(Tordenados[3].titulo,"CIENCIA");
	strcpy(Tordenados[4].titulo,"INVENTOS");
	strcpy(Tordenados[5].titulo,"LITERATURA");
	strcpy(Tordenados[6].titulo,"ARTE");
	strcpy(Tordenados[7].titulo,"GEOGRAFIA");
	Ntema Tdesordenados[NUMT1];
//	for(i=0; i<NUMT1; i++)
//	{
//		posicion=aleatorio[i];
//		Tdesordenados[i]=Tordenados[posicion];
//	}
	
	
	printf("         ---------------------------------------------\n         ---------------------------------------------\n         ---------------------------------------------\n");
	printf("         ********BIENVENIDO A ATRAPA UN MILLON********\n         ---------------------------------------------\n");
	printf("         ---------------------------------------------\n         ---------------------------------------------\n\n");
	
	escribeTexto("Hola!, soy Carlos y te doy la bienvenida a ATRAPA UN MILLON.\n\
Para empezar, me gustaria saber tu nombre y apellidos para conocernos mejor:\n\n");

	gets(nombre); //obtiene el nombre de la persona
	
while(feof(pf)==0)
	{
		fscanf(pf, " %[^\n]; %s\n", &nombrearchivo);
		if(strcmp(nombrearchivo,nombre)==1) //significa que los dos nombres son iguales
		{
			loged=1; //está logeado
			escribeTexto("\nMuy bien ");
			escribeTexto(nombre);
			escribeTexto(", como veo ya has jugado a este juego y por lo tanto no hace falta que te expliquemos las normas. \n\
asi pues, procederemos a la primera seleccion de temas:\n" );
			break;
		}
	}
	if(loged==0) //no está logeado
	{
		fclose(pf);
		fopen("Ficheros/Nombres/Nombres.txt", "a");
		fprintf(pf,"\n%s",nombre);
		escribeTexto("\nMuy bien ");
		escribeTexto(nombre);
		escribeTexto(", como veo eres nuevo en este juego. Te gustaria que te explicaramos las reglas del juego?\n\n"); //pregunta si quieres que explique las normas o no
	scanf("%c", &respuesta);
	while ((respuesta!='s')&&(respuesta!='n')&&(respuesta!='S')&&(respuesta!='N')) //si no pone ni si ni no
	{
		escribeTexto("\nNo te entiendo. Por favor, escribe 'si' o 'no':\n\n");
		scanf("%c", &respuesta);	
	}
	switch(respuesta) //si pone si
    {
    case 'S':
    case 's':
    	escribeTexto("\nEl juego consta de un total de 8 preguntas. La dificultad de cada pregunta ira aumentando \n\
progresivamente. Al principio, empezaras con un total de un millon de euros repartidos en 40 fajos de 25.000 \n\
en cada uno. Antes de cada pregunta podras elegir entre dos posibles temas. En cada pregunta podras repartir tu \n\
dinero a las diferentes posibles respuestas de cada una. En las cuatro primeras preguntas habra cuatro opciones, \n\
pero solo podras repartir tu dinero en tres de ellas. En las tres siguientes habra 3 posibles opciones, pero solo \n\
podras elegir dos y en la ultima pregunta, habra dos posibles respuestas y solo podras elegir una de ellas. \n\
En cada pregunta dispondras de 60 segundos para contestar. \n\n\
Bien, ahora que sabes las normas, empezaremos con la primera seleccion de temas. Recuerda que tienes un millon de euros para jugar...\n\n"); 
    	break;
    case 'N':
    case 'n':
    	escribeTexto("\nMuy bien, entonces empezemos con la primera seleccion de temas. Recuerda que ahora tienes un millon de euros para jugar...\n\n\n");
    	break;
    }	
	}

    
    //se generan  dos temas aleatorios
    /*switch(tema)
    {
    	case 'tema1':
    		//printea aleatoriamente una de las preguntas del tema 1 y sus posibles respuestas
    		//apuesta el dinero en las posibles respuestas
    		switch(respuesta)
    		{
    			case 'si':
    				//se vuelve a repetir el reparto
    				break;
    			case 'no':
    				//printea la respuesta y el dinero conservado
			}  		
    		break;
    	case 'tema2':
    		//igual que en tema1
    		break;
    //si te quedas sin dinero, se acaba el juego. Si no, pasas a la siguiente pregunta
	}*/
    temasrand(aleatorio);

}


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



