#ifndef CQUEUE
#define CQUEUE
#include<stdio.h>
#define MAX 6
#include<stdbool.h>

typedef struct{
	int data[MAX];
	int front;
	int rear;
}CircularQ;

void initQ(CircularQ *L);
bool isEmpty(CircularQ L);
bool isFull(CircularQ L);
void enqueue(CircularQ *L, int data);   
void dequeue(CircularQ *L);
void display(CircularQ L);




#endif
