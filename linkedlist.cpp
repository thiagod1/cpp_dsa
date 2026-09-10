/*
 *
 *
 */

#include <iostream>
#include <ostream>

class Node {
public:
  int value;
  Node *next;
  Node (int node_value){
    next = nullptr;
    value = node_value;
  }
};

class LinkedList {
public:
  Node* head;
  Node* tail;
  int length;
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
  }
  void append(int value) {
    Node* new_to_append = new Node(value);
    if(length == 0){
      head = new_to_append;
      tail = new_to_append;
    }else{
      tail->next = new_to_append;
      tail = new_to_append;
    }
   length++; 
  }

  void printsList(){
    Node* current = head;
    // Prints the first element of the list
    while(current->next != nullptr){
      std::cout << current->value << std::endl;
      current = current->next;
    }
    std::cout << current->value << std::endl;
  }

  void printsHead(){
    Node* head_add = head;
    do {
      std::cout << head_add->value; 
    } while(head_add->next != nullptr);
  }
  void deleteLast() {}


};

int main() {
  Node(5);

  LinkedList newLinked;
  newLinked.append(5);
  newLinked.append(10);
  newLinked.append(20);
  newLinked.printsList();

  return 0;
}
