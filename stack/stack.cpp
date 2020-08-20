#ifndef _IOSTREAM_H_
#define _IOSTREAM_H_
#include <iostream>
#endif
using namespace std;

#ifndef _STRING_H_
#define _STRING_H_
#include <string>
#endif

#ifndef _STACK_H_
#define STACK_H_
#include "stack.h"
#endif


template <typename T>
Stack<T>* Stack<T>::last = nullptr;
template <typename T>
int Stack<T>::size = 0;

template <typename T>
Stack<T>::Stack(){
	this->data = '\0';
	this->next = nullptr;
	this->previous = nullptr;
}

template <typename T>
Stack<T>::Stack(T _data){
	this->data = _data;
	this->next = nullptr;
	this->previous = nullptr;
}

template <typename T>
void Stack<T>::pushData(T _data){
	Stack<T>* new_data = new Stack(_data);
	if(!last){
		last = new_data;
		this->next = new_data;
	}
	else{
		new_data->previous = last;
		last->next = new_data;
		last = new_data;
	}
	size++;
	return;
}

template <typename T>
void Stack<T>::popData(void){
	try{
		if(size <= 0){
			string exception = "stack is empty";
			throw exception;
		}
	}
	catch(string exception){
		string error = "Can't pop data: " + exception;
		cout << error << endl;
	}
	if(!last) return;
	Stack<T>* useless = last;
	last = last->previous;
	size--;
	delete useless;
	return;
}

template <typename T>
int Stack<T>::returnSize(void){
	return size;
}

template <typename T>
bool Stack<T>::emptyStack(void){
	return size ? false : true;
}

template <typename T>
T Stack<T>::topData(void){
	try{
		if(size <= 0){
			string exception = "stack is empty";
			throw exception;
		}
	}
	catch (string exception){
		return NULL;
	}
	return last->data;
}

template <typename T> 
void Stack<T>::print(void){
	Stack<T>* tmp = this;
	while(tmp){
		if(tmp->data) cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
