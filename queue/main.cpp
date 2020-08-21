#include "queue.cpp"

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Queue<int>* q = new Queue<int>();
	cout << "newest:" << q->frontEle() << endl;
	cout << "oldest:" << q->backEle() << endl;
	cout << "size: " << q->returnSize() << endl;
	q->popEle();
	q->PushEle(1);
	q->PushEle(2);
	q->PushEle(3);
	cout << "newest:" << q->frontEle() << endl;
	cout << "oldest:" << q->backEle() << endl;
	cout << "size: " << q->returnSize() << endl;
	q->printQueue();
	q->popEle();
	q->printQueue();
	cout << "newest:" << q->frontEle() << endl;
	cout << "oldest:" << q->backEle() << endl;
	cout << "size: " << q->returnSize() << endl;
}
