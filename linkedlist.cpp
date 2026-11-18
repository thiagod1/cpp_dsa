/*
 *
 *
 */

#include <iostream>
#include <limits>
#include <ostream>
#include <raylib.h>
#include <stdexcept>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

class Node {
public:
  int value; Node *next;
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
    if (!current->next) {
      std::cout << "no next ";
    }
    // Prints the first element of the list
    while (current) {
      std::cout << current->value << " -> ";
      current = current->next;
    }
  }

  void printsHead() {
    Node *current = head;
    if (!current) {
      std::cout << "No node yet" << std::endl;
      return;
    }
    std::cout << current->value << std::endl;
  }

  void printLast() {
    Node *current = head;
    if (!current) {
      std::cout << "No node yet" << std::endl;
    }

    while (current->next != nullptr) {
      current = current->next;
    }
    std::cout << current->value << std::endl;
  }

  void deleteLast() {
    Node *current = head;
    if (!current) {
      std::cout << "No node yet" << std::endl;
      return;
    }
    while (current->next) {
      tail = current;
      current = current->next;
    }
    tail->next = nullptr;
    delete current;
  }

  void deleteValue(int value) {

    if (!head)
      return;

    if (head->value == value) {
      Node *temp = head;
      head = head->next;

      if (head == nullptr) {
        tail = nullptr;
      }
      delete temp;
      return;
    }

    Node *current = head;
    while (current) {
      tail = current;
      current = current->next;
      if (current->value == value) {
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

//    bool IsMouseButtonPressed(int button);                  // Check if mouse
//    button has been pressed once bool IsMouseButtonDown(int button); // Check
//    if mouse button is being pressed bool IsMouseButtonReleased(int button);
//    // Check if mouse button has been released once bool IsMouseButtonUp(int
//    button);                       // Check if mouse button is NOT being
//    pressed

int main() {

  InitWindow(800, 450, "My App"); // the main window
  SetTargetFPS(60);

  int count = 0;

  char name_size[64] = "";
  int value = atoi(name_size);
  bool editing = false;

  while (!WindowShouldClose()) { // runs every frame until you close the window
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (GuiTextBox(Rectangle{20, 20, 250, 40}, name_size, 64, editing)) {
      editing = !editing;
    }

    //               x   y   width height   label
    if (GuiButton(Rectangle{150, 20, 150, 40}, "Add")) {
      TraceLog(LOG_INFO, "Your Value: %s: ", name_size);
    }
    if (GuiButton(Rectangle{20, 70, 150, 40}, "Reset")) {
      count = 0;
    }

    DrawText(TextFormat("Value:%d", value), 200, 230, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

  //  int value;
  //  LinkedList emptyTest;
  //  emptyTest.printsHead();
  //  emptyTest.deleteLast();
  //
  //  for (int i = 0; i < 5; i++){
  //    value = i + 1;
  //    if (std::cin.fail()){
  //      std::cin.clear(); // required to clean buffer beclause if there is an
  //      eror program just freezes
  //      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  //      std::cout << "Invalid Input" << std::endl;
  //    }else{
  //      emptyTest.append(value);
  //      emptyTest.printsList();
  //      std::cout << "\n";
  //    }
  //  }
  //
  //  int menu;
  //  std::cout << "0 to quit / 1 to delete last / 2 print last / 3 delete
  //  value" << std::endl; std::cin >>  menu; if(menu==0){
  //    return 0;
  //  }
  //  if(menu == 1){
  //    emptyTest.deleteLast();
  //  }
  //  if(menu == 2) {
  //    emptyTest.printLast();
  //  }
  //  if(menu == 3) {
  //    int del_value;
  //    std::cout << "Enter a value to delete" << std::endl;
  //    std::cin >> del_value;
  //    emptyTest.deleteValue(del_value);
  //  }
  //  std::cout << "List after change" << std::endl;
  //  emptyTest.printsList();
  //

  return 0;
}
