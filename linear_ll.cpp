#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};
typedef struct node node;
int isEmpty(node* head){
	if (head==NULL){
		return 1;
	}
	return 0;
}
node* createNode(int item){
	node* temp=(node*)malloc(sizeof(node));
	temp->data=item;
	temp->next=NULL;
	return temp;
}
node* insertAtFront(node* head,int item){
	node* temp=createNode(item);
	if (isEmpty(head)){
		return temp;
	}
	temp->next=head;
	return temp;
}

node* insertAtIndex(node* head,int item,int index){
	node* temp=head;
	node* ptr=(node*)malloc(sizeof(node));
	int i=0;
	if (index==0){
		return insertAtFront(head,item);
	}
	while(temp->next!=NULL && i<index-1){
		i++;
		temp=temp->next;
	}
	ptr=createNode(item);
	if (temp->next==NULL){
		temp->next=ptr;
		return head;
	}
	ptr->next=temp->next;
	temp->next=ptr;
	return head;
}

node* insertAtEnd(node* head,int item){
	node* temp=head;
	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	node* ptr=createNode(item);
	temp->next=ptr;
	return head;
}

node* deleteFromStart(node* head){
	
	node* temp=head;
	head=temp->next;
	free(temp);
	return head;
}

node* deleteFromEnd(node* head){
	node* temp=head;
	node* prev=NULL;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	free(temp);
	prev->next=NULL;
	return head;
}

node* deleteElement(node* head,int item){
	node* temp=head;
	node*prev=NULL;
	
	while(temp!=NULL || temp->data!=item){
		prev=temp;
		temp=temp->next;
	}
	if (prev==NULL){
		return deleteFromStart(head);
	}
	prev->next=temp->next;
	free(temp);
	return head;
}

void displayFromStart(node* head){
	node* temp=head;
	
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

void displayFromEnd(node* head){
	if (head==NULL){
		return;
	}
	displayFromEnd(head->next);
	printf("%d ",head->data);
}
int main(){
	node* head=NULL;
	int item,index;
	int choice;
	
	do{
		printf("Welcome to linear linked list...\n");
		printf("1.Insert at front\n2.Insert at index\n3.Insert at end\n4.Delete from start\n5.Delete from end\n6.Delete an element\n7.Display from start\n8.Display from end\n9.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:printf("Enter an element :");
			scanf("%d",&item);
			head=insertAtFront(head,item);
			break;
			
			case 2:printf("Enter an element and its index :");
			scanf("%d%d",&item,&index);
			head=insertAtIndex(head,item,index);
			break;
			
			case 3:printf("Enter an element :");
			scanf("%d",&item);
			head=insertAtEnd(head,item);
			break;
			
			case 4: if (isEmpty(head)){
				printf("List is Empty\n");
			}
			else
			head=deleteFromStart(head);
			break;
			case 5:if (isEmpty(head)){
				printf("List is Empty\n");
			}
			else
			head=deleteFromEnd(head);
			break;
			
			case 6: if (isEmpty(head)){
				printf("List is Empty\n");
			}
			else{
			printf("Enter element to be deleted:");
			scanf("%d",&item);
			head=deleteElement(head,item);
		    }
			break;
			
			case 7: if (isEmpty(head)){
				printf("List is Empty\n");
			}
			else
			displayFromStart(head);
			break;
			
			case 8: if (isEmpty(head)){
				printf("List is Empty\n");
			}
			else
			   displayFromEnd(head);
			break;
			
			case 9: printf("Exiting...\n");
			break;
			
			default: printf("Enter a valid choice: ");
			
		}
	}while(choice!=9);
}
