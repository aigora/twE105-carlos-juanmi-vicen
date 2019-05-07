#include "mylib.h"

typedef struct {    //2 preguntas en cada tema
char contenido[100];
char respuesta[16][4];
} question;

typedef struct {    //8 temas
char titulo[15];
question pregunta[2];
} Ntema; 

int main() //programa principal
{
	srand (time(NULL)); 
	char nombre[50], respuestanombre, nombrearchivo[50], respuestatema[50];
	int i, j, l, k, posicion, flag; //posicion se usa en el desorden de los temas
	int aleatorio8[NUMT1], aleatorio2[NUMP], loged=0;
	Ntema Tordenados[NUMT1];
	FILE *pf, *pb1, *pb2, *pb3, *res1;
	strcpy(Tordenados[0].titulo,"ANIMALES");				
	strcpy(Tordenados[1].titulo,"HISTORIA");
	strcpy(Tordenados[2].titulo,"DEPORTE");
	strcpy(Tordenados[3].titulo,"CIENCIA");
	strcpy(Tordenados[4].titulo,"INVENTOS");
	strcpy(Tordenados[5].titulo,"LITERATURA");
	strcpy(Tordenados[6].titulo,"ARTE");
	strcpy(Tordenados[7].titulo,"GEOGRAFIA");
	//abre los ficheros de los nombres y de los bloques de las preguntas
	pf = fopen("Ficheros/Nombres/Nombres.txt", "r");
	pb1 = fopen("Ficheros/Preguntas/PreguntasBloque1.txt", "r");
	pb2 = fopen("Ficheros/Preguntas/PreguntasBloque2.txt", "r");
	pb3 = fopen("Ficheros/Preguntas/PreguntasBloque3.txt", "r");
	res1 = fopen("Ficheros/Preguntas/RespuestasBloque1.txt", "r");
	for (l=0; l<8; l++) 
	{
		for (j=0; j<2; j++)
		{
			fscanf(pb1,"%[^\n]\n", &Tordenados[l].pregunta[j].contenido); 
			for (k=0; k<4; k++)
			{			
				fscanf(res1, "%[^-]", &Tordenados[l].pregunta[j].respuesta[j][k]);	
			}
		}
	}
	vectorrand8(aleatorio8);  //creamos un vector aleatorio de 8
	vectorrand2(aleatorio2);  //creamos un vector aleatorio de 2
	Ntema Tdesordenados[NUMT1]; //creamos la estructura de temas desordenados 
	for(i=0; i<NUMT1; i++) //aleatoriza la estructura de temas que estaba ordenada
	{
		posicion=aleatorio8[i];
		Tdesordenados[i]=Tordenados[posicion];
	}
	
	

	printf("         ---------------------------------------------\n         ---------------------------------------------\n         ---------------------------------------------\n");
	printf("         ********BIENVENIDO A ATRAPA UN MILLON********\n         ---------------------------------------------\n");
	printf("         ---------------------------------------------\n         ---------------------------------------------\n\n");
	
	escribeTexto("Hola!, soy Carlos y te doy la bienvenida a ATRAPA UN MILLON.\n\
Para empezar, me gustaria saber tu nombre y apellidos para conocernos mejor:\n\n");

	gets(nombre); //obtiene el nombre de la persona
    while(!feof(pf))
    {
        fscanf(pf, "%[^\n]\n", &nombrearchivo); //escanea un nombre hasta el primer salto de linea
        if(strcmp(nombrearchivo,nombre)==0) //significa que los dos nombres son iguales
        {
            loged=1; //está logeado
            escribeTexto("\nMuy bien ");
            escribeTexto(nombre);
            escribeTexto(", como veo ya has jugado a este juego y por lo tanto no hace falta que te expliquemos las normas. \n\
Asi pues, procederemos a la primera seleccion de temas:\n" );
            break;
        }
    }
    if(loged==0) //no está logeado
    {
        fclose(pf);
        fopen("Ficheros/Nombres/Nombres.txt", "a");
        fprintf(pf,"\n\n%s",nombre);
		escribeTexto("\nMuy bien ");
		escribeTexto(nombre);
		escribeTexto(", como veo eres nuevo en este juego. Te gustaria que te explicaramos las reglas del juego?\n\n"); //pregunta si quieres que explique las normas o no
	scanf("%c", &respuestanombre);
	while ((respuestanombre!='s')&&(respuestanombre!='n')&&(respuestanombre!='S')&&(respuestanombre!='N')) //si no pone ni si ni no
	{
		escribeTexto("\nNo te entiendo. Por favor, escribe 'si' o 'no':\n\n");
		scanf("%c", &respuestanombre);	
	}
	switch(respuestanombre) //si pone si
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
    	escribeTexto("\n Muy bien, entonces empezemos con la primera seleccion de temas. Recuerda que ahora tienes un millon de euros para jugar...\n\n\n");
    	break;
    }	
	}
	//empezamos con la seleccion de temas
	printf("\n\n		%s		%s\n\n", Tdesordenados[0].titulo, Tdesordenados[1].titulo);	
	flag=0;
	gets(respuestatema);
	while(flag==0)
	{
	if(strcmp(respuestatema,Tdesordenados[0].titulo)==0)
	{
		printf("\n%s", Tdesordenados[0].pregunta[aleatorio2[0]].contenido);
		flag=1;
	}
	else if(strcmp(respuestatema,Tdesordenados[1].titulo)==0)
	{
		printf("\n%s", Tdesordenados[1].pregunta[aleatorio2[0]].contenido);
		flag=1;
	}
	else
	{
		printf("\nNo te entiendo. Escoge uno de los dos temas propuestos.\n");
		gets(respuestatema);
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
    

}

