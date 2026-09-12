/*
 *
 *
 */

#include <iostream>
#include <ostream>
#include <stdexcept>

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
    if(head== nullptr){
      std::cout << "No node yet" << std::endl;
      throw std::invalid_argument("Head is null, add a node with append");
      
    }
    // Prints the first element of the list
    while(current->next != nullptr){
      std::cout << current->value << ">";
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

  ~LinkedList(){
    Node* current = head;
    while(current != nullptr){
      Node* next= current->next;
      delete current;
      current = next;
    }
//    if(tail){
//      std::cout << "Destructor failed" << std::endl;
//    }
  };

};

int main() {


  int number;
  LinkedList linked;
  try {
    for(int i = 0; i < 5; i++){
      std::cout  << "Enter a value for a node: " << std::endl;
      std::cin >> number;
      linked.append(number);
    }
    std::cout << "\n";
    linked.printsList();
  }
  catch (const std::runtime_error& e) {
    std::cerr << "Error: " <<  e.what() << std::endl;
  }

//  LinkedList newLinked;
//  newLinked.append(5);
//  newLinked.append(10);
//  newLinked.append(20);
//  newLinked.printsList();
//  Test with a empty list
//  LinkedList empty;
//  empty.printsList();

  return 0;
}
