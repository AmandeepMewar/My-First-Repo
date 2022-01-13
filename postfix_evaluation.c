#include <stdio.h>
#include <ctype.h>
#define MAX 50

void push(int stack[],int *top,int n){
    stack[++(*top)]=n;
}

int pop(int stack[],int *top){
    return stack[(*top)--];
}
int main(){
    char exp[MAX];
    printf("Enter a postfix expression: ");

    scanf("%s",&exp);
    int stack[MAX];

    int n1,n2,n3;
    int n;
    int top=-1;
    char* e=exp;

    while(*e!='\0'){
        if (isdigit(*e)){
            n=(*e)-48;
            push(stack,&top,n);
        }
        else{
            n1=pop(stack,&top);
            n2=pop(stack,&top);

            switch(*e){
                case '+':n3=n1+n2;
                push(stack,&top,n3);
                break;

                case '-': n3=n1-n2;
                push(stack,&top,n3);
                break;

                case '*': n3=n1*n2;
                push(stack,&top,n3);
                break;

                case '/':n1=n1/n2;
                break;
            }
        }
        e++;
    }

    printf("Result : %d\n",stack[top]);
}