#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"


void initQueue(Queue *L){
	L->front = L->rear = NULL;
}

bool isEmpty(Queue L){
	return L.front == NULL?true:false;
}


void Enqueue(Queue *L, int data){
	NodePtr temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	printf("%d is Enqueued\n",temp->data);
	if(L->rear == NULL){
		L->front = temp;
		L->rear = temp;
	}else{
		L->rear->next = temp;
		L->rear = temp;
	}
	
 	
	
}

void Dequeue(Queue *L){
	NodePtr temp;
	temp = L->front;
	L->front = L->front->next;
	printf("%d is Dequeued\n",temp->data);
	free(temp);
	
}

int Front(Queue L){
	if(isEmpty(L)){
		printf("Queue is empty!\n");
		return -1;
	}else{
		return L.front->data;
	}

	
}

int Rear(Queue L){
	if(isEmpty(L)){
		printf("Queue is empty!\n");
		return -1;
	}else{
		return L.rear->data;
	}
	
}
void display(Queue L){
	
	Queue trav;
	printf("\nQueue = ");
	for(trav.front = L.front; trav.front!=NULL; trav.front = trav.front->next){
		printf("%d ",trav.front->data);
		trav.front->next!=NULL?printf("-> "):printf(""); 
	
	}
	
	
}






