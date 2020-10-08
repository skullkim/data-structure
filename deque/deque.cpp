#ifndef _DEQUE_H_
#define _DEQUE_H_
#include "deque.h"
#endif

#ifndef _IOSTREAM_H_
#define _IOSTREAM_H_
#include <iostream>
#endif
using namespace std;

template <typename T>
Deque<T>* Deque<T>::first = nullptr;

template <typename T>
Deque<T>* Deque<T>::last = nullptr;

template <typename T>
T Deque<T>:: size = 0;

template <typename T>
Deque<T>::Deque(){
	this->data = '\0';
	this->next = nullptr;
	this->previous = nullptr;
}

template <typename T>
Deque<T>::Deque(T _data){
	this->data = _data;
	this->next = nullptr;
	this->previous = nullptr;
	if(!size){
		first = this;
		last = this;
	}
}

template <typename T>
bool Deque<T>::isEmpty(void){
	return size > 0 ? false : true;
}

template <typename T>
void Deque<T>::addFront(T _data){
	Deque<T>* new_data = new Deque<T>(_data);
	Deque<T>* curr_node = this;
	if(!size){
		this->next = new_data;
		first = new_data;
		last = new_data;
	}
	else{
		new_data->next = this->next;
		this->next->previous = new_data;
		new_data->previous = this;
		this->next = new_data;
		first = new_data;
	}
	size++;
	return;
}

template <typename T>
void Deque<T>::addEnd(T _data){
	Deque<T>* new_data = new Deque<T>(_data);
	Deque<T>* curr_node = this;
	if(!size){
		curr_node = new_data;
		first = new_data;
		last = new_data;
	}
	else{
		new_data->previous = last;
		last->next = new_data;
		last->previous = last;
		last = last->next;
	}
	size++;
	return;
}

template <typename T>
void Deque<T>::removeFront(void){
	Deque<T>* useless = first;
	first->next ? first = first->next : first = nullptr;
	this->next->next ? this->next = this->next->next : this->next = nullptr;
	delete useless;
	useless = nullptr;
	size--;
	return;
}

template <typename T>
void Deque<T>::removeEnd(void){
	Deque<T>* useless = last;
	last->previous ? last = last->previous : last = nullptr;
	last->next = nullptr;
	delete useless;
	useless = nullptr;
	size--;
	return;
}

template <typename T>
T Deque<T>::returnFrontData(void){
	try{
		if(!first->data) throw "deque is empty";
	}
	catch(const char* str){
		cout << str << endl;
		return EXIT_FAILURE;
	}
	return first->data;
}

template <typename T>
T Deque<T>::returnEndData(void){
	try{
		if(!first->data) throw "deque is empty";
	}
	catch(const char* str){
		cout << str << endl;
		return EXIT_FAILURE;
	}
	return last->data;
}

template <typename T>
void Deque<T>::printAllData(void){
	Deque<T>* curr_node = this;
	while(curr_node){
		if(curr_node->data) cout << curr_node->data << " ";
		curr_node = curr_node->next;
	}
	cout << endl;
	return;
}
