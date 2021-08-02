#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int main (int argc, char *argv[]){
	
	//Variables
	char letra;
	char palabra[30];
	char palabraOculta[30]= {};
	int i=0, intentos=3, flag=0, aciertos=0, palabraRepetida=0;
	
	printf("\tADIVINA LA PALABRA\n\n");
	printf("Escribe la palabra con la que quieres jugar: ");
	scanf("%s", &palabra);
	system("cls");
	//Asigna "-" a cada letra de la palabra escrita anteriormente
	for(i=0;i<strlen(palabra);i++){
		palabraOculta[i]= "-";
	}
	do{
		if (palabraRepetida==1){
			printf("Ya se ha introducido esa letra\n\n");
			palabraRepetida=0;
		}
		//Imprime en pantalla
		printf("Palabra oculta: %s\n\n", palabraOculta);
		printf("Letras Acertadas: %d\n", aciertos);
		printf("Fallos restantes: %d\n\n", intentos);
		printf("Introduzca una letra: ");
		scanf ("%s", &letra);
		
		int palabraCorrecta=0, opcion=0;
		for(i=0; i<strlen(palabra);i++){
			if(palabra[i]==letra && palabraOculta[i] != letra){
				palabraOculta[i]=letra;
				aciertos++;
				palabraCorrecta = 1;
			}else if (palabraOculta[i]==letra){
				palabraRepetida=1;
				palabraCorrecta=1;
			}
		}
		if (!palabraCorrecta){
			intentos-=1;
		}
		if (!strcmp(palabra, palabraOculta)){
			
			printf("\nFELICITACIONES, GANASTE! \n LA PALABRA ES: %s\n\n", palabra);
			flag=1;
		}else if (intentos==0){
			
			printf ("\nOh no! INTENTELO DE NUEVO ...\n\nLA PALABRA OCULTA ERA...: %s\n\n\n", palabra);
			flag=1;
		}
	}while(flag!=1);
	
	system("pause");
}

