#include <stdio.h>
#include <stdlib.h>
#include "StackLL.h" //StackLL.h    /   StackArray.h


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
#ifdef STACK_ARRAY	
	StackArrayList List;
	initStack(&List);
	stack_push(&List,5);
	stack_push(&List,6);
	stack_push(&List,7);
	stack_push(&List,8);
	
	stack_pop(&List);
	
	
	int top = stack_peek(List);
	printf("TOP = %d at index %d\n",List.data[top],top);
	display(List);
	
	printf("\n\nStack Visualization:\n");
	visualize(List);
#endif	
	
#ifdef STACK_LL		
	StackLLPtr Top;
	initStack(&Top);
	bool checker = isEmptyLL(Top);
	checker==true?printf("List is Empty\n\n"):0;
	stack_pushLL(&Top,5);
	stack_pushLL(&Top,6);
	stack_pushLL(&Top,7);
	stack_pushLL(&Top,8);
	
	stack_popLL(&Top);
	
	int top = stack_peek(Top);
	printf("TOP = %d\n\n",Top->data);
	displayLL(Top);
#endif
	
	
	
	
	
	
	
	
	
	return 0;
}
