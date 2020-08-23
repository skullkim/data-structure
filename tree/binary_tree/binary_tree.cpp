#ifndef _IOSTREAM_H_
#define _IOSTREAM_H_
#include <iostream>
#endif
using namespace std;

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include "binary_tree.h"
#endif

template <typename T>
BiTree<T>* BiTree<T>:: root = nullptr;

template <typename T>
BiTree<T>::BiTree(){
	this->data = NULL;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

template <typename T>
BiTree<T>::BiTree(T _data){
	this->data = _data;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

template <typename T>
void BiTree<T>::insertData(T _data){
	BiTree<T>* new_node = new BiTree(_data);
	BiTree<T>* curr_node = this;
	if(!root) root = this;
	while(curr_node->left && curr_node->right){
		if(curr_node->left->data >= new_node->data) curr_node = curr_node->left;
		else curr_node = curr_node->right;
	}
	new_node->parent = curr_node;
	if((!curr_node->left && !curr_node->right) || (curr_node->left->data >= new_node->data)) curr_node->left = new_node; 
	else curr_node->right = new_node;
}

template <typename T>
BiTree<T>* BiTree<T>::getLeftTree(void){
	return this->left;	
}

template <typename T>
BiTree<T>* BiTree<T>::getRightTree(void){
	return this->right;
}

template <typename T>
T BiTree<T>::getRoot(void){
	return root->data;
}

template <typename T>
void BiTree<T>::preorderSearch(BiTree<T>* curr_node){
	if(!curr_node) return;
	cout << curr_node->data << " ";
	preorderSearch(curr_node->left);
	preorderSearch(curr_node->right);
}

template <typename T>
void BiTree<T>::inorderSearch(BiTree<T>* curr_node){
	if(!curr_node) return;
	preorderSearch(curr_node->left);
	cout << curr_node->data << " ";
	preorderSearch(curr_node->right);
}

template <typename T>
void BiTree<T>::postorderSearch(BiTree<T>* curr_node){
	if(!curr_node) return;
	preorderSearch(curr_node->left);
	preorderSearch(curr_node->right);
	cout << curr_node->data << " ";
}
