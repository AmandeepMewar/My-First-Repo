#include <stdio.h>

void push(int r,int c,int stack[r][c],int *topr,int *topc,int item){
    if(*topc==c-1){
        (*topr)++;
        (*topc)=0;
        stack[*topr][*topc]=item;
    }
    else{
        if (*topr==-1){
            (*topr)++;
        }
        stack[(*topr)][++(*topc)]=item;
    }
}

void pop(int r,int c,int stack[r][c],int *topr,int *topc){
    if (*topr==-1 && *topc==-1){
        printf("Stack is empty\n");
    }
    else if(*topc==0){
        if (*topr==0){
            printf("Element popped:%d\n",stack[(*topr)--][(*topc)--]);
        }
        else if(*topr>0){
            printf("Element popped: %d\n",stack[*topr][*topc]);
            *topc=c-1;
            (*topr)--;
        }
    }
    else{
        printf("Element popped: %d\n",stack[(*topr)][(*topc)--]);
    }
}

void display(int r,int c,int stack[r][c],int topr,int topc){
    if (topr==-1 && topc==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Display elements...\n");
        for(int i=topr;i>=0;i--){
            if (topc==c-1){
                for( int j=c-1;j>=0;j--){
                    printf("%d ",stack[i][j]);
                }
                printf("\n");
            }
            else{
                for(int j=topc;j>=0;j--){
                    printf("%d ",stack[i][j]);
                }
                printf("\n");
                topc=c-1;
            }
        }
    }
}

int main(){
    int r=3,c=4;
    int stack[r][c];
    int choice,item;
    int topr=-1;
    int topc=-1;

    do{
        printf("Welcome to 2d stack..\n");
        printf("1.push\n2.pop\n3.display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:if (topr==r-1 && topc==c-1){
                printf("Stack is full\n");
            }
            else{
                printf("Enter elements:");
                scanf("%d",&item);
                push(r,c,stack,&topr,&topc,item);
                break;
            }

            case 2: pop(r,c,stack,&topr,&topc);
            break;

            case 3: display(r,c,stack,topr,topc);
            break;

            case 4: printf("Exiting..\n");
            break;

            default: printf("Enter a valid choice\n");
        }
        
    }while (choice!=4);
}