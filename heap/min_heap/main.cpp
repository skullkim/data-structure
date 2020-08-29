#include "min_heap.cpp"

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	MinHeap<int>* heap = new MinHeap<int>(5);
	cout << heap->returnMinValue() << endl;
	heap->deleteData();
	heap->insertData(6);
	heap->insertData(3);
	cout << heap->returnMinValue() << endl;
	heap->insertData(20);
	heap->insertData(10);
	heap->printAllData(heap);
	cout << endl;
	heap->deleteData();
	heap->printAllData(heap);
	cout << endl;
	heap->insertData(1);
	cout << heap->returnMinValue() << endl;
	heap->printAllData(heap);
	cout << endl;
}
