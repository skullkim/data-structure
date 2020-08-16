#include <iostream>
#include <cstdlib>
using namespace std;
const int LOAD_FACTOR = 20;
struct Node{
	int data;
	Node* next;
};
struct HashNode{
	int key;
	int count;
	Node* list;
};
struct HashTable{
	int size;
	HashNode** table;
};

void insertHash(HashTable*, int);
void reHash(HashTable*);

HashTable* createHash(int table_size){
	HashTable* h_table = new HashTable();
	h_table->size = table_size;
	h_table->table = new HashNode*[table_size];
	for(int i = 0; i < table_size; i++){
		h_table->table[i] = new HashNode();
		h_table->table[i]->key = i;
		h_table->table[i]->count = 0;
		h_table->table[i]->list = NULL;
	}
	return h_table;
}

int getKey(int data, int table_size){
	return data % table_size;
}

bool searchHash(HashTable* h_table, int target){
	Node* node = h_table->table[getKey(target, h_table->size)]->list;
	while(node){
		if(node->data == target) return true;
		node = node->next;
	}
	return false;
}

void deleteHash(HashTable* h_table){
	for(int i = 0; i < h_table->size; i++){
		Node* now = h_table->table[i]->list;
		Node* before;
		while(now){
			before = now;
			now = now->next;
			free(before);
		}
	}
	for(int i = 0; i < h_table->size; i++) free(h_table->table[i]);
	free(h_table);
}

void insertHash(HashTable* h_table, int data){
	HashNode* h_node = h_table->table[getKey(data, h_table->size)];
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	if(h_node->list == NULL) h_node = new_node;
	else{
		Node* tmp = h_node->list;
		h_node->list = new_node;
		new_node->next = tmp;
	}
	h_node->count++;
	if((h_node->count / h_table->size) > LOAD_FACTOR) h_table = reHash(h_table);
}

HashTable* reHash(HashTable* h_table){
	HashTable* old_table = h_table;
	h_table = createHash(h_table->size * 2);
	for(int i = 0 ; i< old_table->size; i++){
		HashNode* old = old_table->table[i];
		Node* tmp = old->list;
		while(tmp){
			insertHash(h_table, tmp->data);
			tmp = tmp->next;
		}
	}
	deleteHashTable(old_table);
	return h_table;
}

void deleteHash(HashTable* h_table, int data){
	HashNode* first = h_table->table[getKey(data, h_table->size)];
	Node* tmp = first->list;
	Node* before = tmp;
	if(!tmp) return;
	while(tmp){
		if(tmp->data == data){
			before == tmp ? first->list = tmp->next : before->next = tmp->next;
			free(tmp);
			break;
		}
		before = tmp;
		tmp = tmp->next;
	}
	first->count--;
}
