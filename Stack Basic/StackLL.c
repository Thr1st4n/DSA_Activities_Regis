#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StackLL.h"


void initStackLL(StackLLPtr *T){
	*T = NULL;
}
bool isEmptyLL(StackLLPtr T){
	return T == NULL?true:false;
}
bool stack_pushLL(StackLLPtr *T, int data){
	StackLLPtr temp = malloc(sizeof(StackLL));
	temp->data = data;
	temp->next = *T;
	*T = temp;
}
bool stack_popLL(StackLLPtr *T){
	StackLLPtr temp; 
	temp = *T;
	*T = (*T)->next;
	free(temp);
}
int stack_peekLL(StackLLPtr T){
	return T->data;
}

void displayLL(StackLLPtr T){
	StackLLPtr trav;
	printf("Stack List:\n");
	for(trav = T; T!=NULL; trav = trav->next){
		printf("%d",trav->data);
		trav->next!=NULL?printf(" -> "):printf(" ");
	}
	
}


