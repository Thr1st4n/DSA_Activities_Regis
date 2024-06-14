#ifndef STACK_ARRAY
#define STACK_ARRAY
#define MAX 5

#include <stdbool.h>


typedef struct{
	int data[MAX];
	int top;
	
}StackArrayList;

void initStack(StackArrayList *s);
bool isEmpty(StackArrayList s);
bool isFull(StackArrayList s);
StackArrayList createStack();
bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);
void display(StackArrayList s);
void visualize(StackArrayList s);

#endif



