#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	NodePtr head = NULL; 
	
	Product P[6] = {
					{"Banana",15.0,5,{20,01,2023}},
					{"Apple",20.0,5,{8,01,2023}}, 
					{"Mango",30.0,5,{18,01,2023}}, 
					{"Apricot",20.0,5,{8,01,2023}}, 
					{"Lemon",80.0,5,{25,01,2023}}, 
					{"Orange",50.5,5,{15,01,2023}} 
					};
					
					
	add(&head,P[0]);
	add(&head,P[1]);
	add(&head,P[2]);
	add(&head,P[3]);
	add(&head,P[4]);
	add(&head,P[5]);


	printf("In-order traversal:\n");
	delete(&head,"Apricot");
	inorderTraversal(head);
	return 0;
}
