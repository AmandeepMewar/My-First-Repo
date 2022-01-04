//Program to print first recurring character in a string.

#include <stdio.h>
#define MAX 50
#include <string.h>

int main(){
	char str[MAX];
	printf("Enter a string...\n");
	scanf("%s",&str);
	char visited='*';
	int count,s=0;
	
	for (int i=0;i<strlen(str)-1;i++){
		count=0;
		for(int j=i+1;j<strlen(str);j++){
			if (str[j]!=visited){
				if (str[i]==str[j]){
					count++;
					str[j]=visited;
				}
			}
		}
		if (count>0){
			s++;
			if (s==1){
				printf("%c",str[i]);
				return 0;
			}
		}
	}
	printf("Not found\n");
}
