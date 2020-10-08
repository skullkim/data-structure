#include "deque.cpp"

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Deque<int>* dq = new Deque<int>();
	dq->isEmpty() ? cout << "deque is empty" << endl : cout << "deque is not empty" << endl;
	dq->addFront(2);
	cout << "front: " << dq->returnFrontData() << endl;
	dq->addFront(3);
	cout << "front: " << dq->returnFrontData() << endl;
	cout << "last: " << dq->returnEndData() << endl;
	dq->addEnd(4);
	cout << "last: " << dq->returnEndData() << endl;
	dq->addEnd(5);
	dq->printAllData();
	dq->removeFront();
	cout << "front: " << dq->returnFrontData() << endl;
	dq->removeEnd();
	cout << "last: " << dq->returnEndData() << endl;
	dq->printAllData();
	dq->addFront(5);
	dq->printAllData();
	dq->addEnd(10);
	dq->printAllData();
	dq->isEmpty() ? cout << "deque is empty" << endl : cout << "deque is not empty" << endl;
}
