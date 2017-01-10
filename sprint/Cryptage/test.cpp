#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char * message, int degree) {

	int n = 0, rotateSwap = 0;
	int i;

		for(i=0; i<strlen(message); i++){
        	if(message[i] >='a' && message[i] <='z'){
                n = 'z' - message[i];
                if( degree > n ){
                    rotateSwap = degree - n - 1;
                    message[i] = 'a';
                    message[i] += rotateSwap;
                  }  
               	else
                message[i] += degree;
               }
       }
}

int main()
{
    char * message;
   	int  degree;
	
   	printf("Enter String: ");
   	gets(message);
   	printf("Enter Number: ");
   	scanf("%i", &degree);

	encrypt(message, degree);

   	int j;
    	for(j = 0; message[j] !='\0'; j++){
        	 printf("%c", message[j]);
       	}

      	printf("\n");

     	return 0;
}