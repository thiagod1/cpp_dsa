/*
 *
 *
 */

#include <iostream>
#include <limits>
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
      return;

//      throw std::runtime_error("Head is null, add a node with append");
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
      std::cout << "No node yet" << std::endl;
      return;
//      throw std::runtime_error("Head is null, add a node with append");
    }
    std::cout << current->value << std::endl;
  }



  // Work on this next, still doesn't work
  // getting heap after user error 
  // When I append a list 
  // delete it 
  // print it
  // then get error
  void deleteLast(){ 
    Node* last = head;
    while(last->next != nullptr){
      last->next = last->next->next;
      if(last->next == nullptr){
        delete last;
      }
    }
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

  int value;
  LinkedList emptyTest;
  emptyTest.printsHead();

  for (int i = 0; i < 5; i++){
    std::cout << "Enter a integer: ";
    std::cin >> value;
    if (std::cin.fail()){
      std::cin.clear(); // required to clean buffer beclause if there is an eror program just freezes
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout << "Invalid Input" << std::endl;
    }else{
      emptyTest.append(value);
      emptyTest.printsList();
    }
  }

  //  try {
  //    std::cout << "Enter a value: " << std::endl;
  //    std::cin >> value;  
  //  }catch (std::runtime_error &e){
  //    std::cerr << "Error: " << e.what() << std::endl;
  //  }



//  Empty list still causes a crash
  std::cout << "\nPRINTING HEAD TEST\n";
  LinkedList head;
  try{ 
    head.printsList();
  }catch (const std::runtime_error &e){
    std::cerr << "Error: " << e.what() << std::endl;
  }
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
      std::cout << "Press 1 to quit and press 0 to print list 2 to deleteLast" <<  std::endl;
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
