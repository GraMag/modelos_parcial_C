#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void initArray(sSubscriber subs[], int len)
{
	for(int i = 0; i < len; i++)
	{
		subs[i].isEmpty = 1;
	}
}

int menue()
{
	int option;

	printf("Seleccione una opcion:\n\n"
			"1.- Alta abonado\n"
			"2.- Modificar abonado\n"
			"3.- Baja abonado\n"
			"4.- Nueva llamada\n"
			"5.- Fin llamada\n"
			"6.- Informar\n");
	scanf("%d", &option);

	return option;
}

sSubscriber askSubscriber()
{
	sSubscriber subs;
	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(subs.name);
	printf("Ingrese apellido: ");
	fflush(stdin);
	gets(subs.lastName);
	printf("Ingrese telefono: ");
	scanf("%d",&subs.number);

	return subs;
}

int addSubscriber(sSubscriber subs[], int len, int id)
{
	sSubscriber userInfo;

	for (int i = 0; i < len; i++)
	{
		if(subs[i].isEmpty == 1)
		{
			userInfo = askSubscriber();
			subs[i].id = id;
			strcpy(subs[i].name, userInfo.name);
			strcpy(subs[i].lastName, userInfo.lastName);
			subs[i].number = userInfo.number;
			subs[i].isEmpty = 0;
			return 0;
		}
	}
	return-1;
}

int findsubsByID(sSubscriber subs[], int len)
{
	int id;
	printf("Ingrese id: ");
	scanf("%d", &id);

	for (int i = 0; i < len; i++)
	{
		if (subs[i].id == id)
		{
			return i;
		}
	}
	return -1;
}

int modifySubscriber(sSubscriber subs[], int len)
{
	int index = findsubsByID(subs, len);

	if (index == -1)
	{
		return -1;
	}
	else
	{
		printf("Ingrese nuevo nombre: \n");
		fflush(stdin);
		gets(subs[index].name);
		printf("Ingrese nuevo apellido: \n");
		fflush(stdin);
		gets(subs[index].lastName);
		return 0;
	}
}

int removeSubscriber(sSubscriber subs[], int len)
{
	int index = findsubsByID(subs, len);

	if (index == -1)
	{
		return -1;
	}
	else
	{
		subs[index].isEmpty = 1;
		return 0;
	}
}

void printSubscriber(sSubscriber subs) //borrar esta funcion
{
	printf("| %04d | %20s | %20s  %8d   |\n", subs.id, subs.name, subs.lastName, subs.number);
}

int printSubscribers(sSubscriber subs[], int len) //borrar esta funcion
{
	printf("|  ID  |        NOMBRE        |       APELLIDO       |   numero\n");
	for(int i = 0; i < len; i++)
	{
		if(subs[i].isEmpty == 0)
		{
			printSubscriber(subs[i]);
		}
	}
	return 0;
}
