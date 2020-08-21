#ifndef _IOSTREAM_H_
#define _IOSTREAM_H_
#include <iostream>
#endif
using namespace std;

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "queue.h"
#endif

#ifndef _CSTDLIB_H_
#define _SCTDLIB_H_
#include "cstdlib"
#endif

template <typename T>
Queue<T>* Queue<T>::last = nullptr;
template <typename T>
int Queue<T>::size = 0;

template <typename T>
Queue<T>::Queue(){
	this->data = NULL;
	this->next = nullptr;
	this->previous = nullptr;
}

template <typename T>
Queue<T>::Queue(T _data){
	this-> data = _data;
	this->next = nullptr;
	this->previous = nullptr;
}

template <typename T>
bool Queue<T>::emptyQueue(void){
	return size <= 0 ? true : false;
}

template <typename T>
int Queue<T>::returnSize(void){
	return size;
}

template <typename T>
void Queue<T>::PushEle(T _data){
	Queue<T>* new_data = new Queue(_data);
	if(!last){
		last = new_data;
		this->next = new_data;
	}
	else{
		new_data->next = this->next;
		this->next->previous = new_data;
		new_data->previous = this;
		this->next = new_data;
	}
	size++;
	return;
}

template <typename T>
void Queue<T>::popEle(void){
	try{
		if(size <= 0) throw "Queue is empty";
	}
	catch(const char* str){
		cout << "Cannot delete element: " << str << endl;
		return;
	}
	Queue<T>* useless = last;
	last = last->previous;
	size--;
	delete useless;
}

template <typename T>
T Queue<T>::frontEle(void){
	if(size <= 0) throw QueueEmptyException();
	return last->data;
}

template <typename T>
T Queue<T>::backEle(void){
	if(size <= 0) throw QueueEmptyException();
	return this->next->data; 
}

template <typename T>
void Queue<T>::printQueue(void){
	Queue<T>* tmp = this;
	while(tmp){
		if(tmp->data) cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
	return;
}



QueueEmptyException::QueueEmptyException()
: message("Queue is Empty"){}

QueueEmptyException::QueueEmptyException(string _m)
: message("" + _m){}

const char * QueueEmptyException::what() const throw(){
	return message.c_str();
}
