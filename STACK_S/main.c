#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	StackArrayList List;
	initStack(&List);
	stack_push(&List,5);
	stack_push(&List,6);
	stack_push(&List,7);
	stack_push(&List,8);
	
	
	stack_pop(&List);
	stack_pop(&List);
	
	
	
	
	
	int top = stack_peek(List);
	printf("TOP = %d",top);
	//display(List);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
