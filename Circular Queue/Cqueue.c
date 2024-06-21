#include<stdio.h>
#include "Cqueue.h"



void initQ(CircularQ *L){
	L->front = L->rear = -1;
}

bool isEmpty(CircularQ L){
	return L.front == -1;
	
}

bool isFull(CircularQ L){
	return (L.rear+2)%MAX == L.front;
	
}

void enqueue(CircularQ *L, int data){

 if (isFull(*L)) {
// 		printf("%d - %d\n\n", (*L).rear, (*L).front);
        printf("Queue is already full!\n\n");
    } else {
        if (isEmpty(*L)) {
            L->front = L->rear = 0;
        } else {	
            L->rear = (L->rear + 1) % MAX; 
        }
        L->data[L->rear] = data;
    }
}


void dequeue(CircularQ *L) {
    if (isEmpty(*L)) {
        printf("Queue is empty!\n");
    } else {
    	(*L).front = ((*L).front == (*L).rear) ? ((*L).rear = -1, -1) : ((*L).front + 1) % MAX;
//    	if((*L).front == (*L).rear){
//    		(*L).front = (*L).rear = -1;
//		}else{
//			(*L).front = ((*L).front+1)%MAX;
//		}
    		
//    	printf("->%d ",(*L).front);
    }
}

//void display(CircularQ L){
//	int i=0;
//	CircularQ temp;
//	initQ(&temp);
//	if(isEmpty(L)){
//		printf("Queue is empty!\n");
//	}else{
//		printf("Front->");
//		while(!isEmpty(L)){
//			enqueue(&temp,L.data[L.front]);
//			L.front == L.rear?printf("Rear->",L.rear):printf("");
//			printf("\t\t[%d] | %d\n",L.front,L.data[L.front]);
//			dequeue(&L);
//		}
//		while(!isFull){
//			enqueue(&L,temp.data[temp.front]);
//			dequeue(&temp);
//		}
//	}
//	
//	
//}


void display(CircularQ L){
	int i;
	if(isEmpty(L)){
		printf("Queue is empty!\n");
	}else{
		printf("Front->");
		
		for(i=L.front; i!=(L.rear+1)%MAX;i = (i+1)%MAX){
			i == L.rear?printf("Rear->",L.rear):printf("");
			printf("\t\t[%d] | %d\n",i,L.data[i]);
		
	}
	}
	
	
}










