#define NUMT1 8     //numero temas de la primera parte
#define NUMT2 6 	//numero temas de la segunda parte
#define NUMT3 2 	//numero temas de la tercera parte
#define NUMP 2 		//numero preguntas en cada tema
#define NUMR1 4     //numero respuestas de la primera parte
#define NUMR2 3 	//numero respuestas de la segunda parte
#define NUMR3 2 	//numero respuestas de la tercera parte
#define NUMP 2 //numero preguntas en cada tema
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void escribeTexto(char vector[]); //funcion para que las letras vayan con retraso
void vectorrand8(int aleatorio[NUMT1]); //generador de vector aleatorio de 8
void abrirficherospreguntas(void); //abre todos los ficheros de las preguntas
void vectorrand2(int aleatorio[NUMP]); //generador de vector aleatorio de 2
