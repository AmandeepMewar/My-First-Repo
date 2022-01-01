//Code to check if the substring of a given string is palindrome or not.
//If palindrome replace each letter of such subtring with '*'.

/*  
    Sample input - bob in a radar plane
    output - *** in a ***** plane
*/

#include <iostream>
#include <cstring>
#define MAX 50
using namespace std;

int palindrome(char pal[]){
	int n=strlen(pal);
	int i=0;
	if (n==1){
		return 0;
	}
	while(i<n-1){
		if (pal[i]!=pal[n-1]){
			return 0;
		}
		i++;
		n--;
	}
	return 1;	
}

void replace(char str[],int k,int j){
	int i=0;
	while(i<j){
		str[k]='*';
		i++;
		k++;
	}
}

int main(){
	char str[MAX];
	char pal[MAX];
	printf("Enter a string :");
	cin.getline(str,MAX);
	int n=strlen(str);
	
	cout<<"length of string :"<<n<<endl;
	cout<<"\nstring before : "<<str<<endl;
	
	int i=0;
	int j;
	int k;
	
	while(i<n){
		j=0;
		k=i;
		while(str[i]!=' ' && str[i]!='\0'){
			pal[j]=str[i];
			i++;
			j++;
		}
		pal[j]='\0';
		if (palindrome(pal)){
			replace(str,k,j);
		}
		i++;
	}
	cout<<"String after Palindrome check: "<<str<<endl;
	
	return 0;
}
