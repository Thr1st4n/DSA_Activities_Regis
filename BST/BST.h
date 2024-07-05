#ifndef BST
#define BST


typedef struct{
	int dat, month, year;
}Date;

typedef struct{
	
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node{
	Product item;
	struct node* left, * right;
}NodeType, *NodePtr;


void add(NodePtr *head, Product newItem);
void inorderTraversal(NodePtr node);
void preorderTraversal(NodePtr node);
void postorderTraversal(NodePtr node);
void delete(NodePtr* head);


#endif
