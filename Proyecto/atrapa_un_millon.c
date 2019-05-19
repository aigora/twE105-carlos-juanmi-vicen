#include "mylib.h"

typedef struct {    ////4 respuestas en cada pregunta
char dentro[50];
} answer;

typedef struct {    //2 preguntas en cada tema
char contenido[300];
answer respuesta[4];
} question;

typedef struct {    //8 temas
char titulo[30];
question pregunta[2];
} Ntema; 		

int main() //programa principal
{
	srand (time(NULL)); 
	char nombre[50], respuestanombre, nombrearchivo[50], respuestatema[50], basura[5];
	int i, j, l, k, x=0, posicion, flag, correcto; //posicion se usa en el desorden de los temas
	int aleatorio8[NUMT1], aleatorio2[NUMP], aleatorio4[NUMR1], aleatorio6[NUMT2], aleatorio3[NUMR3], loged=0;
	float dinero=1000000, fajos=40, apuestaA, apuestaB, apuestaC, apuestaD, estado;
	Ntema Tordenados1[NUMT1];
	Ntema Tordenados2[NUMT2];
	Ntema Tordenados3[NUMT3];
	FILE *pf, *pb1, *pb2, *pb3, *res1, *res2, *res3, *tem1, *tem2, *tem3;
	//abre los ficheros de los nombres y de los bloques de las preguntas
	pf = fopen("Ficheros/Nombres/Nombres.txt", "r");
	pb1 = fopen("Ficheros/Preguntas/PreguntasBloque1.txt", "r");
	pb2 = fopen("Ficheros/Preguntas/PreguntasBloque2.txt", "r");
	pb3 = fopen("Ficheros/Preguntas/PreguntasBloque3.txt", "r");
	res1 = fopen("Ficheros/Preguntas/RespuestasBloque1.txt", "r");
	res2 = fopen("Ficheros/Preguntas/RespuestasBloque2.txt", "r");
	res3 = fopen("Ficheros/Preguntas/RespuestasBloque3.txt", "r");
	tem1 = fopen("Ficheros/Temas/Temas1.txt", "r");
	tem2 = fopen("Ficheros/Temas/Temas2.txt", "r");
	tem3 = fopen("Ficheros/Temas/Temas3.txt", "r");
	for (l=0; l<NUMT1; l++) 
	{
		fscanf(tem1,"%[^\n]\n", &Tordenados1[l].titulo);
		for (j=0; j<NUMP; j++)
		{
			fscanf(pb1,"%[^\n]\n", &Tordenados1[l].pregunta[j].contenido); 
			for (k=0; k<NUMR1; k++)
			{			
				fscanf(res1,"%[^\n]\n", &Tordenados1[l].pregunta[j].respuesta[k].dentro);	
			}
		}
	}
	vectorrand(8,aleatorio8);  //creamos un vector aleatorio de 8
	vectorrand(6,aleatorio6);  //creamos un vector aleatorio de 6
	vectorrand(2,aleatorio2);  //creamos un vector aleatorio de 2
	vectorrand(4,aleatorio4);  //creamos un vector aleatorio de 4
	vectorrand(3,aleatorio3);  //creamos un vector aleatorio de 3
	Ntema Tdesordenados1[NUMT1]; //creamos la estructura de temas desordenados 
	Ntema Tdesordenados2[NUMT2];
	Ntema Tdesordenados3[NUMT3];
	for(i=0; i<NUMT1; i++) //aleatoriza la estructura de temas que estaba ordenada
	{
		posicion=aleatorio8[i];						
		Tdesordenados1[i]=Tordenados1[posicion];
	}	
	printf("         ---------------------------------------------\n         ---------------------------------------------\n         ---------------------------------------------\n");
	printf("         ********BIENVENIDO A ATRAPA UN MILLON********\n         ---------------------------------------------\n");
	printf("         ---------------------------------------------\n         ---------------------------------------------\n\n");

	escribeTexto("Hola!, soy Carlos y te doy la bienvenida a ATRAPA UN MILLON.\n\
Antes de nada, me gustaria pedirte que durante el juego solo utilices mayusculas.\n\
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
Asi pues, procederemos a la primera seleccion de temas: (pulsa intro para continuar)\n" );
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
	while ((respuestanombre!='S')&&(respuestanombre!='N')) //si no pone ni si ni no
	{
		escribeTexto("\nNo te entiendo. Por favor, escribe 'si' o 'no':\n\n");
		scanf("%c", &respuestanombre);	
	}
	switch(respuestanombre) //si pone si
    {
    case 'S':
    	escribeTexto("\nEl juego consta de un total de 8 preguntas. La dificultad de cada pregunta ira aumentando \n\
progresivamente. Al principio, empezaras con un total de un millon de euros repartidos en 40 fajos de 25.000 \n\
en cada uno. Antes de cada pregunta podras elegir entre dos posibles temas. En cada pregunta podras repartir tu \n\
dinero a las diferentes posibles respuestas de cada una. En las cuatro primeras preguntas habra cuatro opciones, \n\
pero solo podras repartir tu dinero en tres de ellas. En las tres siguientes habra 3 posibles opciones, pero solo \n\
podras elegir dos y en la ultima pregunta, habra dos posibles respuestas y solo podras elegir una de ellas. \n\
En cada pregunta dispondras de 60 segundos para contestar. \n\n\
Bien, ahora que sabes las normas, empezaremos con la primera seleccion de temas. Recuerda que tienes un millon de euros para jugar... (pulsa intro para continuar)\n\n"); 
    	break;
    case 'N':
    	escribeTexto("\nMuy bien, entonces empezemos con la primera seleccion de temas. Recuerda que ahora tienes un millon de euros para jugar... (pulsa intro para continuar)\n\n\n");
    	break;
    }	
	}
	//empezamos con la seleccion de temas	

	for(i=0;i<7;i=i+2)
	{
	correcto=0;
	flag=0;
	getch(); //pulsa cualquier tecla para continuar
	fflush(stdin); //pa que no se buguee
	system("cls"); //limpia la consola
	x=x+1;
	printf("\n		BLOQUE 1 - Pregunta %i\n", x);
	printf("\n		%s		%s\n\n              		 ", Tdesordenados1[i].titulo, Tdesordenados1[i+1].titulo);	
	while(correcto==0)
	{
	gets(respuestatema);
	if(strcmp(respuestatema,Tdesordenados1[i].titulo)==0)
	{
		correcto=1;
		printf("\n%s\n", Tdesordenados1[i].pregunta[aleatorio2[0]].contenido);				
		printf("A) %s\n", Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[aleatorio4[0]].dentro);
		printf("B) %s\n", Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[aleatorio4[1]].dentro);
		printf("C) %s\n", Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[aleatorio4[2]].dentro);
		printf("D) %s\n", Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[aleatorio4[3]].dentro);
		printf("Tienes %.0f euros,es decir %.0f fajos.\nCuantos fajos quieres apostar a:\n ",dinero, fajos);
		while(flag==0)
		{
		apuesta1(&apuestaA,&apuestaB,&apuestaC,&apuestaD);
		flag=ComprobarDinero1(&apuestaA,&apuestaB,&apuestaC,&apuestaD,&dinero,&fajos);
		}
		if(strcmp(Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[aleatorio4[0]].dentro)==0)
		dinero=apuestaA*25000;
		if(strcmp(Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[aleatorio4[1]].dentro)==0)
		dinero=apuestaB*25000;
		if(strcmp(Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[aleatorio4[2]].dentro)==0)
		dinero=apuestaC*25000;
		if(strcmp(Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[aleatorio4[3]].dentro)==0)
		dinero=apuestaD*25000;
		fajos=dinero/25000;
		printf("\n\nLa respuesta correcta es... %s.\nTe queda un total de %.0f euros(%.0f fajos)\n", Tdesordenados1[i].pregunta[aleatorio2[0]].respuesta[0].dentro, dinero, fajos);
	if(dinero==0)
	{
		printf("Te has quedado sin dinero, esperemos que tengas mejor suerte la proxima vez. Has llegado a la pregunta %i",x);
		return 0;
	}
	printf("Pulsa intro para continuar a la siguiente pregunta.\n");
	}
	else if(strcmp(respuestatema,Tdesordenados1[i+1].titulo)==0)
	{
		correcto=1;
		printf("\n%s\n", Tdesordenados1[i+1].pregunta[aleatorio2[0]].contenido);				
		printf("A) %s\n", Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio4[0]].dentro);
		printf("B) %s\n", Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio4[1]].dentro);
		printf("C) %s\n", Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio4[2]].dentro);
		printf("D) %s\n", Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio4[3]].dentro);
		printf("Tienes %.0f euros,es decir %.0f fajos.\nCuantos fajos quieres apostar a:\n ",dinero, fajos);
		while(flag==0)
		{
		apuesta1(&apuestaA,&apuestaB,&apuestaC,&apuestaD);
		flag=ComprobarDinero1(&apuestaA,&apuestaB,&apuestaC,&apuestaD,&dinero,&fajos);
		}
		if(strcmp(Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio4[0]].dentro)==0)
		dinero=apuestaA*25000;
		if(strcmp(Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio4[1]].dentro)==0)
		dinero=apuestaB*25000;
		if(strcmp(Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio4[2]].dentro)==0)
		dinero=apuestaC*25000;
		if(strcmp(Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio4[3]].dentro)==0)
		dinero=apuestaD*25000;
		fajos=dinero/25000;
		printf("\n\nLa respuesta correcta es... %s.\nTe queda un total de %.0f euros(%.0f fajos)\n", Tdesordenados1[i+1].pregunta[aleatorio2[0]].respuesta[0].dentro, dinero, fajos);
	if(dinero==0)
	{
		printf("Te has quedado sin dinero, esperemos que tengas mejor suerte la proxima vez. Has llegado a la pregunta %i",x);
		return 0;
	}
	printf("Pulsa intro para continuar a la siguiente pregunta.\n");	
	}
	else
	{
		printf("\nNo te entiendo. Por favor, escoge uno de los temas propuestos.\n\n");
	}
	}
	}  
	//empieza el segundo bloque	
	for (l=0; l<NUMT2; l++) 
	{
		fscanf(tem2,"%[^\n]\n", &Tordenados2[l].titulo);
		for (j=0; j<NUMP; j++)
		{
			fscanf(pb2,"%[^\n]\n", &Tordenados2[l].pregunta[j].contenido); 
			for (k=0; k<NUMR2; k++)
			{			
				fscanf(res2,"%[^\n]\n", &Tordenados2[l].pregunta[j].respuesta[k].dentro);
			}
		}
	}
	for(i=0; i<NUMT2; i++) //aleatoriza la estructura de temas que estaba ordenada
	{
		posicion=aleatorio6[i];						
		Tdesordenados2[i]=Tordenados2[posicion];
	}
	x=0;
	for(i=0;i<6;i=i+2)
	{
	correcto=0;
	flag=0; 
	getch();	//pulsa cualquier tecla para continuar
	fflush(stdin); //pa que no se buguee
	system("cls"); //limpia la consola
	x=x+1;
	printf("\n		BLOQUE 2 - Pregunta %i\n", x);
	printf("\n		%s		%s\n\n              		 ", Tdesordenados2[i].titulo, Tdesordenados2[i+1].titulo);	
	fflush(stdin);
	while (correcto==0)
	{
	gets(respuestatema);
	if(strcmp(respuestatema,Tdesordenados2[i].titulo)==0)
	{
		correcto=1;
		printf("\n%s\n", Tdesordenados2[i].pregunta[aleatorio2[0]].contenido);				
		printf("A) %s\n", Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[0]].dentro);
		printf("B) %s\n", Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[1]].dentro);
		printf("C) %s\n", Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[2]].dentro);
		printf("Tienes %.0f euros,es decir %.0f fajos.\nCuantos fajos quieres apostar a:\n ",dinero, fajos);
		while(flag==0)
		{
		apuesta2(&apuestaA,&apuestaB,&apuestaC);
		flag=ComprobarDinero2(&apuestaA,&apuestaB,&apuestaC,&dinero,&fajos);
		}
		if(strcmp(Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[0]].dentro)==0)
		dinero=apuestaA*25000;
		if(strcmp(Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[1]].dentro)==0)
		dinero=apuestaB*25000;
		if(strcmp(Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[2]].dentro)==0)
		dinero=apuestaC*25000;
		fajos=dinero/25000;
		printf("\n\nLa respuesta correcta es... %s.\nTe queda un total de %.0f euros(%.0f fajos)\n", Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[0].dentro, dinero, fajos);
	if(dinero==0)
	{
		x=x+8;
		printf("Te has quedado sin dinero, esperemos que tengas mejor suerte la proxima vez Has llegado a la pregunta %i",x);
		return 0;
	}
	printf("Pulsa intro para continuar a la siguiente pregunta.\n");	
	}
	else if(strcmp(respuestatema,Tdesordenados2[i+1].titulo)==0)
	{
		correcto=1;
		printf("\n%s\n", Tdesordenados2[i+1].pregunta[aleatorio2[0]].contenido);				
		printf("A) %s\n", Tdesordenados2[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio3[0]].dentro);
		printf("B) %s\n", Tdesordenados2[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio3[1]].dentro);
		printf("C) %s\n", Tdesordenados2[i+1].pregunta[aleatorio2[0]].respuesta[aleatorio3[2]].dentro);

		printf("Tienes %.0f euros,es decir %.0f fajos.\nCuantos fajos quieres apostar a:\n ",dinero, fajos);
		while(flag==0)
		{
		apuesta2(&apuestaA,&apuestaB,&apuestaC);
		flag=ComprobarDinero2(&apuestaA,&apuestaB,&apuestaC,&dinero,&fajos);
		}
		if(strcmp(Tdesordenados2[i+1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[0]].dentro)==0)
		dinero=apuestaA*25000;
		if(strcmp(Tdesordenados2[i+1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[1]].dentro)==0)
		dinero=apuestaB*25000;
		if(strcmp(Tdesordenados2[i+1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[aleatorio3[2]].dentro)==0)
		dinero=apuestaC*25000;
		fajos=dinero/25000;
		printf("\n\nLa respuesta correcta es... %s.\nTe queda un total de %.0f euros(%.0f fajos)\n", Tdesordenados2[i].pregunta[aleatorio2[0]].respuesta[0].dentro, dinero, fajos);
	if(dinero==0)
	{
		x=x+8;
		printf("Te has quedado sin dinero, esperemos que tengas mejor suerte la proxima vez Has llegado a la pregunta %i",x);
		return 0;
	}
	printf("Pulsa intro para continuar a la siguiente pregunta.\n");	
	}
	else
	{
		printf("\nNo te entiendo. Por favor, escoge uno de los temas propuestos.\n\n");
	}
	}
	}  
	//ULTIMA PREGUNTA
	for (l=0; l<NUMT3; l++) 
	{
		fscanf(tem3,"%[^\n]\n", &Tordenados3[l].titulo);
		for (j=0; j<NUMP; j++)
		{
			fscanf(pb3,"%[^\n]\n", &Tordenados3[l].pregunta[j].contenido); 
			for (k=0; k<NUMR3; k++)
			{			
				fscanf(res3,"%[^\n]\n", &Tordenados3[l].pregunta[j].respuesta[k].dentro);
			}
		}
	}
	for(i=0; i<NUMT3; i++) //aleatoriza la estructura de temas que estaba ordenada
	{
		posicion=aleatorio2[i];						
		Tdesordenados3[i]=Tordenados3[posicion];
	}
	correcto=0;	
	flag=0;
	getch(); //pulsa cualquier tecla para continuar
	fflush(stdin); //pa que no se buguee
	system("cls"); //limpia la consola
	printf("\n		---------ULTIMA PREGUNTA---------\n");
	printf("\n		%s		%s\n\n              		 ", Tdesordenados3[0].titulo, Tdesordenados3[1].titulo);	
	while (correcto==0)
	{
	gets(respuestatema);
	if(strcmp(respuestatema,Tdesordenados3[0].titulo)==0)
	{
		correcto=1;
		printf("\n%s\n", Tdesordenados3[0].pregunta[aleatorio2[0]].contenido);				
		printf("A) %s\n", Tdesordenados3[0].pregunta[aleatorio2[0]].respuesta[aleatorio2[0]].dentro);
		printf("B) %s\n", Tdesordenados3[0].pregunta[aleatorio2[0]].respuesta[aleatorio2[1]].dentro);
		printf("Tienes %.0f euros,es decir %.0f fajos.\nCuantos fajos quieres apostar a:\n ",dinero, fajos);
		while(flag==0)
		{
		apuesta3(&apuestaA,&apuestaB);
		flag=ComprobarDinero3(&apuestaA,&apuestaB,&dinero,&fajos);
		}
		if(strcmp(Tdesordenados3[0].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados3[0].pregunta[aleatorio2[0]].respuesta[aleatorio2[0]].dentro)==0)
		dinero=apuestaA*25000;
		if(strcmp(Tdesordenados3[0].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados3[0].pregunta[aleatorio2[0]].respuesta[aleatorio2[1]].dentro)==0)
		dinero=apuestaB*25000;
		fajos=dinero/25000;
		escribeTexto("\n\nLa respuesta correcta es... ");
		printf("%s\n\n", Tdesordenados3[0].pregunta[aleatorio2[0]].respuesta[0].dentro);
	if(dinero==0)
	{
		escribeTexto("Que cerca has estado! Mas suerte la proxima vez");
		return 0;
	}
		estado=dinero*20.0/100.0;
		dinero=dinero-estado;
		printf("ENHORABUENA!!! Espero que disfrutes tus %.2f euros, ya que los %.2f restantes se los queda hacienda!", dinero, estado);
	return 0;

	}
	else if(strcmp(respuestatema,Tdesordenados3[1].titulo)==0)
	{
		correcto=1;
		printf("\n%s\n", Tdesordenados3[1].pregunta[aleatorio2[0]].contenido);				
		printf("A) %s\n", Tdesordenados3[1].pregunta[aleatorio2[0]].respuesta[aleatorio2[0]].dentro);
		printf("B) %s\n", Tdesordenados3[1].pregunta[aleatorio2[0]].respuesta[aleatorio2[1]].dentro);
		printf("Tienes %.0f euros,es decir %.0f fajos.\nCuantos fajos quieres apostar a:\n ",dinero, fajos);
		while(flag==0)
		{
		apuesta3(&apuestaA,&apuestaB);
		flag=ComprobarDinero3(&apuestaA,&apuestaB,&dinero,&fajos);
		}
		if(strcmp(Tdesordenados3[1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados3[1].pregunta[aleatorio2[0]].respuesta[aleatorio2[0]].dentro)==0)
		dinero=apuestaA*25000;
		if(strcmp(Tdesordenados3[1].pregunta[aleatorio2[0]].respuesta[0].dentro, Tdesordenados3[1].pregunta[aleatorio2[0]].respuesta[aleatorio2[1]].dentro)==0)
		dinero=apuestaB*25000;
		fajos=dinero/25000;
		escribeTexto("\n\nLa respuesta correcta es... ");
		printf("%s\n\n", Tdesordenados3[1].pregunta[aleatorio2[0]].respuesta[0].dentro);

	if(dinero==0)
	{
		printf("Que cerca has estado! Mas suerte la proxima vez");
		return 0;
	}

	estado=dinero*20.0/100.0;
	dinero=dinero-estado;
	printf("ENHORABUENA!!! Espero que disfrutes tus %.2f euros, ya que los %.2f restantes se los queda hacienda!", dinero, estado);
	return 0;
}

	}

}
    



