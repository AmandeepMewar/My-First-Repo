#include <stdio.h>
#include <ctype.h>
#define MAX 50

void push(char stack[],int *top,char c){
	stack[++(*top)]=c;
}

void pop(char stack[],int *top){
	printf("%c",stack[(*top)--]);
}

int priority(char c){
	if (c=='('){
		return 0;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else if(c=='*' || c=='/'){
		return 2;
    }
    else if(c=='^'){
    	return 3;
	}
    return 0;
}

int main(){
	char exp[MAX];
	char stack[MAX];
	int top=-1;
	printf("Enter a expression: ");
	scanf("%s",&exp);
	
	char *c=exp;
	
	while(*c!='\0'){
		if (isalnum(*c)){
			printf("%c",*c);
		}
		else if(*c=='('){
			push(stack,&top,*c);
		}
		else if(*c==')'){
			pop(stack,&top);
			(top)--;
		}
		else{
			if (priority(stack[top])>priority(*c)){
				pop(stack,&top);
			}
			push(stack,&top,*c);
		}
		c++;
	}
	
	while(top>-1){
		printf("%c",stack[(top)--]);
	}
}
