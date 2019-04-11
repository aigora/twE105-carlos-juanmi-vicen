#include <stdio.h>/
#include <math.h>
#include <windows.h>
#include <stdlib.h>


void escribeTexto(char vector[]); //funcion para que las letras vayan con retraso

int main() //programa principal
{
	//srand (time(NULL));
	char nombre[50], respuesta;
	char instrucciones[]= "\nEl juego consta de un total de 8 preguntas. La dificultad de cada pregunta ira aumentando \n\
progresivamente. Al principio, empezaras con un total de un millon de euros repartidos en 40 fajos de 25.000 \n\
en cada uno. Antes de cada pregunta podras elegir entre dos posibles temas. En cada pregunta podras repartir tu \n\
dinero a las diferentes posibles respuestas de cada una. En las cuatro primeras preguntas habra cuatro opciones, \n\
pero solo podras repartir tu dinero en tres de ellas. En las tres siguientes habra 3 posibles opciones, pero solo \n\
podras elegir dos y en la ultima pregunta, habra dos posibles respuestas y solo podras elegir una de ellas. \n\
En cada pregunta dispondras de 60 segundos para contestar. \n\n\
Bien, ahora que sabes las normas, empezaremos con la primera seleccion de temas. Recuerda que tienes un millon de euros para jugar...\n\n";
	char noentiendo[]="\nNo te entiendo. Por favor, escribe 'si' o 'no':\n\n";
	int i=0;
	printf("         ---------------------------------------------\n         ---------------------------------------------\n         ---------------------------------------------\n");
	printf("         ********BIENVENIDO A ATRAPA UN MILLON********\n         ---------------------------------------------\n");
	printf("         ---------------------------------------------\n         ---------------------------------------------\n\n");
	char texto1[]= "Hola!, soy Carlos y te doy la bienvenida a ATRAPA UN MILLON.\n\
Para empezar, me gustaria saber tu nombre para conocernos mejor:\n\n";
	escribeTexto(texto1);
	gets(nombre); //obtiene el nombre de la persona
	char texto2[]= "\nMuy bien ";
	escribeTexto(texto2);
	escribeTexto(nombre);
	printf(", eres nuevo en este juego y quieres que te expliquemos las normas rapidamente?\n\n"); //pregunta si quieres que explique las normas o no
	scanf("%c", &respuesta);
	while ((respuesta!='s')&&(respuesta!='n')&&(respuesta!='S')&&(respuesta!='N')) //si no pone ni si ni no
	{
		escribeTexto(noentiendo);
		scanf("%c", &respuesta);	
	}
	switch(respuesta) //si pone si
    {
    case 'S':
    case 's':
    	escribeTexto(instrucciones); 
    	break;
    case 'N':
    case 'n':
    	printf("\nMuy bien, entonces empezemos con la primera seleccion de temas. Recuerda que ahora tienes un millon de euros para jugar...\n\n\n");
    	break;
    }
    //se generan  dos temas aleatorios
    printf("TEMA1 / TEMA2")
    switch(tema)
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
	}
    

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
	
vectorRandom(int temas[])
}




