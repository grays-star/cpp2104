#ifndef LIST_H
#define LIST_H

#include <string.h>

using namespace std;



class List{
	
	private: 
	node *front;  	
	node *end;   	
	
	public:
	List();
	int pop();
	void remove(node*pos);
	void push(int newData);
	int size();
	void insert(node *node, int newData);
	void print();
	
};

#endif