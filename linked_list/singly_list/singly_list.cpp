#ifndef IOSTREAM_H_
#define IOSTREAM_H_
#include <iostream>
#endif

#ifndef SINGLYLIST_H_
#define SINGLYLIST_H_
#include "singlyList.h"
#endif
using namespace std;

template<typename T>
int SinglyList<T>:: size = 0;

template<typename T>
SinglyList<T>:: SinglyList(){
	this->data = '\0';
	next = nullptr;
	last = nullptr;
}

template<typename T>
SinglyList<T>:: SinglyList(T _data){
	this->data = _data;
	next = nullptr;
	last = nullptr;
}

template<typename T>
void SinglyList<T>::pushBack(T _data){
	SinglyList<T>* new_data = new SinglyList<T>(_data);
	if(this->last == nullptr){
		if(this->next == nullptr) this->next = new_data;
		this->last = new_data;
	}
	else{
		this->last->next = new_data;
		this->last = last->next;
	}
	size++;
}

template<typename T>
void SinglyList<T>::pushNextTo(T prev_data, T target){
	SinglyList<T>* new_data = new SinglyList<T>(target);
	SinglyList<T>* node = this;
	while(node && node->data != prev_data) node = node->next;
	if(!node){
		cout << "data does not exist" << endl;
		return;
	}
	if(node == this->last){
		node->pushBack(target);
	}
	else{
		new_data->next = node->next;
		node->next = new_data;
		size++;
	}
}

template<typename T>
void SinglyList<T>::deleteData(T target){
	SinglyList<T>* node = this;
	SinglyList<T>* useless;
	while(node && node->next->data != target) node = node->next;
	useless = node->next;
	node->next == this->last ? this->last = node : node->next = node->next->next;
	size--;
	delete useless;
}

template<typename T>
int SinglyList<T>::printSize(void){
	return size;	
}

template <typename T>
void SinglyList<T>::printData(void){
	SinglyList* node = this;
	while(node){
		if(node->data)cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}
