/*
 ============================================================================
 Name        : modeloParcial2016.c
 Author      : Maga
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define LEN 3
#define FALLA3G 1
#define FALLALTE 2
#define FALLAEQUIPO 3
#define ENCURSO 1
#define SOLUCIONADO 2
#define NOSOLUCIONADO 3

void newCall();
void endCall();
void informs();


int main(void) {

	sSubscriber subscriber[LEN];
	int id = 0;
	char repeat = 's';


	initArray(subscriber, LEN);

	setbuf(stdout,NULL);

	do
	{
		fflush(stdin);

		switch (menue())
		{
			case 1:
			if(!(addSubscriber(subscriber, LEN, id)))
			{
				id++;
			}
			break;
			case 2:
				modifySubscriber(subscriber, LEN);
				break;
			case 3:
				removeSubscriber(subscriber, LEN);
				break;
			case 5:
				printSubscribers(subscriber, LEN);
				break;
		}

		system("pause");

	} while (repeat == 's');
	/*Alta
	 * modificar
	 * baja
	 * nueva llamada
	 * fin llamada
	 * informar
	 *
	 */
	return EXIT_SUCCESS;
}


void newCall(sSubscriber subs[], int len);
void endCall(sSubscriber subs[], int len);
void informs(sSubscriber subs[], int len);

