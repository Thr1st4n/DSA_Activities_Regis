#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Queue List;
	initQueue(&List);
	int numP;

	printf("Input number of processes: ");
	scanf("%d",&numP);
	
	List.P = malloc(numP*sizeof(Process));
	inputUser(&List,numP);
	

	displayQueue(List,numP);
	
	free(List.P);
	
	
	return 0;
}
