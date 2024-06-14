#ifndef QUEUE
#define QUEUE
#include<stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void initQueue(Queue *L);
void Enqueue(Queue *L, int data);
void Dequeue(Queue *L);
int Front(Queue L);
int Rear(Queue L);
bool isEmpty(Queue L);









#endif
