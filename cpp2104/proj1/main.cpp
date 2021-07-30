#include <iostream>
using namespace std;
struct node{
   int data;
   node* next;
};
class SingleLinkedList{
   private:
   node* head;
   public:
   SingleLinkedList(){
       head = nullptr;
   }
   // Print the list's contents
   void print(){
       node* tmp = head;
       while(tmp->next != nullptr){
           cout << tmp->data << " ";
           tmp = tmp->next;
       }
       cout << tmp->data << " ";
       cout << endl;
   }
   // Adds a new node to the end of the list
   void push(int newData){
       if(head == nullptr){
           head = new node;
           head->data = newData;
           head->next = nullptr;
       } else {
           // Loop until we find end of list
           node* tmp = head;
           while(tmp->next != nullptr){
               tmp = tmp->next;
           }
           // Add new node to end of list
           tmp->next = new node;
           (tmp->next)->data = newData;
           (tmp->next)->next = nullptr;
       }
   }
   // Removes the last node in the list and returns its data
   int pop(){
       int ret;
       node* tmp = head;
       node* prev = nullptr;
       while(tmp->next != nullptr){
           prev = tmp;
           tmp = tmp->next;
       }
       // Save return value
       ret = tmp->data;
       // Pop last node off of list and clean up data
       delete tmp;
       prev->next = nullptr;
       return ret;
   };
   // head-> 5-> 8-> 4-> 12-> 14-> 3-> nullptr
   // 4, 2
   void insert(int dataToInsert, unsigned int index){
       if(index == 0){
           node* backup = head;
           head = new node;
           head->data = dataToInsert;
           head->next = backup;
       }
       node* tmp = head;
       for(int i = 0; i < index - 1; i++){
           tmp = tmp->next;
       }
       node* backup = tmp->next;
       tmp->next = new node;
       tmp->next->data = dataToInsert;
       tmp->next->next = backup;
   }
};
int main(){
   SingleLinkedList list;
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

