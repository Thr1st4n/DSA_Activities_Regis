#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include "StackArray.h"


void initStack(StackArrayList *s){
	s->top = -1;
}

bool isEmpty(StackArrayList s){
	return s.top==-1?true:false;	
}

bool isFull(StackArrayList s){
	return s.top==MAX?true:false;
	
}

StackArrayList createStack(){
	StackArrayList temp;
	temp.top = -1;
	return temp;
	
}

bool stack_push(StackArrayList *s, int elem){
	if(!isFull(*s)){
		s->data[s->top+1] = elem;	
		s->top++;
		return true;
	}else{
		return false;
		printf("LIST IS ALREADY FULL, CANNOT BE PUSHED!\n");
	}		
	
}

bool stack_pop(StackArrayList *s){
	if(!isEmpty(*s)){
		s->data[s->top] = '\0';
		s->top--;
		return true;
	}else{
		printf("LIST IS EMPTY, CANNOT BE POPPED!\n");
		return false;
	}
		
}
int stack_peek(StackArrayList s){
	return s.top;
}

void display(StackArrayList s){
	int i=0;
	StackArrayList temp;
	initStack(&temp);
		
	



	printf("Stack Elements: ");
	for(s.top; s.top!=-1;){
		stack_push(&temp,s.data[s.top]);
		printf("[%d]%d ",s.top,temp.data[temp.top]);
		stack_pop(&s);
	}
	
	for(temp.top; temp.top!=-1;){
		stack_push(&s,temp.data[temp.top]);
		stack_pop(&temp);
	}

	
}

void visualize(StackArrayList s){
	int i;
	printf("Top->");
	for(i = s.top; i!=-1;i--){
		printf("	[%d]%d\n",i,s.data[i]);
	}
	
	
}

