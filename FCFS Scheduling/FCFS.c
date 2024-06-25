#include "FCFS.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


void initQueue(Queue *L){
	L->front = -1;
	L->rear = -1;
}

bool isEmpty(Queue L){
	return L.front == -1;  
}

void enqueue(Queue* L, Process P, int size){
	
	if(L->front == -1){
		L->front = L->rear = 0;
	}else{
		L->rear = (L->rear+1)%size;
	}
	L->P[L->rear] = P;
	
}


void dequeue(Queue* L,int size){
	if (!isEmpty(*L)) {
        if (L->front == L->rear) {
            L->front = L->rear = -1;
        } else {
            L->front = (L->front + 1) % size;
        }
    } else {
        printf("Queue is Empty\n");
    }
}


void sortbyArrival(Process *P, int size){
	int i,j;
	
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(P[j].AT > P[j+1].AT){
				Process temp = P[j];
				P[j] = P[j+1];
				P[j+1] = temp;
			}
		}
	}
	
	
}



void calculateTime(Process *P,int size){
	
	int i;
	int currentET = P[0].AT;
	for(i=0;i<size;i++){
		P[i].ET += currentET;
		P[i].WT = P[i].ET - P[i].AT;
		P[i].TT = P[i].BT + P[i].ET;
		currentET += P[i].BT;
	}

		
}

void inputUser(Queue* P, int size) {
    int i;
    Process *temp = malloc(size * sizeof(Process));
    for (i = 0; i < size; i++) {
        printf("Enter Arrival time for process %d: ", i + 1);
        scanf("%d", &temp[i].AT);
        printf("Enter Burst time for process %d: ", i + 1);
        scanf("%d", &temp[i].BT);
        temp[i].ET = temp[i].WT = temp[i].TT = 0; 
    }
    
    sortbyArrival(temp, size);
    calculateTime(temp, size);
    for (i = 0; i < size; i++) {
        enqueue(P, temp[i], size);
    
    }

}

void displayQueue(Queue P, int size) {
	Queue temp;
	initQueue(&temp);
    temp.P = malloc(size * sizeof(Process));
	int totalWT = 0, totalTT = 0;
    printf("\nPROCESS TABLE\n");
    printf("PROCESS  |  BT  |  AT  |  ET  |  WT  |  TT \n");
    while (!isEmpty(P)) {
        printf("   %3d   | %3d  | %3d  | %3d  | %3d  | %3d\n",
               P.front + 1,
               P.P[P.front].BT, 
               P.P[P.front].AT, 
               P.P[P.front].ET, 
               P.P[P.front].WT, 
               P.P[P.front].TT);
           	totalWT+=P.P[P.front].WT;
           	totalTT+=P.P[P.front].TT;
        enqueue(&temp,P.P[P.front], size);
        dequeue(&P, size);
    }
    
    printf("  TOTAL------------------------- %d  |  %d",totalWT,totalTT);
    printf("\nAVERAGE----------------------- %.2f  |  %.2f",(float)totalWT/size,(float)totalTT/size);
    
    while (!isEmpty(temp)) {
        enqueue(&P,temp.P[temp.front], size);
        dequeue(&temp, size);
    }
    
    free(temp.P);
    
    
    
}







