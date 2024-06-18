#include <stdio.h>
#include <stdlib.h>
#include "Cqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	CircularQ L;
	initQ(&L);
	
	enqueue(&L,1);
	enqueue(&L,2);
	enqueue(&L,3);
	enqueue(&L,4);
	enqueue(&L,5);
	
	dequeue(&L);
	
	enqueue(&L,6);
	
	dequeue(&L);
	dequeue(&L);
	
	enqueue(&L,7);
	enqueue(&L,8);
	enqueue(&L,9);
	
	display(L);

	
	
	return 0;
}
