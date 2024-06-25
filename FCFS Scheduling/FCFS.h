#ifndef FCSC_QUEUE
#define FCFS_QUEUE



typedef struct{
	int AT,BT,ET,WT,TT;
}Process;

typedef struct{
	Process* P;
	int front;
	int rear;
}Queue;

void initQueue(Queue *L);
void enqueue(Queue* L, Process P, int size);
void dequeue(Queue* L,int size);
void displayQueue(Queue P,int size);






#endif
