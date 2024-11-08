

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char math[10];
	int num1 = 0;
	int num2 = 0;
	

	printf(" 계산 방법 입력: ");
	scanf("%s",math);

	printf(" 계산할 숫자1 입력: ");
	scanf("%d",&num1);
	printf(" 계산할 숫자2 입력: ");
	scanf("%d",&num2);
	
	if(strcmp(math, "add")==0){
		printf("덧셈: %d\n", add(num1, num2));
	}
	else if(strcmp(math, "subtract")==0){
		 printf("뺄셈: %d\n", subtract(num1, num2));
	 }
	else if(strcmp(math, "multiply")==0){
	        printf("곱셈: %d\n", multiply(num1, num2));
	 }
	else{
		printf("나눗셈: %d\n", divide(num1, num2));
	}

	return 0;

}
