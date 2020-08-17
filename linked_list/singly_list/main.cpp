#include "singly_list.cpp"

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	SinglyList<int>* root = new SinglyList<int>(1);
	root->pushBack(2);
	root->pushBack(3);
	root->pushBack(4);
	cout << root->printSize() << endl;
	root->printData();
	root->pushNextTo(4, 5);
	root->deleteData(3);
	cout << root->printSize() << endl;
	root->printData();
}
