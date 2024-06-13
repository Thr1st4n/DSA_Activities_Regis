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
	int i;
	StackArrayList temp;
	initStack(&temp);
		
	for(i = s.top; i!=-1;){
		stack_push(&temp,s.data[s.top]);
		printf("%d ",temp.data[temp.top]);
		stack_pop(&s);
	}
	
	for(i = temp.top; i!=-1;){
		stack_push(&s,temp.data[temp.top]);
		stack_pop(&temp);
	}


	
}

//void visualize(StackArrayList s){
//	
//	
//	
//}

