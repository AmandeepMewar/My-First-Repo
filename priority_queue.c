//Priority Queue using BST.

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int priority;
	struct node* left;
	struct node* right;
};
typedef struct node node;

int isEmpty(node* root){
	if (root==NULL){
		return 1;
	}
	return 0;
}
node* createNode(int item,int priority){
	node* temp=(node*)malloc(sizeof(node));
	temp->data=item;
	temp->priority=priority;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node* insertElement(node* root,int item,int priority){
	
	if (root==NULL){
		return createNode(item,priority);
	}
	else if(root->priority < priority){
		root->right=insertElement(root->right,item,priority);
	}
		else if(root->priority > priority){
		root->left=insertElement(root->left,item,priority);
	}
	else{
		printf("Element with same priority is already present\n");
	}
}

node* deleteHighestPriority(node* root){
	node* temp=root;
	node* prev=NULL;
	if (temp->right==NULL){
		if (temp->left!=NULL){
			temp=temp->left;
			root->left=temp->left;
			free(temp);
			return root;
		}
		printf("Element deleted: %d (priority: %d)\n",temp->data,temp->priority);
		free(temp);
		return NULL;
	}
	while(temp->right!=NULL){
		prev=temp;
		temp=temp->right;
	}
	prev->right=NULL;
	printf("Element deleted: %d (priority: %d)",temp->data,temp->priority);
	free(temp);
	return root;
}

void display(node* root){
	
	if(root!=NULL){
		display(root->right);
		printf("Element: %d    Priority: %d\n",root->data,root->priority);
		display(root->left);
	}
	return;
}
int main(){
	node* root=NULL;
	int item;
	int priority;
	int choice;
	
	do{
		printf("Welcome to priority Queue\n");
		printf("1.Insert element\n2.Delete element\n3.Display\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: printf("Enter element and its priority :");
			scanf("%d%d",&item,&priority);
			root=insertElement(root,item,priority);
			break;
			case 2: if (isEmpty(root)){
				printf("Queue is empty\n");
				break;
			}
			root=deleteHighestPriority(root);
			break;
			case 3: if (isEmpty(root)){
				printf("Queue is empty\n");
				break;
			}
			display(root);
			break;
			case 4: printf("Exiting...\n");
			break;
			default: printf("Enter a valid choice...\n");
		}
	}while(choice!=4);
}
