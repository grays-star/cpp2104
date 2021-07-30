#include <iostream>
#include "list.h"
using namespace std;

struct node
{
	int data;     	
	node *prev;  	
	node *next; 	
};


};
int main(){
   List list;
   list.push(5);
   list.push(4);
   list.push(7);
   list.push(8);
   list.print();
   cout << "pop: " << list.pop() << endl;
   int* ptr;
   cout << ptr << endl;
   list.print();
   return 0;
}

