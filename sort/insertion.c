#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int min(int a, int b){}

int main(void){
	int arr[] = {5, 1, 6, 2, 4, 3};
	for(int i = 1; i < 6; i++){
		int key = arr[i];
		int k;
		for(k  = i - 1; k >= 0; k--){
			if(arr[k] > key) arr[k + 1] = arr[k];
			else break;
		}
		arr[k + 1] = key;
	}
	for(int i = 0; i < 6; i++) printf("%d ", arr[i]);
}
