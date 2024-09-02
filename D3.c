#include <stdio.h>
#include <stdlib.h>
int* foo(char*,int,int*);

int main(){
		char* arr = (char*)malloc(10 * sizeof(char));
		const int size = 10;
		for(int i = 0; i < size; i++){
				scanf("%c", &arr[i]);
		}
		int count = 0;
		int* arr1 = foo(arr, size, &count);
		for(int i = 0; i < count; i++) {
				printf("%d ", arr1[i]);
		}
		free(arr1);
		arr1 = NULL;
		free(arr);
		arr = NULL;
		return 0;
}
int* foo(char* arr, int size, int* count) {
		int* arr2 = (int*)malloc(size * sizeof(int));
		int c = 0;
		for(int i = 0; i < size; i++) {
				if(arr[i] >= '0' && arr[i] <= '9'){
					arr2[c] = arr[i] - '0';
					c++;
				}
		}
		arr2 = realloc(arr2,c * sizeof(int));
		*count = c;
		return arr2;
}
