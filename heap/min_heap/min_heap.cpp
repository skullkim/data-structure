#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_
#include "min_heap.h"
#endif

#ifndef _IOSTREAM_H_
#define IOSTREAM_H_
#include <iostream>
#endif
using namespace std;

template <typename T>
T MinHeap<T>::root = NULL;

template <typename T>
MinHeap<T>::MinHeap(){
	this->data = '\0';
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

template <typename T>
MinHeap<T>::MinHeap(T _data){
	if(!root) root = _data;
	this->data = _data;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

template <typename T>
MinHeap<T>::~MinHeap(){
//	this->data = NULL;
//	this->left = nullptr;
//	this->right = nullptr;
//	this->parent = nullptr;
}

template<typename T>
void MinHeap<T>::swap(MinHeap<T>* node){
	T tmp = this->data;
	this->data = node->data;
	node->data = tmp;
}

template <typename T>
MinHeap<T>* MinHeap<T>::findLeafParent(MinHeap<T>* curr_node){
	MinHeap<T>* node;
	if(!curr_node->left || !curr_node->right || !curr_node->left->data || !curr_node->right->data){
		return curr_node;
	}
	node = findLeafParent(curr_node->left);
	node = findLeafParent(curr_node->right);
	return node;
}

template <typename T>
void MinHeap<T>::insertData(T _data){
	if(!_data) return;
	MinHeap<T>* new_data = new MinHeap<T>(_data);
	if(this->data == NULL){
		this->data = _data;
		root = _data;
	}
	else{
		T tmp;
		new_data->parent = findLeafParent(this);
		if(new_data->parent == new_data) new_data->parent = nullptr;
		if(new_data->parent){
			 !new_data->parent->left ? new_data->parent->left = new_data : new_data->parent->right = new_data;
		} 
		while(new_data->parent && new_data->parent->data > new_data->data){
			new_data->swap(new_data->parent);
			new_data = new_data->parent;
		}
		if(root && root > new_data->data) root = new_data->data;
	}
}

//template <typename T>
//MinHeap<T>* MinHeap<T>::remakeHeap(MinHeap<T>* curr_node, MinHeap<T>* prev_heap){
//	if(!prev_heap) return nullptr;
//	
//	MinHeap<T>* node;
//	if(prev_heap->parent && prev_heap->data != NULL){
//		node = new MinHeap<T>();
//		node->insertData(prev_heap->data);
//	}
//	node = remakeHeap(curr_node, prev_heap->left);
//	node = remakeHeap(curr_node, prev_heap->right);
//	return node;
//}

template <typename T>
void MinHeap<T>::remakeHeap(void){
	if(!this && !this->data) return;
	T tmp;
	if(this->left && this->right){
		if(this->left->data && this->left->data <= this->right->data && this->data > this->left->data){
			this->swap(this->left);
		}
		else if(this->right->data && this->right->data < this->left->data && this->data > this->right->data){
			this->swap(this->right);
		}
	}
	if(this->left != nullptr) this->left->remakeHeap();
	if(this->right != nullptr) this->right->remakeHeap();
}

template <typename T>
void MinHeap<T>::deleteData(void){
	MinHeap<T>* leaf_parent = findLeafParent(this);
	MinHeap<T>* useless;
	T tmp;
	if(leaf_parent->right){
		this->swap(leaf_parent->right);
		useless = leaf_parent->right;
		delete leaf_parent->right;
		leaf_parent->right = nullptr;
	}
	else if(!leaf_parent->right && !leaf_parent->left){
		this->swap(leaf_parent);
		delete leaf_parent;
		leaf_parent = nullptr;
	}
	else{
		this->swap(leaf_parent->left);
		useless = leaf_parent->left;
		delete leaf_parent->left;
		leaf_parent->left = nullptr;
	}
	this->remakeHeap();
	root = this->data;
	//MinHeap<T>* this_root = this;
	//this_root = remakeHeap(new MinHeap<T>(), this);
	//this_root = this->remakeHeap();
}

template<typename T>
T MinHeap<T>::returnMinValue(void){
	return root;
}

template <typename T>
void MinHeap<T>::printAllData(MinHeap<T>* curr_node){
	if(!curr_node || !curr_node->data) return;
	cout << curr_node->data << " ";
	printAllData(curr_node->left);
	printAllData(curr_node->right);
}
