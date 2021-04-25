#include <stdio.h>

int min(int a, int b){
	return a < b ? a : b;
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void){
	int arr[] = {99, 34, 55, 7, 82, 21, 9, 10, 46};
	for(int i = 0; i < 9; i++){
		int min_val = arr[i];
		int min_idx = i;
		for(int k = i; k < 9; k++){
			if(min_val > arr[k]){
				min_val = arr[k];
				min_idx = k;
			}
		}
		if(arr[i] > min_val) swap(&arr[i], &arr[min_idx]);
	}
	for(int i = 0; i < 9; i++){
		printf("%d ", arr[i]);
	}
}
