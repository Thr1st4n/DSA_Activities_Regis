#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue List;	
	initQueue(&List);
	bool checker;
	checker = isEmpty(List);
	
	checker == true?printf("List is empty!\n\n"):0;
	
	Enqueue(&List,1);
	Enqueue(&List,2);
	Enqueue(&List,3);
	Enqueue(&List,4);
	
	Dequeue(&List); 
	
	display(List);
		

	return 0;
}
