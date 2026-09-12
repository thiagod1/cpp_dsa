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
  Node(int node_value) {
    next = nullptr;
    value = node_value;
  }
};
class LinkedList {
public:
  Node *head;
  Node *tail;
  int length;

  LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
  }
  void append(int value) {
    Node *new_to_append = new Node(value);
    if (length == 0) {
      head = new_to_append;
      tail = new_to_append;
    } else {
      tail->next = new_to_append;
      tail = new_to_append;
    }
    length++;
  }

  void printsList() {
    Node *current = head;
    if (head == nullptr) {
      std::cout << "No node yet" << std::endl;
      throw std::runtime_error("Head is null, add a node with append");
    }
    // Prints the first element of the list
    while (current->next != nullptr) {
      std::cout << current->value << ">";
      current = current->next;
    }
    std::cout << current->value << std::endl;
  }

  void printsHead() {
    Node *current= head;
    if(!current){
      std::cout << "There is no head";
    }
    std::cout << current->value << std::endl;

  }
  void deleteLast(){ 
    Node* last = tail;
    delete last;
  }

  ~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  };
};

int main() {

  int number;
  LinkedList linked;
  try {
    for (int i = 0; i < 5; i++) {
      std::cout << "Enter a value for a node: " << std::endl;
      std::cin >> number;
      linked.append(number);
    }
    std::cout << "\n";
    linked.printsList();
  } catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

//  Empty list still causes a crash
  std::cout << "\nPRINTING HEAD TEST\n";
  LinkedList head;
  try{ 
    head.printsList();
  }catch (const std::runtime_error &e){
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try{
    LinkedList deleteLast;
    for (int i = 0; i < 5; i++) {
      std::cout << "Enter a value for a node: " << std::endl;
      std::cin >> number;
      deleteLast.append(number);
    }
    int loop_condition;
    int user_input;
    while(loop_condition != 1){
      std::cout << "Press 1 to quit and press 0 to print list" <<  std::endl;
      std::cin >> user_input; 
      if(user_input == 0){
        deleteLast.printsList();
      }
      if(user_input == 1){
        loop_condition = 1;
      }
      if(user_input == 2){
        deleteLast.deleteLast();
      }
    }


  }catch(const std::runtime_error &e){
    std::cerr << "Error: " << e.what() << std::endl;
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
