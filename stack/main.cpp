#include "stack.cpp"

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Stack<int>* stack = new Stack<int>();
	stack->popData();
	stack->emptyStack() ? cout << "true" << endl : cout << "false" << endl;
	cout << stack->returnSize() << endl;
	cout << stack->topData() << endl;
	stack->pushData(1);
	stack->pushData(2);
	stack->pushData(3);
	cout << stack->topData() << endl;
	cout << stack->returnSize() << endl;
	stack->print();
	stack->popData();
	cout << stack->returnSize() << endl;
	stack->print();
	stack->emptyStack() ? cout << "true" << endl : cout << "false" << endl;
}
