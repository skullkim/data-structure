#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void){
	vector<list<int>> v(10);
	int arr[] = {22, 44, 66, 21, 11, 14, 63, 30};
	for(int i= 0; i < 8; i++){
		int n = arr[i] / 10;
		v[n].push_back(arr[i]);
	}
	for(int i = 0; i < 8; i++){
		v[i].sort();
	}
	for(int i = 0; i < 10; i++){
		for(auto k : v[i]) cout << k << " ";
	}
}
