/*
 * lib.h
 *
 *  Created on: 11 may. 2020
 *      Author: reyna
 */

#ifndef LIB_H_
#define LIB_H_

typedef struct

{
	int id;
	char name[20];
	char lastName[20];
	int number;
	int isEmpty;

}sSubscriber;

#endif /* LIB_H_ */

void printEmployee(sSubscriber subs);
int printEmployees(sSubscriber subs[], int len);
void initArray(sSubscriber subs[], int len);
int menue();
sSubscriber askSubscriber();
int addSubscriber(sSubscriber subs[], int len, int id);
int findsubsByID(sSubscriber subs[], int len);
int modifySubscriber(sSubscriber subs[], int len);
int removeSubscriber(sSubscriber subs[], int len);

