/* Program to Insert element inside a queue from right side and delete it from left side without violiating the FIFO  rules */

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
node* enqueue(node* head,int item){
    node* temp=(node* )malloc(sizeof(node));
    if (head==NULL){
        temp->data=item;
        temp->next=NULL;
        return temp;
    }
    temp->data=item;
    temp->next=head;
    return temp;

}

node* dequeue(node* head){
    node* temp=head;
    node* prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    printf("Element dequeued: %d\n",temp->data);
    free(temp);
    if (prev==NULL){
        return NULL;
    }
    prev->next=NULL;
    return head;
}

void display(node* head){
    if (head==NULL){
        return;
    }
    display(head->next);
    printf("%d ",head->data);
}
int main(){
    node* head=NULL;
    int choice;
    int item;

    do{
        printf("Welcome to Queue..\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: printf("Enter element to be inserted: ");
        scanf("%d",&item);
        head=enqueue(head,item);
        break;
        
        case 2: if (isEmpty(head)){
            printf("Queue is empty\n");
            break;
        }
        head=dequeue(head);
        break;

        case 3:if (isEmpty(head)){
            printf("Queue is empty\n");
            break;
        }
        display(head);
        printf("\n");
        break;

        case 4: printf("Exiting..\n");
        break;

        default: printf("Enter a valid choice\n");
        break;
        }
    }while (choice!=4);
}