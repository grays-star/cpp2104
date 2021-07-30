#include <iostream>
#include <string>
#include <vector>
#include "list.h"

using namespace std;

List ::List(){
		front = nullptr;
		end = nullptr;
	}

void List :: push(int newData){

	node *temp;
	temp = new node();
	temp->data = newData;
	temp->prev = end;
	temp->next = nullptr;


	if(end == nullptr){
		front = temp;
	}
	else{
		end->next = temp;	
		end = temp;
   }
}

void List :: remove(node *pos)
{	
	if(pos->prev == nullptr){
		front = pos->next; 
		front->prev = nullptr;
	}
	else if(pos->next == nullptr){
		end = pos->prev;   
		end->next = nullptr;
	}
	else{
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
	}

	delete(pos);			
}

int List :: pop(){
       int ret;
       node* temp = front;
       node* prev = nullptr;
       while(temp->next != nullptr){
           prev = temp;
           temp = temp->next;
       }
       ret = temp->data;
       delete temp;
       prev->next = nullptr;
       return ret;
   };
   
int List :: size(){ 
   int length = 0; 
   while (node != nullptr) { 
       length++; 
       node = node->next; 
   } 
   return length; 
} 


void List :: insert(node *node, int newData){
	
	node *temp;
	temp = new node();
	temp->data = newData;
	temp->prev = node;
	temp->next = node->next;
	node->next = temp;

	if(node->next == nullptr){
		end = temp;
	}
}

void List :: print(){
       node* temp = front;
       while(temp->next != nullptr){
           cout << temp->data << " ";
           temp = temp->next;
       }
       cout << temp->data << " ";
       cout << endl;
   }