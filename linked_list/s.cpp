#include <iostream>
using namespace std;

template<typename T>
class SinglyList{
private:
	T data;
	int size;
	SinglyList* next;
	SinglyList* last;
public:
	SinglyList(){}
	SinglyList(T _data){
		this->data = _data;
		size = 0;
		next = nullptr;
		last = nullptr;
	}
	void pushBack(T _data){
		SinglyList<T>* new_data = new SinglyList<T>(_data);
		if(this->last == nullptr){
			if(this->next == nullptr) this->next = new_data;
			this->last = new_data;
		}
		else{
			this->last->next = new_data;
			this->last = last->next;
		}
	}
	void printData(void){
		SinglyList<int>* tmp = this;
		while(tmp){
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	SinglyList<int>* root = new SinglyList<int>(1);
	root->pushBack(2);
	root->pushBack(3);
	root->pushBack(4);
	root->printData();
}
