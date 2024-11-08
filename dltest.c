#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main(){
	void *handle;
	int (*add)(int, int);
	int (*minus)(int, int);
        int (*multiply)(int, int);
        int (*divide)(int, int);
        char *error;
	
	handle = dlopen("./lib/libshare.so", RTLD_LAZY);
	if (!handle) {
		fputs(dlerror(), stderr);
	        exit(1);
	 }
	
	 add = dlsym(handle, "add");
	 minus = dlsym(handle, "minus");
	 multiply = dlsym(handle, "multiply");
	 divide = dlsym(handle, "divide");
	
	if ((error = dlerror()) != NULL) {
		 fputs(error, stderr);
		 exit(1);
	 }

	char *str = (char *)malloc(10 * sizeof(char));
	int num1, num2;
	
	printf("Please enter an operation (add, minus, multiply, divide): ");
	scanf("%s", str);
	printf("Please enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	
	if (strcmp(str, "add") == 0) {
		printf("Result: %d\n", add(num1, num2));
	}else if (strcmp(str, "minus") == 0) {
		printf("Result: %d\n", minus(num1, num2));
	}else if (strcmp(str, "multiply") == 0) {
		printf("Result: %d\n", multiply(num1, num2));
	}else if (strcmp(str, "divide") == 0) {
		if (num2 != 0) {
			printf("Result: %d\n", divide(num1, num2));
		} else {
			printf("Error: Division by zero\n");
		}
	}

	dlclose(handle);
	free(str);
	return 0;

}
