#ifndef STACK_LL
#define STACK_LL
#include <stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}StackLL,*StackLLPtr;



void initStackLL(StackLLPtr *T);
bool isEmptyLL(StackLLPtr T);
bool stack_pushLL(StackLLPtr *T, int data);
bool stack_popLL(StackLLPtr *T);
int stack_peekLL(StackLLPtr T);
void displayLL(StackLLPtr T);





#endif
