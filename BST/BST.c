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


void delete(NodePtr* head){
	
}


void inorderTraversal(NodePtr node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("Product: %s\n", node->item.prodName);
        printf("  Price: %.2f\n", node->item.prodPrice);
        printf("  Quantity: %d\n", node->item.prodQty);
        printf("  Expiry Date: %02d/%02d/%04d\n\n", node->item.expDate.dat, node->item.expDate.month, node->item.expDate.year);
        inorderTraversal(node->right);
    }
}

void preorderTraversal(NodePtr node) {
    if (node != NULL) {
        printf("Product: %s\n", node->item.prodName);
        printf("  Price: %.2f\n", node->item.prodPrice);
        printf("  Quantity: %d\n", node->item.prodQty);
        printf("  Expiry Date: %02d/%02d/%04d\n", node->item.expDate.dat, node->item.expDate.month, node->item.expDate.year);
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
        printf("  Expiry Date: %02d/%02d/%04d\n", node->item.expDate.dat, node->item.expDate.month, node->item.expDate.year);
    }
}



