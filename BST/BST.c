#include "BST.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void add(NodePtr *head, Product newItem){
	
	NodePtr newNode = malloc(sizeof(NodeType));
 	newNode->item = newItem;
    newNode->left = NULL;
    newNode->right = NULL;
    
	NodePtr *trav;
	for(trav = head; *trav !=NULL; trav = strcmp((*trav)->item.prodName, newItem.prodName)>0? &(*trav)->left: &(*trav)->right){}
	*trav = newNode;
		
}


void delete(NodePtr* head,char item[]){
	
	NodePtr *trav;
	for(trav = head; *trav!=NULL && strcmp((*trav)->item.prodName,item)!=0; trav = strcmp((*trav)->item.prodName, item)>0? &(*trav)->left: &(*trav)->right){}
	
	if((*trav)==NULL){
		printf("\n----- Item %s not found in the list! -----\n\n",item);
	}else{
		
		NodePtr toRemove = *trav;
		if(toRemove->left == NULL && toRemove->right == NULL){
		*trav = NULL;
		}else{
			*trav = (toRemove->left == NULL)? toRemove->right: toRemove->left;
			if(toRemove->left!=NULL && toRemove->right!=NULL){
				NodePtr *successor = &toRemove->right;
				
        		while ((*successor)->left != NULL) {
            	successor = &(*successor)->left;
       	 		}
       	 		
        		toRemove->item = (*successor)->item;
        		NodePtr successorNode = *successor;
        		*successor = (*successor)->right;
        		free(successorNode);	
			}		
		}
		 printf("\n--- Item %s has been removed--- \n\n",item);
		 free(toRemove);
		
		
		
	}
	

	
	
	
}


void inorderTraversal(NodePtr node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("Product: %s\n", node->item.prodName);
        printf("  Price: %.2f\n", node->item.prodPrice);
        printf("  Quantity: %d\n", node->item.prodQty);
        printf("  Expiry Date: %2d/%2d/%4d\n\n", node->item.expDate.dat, node->item.expDate.month, node->item.expDate.year);
        inorderTraversal(node->right);
    }
}

void preorderTraversal(NodePtr node) {
    if (node != NULL) {
        printf("Product: %s\n", node->item.prodName);
        printf("  Price: %.2f\n", node->item.prodPrice);
        printf("  Quantity: %d\n", node->item.prodQty);
        printf("  Expiry Date: %2d/%2d/%4d\n", node->item.expDate.dat, node->item.expDate.month, node->item.expDate.year);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}


void postorderTraversal(NodePtr node) {
    if (node != NULL) {
      
        postorderTraversal(node->left);

        postorderTraversal(node->right);
        printf("Product: %s\n", node->item.prodName);
        printf("  Price: %.2f\n", node->item.prodPrice);
        printf("  Quantity: %d\n", node->item.prodQty);
        printf("  Expiry Date: %2d/%2d/%4d\n", node->item.expDate.dat, node->item.expDate.month, node->item.expDate.year);
    }
}



