#include <stdio.h>

int main(void){
	int arr[] = {10, 12, 14, 15, 16, 20};
	int search = 15;

	int start = 0, end = 6 - 1;//len - 1
	while(start <= end){
		int mid = (start + end) / 2;
		if(arr[mid] == serach) return mid;
		else if(serach >= arr[mid]) start = mid + 1;
		else end = mid - 1;
	}
}
