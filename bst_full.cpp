#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node node;

node* createNode(int item){
	node* temp=(node*)malloc(sizeof(node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node* insert(node* root,int item){
	if (root==NULL){
		return createNode(item);
	}
	else if (root->data < item){
		root->right=insert(root->right,item);
	}
	else if (root->data > item){
		root->left=insert(root->left,item);
	}
	else if(root->data == item){
		printf("Element already present...\n");
		return root;
	}
	return root;
}
node* inOrderPredecessor(node* root){
	root = root->left;
	while(root->right!=NULL){
		root=root->right;
	}
	return root;
}

node* deleteNode(node* root,int value){
	node* iPre;
	if (root==NULL){
		return NULL;
	}
	
	if (root->left==NULL && root->right==NULL){
		free(root);
		return NULL;
	}
	
	//Search for node to be deleted
	if (value < root->data){
		root->left = deleteNode(root->left,value);
	}
	else if(value > root->data){
		root->right = deleteNode(root->right,value);
	}
	// Now if value == root-data 
	else{
		iPre = inOrderPredecessor(root);
		root->data = iPre->data;
		root->left = deleteNode(root->left,iPre->data);
	}
	return root;
}

void inorder(node* root){
	if (root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(node* root){
	if (root==NULL){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root){
	if (root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

void enqueue(node** queue,int *front,int *rear,node* newNode){
	queue[++(*rear)]=newNode;
	if (*front==-1){
		(*front)++;
	}
}

node* dequeue(node** queue,int *front,int *rear){
	if (*front>*rear){
		return NULL;
	}
	return queue[(*front)++];
}

void printleverorder(node* root){
	int front=-1,rear=-1,MAX=50;
	node** queue=(node**)malloc(MAX*sizeof(node));
	node* temp=root;
	while(temp!=NULL){
		printf("%d ",temp->data);
		if (temp->left!=NULL){
			enqueue(queue,&front,&rear,temp->left);
		}
		if (temp->right!=NULL){
			enqueue(queue,&front,&rear,temp->right);
		}
		temp=dequeue(queue,&front,&rear);
	}
}
int main(){
	node* root=NULL;
	int item;
	int choice;
	
	do{
		printf("Welcome to Binary Search Tree\n");
		printf("1.Insert an element\n2.Delete an element\n3.Inorder Traversal\n4.Preorder Traversal\n5.Postorder Traversal\n6.Level Order Traversal\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		printf("\n");
		switch(choice){
			case 1: printf("Enter element to be inserted:");
			scanf("%d",&item);
			root=insert(root,item);
			printf("\n");
			break;
			case 2: printf("Enter element to be deleted: ");
			scanf("%d",&item);
			root=deleteNode(root,item);
			printf("Element deleted\n");
			printf("\n");
			break;
			case 3: if (root==NULL){
				printf("Tree is Empty\n");
			}
			else{
			    printf("Inorder : "); 
			    inorder(root);
			    printf("\n\n");
		    }
			break;
			case 4: if (root==NULL){
				printf("Tree is Empty\n");
			}
			else{
			    printf("Preorder : ");
			    preorder(root);
			    printf("\n\n");
		    }
			break;
			case 5: if (root==NULL){
				printf("Tree is Empty\n");
			}
			else{
			    printf("Postorder : ");
			    postorder(root);
			    printf("\n\n");
			}
			break;
			case 6: if (root==NULL){
				printf("Tree is Empty\n");
			}
			else{
			    printf("Lever Order traversal : ");
			    printleverorder(root);
			    printf("\n\n");
			}
			break;
			case 7: printf("Exiting...\n");
			break;
			default : printf("Enter a valid choice...\n");
		}
	}while(choice!=7);
}
