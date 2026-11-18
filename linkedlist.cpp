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
    }
    if(!current->next){
      std::cout << "no next ";
    }
    // Prints the first element of the list
    while (current) {
      std::cout << current->value << " -> ";
      current = current->next;
    }
  }

  void printsHead() {
    Node *current= head;
    if(!current){
      std::cout << "No node yet" << std::endl;
      return;
    }
    std::cout << current->value << std::endl;
  }

  void printLast(){
    Node *current = head;
    if(!current){
      std::cout << "No node yet" << std::endl;
    }

    while (current->next != nullptr){
      current = current->next;
    }
   std::cout << current->value << std::endl;
  }

  void deleteLast(){ 
    Node *current = head;
    if (!current){
      std::cout << "No node yet"<< std::endl;
      return;
    }
    while(current->next){
      tail = current;
      current = current->next;
    }
    tail->next = nullptr;
    delete current;
  }

  void deleteValue(int value){

    if(!head) return;

    if(head->value == value){
      Node *temp = head;
      head = head->next;

      if(head == nullptr){
        tail = nullptr;
      }
      delete temp;
      return;
    }


    Node *current = head;
    while(current){
      tail = current;
      current = current->next;
      if(current->value == value){
        std::cout << "FOUND: " << current->value << std::endl;
        tail->next = current->next;
        delete current;
        return;
      }
    }
    std::cout << "not found value" << std::endl;
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


  // test of delete last, still getting seg fault
  // What is causing the seg fault is not delete but the printsList afterwards

  int value;
  LinkedList emptyTest;
  emptyTest.printsHead();
  emptyTest.deleteLast();

  for (int i = 0; i < 5; i++){
    value = i + 1;
    if (std::cin.fail()){
      std::cin.clear(); // required to clean buffer beclause if there is an eror program just freezes
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout << "Invalid Input" << std::endl;
    }else{
      emptyTest.append(value);
      emptyTest.printsList();
      std::cout << "\n";
    }
  }

  int menu;
  std::cout << "0 to quit / 1 to delete last / 2 print last / 3 delete value" << std::endl;
  std::cin >>  menu;
  if(menu==0){
    return 0;
  }
  if(menu == 1){
    emptyTest.deleteLast();
  }
  if(menu == 2) {
    emptyTest.printLast();
  }
  if(menu == 3) {
    int del_value;
    std::cout << "Enter a value to delete" << std::endl;
    std::cin >> del_value;
    emptyTest.deleteValue(del_value);
  }
  std::cout << "List after change" << std::endl;
  emptyTest.printsList();


//  Empty list still causes a crash [x] Solved
//  std::cout << "\nPRINTING HEAD TEST\n";
//  LinkedList head;
//  try{ 
//    head.printsList();
//  }catch (const std::runtime_error &e){
//    std::cerr << "Error: " << e.what() << std::endl;
//  }
//int number;
//  LinkedList linked;
//  try {
//    for (int i = 0; i < 5; i++) {
//      std::cout << "Enter a value for a node: " << std::endl;
//      std::cin >> number;
//      linked.append(number);
//    }
//    std::cout << "\n";
//    linked.printsList();
//  } catch (const std::runtime_error &e) {
//    std::cerr << "Error: " << e.what() << std::endl;
//  }
//
//  try{
//    LinkedList deleteLast;
//    for (int i = 0; i < 5; i++) {
//      std::cout << "Enter a value for a node: " << std::endl;
//      std::cin >> number;
//      deleteLast.append(number);
//    }
//    int loop_condition;
//    int user_input;
//    while(loop_condition != 1){
//      std::cout << "Press 1 to quit and press 0 to print list 2 to deleteLast" <<  std::endl;
//      std::cin >> user_input; 
//      if(user_input == 0){
//        deleteLast.printsList();
//      }
//      if(user_input == 1){
//        loop_condition = 1;
//      }
//      if(user_input == 2){
//        deleteLast.deleteLast();
//      }
//    }
//  }catch(const std::runtime_error &e){
//    std::cerr << "Error: " << e.what() << std::endl;
//  }

  

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
